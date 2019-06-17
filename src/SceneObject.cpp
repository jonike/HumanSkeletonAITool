/*
 * SceneObject.cpp
 *
 *  Created on: June 8, 2019
 *      Author: mark
 */

#include "SceneObject.h"

SceneObject::SceneObject()
{
	location = nullptr;
	argc = 0;
	argv = nullptr;
	texture = nullptr;
	doResize = false;
}

SceneObject::SceneObject(int argc, char** argv) : SceneObject()
{
	this->argc = argc;
	this->argv = argv;
}

SceneObject::~SceneObject()
{
	if(location)
		delete[] location;
}

void SceneObject::Init(const rapidjson::Value& jsonobject)
{
	int x = 0, y = 0;

	std::cout << "SceneObject = {" << std::endl;

	if(jsonobject.HasMember("name"))
	{
		this->name = jsonobject["name"].GetString();
		std::cout << "name = " << this->name << std::endl;
	}
	if(jsonobject.HasMember("texture"))
	{
		this->texture = new Texture();
		this->texture->Init(jsonobject["texture"]);
	}
	if(jsonobject.HasMember("geometryfile"))
	{
		this->geometryfile = jsonobject["geometryfile"].GetString();
		std::cout << "geometryfile = " << this->geometryfile << std::endl;
	}
	if(jsonobject.HasMember("resize"))
	{
		this->doResize = jsonobject["resize"].GetBool();
		std::cout << "resize = " << this->doResize << std::endl;
	}

	std::cout << "} End SceneObject " << std::endl;

	location = new int[2] {x, y};

	if(this->geometryfile != "")
	{
		std::string warn, err;

		//need to set triangulate to false or else it will only load objects as triangle meshes despite being in quad format
		if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, this->geometryfile.c_str(), nullptr, false)) {
			throw std::runtime_error(warn + err);
		}
	}
}

void SceneObject::Update()
{

}

void SceneObject::Render()
{
	glPushMatrix();

	if(texture != nullptr)
	{
		glEnable(GL_TEXTURE_2D);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture->texture);

		glScalef((float)texture->size[0], (float)texture->size[1], 1.0f);
	}
	else
	{
		glColor3f(0.4f, 0.4f, 0.4f);
		glScalef(10.0f, 10.0f, 5.0f);
		glRotatef(90.0f, 0.0, 1.0, 0.0);
		glRotatef(90.0f, 1.0, 0.0, 0.0);
	}



	for (size_t s = 0; s < shapes.size(); s++) {
		// Loop over faces(polygon)
		size_t index_offset = 0;
		for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {

			int fv = shapes[s].mesh.num_face_vertices[f];

			glBegin(fv == 3 ? GL_TRIANGLES : GL_QUADS);

			// Loop over vertices in the face.
			for (size_t v = 0; v < fv; v++) {
				// access to vertex
				tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
				if(texture != nullptr) glTexCoord2f(attrib.texcoords[2*idx.texcoord_index+0], attrib.texcoords[2*idx.texcoord_index+1]);
				glNormal3f(attrib.normals[3*idx.normal_index+0], attrib.normals[3*idx.normal_index+1], attrib.normals[3*idx.normal_index+2]);
				glVertex3f(attrib.vertices[3*idx.vertex_index+0], attrib.vertices[3*idx.vertex_index+1], attrib.vertices[3*idx.vertex_index+2]);
			}
			index_offset += fv;

			glEnd();
		}
	}

	if(texture != nullptr)
	{
		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();
}

void SceneObject::Shutdown()
{

}

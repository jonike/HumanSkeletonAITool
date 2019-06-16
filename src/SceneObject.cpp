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
		texture = new Texture();
		texture->Init(jsonobject["texture"]);
	}
	if(jsonobject.HasMember("geometryfile"))
	{
		this->geometryfile = jsonobject["geometryfile"].GetString();
		std::cout << "geometryfile = " << this->geometryfile << std::endl;
	}

	std::cout << "} End SceneObject " << std::endl;

	location = new int[2] {x, y};

	if(this->geometryfile != "")
	{
		tinyobj::attrib_t attrib;
		std::vector<tinyobj::shape_t> shapes;
		std::vector<tinyobj::material_t> materials;
		std::string warn, err;

		if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, this->geometryfile.c_str())) {
			throw std::runtime_error(warn + err);
		}

		for (size_t s = 0; s < shapes.size(); s++) {
		  // Loop over faces(polygon)
		  size_t index_offset = 0;
		  for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
		    int fv = shapes[s].mesh.num_face_vertices[f];

		    // Loop over vertices in the face.
		    for (size_t v = 0; v < fv; v++) {
		      // access to vertex
		      tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
		      tinyobj::real_t vx = attrib.vertices[3*idx.vertex_index+0];
		      tinyobj::real_t vy = attrib.vertices[3*idx.vertex_index+1];
		      tinyobj::real_t vz = attrib.vertices[3*idx.vertex_index+2];
		      tinyobj::real_t nx = attrib.normals[3*idx.normal_index+0];
		      tinyobj::real_t ny = attrib.normals[3*idx.normal_index+1];
		      tinyobj::real_t nz = attrib.normals[3*idx.normal_index+2];
		      tinyobj::real_t tx = attrib.texcoords[2*idx.texcoord_index+0];
		      tinyobj::real_t ty = attrib.texcoords[2*idx.texcoord_index+1];
		      // Optional: vertex colors
		      // tinyobj::real_t red = attrib.colors[3*idx.vertex_index+0];
		      // tinyobj::real_t green = attrib.colors[3*idx.vertex_index+1];
		      // tinyobj::real_t blue = attrib.colors[3*idx.vertex_index+2];

		      std::cout << vx << '\t' << vy << '\t' << vz << std::endl;
		    }
		    index_offset += fv;

		    // per-face material
		    shapes[s].mesh.material_ids[f];
		  }
		}
	}
}

void SceneObject::Update()
{

}

void SceneObject::Render()
{
	//glRotatef(angle, 0.0f, 1.0f, 0.0f);

	//glColor3f(1.0f,1.0f,1.0f);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture->texture);

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 0.0);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f,-1.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f( 1.0f, 1.0f, 0.0);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f( 1.0f, -1.0f, 0.0);
	glEnd();
}

void SceneObject::Shutdown()
{

}

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

void SceneObject::Init(const Value& jsonobject)
{
	int x = 0, y = 0;

	cout << "SceneObject = {" << endl;

	if(jsonobject.HasMember("name"))
	{
		this->name = jsonobject["name"].GetString();
		cout << "name = " << this->name << endl;
	}
	if(jsonobject.HasMember("texturefile"))
	{
		this->texturefile = jsonobject["texturefile"].GetString();
		cout << "texturefile = " << this->texturefile << endl;
	}
	if(jsonobject.HasMember("geometryfile"))
	{
		this->geometryfile = jsonobject["geometryfile"].GetString();
		cout << "geometryfile = " << this->geometryfile << endl;
	}

	cout << "} End SceneObject " << endl;

	location = new int[2] {x, y};
}

void SceneObject::Update()
{

}

void SceneObject::Render()
{

}

void SceneObject::Shutdown()
{

}

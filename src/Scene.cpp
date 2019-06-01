/*
 * Scene.cpp
 *
 *  Created on: May 30, 2019
 *      Author: mark
 */

#include "Scene.h"

Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::Init(Document& scenefile)
{
	scenefile["scene"].GetObject();
	cout << "Scene = {" << endl;

	if(scenefile["scene"].HasMember("name"))
	{
		name = scenefile["scene"]["name"].GetString();
		cout << "Name = " << name << endl;
	}
	if(scenefile["scene"].HasMember("camera"))
	{
		this->camera = new Camera();
		this->camera->Init(scenefile);
	}
	if(scenefile["scene"].HasMember("viewport"))
	{
		this->viewport = new Viewport();
		this->viewport->Init(scenefile);
	}

	cout << "} End Scene" << endl;

}

void Scene::Update()
{

}

void Scene::Render()
{

}

void Scene::Shutdown()
{

}

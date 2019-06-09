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

void Scene::Init(const rapidjson::Value& scenefile)
{
	std::cout << "Scene = {" << std::endl;

	if(scenefile.HasMember("name"))
	{
		name = scenefile["name"].GetString();
		std::cout << "Name = " << name << std::endl;
	}
	if(scenefile.HasMember("camera"))
	{
		this->camera = new Camera();
		this->camera->Init(scenefile["camera"]);
	}
	if(scenefile.HasMember("viewport"))
	{
		this->viewport = new Viewport();
		this->viewport->Init(scenefile["viewport"]);
	}
	if(scenefile.HasMember("sceneobjects"))
	{
		const rapidjson::Value& jsonsceneobjects = scenefile["sceneobjects"];
		for (rapidjson::Value::ConstValueIterator itr = jsonsceneobjects.Begin(); itr != jsonsceneobjects.End(); ++itr) {
			SceneObject sceneobject = SceneObject();
			sceneobject.Init((*itr));
			this->sceneobjects.push_back(sceneobject);
		}
	}

	std::cout << "} End Scene" << std::endl;

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

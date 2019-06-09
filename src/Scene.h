/*
 * Scene.h
 *
 *  Created on: May 30, 2019
 *      Author: mark
 */

#ifndef SCENE_H_
#define SCENE_H_

#include "Camera.h"
#include "Viewport.h"
#include "SceneObject.h"

class Scene
{
public:
	std::string name;
	Camera* camera;
	Viewport* viewport;
	std::vector<SceneObject> sceneobjects;

	Scene();

	~Scene();

	void Init(const rapidjson::Value& scenefile);

	void Update();

	void Render();

	void Shutdown();
};

#endif /* SCENE_H_ */

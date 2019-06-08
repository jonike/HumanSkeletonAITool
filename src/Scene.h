/*
 * Scene.h
 *
 *  Created on: May 30, 2019
 *      Author: mark
 */

#ifndef SCENE_H_
#define SCENE_H_

#include <iostream>
#include <string>
#include <vector>
#include "Camera.h"
#include "Viewport.h"
#include "JSONReader.h"
#include "SceneObject.h"

class Scene
{
public:
	string name;
	Camera* camera;
	Viewport* viewport;
	vector<SceneObject> sceneobjects;

	Scene();

	~Scene();

	void Init(const Value& scenefile);

	void Update();

	void Render();

	void Shutdown();
};

#endif /* SCENE_H_ */

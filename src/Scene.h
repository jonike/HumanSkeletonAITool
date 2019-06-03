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
#include "Camera.h"
#include "Viewport.h"
#include "JSONReader.h"

class Scene
{
public:
	Camera* camera;
	Viewport* viewport;
	string name;

	Scene();

	~Scene();

	void Init(Document& scenefile);

	void Update();

	void Render();

	void Shutdown();
};

#endif /* SCENE_H_ */

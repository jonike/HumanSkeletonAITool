/*
 * SceneObject.h
 *
 *  Created on: June 8, 2019
 *      Author: mark
 */

#ifndef SCENEOBJECT_H_
#define SCENEOBJECT_H_

#include <GL/glut.h>
#include "tiny_obj_loader.h"
#include "JSONReader.h"
#include "Texture.h"


class SceneObject
{
public:
	int* location;
	std::string name;
	std::string geometryfile;

	Texture* texture;

	SceneObject();
	SceneObject(int argc, char** argv);
	~SceneObject();

	void Init(const rapidjson::Value& jsonobject);
	void Update();
	void Render();
	void Shutdown();

protected:
	int argc;
	char** argv;
};



#endif /* SCENEOBJECT_H */

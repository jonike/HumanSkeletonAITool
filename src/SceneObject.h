/*
 * SceneObject.h
 *
 *  Created on: June 8, 2019
 *      Author: mark
 */

#ifndef SCENEOBJECT_H_
#define SCENEOBJECT_H_

#include <GL/glut.h>
#include "JSONReader.h"

class SceneObject
{
public:
	int* location;
	string name;
	string texturefile;
	string geometryfile;

	SceneObject();
	SceneObject(int argc, char** argv);
	~SceneObject();

	void Init(const Value& jsonobject);
	void Update();
	void Render();
	void Shutdown();

protected:
	int argc;
	char** argv;
};



#endif /* WINDOW_H_ */

/*
 * Viewport.h
 *
 *  Created on: May 26, 2019
 *      Author: mark
 */

#ifndef VIEWPORT_H_
#define VIEWPORT_H_

#include <GL/glut.h>
#include "JSONReader.h"

class Viewport
{
public:
	int* location;
	int* size;

	Viewport();
	~Viewport();

	void Init(const rapidjson::Value& scenefile);
	void Update();
	void Render();
	void Shutdown();

	void Set(int x, int y, int width, int height);
};



#endif /* VIEWPORT_H_ */

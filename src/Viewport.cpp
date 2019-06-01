/*
 * Viewport.cpp
 *
 *  Created on: May 26, 2019
 *      Author: mark
 */

#include "Viewport.h"

Viewport::Viewport()
{
	location = nullptr;
	size = nullptr;
}

Viewport::~Viewport()
{
	if(location)
		delete[] location;
	if(size)
		delete[] size;
}

void Viewport::Init(Document& scenefile)
{
	int x, y = 0;
	int width = 800, height = 600;

	cout << "Viewport = {" << endl;

	if(scenefile["scene"]["viewport"].HasMember("x"))
	{
		x = scenefile["scene"]["viewport"]["x"].GetInt();
		cout << "x = " << x << endl;
	}
	if(scenefile["scene"]["viewport"].HasMember("y"))
	{
		y = scenefile["scene"]["viewport"]["y"].GetInt();
		cout << "y = " << y << endl;
	}
	if(scenefile["scene"]["viewport"].HasMember("width"))
	{
		width = scenefile["scene"]["viewport"]["width"].GetInt();
		cout << "width = " << width << endl;
	}
	if(scenefile["scene"]["viewport"].HasMember("height"))
	{
		height = scenefile["scene"]["viewport"]["height"].GetInt();
		cout << "height = " << height << endl;
	}

	cout << "} End Viewport" << endl;

	location = new int[2] {x, y};
	size = new int[2] { width, height };
}

void Viewport::Update()
{

}

void Viewport::Render()
{

}

void Viewport::Shutdown()
{

}

void Viewport::Set(int x, int y, int width, int height)
{
	location = new int[2] { x, y };
	size = new int[2] { width, height };

	// Set the viewport to be the entire window
	glViewport(location[0], location[1], size[0], size[1]);
}



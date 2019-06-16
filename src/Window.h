/*
 * Window.h
 *
 *  Created on: May 26, 2019
 *      Author: mark
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <GL/glut.h>
#include "Scene.h"
#include "JSONReader.h"

class Window
{
public:
	int* location;
	int* size;

	Scene* scene;

	Window();
	Window(int argc, char** argv);
	~Window();

	void Init(const rapidjson::Value& scenefile);
	void Update();
	void Render();
	void Shutdown();

	void Reshape(int width, int height);
	void Keyboard(unsigned char key, int x, int y);

	void MainLoop();

	void Clear(GLbitfield mask);
	void SwapBuffers();

	static void displayWrapper();
	static void reshapeWrapper(int width, int height);
	static void keyboardWrapper(unsigned char key, int x, int y);
	static void idleWrapper();

protected:
	int argc;
	char** argv;

	static Window *instance;
};



#endif /* WINDOW_H_ */

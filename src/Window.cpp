/*
 * Window.cpp
 *
 *  Created on: May 26, 2019
 *      Author: mark
 */

#include "Window.h"

Window::Window()
{
	location = nullptr;
	size = nullptr;
	reshape = nullptr;
	idle = nullptr;
	display = nullptr;
	keyboard = nullptr;
	argc = 0;
	argv = nullptr;
}

Window::Window(int argc, char** argv) : Window()
{
	this->argc = argc;
	this->argv = argv;
}

Window::~Window()
{
	if(location)
		delete[] location;
	if(size)
		delete[] size;
}

void Window::Init(const Value& scenefile)
{
	int x = 200;
	int y = 200;
	int width = 640;
	int height = 480;

	cout << "Window = {" << endl;

	if(scenefile.HasMember("x"))
	{
		x = scenefile["x"].GetInt();
		cout << "x = " << x << endl;
	}
	if(scenefile.HasMember("y"))
	{
		y = scenefile["y"].GetInt();
		cout << "y = " << y << endl;
	}
	if(scenefile.HasMember("width"))
	{
		width = scenefile["width"].GetInt();
		cout << "width = " << width << endl;
	}
	if(scenefile.HasMember("height"))
	{
		height = scenefile["height"].GetInt();
		cout << "height = " << height << endl;
	}

	cout << "} End Window " << endl;

	location = new int[2] {x, y};
	size = new int[2] { width, height };

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(size[0], size[1]);
	glutInitWindowPosition(location[0], location[1]);
	glutCreateWindow("Human Skeleton AI Tool");

	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void Window::Update()
{

}

void Window::Render()
{

}

void Window::Shutdown()
{

}

void Window::Reshape(void (* callback)( int, int ))
{
	this->reshape = callback;

	glutReshapeFunc(this->reshape);
}

void Window::Idle(void (* callback)( void ))
{
	this->idle = callback;

	glutIdleFunc(this->idle);
}

void Window::Display(void (* callback)( void ))
{
	this->display = callback;

	glutDisplayFunc(this->display);
}

void Window::Keyboard(void (* callback)( unsigned char key, int x, int y ))
{
	this->keyboard = callback;

	glutKeyboardFunc(this->keyboard);
}

void Window::MainLoop()
{
	glutMainLoop();
}

void Window::Clear(GLbitfield mask)
{
	glClear(mask);
}

void Window::SwapBuffers()
{
	glutSwapBuffers();
}


/*
 * Window.cpp
 *
 *  Created on: May 26, 2019
 *      Author: mark
 */

#include "Window.h"

Window *Window::instance = NULL;

Window::Window()
{
	location = nullptr;
	size = nullptr;
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

void Window::Init(const rapidjson::Value& scenefile)
{
	instance = this;

	int x = 200;
	int y = 200;
	int width = 640;
	int height = 480;

	std::cout << "Window = {" << std::endl;

	if(scenefile.HasMember("x"))
	{
		x = scenefile["x"].GetInt();
		std::cout << "x = " << x << std::endl;
	}
	if(scenefile.HasMember("y"))
	{
		y = scenefile["y"].GetInt();
		std::cout << "y = " << y << std::endl;
	}
	if(scenefile.HasMember("width"))
	{
		width = scenefile["width"].GetInt();
		std::cout << "width = " << width << std::endl;
	}
	if(scenefile.HasMember("height"))
	{
		height = scenefile["height"].GetInt();
		std::cout << "height = " << height << std::endl;
	}

	location = new int[2] {x, y};
	size = new int[2] { width, height };

	//Need to init OpenGL context before trying to store texture data which would be in the scene data
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(size[0], size[1]);
	glutInitWindowPosition(location[0], location[1]);
	glutCreateWindow("Human Skeleton AI Tool");

	if(scenefile.HasMember("scene"))
	{
		scene = new Scene();
		scene->Init(scenefile["scene"]);
	}

	std::cout << "} End Window " << std::endl;

	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glutReshapeFunc(reshapeWrapper);
	glutDisplayFunc(displayWrapper);
	glutIdleFunc(idleWrapper);
	glutKeyboardFunc(keyboardWrapper);

	this->MainLoop();
}

void Window::Update()
{

}

void Window::Render()
{
	// Clear Color and Depth Buffers
	this->Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	this->scene->Render();

	this->SwapBuffers();
}

void Window::Shutdown()
{

}

void Window::Reshape(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;

	this->size = new int[2] { w, h };
	scene->viewport->Set(0,  0,  w,  h);

	scene->camera->aspect = ratio;
	scene->camera->SetPerspective();
}


void Window::Keyboard(unsigned char key, int x, int y)
{
	if(key == 'q')
		exit(0);
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

void Window::displayWrapper() {
	instance->Render();
}

void Window::reshapeWrapper(int width, int height) {
	instance->Reshape(width, height);
}

void Window::keyboardWrapper(unsigned char key, int x, int y) {
	instance->Keyboard(key,x,y);
}

void Window::idleWrapper() {
	instance->Update();
}

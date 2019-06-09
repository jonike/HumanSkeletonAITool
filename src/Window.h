/*
 * Window.h
 *
 *  Created on: May 26, 2019
 *      Author: mark
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <GL/glut.h>
#include "JSONReader.h"

class Window
{
public:
	int* location;
	int* size;
	void (* reshape)( int, int );
	void (* display)( void );
	void (* idle)( void );
	void (* keyboard)( unsigned char key, int x, int y );

	Window();
	Window(int argc, char** argv);
	~Window();

	void Init(const rapidjson::Value& scenefile);
	void Update();
	void Render();
	void Shutdown();

	void Reshape(void (* callback)( int, int ));
	void Display(void (* callback)( void ));
	void Idle(void (* callback)( void ));
	void Keyboard(void (* callback)( unsigned char key, int x, int y ));

	void MainLoop();

	void Clear(GLbitfield mask);
	void SwapBuffers();

protected:
	int argc;
	char** argv;
};



#endif /* WINDOW_H_ */

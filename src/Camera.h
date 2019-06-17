/*
 * Camera.h
 *
 *  Created on: May 26, 2019
 *      Author: mark
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include <GL/glut.h>
#include "JSONReader.h"

class Camera
{
public:
	//location
	float* location;
	//direction
	float* direction;
	//up
	float* up;

	//fov, in degrees, in the y direction
	float fov;
	//aspect ratio of width to height
	float aspect;
	//near clipping plane
	float zNear;
	//far clipping plane
	float zFar;

	Camera();

	~Camera();

	void Init(const rapidjson::Value& scenefile);

	void Update();

	void Render();

	void Shutdown();

	void SetOrtho(double width, double height, double zNear, double zFar);

	void SetPerspective();

	void LookAt();
};


#endif /* CAMERA_H_ */

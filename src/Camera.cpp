#include "Camera.h"

Camera::Camera()
{
	location = nullptr;
	direction = nullptr;
	up = nullptr;

	fov = 0.0f;
	aspect = 0.0f;
	zNear = 0.0f;
	zFar = 0.0f;
}

Camera::~Camera()
{
	if(location)
		delete[] location;
	if(direction)
		delete[] direction;
	if(up)
		delete[] up;
}

void Camera::Init(const rapidjson::Value& scenefile)
{
	//defaults
	location = new float[3] {0.0f, 0.0f, 10.0f};
	direction = new float[3] {0.0f, 0.0f, 0.0f};
	up = new float[3] {0.0f, 1.0f, 0.0f};
	fov = 45.0f;
	aspect = 4.0/3.0f;
	zNear = 0.1f;
	zFar = 100.0f;

	std::cout << "Camera = {" << std::endl;

	if(scenefile.HasMember("location"))
	{
		std::cout << "Location = {" << std::endl;
		int i = 0;
		for (auto& v : scenefile["location"].GetArray())
		{
		    location[i] = v.GetFloat();
		    i++;
		}
		std::cout << location[0] << "\t" << location[1] << "\t" << location[2] << std::endl;
		std::cout << "} End Location" << std::endl;
	}
	if(scenefile.HasMember("direction"))
	{
		std::cout << "Direction = {" << std::endl;
		int i = 0;
		for (auto& v : scenefile["direction"].GetArray())
		{
			direction[i] = v.GetFloat();
			i++;
		}
		std::cout << direction[0] << "\t" << direction[1] << "\t" << direction[2] << std::endl;
		std::cout << "} End Direction" << std::endl;
	}
	if(scenefile.HasMember("up"))
	{
		std::cout << "Up = {" << std::endl;
		int i = 0;
		for (auto& v : scenefile["up"].GetArray())
		{
			up[i] = v.GetFloat();
			i++;
		}
		std::cout << up[0] << "\t" << up[1] << "\t" << up[2] << std::endl;
		std::cout << "} End Up" << std::endl;
	}
	if(scenefile.HasMember("fov"))
	{
		fov = scenefile["fov"].GetFloat();
		std::cout << "FOV = " << fov << std::endl;
	}
	if(scenefile.HasMember("aspect"))
	{
		aspect = scenefile["aspect"].GetFloat();
		std::cout << "Aspect = " << aspect << std::endl;
	}
	if(scenefile.HasMember("zNear"))
	{
		zNear = scenefile["zNear"].GetFloat();
		std::cout << "zNear = " << zNear << std::endl;
	}
	if(scenefile.HasMember("zFar"))
	{
		zFar = scenefile["zFar"].GetFloat();
		std::cout << "zFar = " << zFar << std::endl;
	}

	std::cout << "} End Camera" << std::endl;
}

void Camera::Update()
{

}

void Camera::Render()
{

}

void Camera::Shutdown()
{

}

void Camera::SetPerspective()
{
    // Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

       // Reset Matrix
	glLoadIdentity();

	// Set the correct perspective.
	gluPerspective(fov, aspect, zNear, zFar);
}

void Camera::LookAt()
{
	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);

	// Reset transformations
	glLoadIdentity();

	gluLookAt(	location[0], location[1], location[2],
				direction[0], direction[1],  direction[3],
				up[0], up[1],  up[2]);
}

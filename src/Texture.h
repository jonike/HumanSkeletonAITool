/*
 * Texture.h
 *
 *  Created on: Jun 2, 2019
 *      Author: mark
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include "GL/glut.h"
#include "JSONReader.h"
#include "stb_image.h"


class Texture
{
public:
	unsigned int texture;
	std::string file;

	Texture();
	~Texture();

	void Init(const rapidjson::Value& jsonobject);
	void Update();
	void Render();
	void Shutdown();
};



#endif /* TEXTURE_H_ */

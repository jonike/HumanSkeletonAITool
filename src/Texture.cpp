/*
 * Texture.cpp
 *
 *  Created on: Jun 2, 2019
 *      Author: mark
 */

#include "Texture.h"

Texture::Texture()
{

}

Texture::~Texture()
{

}

void Texture::Init(const rapidjson::Value& jsonobject)
{
	if(jsonobject.HasMember("file"))
	{
		this->file = jsonobject["file"].GetString();
		std::cout << "file = " << this->file << std::endl;
	}

	if(this->file != "")
	{
		//texture handle(s)
		glGenTextures(1, &texture);

		//we are now making changes to this handle
		glBindTexture(GL_TEXTURE_2D, texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int width, height, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char *data = stbi_load(this->file.c_str(), &width, &height, &nrChannels, STBI_default);

		if(data)
		{
			GLenum format = nrChannels == 3 ? GL_RGB : GL_RGBA;
			glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
			//mipmap level 0, RGB data values, width and height of the texture, 0 (legacy param), format of source image, datatype of source image, image data
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		}
		else
		{
			std::cout << "Failed to load image." << std::endl;
		}
		stbi_image_free(data);

		glEnable(GL_TEXTURE_2D);
	}
}

void Texture::Render()
{

}



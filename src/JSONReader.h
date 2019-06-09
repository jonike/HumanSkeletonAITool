/*
 * JSONReader.h
 *
 *  Created on: May 30, 2019
 *      Author: mark
 */

#ifndef JSONREADER_H_
#define JSONREADER_H_

#include <fstream>
#include <string>
#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

class JSONReader
{
public:
	std::string filename;
	std::string content;

	JSONReader(std::string file);

	rapidjson::Document Read();

	void Serialize();

	void Deserialize(std::string content);

	~JSONReader();

};


#endif /* JSONREADER_H_ */

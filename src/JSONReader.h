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

using namespace std;
using namespace rapidjson;

class JSONReader
{
public:
	string filename;
	string content;

	JSONReader(string file);

	Document Read();

	void Serialize();

	void Deserialize(string content);

	~JSONReader();

};


#endif /* JSONREADER_H_ */

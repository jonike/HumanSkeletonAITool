#include "JSONReader.h"

JSONReader::JSONReader(std::string file)
{
	filename = file;
}

JSONReader::~JSONReader()
{
}

rapidjson::Document JSONReader::Read()
{
	std::ifstream infile;
	std::string line;
	std::string file;

	infile.open(filename);

	if(!infile) {
		std::cerr << "Unable to open file " + filename;
		return NULL;
	}

	while(infile >> line) {
		file += line;
	}

	infile.close();

	rapidjson::Document d;
	d.Parse(file.c_str());

	return d;
}

void JSONReader::Serialize()
{

}

void JSONReader::Deserialize(std::string content)
{

}


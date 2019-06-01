#include "JSONReader.h"

JSONReader::JSONReader(string file)
{
	filename = file;
}

JSONReader::~JSONReader()
{
}

Document JSONReader::Read()
{
	ifstream infile;
	string line;
	string file;

	infile.open(filename);

	if(!infile) {
		cerr << "Unable to open file " + filename;
		return NULL;
	}

	while(infile >> line) {
		file += line;
	}

	infile.close();

	Document d;
	d.Parse(file.c_str());

	return d;
}

void JSONReader::Serialize()
{

}

void JSONReader::Deserialize(string content)
{

}


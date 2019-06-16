#include "main.h"

Window* window;

int main(int argc, char** argv)
{
	JSONReader* json = new JSONReader(".//resource/scene.json");
	rapidjson::Document scenefile = json->Read();
	if(scenefile == NULL) return 0;

	if(scenefile["window"].IsObject())
	{
		window = new Window(argc, argv);
		window->Init(scenefile["window"]);
	}

    return 1;
}

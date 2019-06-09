#include "main.h"

float angle = 0.0f;

Window* window;
Scene* scene;
Texture* texture;

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;

	window->size = new int[2] { w, h };
	scene->viewport->Set(0,  0,  w,  h);

	scene->camera->aspect = ratio;
	scene->camera->SetPerspective();
}

void renderScene(void) {

	// Clear Color and Depth Buffers
	window->Clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set the camera
	scene->camera->LookAt();

	glRotatef(angle, 0.0f, 1.0f, 0.0f);

	//glColor3f(1.0f,1.0f,1.0f);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture->texture);

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 0.0);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-1.0f,-1.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f( 1.0f, 1.0f, 0.0);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f( 1.0f, -1.0f, 0.0);
	glEnd();

	angle+=0.1f;

	window->SwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	if(key == 'q')
		exit(0);
}

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
	if(scenefile["scene"].IsObject())
	{
		scene = new Scene();
		scene->Init(scenefile["scene"]);
	}

	texture = new Texture();
	texture->Init(scenefile);

    window->Reshape(changeSize);
    window->Display(renderScene);
    window->Idle(renderScene);
    window->Keyboard(keyboard);

    window->MainLoop();

    return 1;
}

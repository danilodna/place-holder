#include "graphics/window.h"
#include "shader.h"
#include "mesh.h"

#include <vector>

int main(int argc, char** argv)
{
	using namespace place;
	using namespace graphics;

	Window window("hehehe", 800, 600);

	glClearColor(0.2f, 0.9f, 0.5f, 1.0f);
	// glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	Shader shader("shaders/basic_shader.vs", "shaders/basic_shader.fs");

	Vertex triangle1[] =
	{
		//	Primeiro Triangulo
		Vertex(glm::vec3(-0.8f, -0.6f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
		Vertex(glm::vec3(-0.5f,  0.4f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)),
		Vertex(glm::vec3(-0.2f, -0.6f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f)),
	};

	Vertex triangle2[] =
	{
		//	Segundo Triangulo
		Vertex(glm::vec3(0.2f, -0.6f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
		Vertex(glm::vec3(0.5f,  0.4f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
		Vertex(glm::vec3(0.8f, -0.6f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f))
	};

	Vertex triangle3[] =
	{
		//	Terceiro Triangulo
		Vertex(glm::vec3(0.2f, -0.6f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f)),
		Vertex(glm::vec3(0.5f,  0.4f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.5f, 1.0f, 0.0f)),
		Vertex(glm::vec3(0.8f, -0.6f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f))
	};

	Vertex rect1[] =
	{
  	//	positions          								 // colors          					// texture coords
   	Vertex(glm::vec3(0.5f,  0.5f, 0.0f),  glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)),	// top right
   	Vertex(glm::vec3(0.5f, -0.5f, 0.0f),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),	// bottom right
  	Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f)),	// bottom left
  	Vertex(glm::vec3(-0.5f,  0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)) 	// top left
	};

	Vertex rect2[] =
	{
  	//	positions          								 // colors          					// texture coords
   	Vertex(glm::vec3(0.5f,  0.5f, 0.0f),  glm::vec3(1.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)),	// top right
   	Vertex(glm::vec3(0.5f, -0.5f, 0.0f),  glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),	// bottom right
  	Vertex(glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f)),	// bottom left
  	Vertex(glm::vec3(-0.5f,  0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)) 	// top left
	};

	Vertex cube[] =
	{
    Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f)),
    Vertex(glm::vec3( 0.5f, -0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
    Vertex(glm::vec3( 0.5f,  0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)),
    Vertex(glm::vec3( 0.5f,  0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)),
    Vertex(glm::vec3(-0.5f,  0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f)),

    Vertex(glm::vec3(-0.5f, -0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f)),
    Vertex(glm::vec3( 0.5f, -0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
    Vertex(glm::vec3( 0.5f,  0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)),
    Vertex(glm::vec3( 0.5f,  0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)),
    Vertex(glm::vec3(-0.5f,  0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f)),

    Vertex(glm::vec3(-0.5f,  0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
    Vertex(glm::vec3(-0.5f,  0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f)),
    Vertex(glm::vec3(-0.5f,  0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),

    Vertex(glm::vec3( 0.5f,  0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
    Vertex(glm::vec3( 0.5f,  0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)),
    Vertex(glm::vec3( 0.5f, -0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
    Vertex(glm::vec3( 0.5f, -0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
    Vertex(glm::vec3( 0.5f, -0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f)),
    Vertex(glm::vec3( 0.5f,  0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),

    Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
    Vertex(glm::vec3( 0.5f, -0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)),
    Vertex(glm::vec3( 0.5f, -0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
    Vertex(glm::vec3( 0.5f, -0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f)),
    Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)),

    Vertex(glm::vec3(-0.5f,  0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
    Vertex(glm::vec3( 0.5f,  0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f)),
    Vertex(glm::vec3( 0.5f,  0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
    Vertex(glm::vec3( 0.5f,  0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)),
    Vertex(glm::vec3(-0.5f,  0.5f,  0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f)),
    Vertex(glm::vec3(-0.5f,  0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f))
 	};

	glm::vec3 cubePositions[] =
	{
  	glm::vec3( 0.0f,  0.0f,  0.0f),
  	glm::vec3( 2.0f,  5.0f, -15.0f),
  	glm::vec3(-1.5f, -2.2f, -2.5f),
  	glm::vec3(-3.8f, -2.0f, -12.3f),
  	glm::vec3( 2.4f, -0.4f, -3.5f),
  	glm::vec3(-1.7f,  3.0f, -7.5f),
  	glm::vec3( 1.3f, -2.0f, -2.5f),
  	glm::vec3( 1.5f,  2.0f, -2.5f),
  	glm::vec3( 1.5f,  0.2f, -1.5f),
  	glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	//	TEXTURES =======================================
	//	Load
	int wText[2], hText[2], nrChannelsText[2];
	unsigned char* textImg[2];
	textImg[0] = stbi_load("textures/container.jpg", &wText[0], &hText[0], &nrChannelsText[0], 0);
	textImg[1] = stbi_load("textures/awesomeface.png", &wText[1], &hText[1], &nrChannelsText[1], 0);

	GLuint texture[2];
	glGenTextures(2, texture);
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	//	Set the texture wrapping options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//	Set texture filtering options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	if(textImg[0] || textImg[1])
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, wText[0], hText[0], 0, GL_RGB, GL_UNSIGNED_BYTE, textImg[0]);
		glGenerateMipmap(GL_TEXTURE_2D);

		//	Set the texture wrapping options
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		//	Set texture filtering options
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glBindTexture(GL_TEXTURE_2D, texture[1]);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, wText[1], hText[1], 0, GL_RGBA, GL_UNSIGNED_BYTE, textImg[1]);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cerr << "Failed to load texture." << '\n';
	}
	stbi_image_free(textImg[0]);
	stbi_image_free(textImg[1]);
	// =================================================


	std::vector<Mesh*> box;
	for (size_t i = 0; i < 10; i++)
		box.push_back(new Mesh(cube, (unsigned int) (sizeof(cube) / sizeof(cube[0])), GL_STATIC_DRAW));


	shader.bind();
	shader.setInt("texture1", 0);
	shader.setInt("texture2", 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture[1]);

	// 	THE CAMERA
	glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));

	//	THE REST
	glm::mat4 model;
	glm::mat4 view;
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	glm::mat4 projection;
	projection = glm::perspective(glm::radians(45.0f), ((float) window.getWidth()) / ((float)window.getHeight()), 0.1f, 100.0f);

	glEnable(GL_DEPTH_TEST);
	while(!window.closed())
	{
		window.clear();

		if(window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT))
			std::cout << "ola marilene" << '\n';

		if(window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_RIGHT))
			std::cout << "vinho tainha" << '\n';

		if(window.isKeyPressed(GLFW_KEY_ESCAPE))
			window.close();

		glm::dvec2 printando = window.getMousePos();

		std::cout << printando.x << ", " << printando.y << '\n';

		for(unsigned int i = 0; i < 10; i++)
		{
			glm::mat4 model;
			glm::mat4 view;
			glm::mat4 projection;

			model = glm::translate(model, cubePositions[i]);
			float angle = 20.0f * i;
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
			projection = glm::perspective(glm::radians(45.0f), ((float) window.getWidth()) / ((float)window.getHeight()), 0.1f, 100.0f);

			shader.setMat4fv("model", 1, GL_FALSE, glm::value_ptr(model));
			shader.setMat4fv("view", 1, GL_FALSE, glm::value_ptr(view));
			shader.setMat4fv("projection", 1, GL_FALSE, glm::value_ptr(projection));

  		box[i]->draw(GL_TRIANGLES);
		}

		window.update();
	}

	return 0;
}

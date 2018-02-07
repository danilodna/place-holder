#ifndef COMMON_H_
#define COMMON_H_

//	OpenGL/Window Lib
#include "../dependencies/glad/include/glad.h"
#include <GLFW/glfw3.h>

//	Some mathematical functions lib
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// 	Library to load textures
#include "../dependencies/stb/stb_image.h"

//	C++ libs
#include <iostream>

#define NUM_ATTRIB 3
#define SIZE_ATTRIB 3

typedef struct Vertex
{
	glm::vec3 m_Pos;
	glm::vec3 m_Color;
	glm::vec3 m_Tex;

	Vertex(const glm::vec3& pos)
	{
		m_Pos = pos;
	}
	Vertex(const glm::vec3& pos, const glm::vec3& color)
	{
		m_Pos = pos;
		m_Color = color;
	}
	Vertex(const glm::vec3& pos, const glm::vec3& color, const glm::vec3& texture)
	{
		m_Pos = pos;
		m_Color = color;
		m_Tex = texture;
	}
} Vertex;

// template <typename T>
// unsigned int numElementsArray(T t)
// {
// 	std::cout << sizeof(*t) << '\n';
// 	return (unsigned int) (sizeof(t) / sizeof(t[0]));
// }

#endif //	COMMON_H_

/*

// set up vertex data (and buffer(s)) and configure vertex attributes
// ------------------------------------------------------------------
float vertices[] = {
		 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		// -0.5f,  0.5f, 0.0f   // top left
};

float triangs[] =
{
	-0.8f, -0.6f, 0.0f,
	-0.5f,  0.4f, 0.0f,
	-0.2f, -0.6f, 0.0f,

	 0.2f, -0.6f, 0.0f,
	 0.5f,  0.4f, 0.0f,
	 0.8f, -0.6f, 0.0f,
};

GLuint VAO, VBO;
glGenVertexArrays(1, &VAO);
glGenBuffers(1, &VBO);
// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
glBindVertexArray(VAO);

glBindBuffer(GL_ARRAY_BUFFER, VBO);
glBufferData(GL_ARRAY_BUFFER, sizeof(triangs), triangs, GL_STATIC_DRAW);

// Linking Vertex attributes
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) (0 * sizeof(float))); // POSITION IN THE ARRAY THAT I GAVE AS PARAMETER
glEnableVertexAttribArray(0);

// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
// glBindBuffer(GL_ARRAY_BUFFER, 0);
// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
// glBindVertexArray(0);

============================================================================================
char* readShaderFile(const char* fileName)
{
	std::ifstream file;
	int length;

	file.open(fileName);							// open input file
	file.seekg(0, std::ios::end);			// go to the end
	length = file.tellg();						// report location (this is the length)
	file.seekg(0, std::ios::beg);			// go back to the beginning
	char* buffer = new char[length];				// allocate memory for a buffer of appropriate dimension
	file.read(buffer, length);				// read the whole file into the buffer
	file.close();
	return buffer;
}

GLuint compileShader(const char* shaderFileName, GLenum shaderType)
{
	GLchar* shaderSource = readShaderFile(shaderFileName);
	GLuint shader;

	shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderSource, NULL);
	glCompileShader(shader);

	int  success;
	char infoLog[512];
	//	Vertex shader error check
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
    glGetShaderInfoLog(shader, 512, NULL, infoLog);
		switch (shaderType)
		{
			case GL_VERTEX_SHADER:
				std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
			break;

			case GL_FRAGMENT_SHADER:
				std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
			break;
		}
	}

	// delete shaderSource;
	// shaderSource = NULL;

	return shader;
}

GLuint linkShader(GLuint vertexShader, GLuint fragShader)
{
	GLuint shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragShader);
	glLinkProgram(shaderProgram);

	int  success;
	char infoLog[512];
	// Verify the linking
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if(!success)
	{
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::LINKING::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragShader);

	return shaderProgram;
}
*/

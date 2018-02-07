#ifndef SHADER_H_
#define SHADER_H_

#include "common.h"

#include <iostream>
#include <fstream>
#include <string>

namespace place	{

class Shader
{
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();
	void bind();
	GLuint getProgram() {return m_ShaderProgram; };

	void setBool(const std::string &name, bool value) const;
  void setInt(const std::string &name, int value) const;
  void setFloat(const std::string &name, float value) const;

	void setMat4fv(const std::string &name, GLsizei count, GLboolean transpose, const GLfloat *value) const;

private:
	static const unsigned int NUM_SHADERS = 2;
	GLuint m_ShaderProgram;
	GLuint m_Shader[NUM_SHADERS];

	Shader(const Shader& other) {}
	void operator=(const Shader& other) {}
};

}
#endif //	SHADER_H_

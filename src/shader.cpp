#include "shader.h"

namespace place {

	static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	static std::string loadShader(const std::string& fileName);
	static GLuint createShader(const std::string& text, GLenum shaderType);

	Shader::Shader(const char* vertexPath, const char* fragmentPath)
	{
		m_ShaderProgram = glCreateProgram();
		m_Shader[0] = createShader(loadShader(vertexPath), GL_VERTEX_SHADER);
		m_Shader[1] = createShader(loadShader(fragmentPath), GL_FRAGMENT_SHADER);

		for(unsigned int i = 0; i < NUM_SHADERS; ++i)
			glAttachShader(m_ShaderProgram, m_Shader[i]);

		// IMPORTANT ?
		// glAttribLocation(m_ShaderProgram, 0, "position");

		glLinkProgram(m_ShaderProgram);
		checkShaderError(m_ShaderProgram, GL_LINK_STATUS, true, "Error: shader program failed to link.");

		glValidateProgram(m_ShaderProgram);
		checkShaderError(m_ShaderProgram, GL_VALIDATE_STATUS, true, "Error: shader program is invalid.");
	}

	Shader::~Shader()
	{
		for(unsigned int i = 0; i < NUM_SHADERS; ++i)
		{
			glDetachShader(m_ShaderProgram, m_Shader[i]);
			glDeleteShader(m_Shader[i]);
		}
		glDeleteProgram(m_ShaderProgram);
	}

	void Shader::bind()
	{
		glUseProgram(m_ShaderProgram);
	}

	// ==================== Basic Binding ====================
	void Shader::setBool(const std::string &name, bool value) const
	{
    glUniform1i(glGetUniformLocation(m_ShaderProgram, name.c_str()), (int)value);
	}
	void Shader::setInt(const std::string &name, int value) const
	{
    glUniform1i(glGetUniformLocation(m_ShaderProgram, name.c_str()), value);
	}
	void Shader::setFloat(const std::string &name, float value) const
	{
    glUniform1f(glGetUniformLocation(m_ShaderProgram, name.c_str()), value);
	}

	// ==================== Matrix Binding ====================
	void Shader::setMat4fv(const std::string &name, GLsizei count, GLboolean transpose, const GLfloat *value) const
	{
		glUniformMatrix4fv(glGetUniformLocation(m_ShaderProgram, name.c_str()), count, transpose, value);
	}


	// ===========================================================================
	// The functions below just exists in this class only
	static GLuint createShader(const std::string& text, GLenum shaderType)
	{
		GLuint shader = glCreateShader(shaderType);
		if(shader == 0)
			std::cerr << "Error: shader creation failed." << std::endl;

		const GLchar* shaderSourceStrs[1];
		GLint shaderSourceStrsLengths[1];

		shaderSourceStrs[0] = text.c_str();
		shaderSourceStrsLengths[0] = text.length();

		glShaderSource(shader, 1, shaderSourceStrs, shaderSourceStrsLengths);
		glCompileShader(shader);
		checkShaderError(shader, GL_COMPILE_STATUS, false, "Error: shader compilation failed.");

		return shader;
	}

	static void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
	{
		int  success;
		char infoLog[512];

		if(isProgram)
			glGetProgramiv(shader, flag, &success);
		else
			glGetShaderiv(shader, flag, &success);

		if(success == GL_FALSE)
		{
			if(isProgram)
				glGetProgramInfoLog(shader, sizeof(infoLog), NULL, infoLog);
			else
				glGetShaderInfoLog(shader, sizeof(infoLog), NULL, infoLog);

			std::cerr << errorMessage << ": ''" << infoLog << "'" <<std::endl;
		}
	}

	static std::string loadShader(const std::string& fileName)
	{
		std::ifstream file;
		std::string output, line;


		file.open((fileName).c_str());

		if(file.is_open())
		{
			while(file.good())
			{
				getline(file, line);
				output.append(line + '\n');
			}
		}
		else
		{
			std::cerr << "Could not load shader: " << fileName << std::endl;
			return NULL;
		}

		file.close();
		return output;
	}
}

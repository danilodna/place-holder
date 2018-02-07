#include "window.h"

#include <iostream>
#include <cstdlib>

namespace place	{	namespace graphics	{

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);

	Window::Window(const char* title, int width, int height)
	{
		m_Title = title;
		m_Width = width;
		m_Height = height;
		m_Ratio = m_Width / (float) m_Height;

		if(!init())
		{
			std::cout << "Error while trying to creat window!" << '\n';
			glfwTerminate();
			exit(EXIT_FAILURE);
		}

		for (size_t i = 0; i < GLFW_KEY_LAST; i++)
			m_Keys[i] = false;

		for (size_t i = 0; i < MAX_MOUSE_BUTTONS; i++)
			m_MouseButtons[i] = false;
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "Error at 'glfwInit'" << '\n';
			return false;
		}

		// Configuration about this instance of the window goes in here FOR NOW
		// /*
		// glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		// glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		// glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		// */

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
		if (!m_Window)
		{
			std::cout << "Error at 'glfwCreateWindow'" << '\n';
			return false;
		}

		glfwMakeContextCurrent(m_Window);

		if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return false;
		}

		glfwSetWindowUserPointer(m_Window, this);
		glfwSetFramebufferSizeCallback(m_Window, resize);

		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetCursorPosCallback(m_Window, cursor_pos_callback);

		glViewport(0, 0, m_Width, m_Height);
		return true;
	}

	void Window::resize(GLFWwindow* window, int width, int height)
	{
		// m_Width = width;
		// m_Height = height;
		// m_Ratio = m_Width / (float) m_Height;
    // //
		glViewport(0, 0, width, height);
	}

	void Window::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update()
	{
		glfwSwapBuffers(m_Window);
    glfwPollEvents();
	}

	bool Window::closed()
	{
		return (glfwWindowShouldClose(m_Window) == 1);
	}

	bool Window::isKeyPressed(unsigned int keycode) const
	{
		return m_Keys[keycode];
	}

	bool Window::isMouseButtonPressed(unsigned int button) const
	{
		return m_MouseButtons[button];
	}

	glm::dvec2 Window::getMousePos() const 
	{
		return glm::dvec2(mx, my);
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* win = (Window*) glfwGetWindowUserPointer(window);
		win->m_Keys[key] = action != GLFW_RELEASE;
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		Window* win = (Window*) glfwGetWindowUserPointer(window);
		win->m_MouseButtons[button] = action != GLFW_RELEASE;
	}

	void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window* win = (Window*) glfwGetWindowUserPointer(window);
		win->mx = xpos;
		win->my = ypos;
	}

	void Window::close()
	{
		glfwSetWindowShouldClose(m_Window, 1);
	}

}	}

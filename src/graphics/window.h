#ifndef WINDOWS_H_
#define WINDOWS_H_

#include "../common.h"

namespace place	{	namespace graphics {

	#define MAX_MOUSE_BUTTONS 64

	class Window
	{
	private:
		friend struct GLFWwindow;
		const char* m_Title;
		int m_Width, m_Height;
		float m_Ratio;
		GLFWwindow* m_Window;

		bool m_Keys[GLFW_KEY_LAST];
		bool m_MouseButtons[MAX_MOUSE_BUTTONS];
		double mx;
		double my;

	public:
		Window(const char* title, int width, int height);
		~Window();

		void update();
		void clear();
		void close();
		bool closed();

		inline int getWidth() const { return m_Width; }
		inline int getHeight() const { return m_Height; }

		bool isKeyPressed(unsigned int button) const;
		bool isMouseButtonPressed(unsigned int button) const;
		glm::dvec2 getMousePos() const;

	private:
		bool init();
		friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		friend void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos);

		static void resize(GLFWwindow* window, int width, int height);
	};

}	}

#endif //	WINDOWS_H_

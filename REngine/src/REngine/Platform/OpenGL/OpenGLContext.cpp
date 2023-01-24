#include "repch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace REngine {


	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_WindowHandle(windowHandle)
	{
		RE_CORE_ASSERT(windowHandle, "window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		//Initialize Glad
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		RE_CORE_ASSERT(status, "Failed to initialize Glad")
		RE_CORE_INFO("OpenGL Info:");
		RE_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		RE_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		RE_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		glClearColor(0.4f, .7f, .7f, 1);
	}

	void OpenGLContext::SwapBuffers()
	{

		glfwSwapBuffers(m_WindowHandle);
		glClear(GL_COLOR_BUFFER_BIT);
	}

}
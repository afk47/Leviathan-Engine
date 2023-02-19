#include "lpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Leviathan {


	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_WindowHandle(windowHandle)
	{
		LE_CORE_ASSERT(windowHandle, "window handle is null!")
	}

	void OpenGLContext::Init()
	{
		LE_PROFILE_FUNCTION();
		glfwMakeContextCurrent(m_WindowHandle);
		//Initialize Glad
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		LE_CORE_ASSERT(status, "Failed to initialize Glad")
		LE_CORE_INFO("OpenGL Info:");
		LE_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		LE_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		LE_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

	}

	void OpenGLContext::SwapBuffers()
	{
		LE_PROFILE_FUNCTION();
		glfwSwapBuffers(m_WindowHandle);
	}

}
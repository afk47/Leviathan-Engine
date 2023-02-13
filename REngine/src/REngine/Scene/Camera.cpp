#include "repch.h"

#include "Camera.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
namespace REngine {



	///
	///	Orthographic Camera
	/// 
	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
	{

	}


	void OrthographicCamera::SetProjection(float left, float right, float bottom, float top) const
	{

	}

	///
	///	Perspective Camera
	/// 

	void PerspectiveCamera::OnUpdate() {
		UpdateView();
	}

	PerspectiveCamera::PerspectiveCamera(float fov, float aspectRatio, float zNear, float zFar) 
		: m_FOV(fov), m_AspectRatio(aspectRatio), m_NearClip(zNear), m_FarClip(zFar), m_ProjectionMatrix(glm::perspective(glm::radians(fov), aspectRatio, zNear, zFar)), m_ViewMatrix(glm::mat4(1.0f)), m_ViewProjectionMatrix(m_ViewMatrix * m_ProjectionMatrix)
	{
		UpdateView();
	}

	void PerspectiveCamera::UpdateView()
	{
		// m_Yaw = m_Pitch = 0.0f; // Lock the camera's rotation


		glm::quat orientation = glm::quat(m_Rotation);
		m_ViewMatrix = glm::translate(glm::mat4(1.0f), m_Position) * glm::toMat4(orientation);
		m_ViewMatrix = glm::inverse(m_ViewMatrix);
		m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
	}

	

	void PerspectiveCamera::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowResizeEvent>(RE_BIND_EVENT_FN(PerspectiveCamera::OnResize));
	}

	bool PerspectiveCamera::OnResize(WindowResizeEvent& e) 
	{
		m_ViewportWidth	=(float) e.GetWidth();
		m_ViewportHeight=(float) e.GetHeight();
		m_AspectRatio	= m_ViewportWidth / m_ViewportHeight;
		return false;
	}

	void PerspectiveCamera::RecalculateViewMatrix()
	{
		glm::quat orientation = glm::quat(glm::vec3(-m_Pitch, -m_Yaw, 0.0f));
		m_ViewMatrix = glm::translate(glm::mat4(1.0f), m_Position) * glm::toMat4(orientation);
		m_ViewMatrix = glm::inverse(m_ViewMatrix);
	}

}
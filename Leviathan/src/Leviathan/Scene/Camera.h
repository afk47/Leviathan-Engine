#pragma once
#include "Leviathan/Events/Event.h"
#include "Leviathan/Events/ApplicationEvent.h"
#include <glm/glm.hpp>

namespace Leviathan {

	class Camera {
	public:
		virtual const glm::vec3& GetPosition() const = 0;
		virtual void SetPosition(const glm::vec3& position) = 0;


		virtual const glm::mat4& GetProjectionMatrix() const = 0;
		virtual const glm::mat4& GetViewMatrix() const = 0;
		virtual const glm::mat4& GetViewProjectionMatrix() const = 0;

	};




	class OrthographicCamera : public Camera
	{
	public:
		OrthographicCamera(float left, float right, float bottom, float top);
		virtual void SetProjection(float left, float right, float bottom, float top) const;

		const glm::vec3& GetPosition() const override { return m_Position; }
		void SetPosition(const glm::vec3& position) override { m_Position = position; RecalculateViewMatrix(); }

		float GetRotation() const  { return m_Rotation; }
		void SetRotation(float rotation)  { m_Rotation = rotation; RecalculateViewMatrix(); }

		const glm::mat4& GetProjectionMatrix() const override { return m_ProjectionMatrix; }
		const glm::mat4& GetViewMatrix() const override { return m_ViewMatrix; }
		const glm::mat4& GetViewProjectionMatrix() const override { return m_ViewMatrix * m_ProjectionMatrix; }
	private:
		void RecalculateViewMatrix() {};
	private:
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;

		glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
		float m_Rotation = 0.0f;
	};

	class PerspectiveCamera : public Camera
	{
	public:
		PerspectiveCamera(float fov, float aspectRatio, float zNear, float zFar);
		void OnEvent(Event& e);
		void OnUpdate();
		void UpdateView();

		inline void SetViewportSize(float width, float height) { m_ViewportWidth = width; m_ViewportHeight = height; update = true;}
		virtual void SetPosition(const glm::vec3& position) override {m_Position = position; update = true;}
		virtual void SetRotation(glm::vec3 rotation) { m_Rotation = rotation; update = true; }

		virtual const glm::vec3& GetRotation() const { return m_Rotation; }
		virtual const glm::vec3& GetPosition() const override { return m_Position; }
		virtual const glm::mat4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
		virtual const glm::mat4& GetViewMatrix() const { return m_ViewMatrix; }
		virtual const glm::mat4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }



	private:
		bool OnResize(WindowResizeEvent& e);

	private:
		bool update = false;
		glm::mat4 m_ProjectionMatrix = glm::mat4(1.0f);
		glm::mat4 m_ViewMatrix = glm::mat4(1.0f);
		glm::mat4 m_ViewProjectionMatrix = glm::mat4(1.0f);

		glm::vec3 m_Position = { 0.0f, 0.0f, -50.0f };
		glm::vec3 m_Rotation = { 0.0f, 0.0f, -50.0f };
	
		float m_FOV = 45.0f, m_AspectRatio = 1.778f, m_NearClip = 0.1f, m_FarClip = 1000.0f;
		float m_Distance = 10.0f;
		float m_Pitch = 0.0f, m_Yaw = 0.0f;

		float m_ViewportWidth = 1280, m_ViewportHeight = 720;
	};


}
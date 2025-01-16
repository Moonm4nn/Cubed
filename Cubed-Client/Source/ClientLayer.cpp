#include "Walnut/Input/Input.h"

#include "ClientLayer.h"

#include "imgui.h"
#include "imgui_internal.h" //why does this need to be defined when it has been defined in the build files

namespace Cubed {

	static void DrawRect(glm::vec2 position, glm::vec2 size, uint32_t color)
	{
		ImDrawList* drawList = ImGui::GetBackgroundDrawList();
		ImVec2 min = ImGui::GetWindowPos() + ImVec2(position.x, position.y);
		ImVec2 max = min + ImVec2(size.x, size.y);

		drawList->AddRectFilled(min, max, color);
	}

	void ClientLayer::OnAttach()
	{

	}

	void ClientLayer::OnDetach()
	{
	
	}

	void ClientLayer::OnUpdate(float ts)
	{
		glm::vec2 dir{ 0.0f, 0.0f };

		if (Walnut::Input::IsKeyDown(Walnut::KeyCode::W))
			dir.y = -1;
		else if (Walnut::Input::IsKeyDown(Walnut::KeyCode::S))
			dir.y = 1;

		if (Walnut::Input::IsKeyDown(Walnut::KeyCode::A))
			dir.x = -1;
		else if (Walnut::Input::IsKeyDown(Walnut::KeyCode::D))
			dir.x = 1;

		
		if (glm::length(dir)) {
			const float speed = 150.0f;
			dir = glm::normalize(dir);
			m_PlayerVelocity = dir * speed;
		}

		m_PlayerPosition += m_PlayerVelocity * ts;

		m_PlayerVelocity = glm::mix(m_PlayerVelocity, glm::vec2(0.0f), 8.0f * ts);

	}

	void ClientLayer::OnUIRender() 
	{
		ImGui::ShowDemoWindow();
		DrawRect(m_PlayerPosition, { 50.0f, 50.0f }, 0xffff00ff);

	}

}
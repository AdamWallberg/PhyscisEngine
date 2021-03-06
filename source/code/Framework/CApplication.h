#pragma once

class phCWindow;
class phCInputSystem;
class phCModelSystem;
class phCTextureSystem;
class phCRenderSystem;
class phCCameraSystem;
class CGameStateMachine;

class phCCamera;

// Contains the game loop, and updates the rest of
// the application. 
class CApplication
{
public:

	CApplication();
	~CApplication();
	
	// Mathod that runs the game loop
	void Run();

private:

	void Update();
	void Render();

	phCWindow* m_pWindow;
	phCInputSystem* m_pInputSystem;
	phCModelSystem* m_pModelSystem;
	phCTextureSystem* m_pTextureSystem;
	phCRenderSystem* m_pRenderer;
	phCCameraSystem* m_pCameraSystem;

	CGameStateMachine* m_pGameStateMachine;
};
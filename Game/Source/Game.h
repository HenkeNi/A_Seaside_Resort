#pragma once

class SDL_Window;
class SDL_Surface;

class Game 
{
public:
	Game();

	bool Init();
	void Shutdown();
	void Run();

private:
	void LoadAssets();

	SDL_Window*  m_window;
	SDL_Surface* m_screenSurface;
	bool		 m_shouldQuit;
};


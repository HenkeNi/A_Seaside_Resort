#include "Pch.h"
#include "Game.h"
#include <SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

Game::Game()
	: m_window{ nullptr }, m_screenSurface{ nullptr }, m_shouldQuit{ false }
{
}

bool Game::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Failed to initialize SDL! Error: " << SDL_GetError() << "\n";
		return false;
	}

	m_window = SDL_CreateWindow("A Seaside Resort", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (!m_window)
	{
		std::cout << "Failed to create a Window! Error: " << SDL_GetError() << "\n";
		return false;
	}

	m_screenSurface = SDL_GetWindowSurface(m_window);

	//SDL_FillRect(m_screenSurface, nullptr, SDL_MapRGB(m_screenSurface->format, 0xFF, 0xFF, 0xFF));
	//SDL_UpdateWindowSurface(m_window);

	LoadAssets();

	return true;
}

void Game::Shutdown()
{
	SDL_DestroyWindow(m_window);
	SDL_Quit();

	m_window = nullptr;
}

void Game::Run()
{
	while (true)
	{
		// Update

		 

		// Draw
		SDL_UpdateWindowSurface(m_window); // swaps buffers
	}
}

void Game::LoadAssets()
{
	if (SDL_Surface* image = SDL_LoadBMP("../Assets/Textures/bush_01.bmp"))
	{
		SDL_BlitSurface(image, nullptr, m_screenSurface, nullptr);
	}
	else
		std::cout << "image loading error: " << SDL_GetError();

}

#pragma once
#include "Pch.h"
#include "Game.h"

int main(int argc, char* argv[])
{
	Game game;

	if (game.Init())
		game.Run();
	
	game.Shutdown();
	return 0;
}
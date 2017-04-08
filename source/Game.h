#pragma once

#include "Snake.h"
#include <SFML\Graphics.hpp>
class Game {
	private:
		Snake Player;
		sf::Sprite Tile;
		sf::Texture tTile;
		sf::RenderWindow window;
		void userInput(sf::Keyboard::Key key);
		void gameUpdate();
		void gameDraw();
	public:
		Game(int largura, int altura, char* titulo);
		void gameLooping();
};

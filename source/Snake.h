#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include <string>
#include "Fruit.h"

class Snake {
	private:
		int xVel, yVel;
		std::vector<sf::Vector2f> body;
		sf::Sprite Head, Tail;
		sf::Texture tHead, tTail;
		void updateTail();
	public:
		enum DIREC { CIMA, DIREITA, BAIXO, ESQUERDA } dir;
		void Draw(sf::RenderWindow& window);
		void eatFruit(Fruit &Apple);
		void Update();
		Snake(sf::Vector2f posHead ,std::string pathHead, std::string pathTail);
};

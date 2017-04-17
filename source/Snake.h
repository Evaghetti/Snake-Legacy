#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include <string>
#include "Fruit.h"

class Snake {
	private:
		int xVel, yVel;
		float delay = 0.1f, timer = 0.0f;
		std::vector<sf::Vector2f> body;
		sf::Vector2f prevPos;
		sf::Sprite Head, Tail;
		sf::Texture tHead, tTail;
		void updateTail();
	public:
		enum DIREC { CIMA, DIREITA, BAIXO, ESQUERDA } dir;
		bool isDead() const;
		void Draw(sf::RenderWindow& window);
		void eatFruit(Fruit &Apple);
		void Update(const float time);
		Snake(sf::Vector2f posHead ,std::string pathHead, std::string pathTail);
};

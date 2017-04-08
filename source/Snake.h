#pragma once

#include <SFML\Graphics.hpp>
#include <vector>
#include <string>

class Snake {
	private:
		int sizeTail, xVel, yVel;
		std::vector<sf::Vector2f> posTail;
		sf::Sprite Head, Tail;
		sf::Texture tHead, tTail;
		sf::Vector2f posHead;
		sf::Vector2f getPosition() const;
		void updateTail();
	public:
		enum DIREC { CIMA, DIREITA, BAIXO, ESQUERDA } dir;
		void Draw(sf::RenderWindow& window);
		void Update();
		Snake(sf::Vector2f posHead, int sizeTail, std::string pathHead, std::string pathTail);
};

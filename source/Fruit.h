#pragma once

#include<SFML\Graphics.hpp>
#include<cstdlib>
#include<ctime>

class Fruit {
	private:
		sf::Vector2f position;
		sf::Texture tFruta;
		sf::Sprite Fruta;
		int newXPos() const;
		int newYPos() const;
	public:
		Fruit(std::string caminho, int x = 0, int y = 0);
		Fruit(sf::Vector2f tempPosition, std::string caminho);
		sf::Vector2f getPosition() const;
		void newPosition();
		void draw(sf::RenderWindow &window);
};

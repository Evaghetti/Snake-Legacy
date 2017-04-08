#pragma once

#include<SFML\Graphics.hpp>

class Fruit {
	private:
		sf::Vector2i position;
		int newXPos();
		int newYPos();
	public:
		Fruit(int x = 0, int y = 0);
		Fruit(sf::Vector2i tempPosition);
		sf::Vector2i getPosition() const;
};


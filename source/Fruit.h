#pragma once

#include<SFML\Graphics.hpp>
#include<cstdlib>
#include<ctime>

class Fruit {
	private:
		sf::Vector2f position;
		sf::Texture tFruta;
		sf::Sprite Fruta;
		int newXPos();
		int newYPos();
	public:
		Fruit(int x = 0, int y = 0);
		Fruit(sf::Vector2f tempPosition);
		sf::Vector2f getPosition() const;
		void newPosition();
		void draw(sf::RenderWindow &window);
};

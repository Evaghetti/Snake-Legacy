#include "Fruit.h"
#include <iostream>
#include <exception>

int Fruit::newXPos() const {
	srand(time(NULL));
	int num;
	do {
		num = rand() % 640;
	} while (num % tFruta.getSize().x != 0);
	return num;
}
int Fruit::newYPos() const {
	srand(time(NULL));
	int num;
	do {
		num = rand() % 480;
	} while (num % tFruta.getSize().y != 0);
	return num;
}

Fruit::Fruit(std::string caminho, int x, int y) {
	if (x == 0)
		x = newXPos();
	else if (y == 0)
		y = newYPos();
	tFruta.loadFromFile(caminho);
	Fruta.setTexture(tFruta);
	position = sf::Vector2f(x, y);
}

Fruit::Fruit(sf::Vector2f tempPosition, std::string caminho) : position(tempPosition) {
	if (tempPosition == sf::Vector2f(0, 0))
		position = sf::Vector2f(newXPos(), newYPos());
	tFruta.loadFromFile(caminho);
	Fruta.setTexture(tFruta);
}

sf::Vector2f Fruit::getPosition() const {
	return position;
}

void Fruit::newPosition() {
	position = sf::Vector2f(newXPos(), newYPos());
}

void Fruit::draw(sf::RenderWindow & window) {
	Fruta.setPosition(position);
	window.draw(Fruta);
}

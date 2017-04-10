#include "Fruit.h"
#include <iostream>

int Fruit::newYPos() {
	srand(time(NULL));
	int num = rand() % 480;
	while(num%60!=0)
		num = rand() % 480;
	return num;
}

int Fruit::newXPos() {
	srand(time(NULL));
	int num = rand() % 640;
	while(num % 64 != 0)
		num = rand() % 640;
	return num;
}

Fruit::Fruit(int x, int y) {
	if (x == 0)
		x = newXPos();
	else if (y == 0)
		y = newYPos();
	position = sf::Vector2f(x, y);
}

Fruit::Fruit(sf::Vector2f tempPosition) : position(tempPosition) {
	if (tempPosition == sf::Vector2f(0, 0))
		position = sf::Vector2f(newXPos(), newYPos());
	tFruta.loadFromFile("images/fruit.png");
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

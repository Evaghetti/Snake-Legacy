#include "Fruit.h"

int Fruit::newYPos() {
	return 0;
}

int Fruit::newXPos() {
	return 0;
}

Fruit::Fruit(int x, int y) {
	if (x == 0)
		x = newXPos();
	else if (y == 0)
		y = newYPos();
	position = { x,y };
}

Fruit::Fruit(sf::Vector2i tempPosition) : position(tempPosition) {
	if (tempPosition == sf::Vector2i(0, 0))
		position = sf::Vector2i(newXPos(), newYPos());
}

sf::Vector2i Fruit::getPosition() const {
	return position;
}

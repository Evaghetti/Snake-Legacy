#include "Snake.h"
#include <iostream>
sf::Vector2f Snake::getPosition() const {
	return posHead;
}

void Snake::updateTail(){
	for (auto it = posTail.rbegin(); it != posTail.rend(); it++)
		it = it + 1;
	posTail.at(sizeTail) = posHead;
}

void Snake::Draw(sf::RenderWindow& window) {
	for (auto it : posTail) {
		Tail.setPosition(it);
		window.draw(Tail);
	}
	Head.setPosition(posHead);
	window.draw(Head);
}


void Snake::Update() {
	switch (dir) {
		case DIREC::DIREITA:
			posHead.x += xVel;
			break;
		case DIREC::ESQUERDA:
			posHead.x -= xVel;
			break;
		case DIREC::CIMA:
			posHead.y -= yVel;
			break;
		case DIREC::BAIXO:
			posHead.y += yVel;
			break;
	}
	if (posHead.x == 640)
		posHead.x = 0;
	else if (posHead.x < 0)
		posHead.x = 640 - xVel;
	if (posHead.y == 480)
		posHead.y = 0;
	else if (posHead.y < 0)
		posHead.y = 480 - 64;
}

Snake::Snake(sf::Vector2f posHead, int sizeTail = 0, std::string pathHead = "", std::string pathTail = "") {
	this->posHead = posHead;
	this->sizeTail = sizeTail;
	try {
		if (!tHead.loadFromFile(pathHead) || !tTail.loadFromFile(pathTail)) {
			throw 98;
		}
	}
	catch (...) {
		std::cout << "Erro ao Abrir alguma Imagem" << std::endl;
		exit(1);
	}
	Head.setTexture(tHead);
	Tail.setTexture(tTail);
	xVel = tTail.getSize().x;
	yVel = tTail.getSize().y;
	dir = DIREC::DIREITA;
	std::cout << Head.getScale().x << " " << Head.getScale().y << std::endl;
}

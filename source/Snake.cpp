#include "Snake.h"
#include <iostream>
#include <exception>
sf::Vector2f Snake::getPosition() const {
	return posHead;
}

void Snake::updateTail(){
	for (int i = posTail.size()-1; i > 0; i--)
		posTail.at(i) = posTail.at(i - 1);
	posTail.at(0) = posHead;
}

void Snake::eatFruit(Fruit & Apple) {
	if (Apple.getPosition() == getPosition()) {
		posTail.push_back(posHead);
		Apple.newPosition();
	}
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
		posHead.x = 640.0f - xVel;
	if (posHead.y == 480)
		posHead.y = 0;
	else if (posHead.y < 0)
		posHead.y = 480.0f - yVel;
	updateTail();
}

Snake::Snake(sf::Vector2f posHead, std::string pathHead = "", std::string pathTail = "") : posTail(1, posHead){
	this->posHead = posHead;
	try {
		tHead.loadFromFile(pathHead);
		tTail.loadFromFile(pathTail);
	}
	catch (std::exception e) {
		std::cerr << "Erro ao abrir imagem: " << e.what() << std::endl;
		exit(1);
	}
	Head.setTexture(tHead);
	Tail.setTexture(tTail);
	xVel = tTail.getSize().x;
	yVel = tTail.getSize().y;
	dir = DIREC::DIREITA;
}

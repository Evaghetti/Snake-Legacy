#include "Snake.h"
#include <iostream>
#include <algorithm>
#include <exception>

void Snake::updateTail(){
	for (int i = body.size() - 1; i > 0; i--) {
		body.at(i) = body.at(i - 1);
	}
}

void Snake::eatFruit(Fruit & Apple) {
	if (Apple.getPosition() == body.at(0)) {
		body.push_back(body.at(0));
		while (std::any_of(body.begin(), body.end(), [&](auto a) {
			return a == Apple.getPosition(); 
		})) {
			Apple.newPosition();
		}
	}
}

void Snake::Draw(sf::RenderWindow& window) {
	for (auto it : body) {
		Tail.setPosition(it);
		window.draw(Tail);
	}
	Head.setPosition(body.at(0));
	window.draw(Head);
}

void Snake::Update() {
	updateTail();
	switch (dir) {
		case DIREC::DIREITA:
			body.at(0).x += xVel;
			break;
		case DIREC::ESQUERDA:
			body.at(0).x -= xVel;
			break;
		case DIREC::CIMA:
			body.at(0).y -= yVel;
			break;
		case DIREC::BAIXO:
			body.at(0).y += yVel;
			break;
	}
	if (body.at(0).x == 640)
		body.at(0).x = 0;
	else if (body.at(0).x  < 0)
		body.at(0).x = 640.0f - xVel;
	if (body.at(0).y == 480)
		body.at(0).y = 0;
	else if (body.at(0).y < 0)
		body.at(0).y = 480.0f - yVel;
}

Snake::Snake(sf::Vector2f posHead, std::string pathHead = "", std::string pathTail = "") : body(1, posHead) {
	try {
		tHead.loadFromFile(pathHead);
		tTail.loadFromFile(pathTail);
	}
	catch (std::exception e) {
		std::cerr << "Erro ao abrir imagem: " << e.what() << std::endl;
		exit(1);
	}
	Tail.setTexture(tTail);
	Head.setTexture(tHead);
	xVel = tTail.getSize().x;
	yVel = tTail.getSize().y;
	dir = DIREC::DIREITA;
}

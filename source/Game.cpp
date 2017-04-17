#include "Game.h"
#include <iostream>
Game::Game(int largura, int altura, char * titulo) : window(sf::VideoMode(largura, altura), titulo),
													 Player(0.25f, { 320.0f, 240.0f }, "images/head.png", "images/tail.png"),
													 Apple("images/fruit.png", 64, 60)
{
	window.setFramerateLimit(60);
	tTile.loadFromFile("images/grade.png");
	Tile.setTexture(tTile);
}

void Game::userInput(sf::Keyboard::Key key) {
	if (key == sf::Keyboard::Left && Player.dir != Snake::DIREITA)
		Player.dir = Snake::ESQUERDA;
	else if (key == sf::Keyboard::Right && Player.dir != Snake::ESQUERDA)
		Player.dir = Snake::DIREITA;
	else if (key == sf::Keyboard::Up && Player.dir != Snake::BAIXO)
		Player.dir = Snake::CIMA;
	else if (key == sf::Keyboard::Down && Player.dir != Snake::CIMA)
		Player.dir = Snake::BAIXO;
}

void Game::gameUpdate() {
	sf::Event e;
	float tempoPassado = timer.restart().asSeconds();
	while (window.pollEvent(e)) {
		if (e.type == sf::Event::Closed)
			window.close();
		else if (e.type == sf::Event::KeyPressed)
			userInput(e.key.code);
	}
	Player.Update(tempoPassado);
	if (Player.isDead())
		std::cout << "Morreu" << std::endl;
	Player.eatFruit(Apple);
}

void Game::gameDraw() {
	window.clear();
	for (int y = 0; y < window.getSize().y; y += tTile.getSize().y) {
		for (int x = 0; x < window.getSize().x; x += tTile.getSize().x) {
			Tile.setPosition(x, y);
			window.draw(Tile);
		}
	}
	Apple.draw(window);
	Player.Draw(window);
	window.display();
}

void Game::gameLooping() {
	while (window.isOpen()) {
		gameUpdate();
		gameDraw();
	}
}

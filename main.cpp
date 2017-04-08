#include <SFML/Graphics.hpp>
#include "source/Game.h"
int main() {
	Game game(640, 480, "Snake C++");
	game.gameLooping();
	return 0;
}

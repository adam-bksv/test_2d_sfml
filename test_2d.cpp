
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

const auto print = [](const auto& x) { std::string str = x; std::cout << *x + "\n"; };

struct character {
	sf::VertexArray chr;
	
};

void move_character(float x, float y) {
	character character;
	character.chr[0].position = sf::Vector2f(x, y);
	character.chr[1].position = sf::Vector2f(x, y);
	character.chr[2].position = sf::Vector2f(x, y);
	character.chr[3].position = sf::Vector2f(x, y);
}

void create_cube(sf::RenderWindow& win) {
	character character;
	sf::VertexArray character_array(sf::Lines, 4);
	character.chr = character_array;
	move_character(1, 5);
	
}

void init() {
	std::vector<sf::VertexArray> trngs;

	sf::RenderTexture rt;
	sf::VertexArray trng1(sf::Triangles, 3);
	sf::RenderWindow win(sf::VideoMode(800, 600), "margiela");

	while (win.isOpen()) {
		sf::Event event;
		while (win.pollEvent(event)) {

			if (event.type == sf::Event::Closed) 
				win.close();
		}

		win.clear(sf::Color::Black);

		//triangles
		create_cube(win);

		win.display();
	}
}

int main()
{
	init();
}

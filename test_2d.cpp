
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <Windows.h>

#define window_size_x 800
#define window_size_y 600

const auto print = [](const auto& x) { std::string str = x; std::cout << *x + "\n"; };

float x = 1, y = 1, size = 50;

sf::RenderWindow win(sf::VideoMode(window_size_x, window_size_y), "margiela");
sf::VertexArray character_array(sf::Lines, 8);

void move_character(float x, float y, float size) {
	if (x > window_size_x || y > window_size_y) {
		return;
	}
	character_array[0].position = sf::Vector2f(x, y); 
	character_array[1].position = sf::Vector2f(x+size, y); 
	character_array[2].position = sf::Vector2f(x+size, y); 
	character_array[3].position = sf::Vector2f(x+size, y+size);
	character_array[4].position = sf::Vector2f(x + size, y + size);
	character_array[5].position = sf::Vector2f(x, y + size);
	character_array[6].position = sf::Vector2f(x, y + size);
	character_array[7].position = sf::Vector2f(x, y);

	for (int i = 0; i <= 7; i++)
	{
		character_array[i].color = sf::Color::Red;
	}
	win.draw(character_array);
}

void create_cube(sf::RenderWindow& win) {
	sf::VertexArray character_array(sf::Lines, 4);
	character_array = character_array;
	move_character(x,y,size);
	
}

void init() {
	std::vector<sf::VertexArray> trngs;

	sf::RenderTexture rt;
	sf::VertexArray trng1(sf::Triangles, 3);

	while (win.isOpen()) {
		sf::Event event;
		while (win.pollEvent(event)) {

			if (event.type == sf::Event::Closed) 
				win.close();
		}

		win.clear(sf::Color::Black);

		//triangles
		create_cube(win);
		
		if (GetKeyState(0x44) & 0x8000) {
			x += .1;
		}
		if (GetKeyState(0x41) & 0x8000) {
			x -= .1;
		}
		if (GetKeyState(0x53) & 0x8000) {
			y += .1;
		}
		if (GetKeyState(0x57) & 0x8000) {
			y -= .1;
		}

		win.display();
	}
}

int main()
{
	init();
}

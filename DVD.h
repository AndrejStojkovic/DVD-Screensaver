#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>

class DVD {
public:
	DVD(sf::RenderWindow& window);
	void update(float dt);
	void draw(sf::RenderWindow& window, float dt);
	void collision(sf::RenderWindow& window);
	sf::Color getColor();
	void switchColor();
	void reset(sf::RenderWindow& window, bool fs);
private:
	sf::Text object;
	sf::Font font;

	float speedX;
	float speedY;
};


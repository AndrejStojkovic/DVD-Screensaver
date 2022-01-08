#include "DVD.h"

DVD::DVD(sf::RenderWindow& window) {
	if (!font.loadFromFile("DigitalSymbols.ttf")) {
		std::cout << "Font could not be loaded!" << std::endl;
	}

	srand(time(NULL));
	int posX = window.getSize().x / 8;
	int posY = window.getSize().y / 8;
	speedX = speedY = 150;

	object.setFillColor(sf::Color::White);
	object.setString("z");
	object.setCharacterSize(120);
	object.setPosition(sf::Vector2f(posX, posY));
	object.setFont(font);

	sf::FloatRect fr = object.getLocalBounds();
	object.setOrigin(fr.width / 2, fr.height / 2);
}

void DVD::update(float dt) {
	int velX = (speedX * dt);
	int velY = (speedY * dt);
	object.move(sf::Vector2f(velX, velY));
}

void DVD::draw(sf::RenderWindow& window, float dt) {
	collision(window);
	update(dt);
	window.draw(object);
}

void DVD::collision(sf::RenderWindow& window) {
	int width = object.getLocalBounds().width / 2;
	int height = object.getLocalBounds().height / 2;

	if (object.getPosition().x + width > window.getSize().x || object.getPosition().x - width < 0) {
		speedX = -speedX;
		switchColor();
	}

	if (object.getPosition().y + height > window.getSize().y - 12.0f || object.getPosition().y - height + 12.0f < 0) {
		speedY = -speedY;
		switchColor();
	}
}

sf::Color DVD::getColor() {
	int one = (rand() % 255) + 1;
	int two = (rand() % 255) + 1;
	int three = (rand() % 255) + 1;

	return sf::Color(one, two, three);
}

void DVD::switchColor() {
	object.setFillColor(getColor());
}

void DVD::reset(sf::RenderWindow& window, bool fs) {
	int posX = window.getSize().x / 8;
	int posY = window.getSize().y / 8;
	object.setPosition(sf::Vector2f(posX, posY));
	object.setFillColor(sf::Color::White);

	if(fs) object.setCharacterSize(150);
	else object.setCharacterSize(120);
}
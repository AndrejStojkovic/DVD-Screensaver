#include <SFML/Graphics.hpp>
#include "DVD.h"

#define MIN_WIDTH 1280
#define MIN_HEIGHT 720

int main() {
	sf::RenderWindow window(sf::VideoMode(MIN_WIDTH, MIN_HEIGHT), "DVD Screensaver", sf::Style::Close);

	int screenWidth = sf::VideoMode::getDesktopMode().width;
	int screenHeight = sf::VideoMode::getDesktopMode().height;

	bool fullscreen = false;
	window.setFramerateLimit(60);

	sf::Clock deltaClock;

	DVD dvd(window);

	while (window.isOpen()) {
		float dt = deltaClock.restart().asSeconds();
		sf::Event evnt;

		while (window.pollEvent(evnt)) {
			switch (evnt.type) {
				case sf::Event::KeyReleased:
					switch (evnt.key.code) {
					case sf::Keyboard::F11:
						if (!fullscreen) {
							// create fullscreen
							window.create(sf::VideoMode(screenWidth, screenHeight), "DVD Screensaver", sf::Style::Fullscreen);
							window.setFramerateLimit(60);
							fullscreen = true;
							dvd.reset(window, fullscreen);
						} else {
							// create windowed
							window.create(sf::VideoMode(MIN_WIDTH, MIN_HEIGHT), "DVD Screensaver", sf::Style::Close);
							window.setFramerateLimit(60);
							fullscreen = false;
							dvd.reset(window, fullscreen);
						}
						break;

						case sf::Keyboard::Escape:
							window.close();
							break;
					}
					break;

				case sf::Event::Closed:
					window.close();
					break;
			}
		}

		window.clear(sf::Color::Black);
		
		dvd.draw(window, dt);

		window.display();
	}

	return 0;
}
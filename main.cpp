#include <SFML/Graphics.hpp>
//#include <GLFW/glfw3.h>
#include <cmath>

/*
int getMonitorRefreshRate() {
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);
	return mode->refreshRate;
}*/

void handleInput(sf::RenderWindow& window, sf::Sprite& playerSprite) {
	sf::Event e;
		while(window.pollEvent(e)) {
			if(e.type == sf::Event::Closed) {
				window.close();
			}
		}
		
	//Handle player movement
    float speed = 6.0f;
   
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        playerSprite.move(0, -speed); //move up
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        playerSprite.move(0, speed); //move down
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        playerSprite.move(-speed, 0); //move left
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        playerSprite.move(speed, 0); //move right
    }
}


int main() {
	sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "gaming", sf::Style::Fullscreen);
	//sf::RenderWindow window(sf::VideoMode(1080, 720), "gaming");
	
	//player texture/sprite
	sf::Texture playerTexture;
	playerTexture.loadFromFile("player.png");
	
	sf::Sprite playerSprite(playerTexture);
	playerSprite.setScale(3.0f, 3.0f);
	playerSprite.setPosition(100, 100);

	//background texture/sprite
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("ground.png");
	backgroundTexture.setRepeated(true);

	sf::Sprite backgroundSprite(backgroundTexture);
	backgroundSprite.setTextureRect(sf::IntRect(0, 0, 1080, 720));
	backgroundSprite.setScale(20.0f, 20.0f);
	

	//set frame rate
	//window.setFramerateLimit(getMonitorRefreshRate());
	//window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(144);

	//game loop
	while(window.isOpen()) {
		handleInput(window, playerSprite);

		window.clear(sf::Color(50, 50, 50));
		window.draw(backgroundSprite);
		window.draw(playerSprite);
		window.display();
		
	}
	return 0;
}

#include <SFML/Graphics.hpp>
#include <cmath>

void handleInput(sf::RenderWindow& window, sf::Sprite& playerSprite) {
	sf::Event e;
		while(window.pollEvent(e)) {
			if(e.type == sf::Event::Closed) {
				window.close();
			}
		}
		
	//Handle player movement
    float speed = 0.1f;
   
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
	sf::RenderWindow window(sf::VideoMode(1080, 720), "The Game!");
	
	sf::Texture playerTexture;
	playerTexture.loadFromFile("player.png");
	
	sf::Sprite playerSprite(playerTexture);
	playerSprite.setPosition(100, 100);

	while(window.isOpen()) {
		handleInput(window, playerSprite);

		window.clear();
		window.draw(playerSprite);
		window.display();
		
	}
	return 0;
}

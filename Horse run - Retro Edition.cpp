#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 300), "Horse Run - C++ Edition");
    window.setFramerateLimit(60);

    // Definir o cavalo como um retângulo (ou carregar uma textura sf::Texture)
    sf::RectangleShape horse(sf::Vector2f(50, 40));
    horse.setFillColor(sf::Color(110, 59, 28));
    horse.setPosition(60, 200);

    float velocityY = 0.f;
    float gravity = 0.8f;
    bool isJumping = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space && !isJumping) {
                    velocityY = -14.f;
                    isJumping = true;
                }
            }
        }

        // Atualizar física
        velocityY += gravity;
        horse.move(0, velocityY);

        if (horse.getPosition().y > 200) {
            horse.setPosition(60, 200);
            velocityY = 0;
            isJumping = false;
        }

        // Renderização
        window.clear(sf::Color(220, 220, 220)); // Cor de fundo
        window.draw(horse);
        window.display();
    }

    return 0;
}
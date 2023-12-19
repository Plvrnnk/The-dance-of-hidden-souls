#include <SFML/Graphics.hpp>
#include "Platform.hpp"

int main() {
    // Створюємо вікно
    sf::RenderWindow window(sf::VideoMode(800, 600), "Platformer");

    // Створюємо платформу
    Platform platform;
    platform.setPosition(sf::Vector2f(100.0f, 200.0f));

    // Цикл відображення гри
    while (window.isOpen()) {
        // Обробляємо введення
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Переміщуємо платформу
        platform.setPosition(platform.getPosition() + sf::Vector2f(0.0f, 1.0f));

        // Очищаємо вікно
        window.clear();

        // Малюємо платформу
        window.draw(platform.getSprite());

        // Відображаємо вікно
        window.display();
    }

    return 0;
}
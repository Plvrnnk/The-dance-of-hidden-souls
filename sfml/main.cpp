#include <SFML/Graphics.hpp>
#include "Platform.hpp"

int main() {
    // ��������� ����
    sf::RenderWindow window(sf::VideoMode(800, 600), "Platformer");

    // ��������� ���������
    Platform platform;
    platform.setPosition(sf::Vector2f(100.0f, 200.0f));

    // ���� ����������� ���
    while (window.isOpen()) {
        // ���������� ��������
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // ��������� ���������
        platform.setPosition(platform.getPosition() + sf::Vector2f(0.0f, 1.0f));

        // ������� ����
        window.clear();

        // ������� ���������
        window.draw(platform.getSprite());

        // ³��������� ����
        window.display();
    }

    return 0;
}
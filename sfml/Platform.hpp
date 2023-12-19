#include <SFML/Graphics.hpp>

class Platform {
public:
    Platform() {
        // Ініціалізуємо позицію платформи
        position = sf::Vector2f(0.0f, 0.0f);

        // Ініціалізуємо розмір платформи
        width = 100.0f;
        height = 50.0f;

        // Завантажуємо графічний об'єкт платформи
        texture.loadFromFile("grass.png");
        sprite.setTexture(texture);
    }

    // Отримуємо позицію платформи
    sf::Vector2f getPosition() const { return position; }

    // Встановлюємо позицію платформи
    void setPosition(const sf::Vector2f& position) { this->position = position; }

    // Отримуємо ширину платформи
    float getWidth() const { return width; }

    // Встановлюємо ширину платформи
    void setWidth(float width) { this->width = width; }

    // Отримуємо висоту платформи
    float getHeight() const { return height; }

    // Встановлюємо висоту платформи
    void setHeight(float height) { this->height = height; }

    // Отримуємо графічний об'єкт платформи
    sf::Sprite getSprite() const { return sprite; }

private:
    // Позиція платформи
    sf::Vector2f position;

    // Ширина платформи
    float width;

    // Висота платформи
    float height;

    // Графічний об'єкт платформи
    sf::Sprite sprite;
    sf::Texture texture;
};

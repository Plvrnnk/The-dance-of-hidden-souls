#include <SFML/Graphics.hpp>

class Platform {
public:
    Platform() {
        // ���������� ������� ���������
        position = sf::Vector2f(0.0f, 0.0f);

        // ���������� ����� ���������
        width = 100.0f;
        height = 50.0f;

        // ����������� ��������� ��'��� ���������
        texture.loadFromFile("grass.png");
        sprite.setTexture(texture);
    }

    // �������� ������� ���������
    sf::Vector2f getPosition() const { return position; }

    // ������������ ������� ���������
    void setPosition(const sf::Vector2f& position) { this->position = position; }

    // �������� ������ ���������
    float getWidth() const { return width; }

    // ������������ ������ ���������
    void setWidth(float width) { this->width = width; }

    // �������� ������ ���������
    float getHeight() const { return height; }

    // ������������ ������ ���������
    void setHeight(float height) { this->height = height; }

    // �������� ��������� ��'��� ���������
    sf::Sprite getSprite() const { return sprite; }

private:
    // ������� ���������
    sf::Vector2f position;

    // ������ ���������
    float width;

    // ������ ���������
    float height;

    // ��������� ��'��� ���������
    sf::Sprite sprite;
    sf::Texture texture;
};

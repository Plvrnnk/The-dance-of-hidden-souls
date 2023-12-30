#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Animation
{
public:
    std::vector<IntRect> frames, frames_flip; // вектор кадров для анимации и для отзеркаленной анимации
    float currentFrame, speed;
    bool flip, isPlaying;
    Sprite sprite;

    // Конструктор умовчання
    Animation();

    // Конструктор копіювання
    Animation(const Animation& other);

    Animation(Texture& t, int x, int y, int w, int h, int count, float Speed);

    ~Animation();

    void tick(float time);
};

class AnimationManager
{
public:
    std::string currentAnim;
    std::map<std::string, Animation> animList;

    AnimationManager();

    AnimationManager(const AnimationManager& other);

    AnimationManager(const std::string& name, Texture& t, int x, int y, int w, int h, int count, float speed);

    ~AnimationManager();

    void create(std::string name, Texture& t, int x, int y, int w, int h, int count, float speed);

    void set(std::string name);

    void draw(RenderWindow& window, int x = 0, int y = 0);

    float getH();

    float getW();

    void flip(bool b);

    void tick(float time);

    void pause();

    void play();

    void play(std::string name);

    bool isPlaying();
};

#endif
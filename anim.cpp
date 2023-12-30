#include "anim.h"



Animation::Animation()
{
    speed = 0;
    currentFrame = 0;
    isPlaying = true;
    flip = false;
}

Animation::Animation(const Animation& other)
    : frames(other.frames), frames_flip(other.frames_flip),
    currentFrame(other.currentFrame), speed(other.speed),
    flip(other.flip), isPlaying(other.isPlaying),
    sprite(other.sprite) {}

Animation::Animation(Texture& t, int x, int y, int w, int h, int count, float Speed)
{
    speed = Speed;
    sprite.setTexture(t);

    currentFrame = 0;
    isPlaying = true;
    flip = false;

    for (int i = 0; i < count; i++)
    {
        frames.push_back(IntRect(x + i * w, y, w, h));
        frames_flip.push_back(IntRect(x + i * w + w, y, -w, h));
    }
}

Animation::~Animation() {}

void Animation::tick(float time)
{
    if (!isPlaying)
        return;

    currentFrame += speed * time;

    if (currentFrame > frames.size())
    {
        currentFrame -= frames.size();
    }

    int i = currentFrame;
    if (flip)
        sprite.setTextureRect(frames_flip[i]);
    else
        sprite.setTextureRect(frames[i]);
}

//////////////////////////AnimationManager//////////////////////////////////////

AnimationManager::AnimationManager()
{
    currentAnim = "None";
}

AnimationManager::AnimationManager(const AnimationManager& other)
{
    currentAnim = other.currentAnim;

    
    for (const auto& pair : other.animList)
    {
        animList[pair.first] = pair.second;
    }
}

AnimationManager::AnimationManager(const std::string& name, Texture& t, int x, int y, int w, int h, int count, float speed)
{
    
    animList[name] = Animation(t, x, y, w, h, count, speed);
    currentAnim = name;
}

AnimationManager::~AnimationManager()
{
    animList.clear();
}

void AnimationManager::create(std::string name, Texture& t, int x, int y, int w, int h, int count, float speed)
{
    animList[name] = Animation(t, x, y, w, h, count, speed);
    currentAnim = name;
}

void AnimationManager::set(std::string name)
{
    currentAnim = name;
}

void AnimationManager::draw(RenderWindow& window, int x, int y)
{
    window.draw(animList[currentAnim].sprite);
}

float AnimationManager::getH()
{
    return animList[currentAnim].frames[0].height;
}

float AnimationManager::getW()
{
    return animList[currentAnim].frames[0].width;
}

void AnimationManager::flip(bool b)
{
    animList[currentAnim].flip = b;
}

void AnimationManager::tick(float time)
{
    animList[currentAnim].tick(time);
}

void AnimationManager::pause()
{
    animList[currentAnim].isPlaying = false;
}

void AnimationManager::play()
{
    animList[currentAnim].isPlaying = true;
}

void AnimationManager::play(std::string name)
{
    animList[name].isPlaying = true;
}

bool AnimationManager::isPlaying()
{
    return animList[currentAnim].isPlaying;
}


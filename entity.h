#ifndef ENTITY_H
#define ENTITY_H
#include"anim.h"
#include"map.h"
#include"view.h"


sf::SoundBuffer buffer;
sf::Sound sound;

void playJumpSound() {
	buffer.loadFromFile("jump.mp3");

	sound.setBuffer(buffer);
	sound.setVolume(20);

	
	sound.play();
}

class Entity {

public:
	float dx, dy, x, y, speed;
	int w, h, health;
	bool life, isMove, onGround;
	AnimationManager anim;
	String name;

	//� �����������
	Entity(AnimationManager& anim, float X, float Y, int W, int H, String Name) {
		x = X; y = Y; w = W; h = H; name = Name; 
		speed = 0; health = 100; dx = 0; dy = 0;
		life = true; onGround = false; isMove = false;
	}

	// ���������
	Entity()
		: dx(0), dy(0), x(0), y(0), speed(0), w(0), h(0), health(100),
		life(true), isMove(false), onGround(false) {}

	// ���������
	Entity(const Entity& other)
		: dx(other.dx), dy(other.dy), x(other.x), y(other.y),
		speed(other.speed), w(other.w), h(other.h), health(other.health),
		life(other.life), isMove(other.isMove), onGround(other.onGround),
		anim(other.anim), name(other.name) {}

	virtual ~Entity() {}

	virtual void update(float) = 0;

	void draw(RenderWindow& window)
	{
		anim.draw(window, x, y);
	}
};

class Player :public Entity {
public:
	enum { left, right, up, down, jump, stay } state;
	int playerScore;

	//� �����������
	Player(AnimationManager& a, float X, float Y, int W, int H, String Name) :Entity(anim, X, Y, W, H, Name) {
		playerScore = 0; state = stay; anim = a;
		if (name == "Player1") {

		}
	}

	// ���������
	Player()
		: Entity(), state(stay), playerScore(0) {}

	// ���������
	Player(const Player& other)
		: Entity(other), state(other.state), playerScore(other.playerScore) {}

	virtual ~Player() {}

	void control() {
		anim.set("idle");

		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			state = left; speed = 0.1; anim.flip(1);  anim.set("walk"); anim.flip(1);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			state = right; speed = 0.1; anim.flip(0); anim.set("walk"); anim.flip(0);
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up)) && (onGround)) {//���� ������ ������� ����� � �� �� �����, �� ����� �������
			state = jump; anim.set("jump"); playJumpSound(); dy = -0.6; onGround = false;//��������� ������ ������  dy = -0.6;
		}


	}
	void checkCollisionWithMap(float Dx, float Dy)//� ��� �������� ������������ � ������
	{
		for (int i = y / 32; i < (y + h) / 32; i++)//���������� �� ��������� �����
			for (int j = x / 32; j < (x + w) / 32; j++)
			{
				if (TileMap[i][j] == '0' || TileMap[i][j] == 'g' || TileMap[i][j] == 'r' || TileMap[i][j] == 'm' || TileMap[i][j] == 'e' || TileMap[i][j] == 'd' || TileMap[i][j] == 'k' || TileMap[i][j] == 'w' || TileMap[i][j] == 'l')//���� ������� ��� ������ �����? ��
				{
					if (Dy > 0) { y = i * 32 - h;  dy = 0; onGround = true; }//�� Y ����=>���� � ���(����� �� �����) ��� ������. � ���� ������ ���� ���������� ��������� � ��������� ��� �� �����, ��� ���� ������� ��� �� �� ����� ��� ����� ����� ����� �������
					if (Dy < 0) { y = i * 32 + 32;  dy = 0; }//������������ � �������� ������ �����(����� � �� �����������)
					if (Dx > 0) { x = j * 32 - w; }//� ������ ����� �����
					if (Dx < 0) { x = j * 32 + 32; }// � ����� ����� �����
				}
			}
	}
	void update(float time)
	{

		control();//������� ���������� ����������
		
		anim.tick(time);
		switch (state)
		{
		case right:dx = speed; break;
		case left:dx = -speed; break;
		case up: break;
		case stay: break;	
		}
		x += dx * time;
		checkCollisionWithMap(dx, 0);//������������ ������������ �� �
		y += dy * time;
		checkCollisionWithMap(0, dy);//������������ ������������ �� Y
		anim.animList[anim.currentAnim].sprite.setPosition(x + w / 2, y); //������ ������� ������� � ����� ��� ������
		if (health <= 0) { life = false; }
		if (!isMove) { speed = 0; }
		if (life) { setPlayerCoordinateForView(x, y); }
		dy = dy + 0.0015 * time;//��������� ������������� � �����

	}
};
class Enemy :public Entity {
public:
	Enemy(AnimationManager& anim, float X, float Y, int W, int H, String Name) :Entity(anim, X, Y, W, H, Name) {
		
			dx = 0.1;//���� ��������.���� ������ ������ ���������
	}
	void checkCollisionWithMap(float Dx, float Dy)//� ��� �������� ������������ � ������
	{
		for (int i = y / 32; i < (y + h) / 32; i++)//���������� �� ��������� �����
			for (int j = x / 32; j < (x + w) / 32; j++)
			{
				if (TileMap[i][j] == '0' || TileMap[i][j] == 'g' || TileMap[i][j] == 'r' || TileMap[i][j] == 'm' || TileMap[i][j] == 'e' || TileMap[i][j] == 'k' || TileMap[i][j] == 'w' || TileMap[i][j] == 'l')//���� ������� ��� ������ �����, ��
				{
					if (Dy > 0) { y = i * 32 - h; }//�� Y ����=>���� � ���(����� �� �����) ��� ������. � ���� ������ ���� ���������� ��������� � ��������� ��� �� �����, ��� ���� ������� ��� �� �� ����� ��� ����� ����� ����� �������
					if (Dy < 0) { y = i * 32 + 32; }//������������ � �������� ������ �����(����� � �� �����������)
					if (Dx > 0) { x = j * 32 - w; dx = -0.08; anim.flip(1); }//� ������ ����� �����
					if (Dx < 0) { x = j * 32 + 32; dx = 0.08; anim.flip(0); }// � ����� ����� �����
				}
			}
	}
	void update(float time)
	{

		
			//moveTimer += time;if (moveTimer>3000){ dx *= -1; moveTimer = 0; }//������ ����������� �������� ������ 3 ���
			anim.tick(time);
			checkCollisionWithMap(dx, 0);//������������ ������������ �� �
			x += dx * time;
			anim.animList[anim.currentAnim].sprite.setPosition(x + w / 2, y);
			if (health <= 0) { life = false; }
		
	}
};



#endif
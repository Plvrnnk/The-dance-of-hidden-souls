#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "entity.h"
#include "anim.h"
using namespace sf;



int main()
{
	RenderWindow window(VideoMode(860, 480), "game");
	view.reset(FloatRect(0, 0, 860, 480));


	Image map_image;
	map_image.loadFromFile("images/tile.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);


	Image easyEnemyImage;
	easyEnemyImage.loadFromFile("images/wolf.png");

	
	Texture playerSprite, wolfsprite;
	playerSprite.loadFromFile("images/sprite2.png");
	wolfsprite.loadFromFile("images/wolf.png");

	
	AnimationManager playeranim, wolfanim;

	playeranim.create("walk", playerSprite, 0, 0, 38, 64, 7, 0.005);
	playeranim.create("jump", playerSprite, 0, 64, 38, 64, 6, 0.005);
	playeranim.create("attack", playerSprite, 0, 128, 88, 64, 5, 0.005);
	playeranim.create("idle", playerSprite, 0, 192, 38, 64, 4, 0.005);

	wolfanim.create("walk", wolfsprite, 0, 0, 38, 64, 7, 0.005);
	wolfanim.create("attack", wolfsprite, 0, 64, 38, 64, 6, 0.005);


	Player p(playeranim, 470, 352, 38, 64, "Player1");
	Enemy easyEnemy(wolfanim, 3160, 150, 97, 84, "EasyEnemy");

	Texture backgroundTexture;
	backgroundTexture.loadFromFile("images/bgfull.png");
	Sprite backgroundSprite(backgroundTexture);


	Music music;
	music.openFromFile("TaleForTheJourney.wav");
	music.setVolume(10);
	music.play();


	Clock clock;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800.f;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		p.update(time);
		window.setView(view);
		window.clear();
		window.draw(backgroundSprite);
		for (int i = 0; i < HEIGHT_MAP; i++)
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(81, 427, 32, 32));
				if (TileMap[i][j] == ' ' || TileMap[i][j] == '0')  s_map.setTextureRect(IntRect(81, 427, 32, 32)); 
				if (TileMap[i][j] == 'o')  s_map.setTextureRect(IntRect(6, 55, 96, 28));
				if ((TileMap[i][j] == 'l')) s_map.setTextureRect(IntRect(131, 41, 80, 40));
				if ((TileMap[i][j] == 'g')) s_map.setTextureRect(IntRect(288, 41, 32, 32));
				if ((TileMap[i][j] == 'w')) s_map.setTextureRect(IntRect(0, 0, 32, 32));
				if (TileMap[i][j] == 'a')  s_map.setTextureRect(IntRect(32, 0, 32, 32));
				if ((TileMap[i][j] == 't')) s_map.setTextureRect(IntRect(0, 100, 181, 266));
				if ((TileMap[i][j] == 'd')) s_map.setTextureRect(IntRect(64, 0, 64, 32));
				if (TileMap[i][j] == 'e')  s_map.setTextureRect(IntRect(407, 31, 100, 77));
				if ((TileMap[i][j] == 'm')) s_map.setTextureRect(IntRect(306, 198, 31, 38));
				if ((TileMap[i][j] == 'r')) s_map.setTextureRect(IntRect(403, 187, 48, 32));
				s_map.setPosition(j * 32, i * 32);
				window.draw(s_map);

			}
		
		p.draw(window);
		window.display();
	}
	return 0;
}


////////////////////////////////////////////Тестування конструкторів для Animation, AnimationManager, Player ///////////////////////////////////////////

/*
int main()
{
	RenderWindow window(VideoMode(860, 480), "game");
	view.reset(FloatRect(0, 0, 860, 480));


	Image map_image;
	map_image.loadFromFile("images/tile.png");
	Texture map;
	map.loadFromImage(map_image);
	Sprite s_map;
	s_map.setTexture(map);


	Texture  wolfsprite;
	wolfsprite.loadFromFile("images/wolf.png");

	Animation wolf_attack(wolfsprite, 0, 0, 97, 84, 4, 0.005), enemy_attack(wolf_attack);

	AnimationManager  wolfanim("walk", wolfsprite, 0, 84, 97, 84, 11, 0.005), enemyanim(wolfanim);

	Player player1(wolfanim, 100, 200, 50, 50, "Player1"), player2(player1);


	Clock clock;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800.f;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		//wolfanim.tick(time); //enemyanim.tick(time);

		//wolf_attack.tick(time);//enemy_attack.tick(time);
		player2.control();
		player2.anim.tick(time);
		window.clear(Color::White);

		//wolfanim.draw(window);
		//enemyanim.draw(window);


		//window.draw(wolf_attack.sprite);
		 //window.draw(enemy_attack.sprite);


		player2.draw(window);

		window.display();
	}
	return 0;
}

*/



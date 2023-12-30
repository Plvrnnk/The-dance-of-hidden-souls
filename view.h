#include <SFML/Graphics.hpp>

sf::View view;//объ€вили sfml объект "вид", который и €вл€етс€ камерой

void setPlayerCoordinateForView(float x, float y) { //функци€ дл€ считывани€ координат игрока
	float tempX = x; float tempY = y;//считываем коорд игрока и провер€ем их, чтобы убрать кра€

	if (x < 430) tempX = 430;//убираем из вида левую сторону 860, 480
	if (x > 3250) tempX = 3250;//убираем из вида правую сторону 860, 480
	//if (y < 190) tempY = 190;//верхнюю сторону
	//if (y > 290) tempY = 290;//нижнюю сторону	

	view.setCenter(tempX, 240); //следим за игроком, передава€ его координаты. 

}
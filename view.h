#include <SFML/Graphics.hpp>

sf::View view;//�������� sfml ������ "���", ������� � �������� �������

void setPlayerCoordinateForView(float x, float y) { //������� ��� ���������� ��������� ������
	float tempX = x; float tempY = y;//��������� ����� ������ � ��������� ��, ����� ������ ����

	if (x < 430) tempX = 430;//������� �� ���� ����� ������� 860, 480
	if (x > 3250) tempX = 3250;//������� �� ���� ������ ������� 860, 480
	//if (y < 190) tempY = 190;//������� �������
	//if (y > 290) tempY = 290;//������ �������	

	view.setCenter(tempX, 240); //������ �� �������, ��������� ��� ����������. 

}
#include "BialyP.h"
#include <Windows.h>


//BialyP::BialyP()
//{
//	setPointCount(6);
//	setPoint(0, sf::Vector2f(6, 14));
//	setPoint(1, sf::Vector2f(8, 14));
//	setPoint(2, sf::Vector2f(8, 26));
//	setPoint(3, sf::Vector2f(0, 26));
//	setPoint(4, sf::Vector2f(0, 0));
//	setPoint(5, sf::Vector2f(6, 0));
//	setOutlineThickness(1);
//	setOutlineColor(sf::Color::Black);
//}
//BialyP::BialyP()
//{
//	setPointCount(6);
//	setPoint(0, sf::Vector2f(0, 0));
//	setPoint(1, sf::Vector2f(11, 0));
//	setPoint(2, sf::Vector2f(11, 30));
//	setPoint(3, sf::Vector2f(16, 30));
//	setPoint(4, sf::Vector2f(16, 52));
//	setPoint(5, sf::Vector2f(0, 52));
//	setOutlineThickness(1);
//	setOutlineColor(sf::Color::White);
//}
BialyP::BialyP()
{
	setTexture();
	Sprite::setTexture(texture1);
	bok.setTexture(texture2);
	bok.setPosition(sf::Vector2f(12, 30));
}

BialyP::~BialyP()
{
}

void BialyP::setID(int a)
{
	id = a;
}

int BialyP::getID()
{
	return id;
}

void BialyP::setTexture()
{
	texture1.loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\srodek_d.png");
	texture2.loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\bok.png");
}

bool BialyP::IsSpiteClicked(sf::RenderWindow &x, BialyP y, sf::Event zdarzenie)
{
	sf::Vector2f mouse(sf::Mouse::getPosition(x));
	if ((zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.key.code == sf::Mouse::Left && y.getGlobalBounds().contains(mouse)) ||
		(zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.key.code == sf::Mouse::Left && y.bok.getGlobalBounds().contains(mouse)))
		return true;
	else
		return false; 
}

void BialyP::setPos(const sf::Vector2f& x)
{
	sf::Sprite::setPosition(sf::Vector2f(0, 0) + x);
	bok.setPosition(sf::Vector2f(sf::Vector2f(12, 30) + x));
}

void BialyP::setCol( sf::Color color)
{
	BialyP::setColor(color);
	bok.setColor(color);
}
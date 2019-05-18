#include "BialyLP.h"


//BialyLP::BialyLP()
//{
//	setPointCount(8);
//	setPoint(0, sf::Vector2f(14, 0));
//	setPoint(1, sf::Vector2f(14, 14));
//	setPoint(2, sf::Vector2f(16, 14));
//	setPoint(3, sf::Vector2f(16, 26));
//	setPoint(4, sf::Vector2f(8, 26));
//	setPoint(5, sf::Vector2f(8, 14));
//	setPoint(6, sf::Vector2f(10, 14));
//	setPoint(7, sf::Vector2f(10, 0));
//	setOutlineThickness(1);
//	setOutlineColor(sf::Color::Black);
//}
//BialyLP::BialyLP()
//{
//	setPointCount(8);
//	setPoint(0, sf::Vector2f(0, 30));
//	setPoint(1, sf::Vector2f(5, 30));
//	setPoint(2, sf::Vector2f(5, 0));
//	setPoint(3, sf::Vector2f(12, 0));
//	setPoint(4, sf::Vector2f(12, 30));
//	setPoint(5, sf::Vector2f(17, 30));
//	setPoint(6, sf::Vector2f(17, 52));
//	setPoint(7, sf::Vector2f(0, 52));
//	setOutlineThickness(1);
//	setOutlineColor(sf::Color::White);
//}
BialyLP::BialyLP()
{
	setTexture();
	Sprite::setTexture(texture1);
	Sprite::setPosition(sf::Vector2f(5, 0));
	bok1.setTexture(texture2);
	bok1.setPosition(sf::Vector2f(0, 30));
	bok2.setTexture(texture2);
	bok2.setPosition(sf::Vector2f(13, 30));
}

BialyLP::~BialyLP()
{
}

void BialyLP::setID(int a)
{
	id = a;
}

int BialyLP::getID()
{
	return id;
}

void BialyLP::setTexture()
{
	texture1.loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\srodek_m.png");
	texture2.loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\bok.png");
}

bool BialyLP::IsSpiteClicked(sf::RenderWindow &x, BialyLP y, sf::Event zdarzenie)
{
	sf::Vector2f mouse(sf::Mouse::getPosition(x));
	if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.key.code == sf::Mouse::Left && (y.getGlobalBounds().contains(mouse) ||
															   y.bok1.getGlobalBounds().contains(mouse) || y.bok2.getGlobalBounds().contains(mouse)) )
		return true;
	else return false;
}

void BialyLP::setPos(const sf::Vector2f& x)
{
	sf::Sprite::setPosition(sf::Vector2f(5, 0) + x);
	bok1.setPosition(sf::Vector2f(sf::Vector2f(0, 30) + x));
	bok2.setPosition(sf::Vector2f(sf::Vector2f(13, 30) + x));
}

void BialyLP::setCol(sf::Color color)
{
	BialyLP::setColor(color);
	bok1.setColor(color);
	bok2.setColor(color);
}
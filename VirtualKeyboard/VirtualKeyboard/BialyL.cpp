#include "BialyL.h"



//BialyL::BialyL()
//{
//	setPointCount(6);
//	setPoint(0, sf::Vector2f( 24,  0));
//	setPoint(1, sf::Vector2f( 24,  26));
//	setPoint(2, sf::Vector2f( 16,  26));
//	setPoint(3, sf::Vector2f( 16,  14));
//	setPoint(4, sf::Vector2f( 18,  14));
//	setPoint(5, sf::Vector2f( 18,  0));
//	setOutlineThickness(1);
//	setOutlineColor(sf::Color::Black);
//}
//BialyL::BialyL()
//{
//	setPointCount(6);
//	setPoint(0, sf::Vector2f(0, 30));
//	setPoint(1, sf::Vector2f(5, 30));
//	setPoint(2, sf::Vector2f(5, 0));
//	setPoint(3, sf::Vector2f(16, 0));
//	setPoint(4, sf::Vector2f(16, 52));
//	setPoint(5, sf::Vector2f(0, 52));
//	setOutlineThickness(1);
//	setOutlineColor(sf::Color::White);
//}
BialyL::BialyL()
{
	setTexture();
	Sprite::setTexture(texture1);
	Sprite::setPosition(sf::Vector2f(5, 0));
	bok.setTexture(texture2);
	bok.setPosition(sf::Vector2f(0, 30));
}

BialyL::~BialyL()
{
}


void BialyL::setID(int a)
{
	id = a;
}

int BialyL::getID()
{
	return id;
}


void BialyL::setTexture()
{
	texture1.loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\srodek_d.png");
	texture2.loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\bok.png");
}

bool BialyL::IsSpiteClicked(sf::RenderWindow &x, BialyL y, sf::Event zdarzenie)
{
	sf::Vector2f mouse(sf::Mouse::getPosition(x));
	if ((zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.key.code == sf::Mouse::Left && y.getGlobalBounds().contains(mouse)) || 
		(zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.key.code == sf::Mouse::Left && y.bok.getGlobalBounds().contains(mouse)))
		return true;
	else return false;
}

void BialyL::setPos(const sf::Vector2f& x)
{
	sf::Sprite::setPosition(sf::Vector2f(5, 0) + x);
	bok.setPosition(sf::Vector2f(sf::Vector2f(0, 30) + x));
}

void BialyL::setCol(sf::Color color)
{
	BialyL::setColor(color);
	bok.setColor(color);
}
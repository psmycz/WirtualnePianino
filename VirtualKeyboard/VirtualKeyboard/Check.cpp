#include "Check.h"



Check::Check()
{
	setText();
	sf::Sprite::setTexture(unchecked);
	setID(3);
}


Check::~Check()
{
}

void Check::setID(int a)
{
	id = a;
}

int Check::getID()
{
	return id;
}

void Check::setText()
{
//	checked.loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\checked.png");
//	unchecked.loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\unchecked.png");
}

bool Check::IsSpiteClicked(sf::RenderWindow &x, sf::Sprite y, sf::Event zdarzenie)
{
	sf::Vector2f mouse(sf::Mouse::getPosition(x));
	if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.key.code == sf::Mouse::Left && y.getGlobalBounds().contains(mouse))
		return true;	
	else return false;
}

bool Check::IsSpriteCovered(sf::RenderWindow &x, sf::Sprite y)
{
	sf::Vector2f mouse(sf::Mouse::getPosition(x));
	if (y.getGlobalBounds().contains(mouse))
		return true;
	else return false;
}
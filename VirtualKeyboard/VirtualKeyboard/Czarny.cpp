#include "Czarny.h"

//Czarny::Czarny()
//{
//	setPointCount(4);
//	setPoint(0, sf::Vector2f(10, 0));
//	setPoint(1, sf::Vector2f(10,14));
//	setPoint(2, sf::Vector2f(6,14));
//	setPoint(3, sf::Vector2f(6,0));
//	setFillColor(sf::Color::Yellow);
//}
//Czarny::Czarny()
//{
//	setPointCount(4);
//	setPoint(0, sf::Vector2f(0, 0));
//	setPoint(1, sf::Vector2f(7, 0));
//	setPoint(2, sf::Vector2f(7, 26));
//	setPoint(3, sf::Vector2f(0, 26));
//	setOutlineThickness(1);
//	setOutlineColor(sf::Color::Yellow);
//	setFillColor(sf::Color::Yellow);
//}
Czarny::Czarny()
{
	setTexture();
	Sprite::setTexture(texture);
	setColor(sf::Color::Black);
}

Czarny::~Czarny()
{
}

void Czarny::setID(int a)
{
	id=a;
}

int Czarny::getID()
{
	return id;
}

void Czarny::setTexture()
{
	texture.loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\czarny.png");
}

bool Czarny::IsSpiteClicked(sf::RenderWindow &x, sf::Sprite y, sf::Event zdarzenie)
{
	sf::Vector2f mouse(sf::Mouse::getPosition(x));
	if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.key.code == sf::Mouse::Left && y.getGlobalBounds().contains(mouse))
		return true;
	else return false;
}
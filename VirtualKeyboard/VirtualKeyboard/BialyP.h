#pragma once
#include <SFML/Graphics.hpp>

class BialyP: public sf::Sprite
{
public:
	BialyP();
	~BialyP();

	void setID(int a);
	int getID();
	void setTexture();
	bool IsSpiteClicked(sf::RenderWindow &, BialyP, sf::Event);
	void setPos(const sf::Vector2f & x);
	Sprite bok;
	void setCol(sf::Color);
private:
	int id;
	sf::Texture texture1, texture2;
};


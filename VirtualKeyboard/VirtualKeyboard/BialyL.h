#pragma once
#include <SFML/Graphics.hpp>

class BialyL: public sf::Sprite
{
public:
	BialyL();
	~BialyL();

	void setID(int a);
	int getID();
	void setTexture();
	bool IsSpiteClicked(sf::RenderWindow &, BialyL, sf::Event);
	void setPos(const sf::Vector2f & x);
	void setCol(sf::Color color);
	Sprite bok;
private:
	int id;
	sf::Texture texture1, texture2;
};


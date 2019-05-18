#pragma once
#include <SFML/Graphics.hpp>

class BialyLP: public sf::Sprite
{
public:
	BialyLP();
	~BialyLP();

	void setID(int a);
	int getID();
	void setTexture();
	bool IsSpiteClicked(sf::RenderWindow &, BialyLP, sf::Event);
	Sprite bok1, bok2;
	void setPos(const sf::Vector2f&);
	void setCol(sf::Color color);
private:
	int id;
	sf::Texture texture1, texture2;
};


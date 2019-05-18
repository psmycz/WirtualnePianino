#pragma once
#include <SFML/Graphics.hpp>

class Check: 
	public sf::Sprite
{
public:
	Check();
	~Check();

	void setText();
	void setID(int a);
	int getID();
	bool IsSpiteClicked(sf::RenderWindow & x, sf::Sprite y, sf::Event zdarzenie);
	bool IsSpriteCovered(sf::RenderWindow & x, sf::Sprite y);
	sf::Texture checked, unchecked;

private:
	int id;
};


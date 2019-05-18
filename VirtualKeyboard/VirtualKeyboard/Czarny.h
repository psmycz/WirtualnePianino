#pragma once
#include <SFML/Graphics.hpp>

class Czarny: 
	public sf::Sprite
{
public:
	Czarny();
	~Czarny();
	Sprite czarny;
	
	void setID(int a);
	int getID();
	void setTexture();
	bool IsSpiteClicked(sf::RenderWindow &, sf::Sprite, sf::Event);
private:
	int id;
	sf::Texture texture;
};


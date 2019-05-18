#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>


class daft_punk
{
public:
	daft_punk();
	~daft_punk();


	void daft();
	bool IsSpiteClicked(sf::RenderWindow & x, sf::Sprite y, sf::Event zdarzenie);

	sf::SoundBuffer buf[16];
	sf::Sound sound[16];
	sf::Texture textur[16];
	sf::Sprite sprajt[16];
};


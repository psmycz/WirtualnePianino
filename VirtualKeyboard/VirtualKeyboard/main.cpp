#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp>
#include "Czarny.h"
#include "BialyP.h"
#include "BialyL.h"
#include "BialyLP.h"
#include "Check.h"
#include "daft_punk.h"


using namespace std;

void rysuj( sf::RenderWindow & window, const sf::Sprite & x);
void rysuj(sf::RenderWindow & window, const sf::Sprite & x, const sf::Sprite & y);
void rysuj(sf::RenderWindow & window, const sf::Sprite & x, const sf::Sprite & y, const sf::Sprite & z);

int main()
{
	
	
	std::string sciezka; // do wczytywania plikow dzwiekowych
	sf::SoundBuffer buffer[88]; // buferki
	for (int i = 0; i < 88; i++)
	{

		if (i < 9)
		{
			sciezka = "C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\sample\\0" + std::to_string(i + 1) + "-bez nazwy.wav";
			buffer[i].loadFromFile(sciezka);
		}
		else
		{
			sciezka = "C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\sample\\" + std::to_string(i + 1) + "-bez nazwy.wav";
			buffer[i].loadFromFile(sciezka);
		}
	}
	std::cout << "zaladowane" << endl;

	sf::Sound sounds[88]; // piosenki
	for (int i = 0, j = 87; i < 88; i++)
	{
		sounds[i].setBuffer(buffer[i]);
		//j--;
	}
	
	sf::RenderWindow oknoAplikacji(sf::VideoMode(1024, 200, 32), "Virtual Piano xD",sf::Style::None);
	oknoAplikacji.setKeyRepeatEnabled(FALSE);  // blokada autorepetycji klawiszy

	float dx = 20, dy = 140; // pozycja lewego gornego rogu klawiatury
	float x = 1; // skala

	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	Czarny czarny[36];
	czarny[0].setPosition(sf::Vector2f(14 + dx, 0 + dy));
	czarny[0].setID(2);
	czarny[0].setScale(sf::Vector2f(x, x));
	for (int i = 0; i < 7; i++) {
		czarny[1 + 5 * i].setPosition(sf::Vector2f(dx + 52 * x + 136 * i * x, dy + 0));
		czarny[2 + 5 * i].setPosition(sf::Vector2f(dx + 72 * x + 136 * i * x, dy + 0));
		czarny[3 + 5 * i].setPosition(sf::Vector2f(dx + 110 * x + 136 * i * x, dy + 0));
		czarny[4 + 5 * i].setPosition(sf::Vector2f(dx + 130 * x + 136 * i * x, dy + 0));
		czarny[5 + 5 * i].setPosition(sf::Vector2f(dx + 150 * x + 136 * i * x, dy + 0));
		czarny[1 + 5 * i].setID(5 + 12 * i);
		czarny[2 + 5 * i].setID(7 + 12 * i);
		czarny[3 + 5 * i].setID(10 + 12 * i);
		czarny[4 + 5 * i].setID(12 + 12 * i);
		czarny[5 + 5 * i].setID(14 + 12 * i);
		czarny[1 + 5 * i].setScale(sf::Vector2f(x, x));
		czarny[2 + 5 * i].setScale(sf::Vector2f(x, x));
		czarny[3 + 5 * i].setScale(sf::Vector2f(x, x));
		czarny[4 + 5 * i].setScale(sf::Vector2f(x, x));
		czarny[5 + 5 * i].setScale(sf::Vector2f(x, x));
	}

	BialyP bialyP[15]; //wciecie z prawej
	bialyP[0].setPos(sf::Vector2f(0 + dx, 0 + dy));
	bialyP[0].setID(1);
	bialyP[0].setScale(sf::Vector2f(x, x));
	for (int i = 0; i < 7; i++) {
		bialyP[1 + 2 * i].setPos(sf::Vector2f(dx + 38 * x + 136 * i * x, dy + 0));
		bialyP[2 + 2 * i].setPos(sf::Vector2f(dx + 96 * x + 136 * i * x, dy + 0));
		bialyP[1 + 2 * i].setID(4 + 12 * i);
		bialyP[2 + 2 * i].setID(9 + 12 * i);
		bialyP[1 + 2 * i].setScale(sf::Vector2f(x, x));
		bialyP[2 + 2 * i].setScale(sf::Vector2f(x, x));
	}

	BialyL bialyL[15]; // wciecie z lewej
	bialyL[0].setPos(sf::Vector2f(19 + dx,0 + dy ));
	bialyL[0].setID(3);
	bialyL[0].setScale(sf::Vector2f(x, x));
	for (int i = 0; i < 7; i++) {
		bialyL[1 + 2 * i].setPos(sf::Vector2f(dx + 77 * x + 136 * i * x, dy + 0));
		bialyL[2 + 2 * i].setPos(sf::Vector2f(dx + 155 * x + 136 * i * x, dy + 0));
		bialyL[1 + 2 * i].setID(8 + 12 * i);
		bialyL[2 + 2 * i].setID(15 + 12 * i);
		bialyL[1 + 2 * i].setScale(sf::Vector2f(x, x));
		bialyL[2 + 2 * i].setScale(sf::Vector2f(x, x));
	}

	BialyLP bialyLP[21];
	for (int i = 0; i < 7; i++) {
		bialyLP[0 + 3 * i].setPos(sf::Vector2f(dx + 57 * x + 136 * i * x, dy + 0));
		bialyLP[1 + 3 * i].setPos(sf::Vector2f(dx + 115 * x + 136 * i * x, dy + 0));
		bialyLP[2 + 3 * i].setPos(sf::Vector2f(dx + 135 * x + 136 * i * x, dy + 0));
		bialyLP[0 + 3 * i].setID(6 + 12 * i);
		bialyLP[1 + 3 * i].setID(11 + 12 * i);
		bialyLP[2 + 3 * i].setID(13 + 12 * i);
		bialyLP[0 + 3 * i].setScale(sf::Vector2f(x, x));
		bialyLP[1 + 3 * i].setScale(sf::Vector2f(x, x));
		bialyLP[2 + 3 * i].setScale(sf::Vector2f(x, x));
	}

	
	
	sf::Texture Exit;
	Exit.loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\exit2.png");
	sf::Sprite exit;
	exit.setTexture(Exit);
	//exit.setScale(sf::Vector2f(0.5, 0.5));
	exit.setPosition(sf::Vector2f(1000,2));

	sf::Texture Extra;																// daft punk
	Extra.loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\extra.jpg");
	sf::Sprite extra;
	extra.setTexture(Extra);
	//exit.setScale(sf::Vector2f(0.5, 0.5));
	extra.setPosition(sf::Vector2f(900, 35));

	
	sf::Texture Title;
	Title.loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\title.png");
	sf::Sprite title;
	title.setTexture(Title);
	//title.setScale(sf::Vector2f(0.5, 0.5));
	title.setPosition(sf::Vector2f(5, 5));

	sf::Texture Tlo;															// tlo
	Tlo.loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\tlo.png");
	sf::Sprite tlo;
	tlo.setTexture(Tlo);
	
	sf::Texture Linia;
	Linia.loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\linia.png");
	sf::Sprite linia1,linia2;
	linia1.setTexture(Linia);
	linia2.setTexture(Linia);
	linia1.setPosition(sf::Vector2f(0, 130));
	linia2.setPosition(sf::Vector2f(0, 120));

	Check box_L[6],box_P[6];
	for (int i = 0; i < 6; i++)
	{
		box_L[i].setID(3 + 12 * i);
		box_L[i].setPosition(sf::Vector2f(200 + 27 * i, 90));

		box_P[i].setID(3 + 12 * i);
		box_P[i].setPosition(sf::Vector2f(700 + 27 * i, 90));
	}
	box_L[0].setTexture(box_L[0].checked);
	box_P[2].setTexture(box_P[2].checked);

	sf::Texture BoxL; // przykrywajka
	BoxL.loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\box_L.png");
	sf::Sprite boxL;
	boxL.setTexture(BoxL);

	int i = 3; // miejsce grajdla 3 - 15 - 27 - 39 - 51 - 63
	int j = 27;

	while (oknoAplikacji.isOpen())
	{

		sf::Event zdarzenie;
		while (oknoAplikacji.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::KeyPressed)
			{
				if (zdarzenie.key.code == sf::Keyboard::Escape) oknoAplikacji.close();

			
				if (zdarzenie.key.code == sf::Keyboard::Tab) {  sounds[i].play(); bialyP[1 + 2 * ((i-2) / 11)].setCol(sf::Color::Yellow);}  // gorna partia
				if (zdarzenie.key.code == sf::Keyboard::Num1) { sounds[i +1].play(); czarny[1 + 5 * ((i - 2) / 11)].setColor(sf::Color::Yellow);}
				if (zdarzenie.key.code == sf::Keyboard::Q) {  sounds[i + 2].play(); bialyLP[0 + 3 * ((i - 2) / 11)].setCol(sf::Color::Yellow);}
				if (zdarzenie.key.code == sf::Keyboard::Num2) {  sounds[i + 3].play(); czarny[2 + 5 * ((i - 2) / 11)].setColor(sf::Color::Yellow);}
				if (zdarzenie.key.code == sf::Keyboard::W) { sounds[i + 4].play(); bialyL[1 + 2 * ((i - 2) / 11)].setCol(sf::Color::Yellow);}
				if (zdarzenie.key.code == sf::Keyboard::E) {  sounds[i + 5].play(); bialyP[2 + 2 * ((i - 2) / 11)].setCol(sf::Color::Yellow);}
				if (zdarzenie.key.code == sf::Keyboard::Num4) { sounds[i + 6].play(); czarny[3 + 5 * ((i - 2) / 11)].setColor(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::R) {  sounds[i + 7].play(); bialyLP[1 + 3 * ((i - 2) / 11)].setCol(sf::Color::Yellow);}
				if (zdarzenie.key.code == sf::Keyboard::Num5) { sounds[i + 8].play(); czarny[4 + 5 * ((i - 2) / 11)].setColor(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::T) { sounds[i + 9].play(); bialyLP[2 + 3 * ((i - 2) / 11)].setCol(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::Num6) { sounds[i + 10].play(); czarny[5 + 5 * ((i - 2) / 11)].setColor(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::Y) {  sounds[i + 11].play(); bialyL[2 + 2 * ((i - 2) / 11)].setCol(sf::Color::Yellow);}
				if (zdarzenie.key.code == sf::Keyboard::U) {  sounds[i + 12].play(); bialyP[3 + 2 * ((i - 2) / 11)].setCol(sf::Color::Yellow);}
				if (zdarzenie.key.code == sf::Keyboard::Num8) { sounds[i + 13].play(); czarny[6 + 5 * ((i - 2) / 11)].setColor(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::I) { sounds[i + 14].play(); bialyLP[3 + 3 * ((i - 2) / 11)].setCol(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::Num9) { sounds[i + 15].play(); czarny[7 + 5 * ((i - 2) / 11)].setColor(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::O) {  sounds[i + 16].play(); bialyL[3 + 2 * ((i - 2) / 11)].setCol(sf::Color::Yellow);}
				if (zdarzenie.key.code == sf::Keyboard::P) { sounds[i + 17].play(); bialyP[4 + 2 * ((i - 2) / 11)].setCol(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::Dash) { sounds[i + 18].play(); czarny[8 + 5 * ((i - 2) / 11)].setColor(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::LBracket) { sounds[i + 19].play(); bialyLP[4 + 3 * ((i - 2) / 11)].setCol(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::Equal) { sounds[i + 20].play(); czarny[9 + 5 * ((i - 2) / 11)].setColor(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::RBracket) { sounds[i + 21].play(); bialyLP[5 + 3 * ((i - 2) / 11)].setCol(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::BackSpace) { sounds[i + 22].play(); czarny[10 + 5 * ((i - 2) / 11)].setColor(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::Return) { sounds[i + 23].play(); bialyL[4 + 2 * ((i - 2) / 11)].setCol(sf::Color::Yellow);}

				if (zdarzenie.key.code == sf::Keyboard::Unknown) { sounds[j].play(); bialyP[1 + 2 * ((j - 2) / 11)].setCol(sf::Color::Yellow); }  // dolna partia
				if (zdarzenie.key.code == sf::Keyboard::A) { sounds[j + 1].play(); czarny[1 + 5 * ((j - 2) / 11)].setColor(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::Z) { sounds[j + 2].play(); bialyLP[0 + 3 * ((j - 2) / 11)].setCol(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::S) { sounds[j + 3].play(); czarny[2 + 5 * ((j - 2) / 11)].setColor(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::X) { sounds[j + 4].play(); bialyL[1 + 2 * ((j - 2) / 11)].setCol(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::C) { sounds[j + 5].play(); bialyP[2 + 2 * ((j - 2) / 11)].setCol(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::F) { sounds[j + 6].play(); czarny[3 + 5 * ((j - 2) / 11)].setColor(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::V) { sounds[j + 7].play(); bialyLP[1 + 3 * ((j - 2) / 11)].setCol(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::G) { sounds[j + 8].play(); czarny[4 + 5 * ((j - 2) / 11)].setColor(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::B) { sounds[j + 9].play(); bialyLP[2 + 3 * ((j - 2) / 11)].setCol(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::H) { sounds[j + 10].play(); czarny[5 + 5 * ((j - 2) / 11)].setColor(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::N) { sounds[j + 11].play(); bialyL[2 + 2 * ((j - 2) / 11)].setCol(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::M) { sounds[j + 12].play(); bialyP[3 + 2 * ((j - 2) / 11)].setCol(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::K) { sounds[j + 13].play(); czarny[6 + 5 * ((j - 2) / 11)].setColor(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::Comma) { sounds[j + 14].play(); bialyLP[3 + 3 * ((j - 2) / 11)].setCol(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::L) { sounds[j + 15].play(); czarny[7 + 5 * ((j - 2) / 11)].setColor(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::Period) { sounds[j + 16].play(); bialyL[3 + 2 * ((j - 2) / 11)].setCol(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::Slash) { sounds[j + 17].play(); bialyP[4 + 2 * ((j - 2) / 11)].setCol(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::Quote) { sounds[j + 18].play(); czarny[8 + 5 * ((j - 2) / 11)].setColor(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::RShift) { sounds[j + 19].play(); bialyLP[4 + 3 * ((j - 2) / 11)].setCol(sf::Color::Yellow); }
				if (zdarzenie.key.code == sf::Keyboard::BackSlash) { sounds[j + 20].play(); czarny[9 + 5 * ((j - 2) / 11)].setColor(sf::Color::Yellow); }

			}
			if (zdarzenie.type == sf::Event::KeyReleased)
			{
				if (zdarzenie.key.code == sf::Keyboard::Tab) {  bialyP[1 + 2 * ((i - 2) / 11)].setCol(sf::Color::White); } // gorna partia
				if (zdarzenie.key.code == sf::Keyboard::Num1) {  czarny[1 + 5 * ((i - 2) / 11)].setColor(sf::Color::Black); }
				if (zdarzenie.key.code == sf::Keyboard::Q) {  bialyLP[0 + 3 * ((i - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::Num2) {  czarny[2 + 5 * ((i - 2) / 11)].setColor(sf::Color::Black); }
				if (zdarzenie.key.code == sf::Keyboard::W) {  bialyL[1 + 2 * ((i - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::E) {  bialyP[2 + 2 * ((i - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::Num4) {  czarny[3 + 5 * ((i - 2) / 11)].setColor(sf::Color::Black); }
				if (zdarzenie.key.code == sf::Keyboard::R) {  bialyLP[1 + 3 * ((i - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::Num5) {  czarny[4 + 5 * ((i - 2) / 11)].setColor(sf::Color::Black); }
				if (zdarzenie.key.code == sf::Keyboard::T) {  bialyLP[2 + 3 * ((i - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::Num6) {  czarny[5 + 5 * ((i - 2) / 11)].setColor(sf::Color::Black); }
				if (zdarzenie.key.code == sf::Keyboard::Y) {  bialyL[2 + 2 * ((i - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::U) {  bialyP[3 + 2 * ((i - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::Num8) {  czarny[6 + 5 * ((i - 2) / 11)].setColor(sf::Color::Black); }
				if (zdarzenie.key.code == sf::Keyboard::I) {  bialyLP[3 + 3 * ((i - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::Num9) {  czarny[7 + 5 * ((i - 2) / 11)].setColor(sf::Color::Black); }
				if (zdarzenie.key.code == sf::Keyboard::O) {  bialyL[3 + 2 * ((i - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::P) {  bialyP[4 + 2 * ((i - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::Dash) {  czarny[8 + 5 * ((i - 2) / 11)].setColor(sf::Color::Black); }
				if (zdarzenie.key.code == sf::Keyboard::LBracket) {  bialyLP[4 + 3 * ((i - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::Equal) {  czarny[9 + 5 * ((i - 2) / 11)].setColor(sf::Color::Black); }
				if (zdarzenie.key.code == sf::Keyboard::RBracket) {  bialyLP[5 + 3 * ((i - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::BackSpace) {  czarny[10 + 5 * ((i - 2) / 11)].setColor(sf::Color::Black); }
				if (zdarzenie.key.code == sf::Keyboard::Return) {  bialyL[4 + 2 * ((i - 2) / 11)].setCol(sf::Color::White); }

				if (zdarzenie.key.code == sf::Keyboard::Unknown) {  bialyP[1 + 2 * ((j - 2) / 11)].setCol(sf::Color::White); }  // dolna partia
				if (zdarzenie.key.code == sf::Keyboard::A) {  czarny[1 + 5 * ((j - 2) / 11)].setColor(sf::Color::Black); }
				if (zdarzenie.key.code == sf::Keyboard::Z) {  bialyLP[0 + 3 * ((j - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::S) {  czarny[2 + 5 * ((j - 2) / 11)].setColor(sf::Color::Black); }
				if (zdarzenie.key.code == sf::Keyboard::X) {  bialyL[1 + 2 * ((j - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::C) {  bialyP[2 + 2 * ((j - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::F) {  czarny[3 + 5 * ((j - 2) / 11)].setColor(sf::Color::Black); }
				if (zdarzenie.key.code == sf::Keyboard::V) {  bialyLP[1 + 3 * ((j - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::G) {  czarny[4 + 5 * ((j - 2) / 11)].setColor(sf::Color::Black); }
				if (zdarzenie.key.code == sf::Keyboard::B) {  bialyLP[2 + 3 * ((j - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::H) {  czarny[5 + 5 * ((j - 2) / 11)].setColor(sf::Color::Black); }
				if (zdarzenie.key.code == sf::Keyboard::N) {  bialyL[2 + 2 * ((j - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::M) {  bialyP[3 + 2 * ((j - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::K) {  czarny[6 + 5 * ((j - 2) / 11)].setColor(sf::Color::Black); }
				if (zdarzenie.key.code == sf::Keyboard::Comma) {  bialyLP[3 + 3 * ((j - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::L) {  czarny[7 + 5 * ((j - 2) / 11)].setColor(sf::Color::Black); }
				if (zdarzenie.key.code == sf::Keyboard::Period) {  bialyL[3 + 2 * ((j - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::Slash) {  bialyP[4 + 2 * ((j - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::Quote) {  czarny[8 + 5 * ((j - 2) / 11)].setColor(sf::Color::Black); }
				if (zdarzenie.key.code == sf::Keyboard::RShift) {  bialyLP[4 + 3 * ((j - 2) / 11)].setCol(sf::Color::White); }
				if (zdarzenie.key.code == sf::Keyboard::BackSlash) {  czarny[9 + 5 * ((j - 2) / 11)].setColor(sf::Color::Black); }
			}
			
			if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.key.code == sf::Mouse::Left)
			{
				if (czarny[0].IsSpiteClicked(oknoAplikacji, exit, zdarzenie) == true) oknoAplikacji.close();  // przycisk wyjscia - w czarnym jest dobra funkcja isspriteclicked
				if (czarny[0].IsSpiteClicked(oknoAplikacji, extra, zdarzenie) == true) daft_punk daft;

				if (czarny[0].IsSpiteClicked(oknoAplikacji, czarny[0], zdarzenie) == true) { sounds[czarny[0].getID() - 1].play(); czarny[0].setColor(sf::Color::Yellow); }
				if (czarny[1].IsSpiteClicked(oknoAplikacji, czarny[1], zdarzenie) == true) { sounds[czarny[1].getID() - 1].play(); czarny[1].setColor(sf::Color::Yellow); }
				if (czarny[2].IsSpiteClicked(oknoAplikacji, czarny[2], zdarzenie) == true) { sounds[czarny[2].getID() - 1].play(); czarny[2].setColor(sf::Color::Yellow); }
				if (czarny[3].IsSpiteClicked(oknoAplikacji, czarny[3], zdarzenie) == true) { sounds[czarny[3].getID() - 1].play(); czarny[3].setColor(sf::Color::Yellow); }
				if (czarny[4].IsSpiteClicked(oknoAplikacji, czarny[4], zdarzenie) == true) { sounds[czarny[4].getID() - 1].play(); czarny[4].setColor(sf::Color::Yellow); }
				if (czarny[5].IsSpiteClicked(oknoAplikacji, czarny[5], zdarzenie) == true) { sounds[czarny[5].getID() - 1].play(); czarny[5].setColor(sf::Color::Yellow); }
				if (czarny[6].IsSpiteClicked(oknoAplikacji, czarny[6], zdarzenie) == true) { sounds[czarny[6].getID() - 1].play(); czarny[6].setColor(sf::Color::Yellow); }
				if (czarny[7].IsSpiteClicked(oknoAplikacji, czarny[7], zdarzenie) == true) { sounds[czarny[7].getID() - 1].play(); czarny[7].setColor(sf::Color::Yellow); }
				if (czarny[8].IsSpiteClicked(oknoAplikacji, czarny[8], zdarzenie) == true) { sounds[czarny[8].getID() - 1].play(); czarny[8].setColor(sf::Color::Yellow); }
				if (czarny[9].IsSpiteClicked(oknoAplikacji, czarny[9], zdarzenie) == true) { sounds[czarny[9].getID() - 1].play(); czarny[9].setColor(sf::Color::Yellow); }
				if (czarny[10].IsSpiteClicked(oknoAplikacji, czarny[10], zdarzenie) == true) { sounds[czarny[10].getID() - 1].play(); czarny[10].setColor(sf::Color::Yellow); }
				if (czarny[11].IsSpiteClicked(oknoAplikacji, czarny[11], zdarzenie) == true) {sounds[czarny[11].getID() - 1].play(); czarny[11].setColor(sf::Color::Yellow);}
				if (czarny[12].IsSpiteClicked(oknoAplikacji, czarny[12], zdarzenie) == true) { sounds[czarny[12].getID() - 1].play(); czarny[12].setColor(sf::Color::Yellow); }
				if (czarny[13].IsSpiteClicked(oknoAplikacji, czarny[13], zdarzenie) == true) { sounds[czarny[13].getID() - 1].play(); czarny[13].setColor(sf::Color::Yellow); }
				if (czarny[14].IsSpiteClicked(oknoAplikacji, czarny[14], zdarzenie) == true) { sounds[czarny[14].getID() - 1].play(); czarny[14].setColor(sf::Color::Yellow); }
				if (czarny[15].IsSpiteClicked(oknoAplikacji, czarny[15], zdarzenie) == true) { sounds[czarny[15].getID() - 1].play(); czarny[15].setColor(sf::Color::Yellow); }
				if (czarny[16].IsSpiteClicked(oknoAplikacji, czarny[16], zdarzenie) == true) { sounds[czarny[16].getID() - 1].play(); czarny[16].setColor(sf::Color::Yellow); }
				if (czarny[17].IsSpiteClicked(oknoAplikacji, czarny[17], zdarzenie) == true) { sounds[czarny[17].getID() - 1].play(); czarny[17].setColor(sf::Color::Yellow); }
				if (czarny[18].IsSpiteClicked(oknoAplikacji, czarny[18], zdarzenie) == true) { sounds[czarny[18].getID() - 1].play(); czarny[18].setColor(sf::Color::Yellow); }
				if (czarny[19].IsSpiteClicked(oknoAplikacji, czarny[19], zdarzenie) == true) { sounds[czarny[19].getID() - 1].play(); czarny[19].setColor(sf::Color::Yellow); }
				if (czarny[20].IsSpiteClicked(oknoAplikacji, czarny[20], zdarzenie) == true) { sounds[czarny[20].getID() - 1].play(); czarny[20].setColor(sf::Color::Yellow); }
				if (czarny[21].IsSpiteClicked(oknoAplikacji, czarny[21], zdarzenie) == true) { sounds[czarny[21].getID() - 1].play(); czarny[21].setColor(sf::Color::Yellow); }
				if (czarny[22].IsSpiteClicked(oknoAplikacji, czarny[22], zdarzenie) == true) { sounds[czarny[22].getID() - 1].play(); czarny[22].setColor(sf::Color::Yellow); }
				if (czarny[23].IsSpiteClicked(oknoAplikacji, czarny[23], zdarzenie) == true) { sounds[czarny[23].getID() - 1].play(); czarny[23].setColor(sf::Color::Yellow); }
				if (czarny[24].IsSpiteClicked(oknoAplikacji, czarny[24], zdarzenie) == true) { sounds[czarny[24].getID() - 1].play(); czarny[24].setColor(sf::Color::Yellow); }
				if (czarny[25].IsSpiteClicked(oknoAplikacji, czarny[25], zdarzenie) == true) { sounds[czarny[25].getID() - 1].play(); czarny[25].setColor(sf::Color::Yellow); }
				if (czarny[26].IsSpiteClicked(oknoAplikacji, czarny[26], zdarzenie) == true) { sounds[czarny[26].getID() - 1].play(); czarny[26].setColor(sf::Color::Yellow); }
				if (czarny[27].IsSpiteClicked(oknoAplikacji, czarny[27], zdarzenie) == true) { sounds[czarny[27].getID() - 1].play(); czarny[27].setColor(sf::Color::Yellow); }
				if (czarny[28].IsSpiteClicked(oknoAplikacji, czarny[28], zdarzenie) == true) { sounds[czarny[28].getID() - 1].play(); czarny[28].setColor(sf::Color::Yellow); }
				if (czarny[29].IsSpiteClicked(oknoAplikacji, czarny[29], zdarzenie) == true) { sounds[czarny[29].getID() - 1].play(); czarny[29].setColor(sf::Color::Yellow); }
				if (czarny[30].IsSpiteClicked(oknoAplikacji, czarny[30], zdarzenie) == true) { sounds[czarny[30].getID() - 1].play(); czarny[30].setColor(sf::Color::Yellow); }
				if (czarny[31].IsSpiteClicked(oknoAplikacji, czarny[31], zdarzenie) == true) { sounds[czarny[31].getID() - 1].play(); czarny[31].setColor(sf::Color::Yellow); }
				if (czarny[32].IsSpiteClicked(oknoAplikacji, czarny[32], zdarzenie) == true) { sounds[czarny[32].getID() - 1].play(); czarny[32].setColor(sf::Color::Yellow); }
				if (czarny[33].IsSpiteClicked(oknoAplikacji, czarny[33], zdarzenie) == true) { sounds[czarny[33].getID() - 1].play(); czarny[33].setColor(sf::Color::Yellow); }
				if (czarny[34].IsSpiteClicked(oknoAplikacji, czarny[34], zdarzenie) == true) { sounds[czarny[34].getID() - 1].play(); czarny[34].setColor(sf::Color::Yellow); }
				if (czarny[35].IsSpiteClicked(oknoAplikacji, czarny[35], zdarzenie) == true) { sounds[czarny[35].getID() - 1].play(); czarny[35].setColor(sf::Color::Yellow); }


				if (bialyP[0].IsSpiteClicked(oknoAplikacji, bialyP[0], zdarzenie) == true) {sounds[bialyP[0].getID() - 1].play(); bialyP[0].setCol(sf::Color::Yellow); }
				if (bialyP[1].IsSpiteClicked(oknoAplikacji, bialyP[1], zdarzenie) == true) {sounds[bialyP[1].getID() - 1].play(); bialyP[1].setCol(sf::Color::Yellow); }
				if (bialyP[2].IsSpiteClicked(oknoAplikacji, bialyP[2], zdarzenie) == true) {sounds[bialyP[2].getID() - 1].play(); bialyP[2].setCol(sf::Color::Yellow); }
				if (bialyP[3].IsSpiteClicked(oknoAplikacji, bialyP[3], zdarzenie) == true) {sounds[bialyP[3].getID() - 1].play(); bialyP[3].setCol(sf::Color::Yellow); }
				if (bialyP[4].IsSpiteClicked(oknoAplikacji, bialyP[4], zdarzenie) == true) {sounds[bialyP[4].getID() - 1].play(); bialyP[4].setCol(sf::Color::Yellow); }
				if (bialyP[5].IsSpiteClicked(oknoAplikacji, bialyP[5], zdarzenie) == true) {sounds[bialyP[5].getID() - 1].play(); bialyP[5].setCol(sf::Color::Yellow); }
				if (bialyP[6].IsSpiteClicked(oknoAplikacji, bialyP[6], zdarzenie) == true) {sounds[bialyP[6].getID() - 1].play(); bialyP[6].setCol(sf::Color::Yellow); }
				if (bialyP[7].IsSpiteClicked(oknoAplikacji, bialyP[7], zdarzenie) == true) {sounds[bialyP[7].getID() - 1].play(); bialyP[7].setCol(sf::Color::Yellow); }
				if (bialyP[8].IsSpiteClicked(oknoAplikacji, bialyP[8], zdarzenie) == true) {sounds[bialyP[8].getID() - 1].play(); bialyP[8].setCol(sf::Color::Yellow); }
				if (bialyP[9].IsSpiteClicked(oknoAplikacji, bialyP[9], zdarzenie) == true) {sounds[bialyP[9].getID() - 1].play(); bialyP[9].setCol(sf::Color::Yellow); }
				if (bialyP[10].IsSpiteClicked(oknoAplikacji, bialyP[10], zdarzenie) == true) {sounds[bialyP[10].getID() - 1].play(); bialyP[10].setCol(sf::Color::Yellow); }
				if (bialyP[11].IsSpiteClicked(oknoAplikacji, bialyP[11], zdarzenie) == true) {sounds[bialyP[11].getID() - 1].play(); bialyP[11].setCol(sf::Color::Yellow); }
				if (bialyP[12].IsSpiteClicked(oknoAplikacji, bialyP[12], zdarzenie) == true) {sounds[bialyP[12].getID() - 1].play(); bialyP[12].setCol(sf::Color::Yellow); }
				if (bialyP[13].IsSpiteClicked(oknoAplikacji, bialyP[13], zdarzenie) == true) {sounds[bialyP[13].getID() - 1].play(); bialyP[13].setCol(sf::Color::Yellow); }
				if (bialyP[14].IsSpiteClicked(oknoAplikacji, bialyP[14], zdarzenie) == true) {sounds[bialyP[14].getID() - 1].play(); bialyP[14].setCol(sf::Color::Yellow); }

				if (bialyL[0].IsSpiteClicked(oknoAplikacji, bialyL[0], zdarzenie) == true) { sounds[bialyL[0].getID() - 1].play(); bialyL[0].setCol(sf::Color::Yellow); }
				if (bialyL[1].IsSpiteClicked(oknoAplikacji, bialyL[1], zdarzenie) == true) { sounds[bialyL[1].getID() - 1].play(); bialyL[1].setCol(sf::Color::Yellow); }
				if (bialyL[2].IsSpiteClicked(oknoAplikacji, bialyL[2], zdarzenie) == true) { sounds[bialyL[2].getID() - 1].play(); bialyL[2].setCol(sf::Color::Yellow); }
				if (bialyL[3].IsSpiteClicked(oknoAplikacji, bialyL[3], zdarzenie) == true) { sounds[bialyL[3].getID() - 1].play(); bialyL[3].setCol(sf::Color::Yellow); }
				if (bialyL[4].IsSpiteClicked(oknoAplikacji, bialyL[4], zdarzenie) == true) { sounds[bialyL[4].getID() - 1].play(); bialyL[4].setCol(sf::Color::Yellow); }
				if (bialyL[5].IsSpiteClicked(oknoAplikacji, bialyL[5], zdarzenie) == true) { sounds[bialyL[5].getID() - 1].play(); bialyL[5].setCol(sf::Color::Yellow); }
				if (bialyL[6].IsSpiteClicked(oknoAplikacji, bialyL[6], zdarzenie) == true) { sounds[bialyL[6].getID() - 1].play(); bialyL[6].setCol(sf::Color::Yellow); }
				if (bialyL[7].IsSpiteClicked(oknoAplikacji, bialyL[7], zdarzenie) == true) { sounds[bialyL[7].getID() - 1].play(); bialyL[7].setCol(sf::Color::Yellow); }
				if (bialyL[8].IsSpiteClicked(oknoAplikacji, bialyL[8], zdarzenie) == true) { sounds[bialyL[8].getID() - 1].play(); bialyL[8].setCol(sf::Color::Yellow); }
				if (bialyL[9].IsSpiteClicked(oknoAplikacji, bialyL[9], zdarzenie) == true) { sounds[bialyL[9].getID() - 1].play(); bialyL[9].setCol(sf::Color::Yellow); }
				if (bialyL[10].IsSpiteClicked(oknoAplikacji, bialyL[10], zdarzenie) == true) { sounds[bialyL[10].getID() - 1].play(); bialyL[10].setCol(sf::Color::Yellow); }
				if (bialyL[11].IsSpiteClicked(oknoAplikacji, bialyL[11], zdarzenie) == true) { sounds[bialyL[11].getID() - 1].play(); bialyL[11].setCol(sf::Color::Yellow); }
				if (bialyL[12].IsSpiteClicked(oknoAplikacji, bialyL[12], zdarzenie) == true) { sounds[bialyL[12].getID() - 1].play(); bialyL[12].setCol(sf::Color::Yellow); }
				if (bialyL[13].IsSpiteClicked(oknoAplikacji, bialyL[13], zdarzenie) == true) { sounds[bialyL[13].getID() - 1].play(); bialyL[13].setCol(sf::Color::Yellow); }
				if (bialyL[14].IsSpiteClicked(oknoAplikacji, bialyL[14], zdarzenie) == true) { sounds[bialyL[14].getID() - 1].play(); bialyL[14].setCol(sf::Color::Yellow); }

				if (bialyLP[0].IsSpiteClicked(oknoAplikacji, bialyLP[0], zdarzenie) == true) { sounds[bialyLP[0].getID() - 1].play(); bialyLP[0].setCol(sf::Color::Yellow); }
				if (bialyLP[1].IsSpiteClicked(oknoAplikacji, bialyLP[1], zdarzenie) == true) { sounds[bialyLP[1].getID() - 1].play(); bialyLP[1].setCol(sf::Color::Yellow); }
				if (bialyLP[2].IsSpiteClicked(oknoAplikacji, bialyLP[2], zdarzenie) == true) { sounds[bialyLP[2].getID() - 1].play(); bialyLP[2].setCol(sf::Color::Yellow); }
				if (bialyLP[3].IsSpiteClicked(oknoAplikacji, bialyLP[3], zdarzenie) == true) { sounds[bialyLP[3].getID() - 1].play(); bialyLP[3].setCol(sf::Color::Yellow); }
				if (bialyLP[4].IsSpiteClicked(oknoAplikacji, bialyLP[4], zdarzenie) == true) { sounds[bialyLP[4].getID() - 1].play(); bialyLP[4].setCol(sf::Color::Yellow); }
				if (bialyLP[5].IsSpiteClicked(oknoAplikacji, bialyLP[5], zdarzenie) == true) { sounds[bialyLP[5].getID() - 1].play(); bialyLP[5].setCol(sf::Color::Yellow); }
				if (bialyLP[6].IsSpiteClicked(oknoAplikacji, bialyLP[6], zdarzenie) == true) { sounds[bialyLP[6].getID() - 1].play(); bialyLP[6].setCol(sf::Color::Yellow); }
				if (bialyLP[7].IsSpiteClicked(oknoAplikacji, bialyLP[7], zdarzenie) == true) { sounds[bialyLP[7].getID() - 1].play(); bialyLP[7].setCol(sf::Color::Yellow); }
				if (bialyLP[8].IsSpiteClicked(oknoAplikacji, bialyLP[8], zdarzenie) == true) { sounds[bialyLP[8].getID() - 1].play(); bialyLP[8].setCol(sf::Color::Yellow); }
				if (bialyLP[9].IsSpiteClicked(oknoAplikacji, bialyLP[9], zdarzenie) == true) { sounds[bialyLP[9].getID() - 1].play(); bialyLP[9].setCol(sf::Color::Yellow); }
				if (bialyLP[10].IsSpiteClicked(oknoAplikacji, bialyLP[10], zdarzenie) == true) { sounds[bialyLP[10].getID() - 1].play(); bialyLP[10].setCol(sf::Color::Yellow); }
				if (bialyLP[11].IsSpiteClicked(oknoAplikacji, bialyLP[11], zdarzenie) == true) { sounds[bialyLP[11].getID() - 1].play(); bialyLP[11].setCol(sf::Color::Yellow); }
				if (bialyLP[12].IsSpiteClicked(oknoAplikacji, bialyLP[12], zdarzenie) == true) { sounds[bialyLP[12].getID() - 1].play(); bialyLP[12].setCol(sf::Color::Yellow); }
				if (bialyLP[13].IsSpiteClicked(oknoAplikacji, bialyLP[13], zdarzenie) == true) { sounds[bialyLP[13].getID() - 1].play(); bialyLP[13].setCol(sf::Color::Yellow); }
				if (bialyLP[14].IsSpiteClicked(oknoAplikacji, bialyLP[14], zdarzenie) == true) { sounds[bialyLP[14].getID() - 1].play(); bialyLP[14].setCol(sf::Color::Yellow); }
				if (bialyLP[15].IsSpiteClicked(oknoAplikacji, bialyLP[15], zdarzenie) == true) { sounds[bialyLP[15].getID() - 1].play(); bialyLP[15].setCol(sf::Color::Yellow); }
				if (bialyLP[16].IsSpiteClicked(oknoAplikacji, bialyLP[16], zdarzenie) == true) { sounds[bialyLP[16].getID() - 1].play(); bialyLP[16].setCol(sf::Color::Yellow); }
				if (bialyLP[17].IsSpiteClicked(oknoAplikacji, bialyLP[17], zdarzenie) == true) { sounds[bialyLP[17].getID() - 1].play(); bialyLP[17].setCol(sf::Color::Yellow); }
				if (bialyLP[18].IsSpiteClicked(oknoAplikacji, bialyLP[18], zdarzenie) == true) { sounds[bialyLP[18].getID() - 1].play(); bialyLP[18].setCol(sf::Color::Yellow); }
				if (bialyLP[19].IsSpiteClicked(oknoAplikacji, bialyLP[19], zdarzenie) == true) { sounds[bialyLP[19].getID() - 1].play(); bialyLP[19].setCol(sf::Color::Yellow); }
				if (bialyLP[20].IsSpiteClicked(oknoAplikacji, bialyLP[20], zdarzenie) == true) { sounds[bialyLP[20].getID() - 1].play(); bialyLP[20].setCol(sf::Color::Yellow); }

				if (box_L[0].IsSpiteClicked(oknoAplikacji, box_L[0], zdarzenie) == true) { i = box_L[0].getID(); for (int i = 0; i < 6; i++)box_L[i].setTexture(box_L[i].unchecked);  box_L[0].setTexture(box_L[0].checked); }
				if (box_L[1].IsSpiteClicked(oknoAplikacji, box_L[1], zdarzenie) == true) { i = box_L[1].getID(); for (int i = 0; i < 6; i++)box_L[i].setTexture(box_L[i].unchecked);  box_L[1].setTexture(box_L[1].checked);}
				if (box_L[2].IsSpiteClicked(oknoAplikacji, box_L[2], zdarzenie) == true) { i = box_L[2].getID(); for (int i = 0; i < 6; i++)box_L[i].setTexture(box_L[i].unchecked);  box_L[2].setTexture(box_L[2].checked);}
				if (box_L[3].IsSpiteClicked(oknoAplikacji, box_L[3], zdarzenie) == true) { i = box_L[3].getID(); for (int i = 0; i < 6; i++)box_L[i].setTexture(box_L[i].unchecked);  box_L[3].setTexture(box_L[3].checked);}
				if (box_L[4].IsSpiteClicked(oknoAplikacji, box_L[4], zdarzenie) == true) { i = box_L[4].getID(); for (int i = 0; i < 6; i++)box_L[i].setTexture(box_L[i].unchecked);  box_L[4].setTexture(box_L[4].checked);}
				if (box_L[5].IsSpiteClicked(oknoAplikacji, box_L[5], zdarzenie) == true) { i = box_L[5].getID(); for (int i = 0; i < 6; i++)box_L[i].setTexture(box_L[i].unchecked);  box_L[5].setTexture(box_L[5].checked);}

				if (box_P[0].IsSpiteClicked(oknoAplikacji, box_P[0], zdarzenie) == true) { j = box_P[0].getID(); for (int i = 0; i < 6; i++)box_P[i].setTexture(box_P[i].unchecked);  box_P[0].setTexture(box_P[0].checked);}
				if (box_P[1].IsSpiteClicked(oknoAplikacji, box_P[1], zdarzenie) == true) { j = box_P[1].getID(); for (int i = 0; i < 6; i++)box_P[i].setTexture(box_P[i].unchecked);  box_P[1].setTexture(box_P[1].checked);}
				if (box_P[2].IsSpiteClicked(oknoAplikacji, box_P[2], zdarzenie) == true) { j = box_P[2].getID(); for (int i = 0; i < 6; i++)box_P[i].setTexture(box_P[i].unchecked);  box_P[2].setTexture(box_P[2].checked);}
				if (box_P[3].IsSpiteClicked(oknoAplikacji, box_P[3], zdarzenie) == true) { j = box_P[3].getID(); for (int i = 0; i < 6; i++)box_P[i].setTexture(box_P[i].unchecked);  box_P[3].setTexture(box_P[3].checked);}
				if (box_P[4].IsSpiteClicked(oknoAplikacji, box_P[4], zdarzenie) == true) { j = box_P[4].getID(); for (int i = 0; i < 6; i++)box_P[i].setTexture(box_P[i].unchecked);  box_P[4].setTexture(box_P[4].checked);}
				if (box_P[5].IsSpiteClicked(oknoAplikacji, box_P[5], zdarzenie) == true) { j = box_P[5].getID(); for (int i = 0; i < 6; i++)box_P[i].setTexture(box_P[i].unchecked);  box_P[5].setTexture(box_P[5].checked);}

			}
			
			if (zdarzenie.type == sf::Event::MouseButtonReleased)
			{
				for (int i = 0; i < 15; i++) // przemalowuje calosc na normalny kolor
				{
					bialyP[i].setCol(sf::Color::White);
					bialyL[i].setCol(sf::Color::White);
				}
				for (int i = 0; i < 21; i++)
					bialyLP[i].setCol(sf::Color::White);
				for (int i = 0; i < 36; i++)
					czarny[i].setColor(sf::Color::Black);
			}

		} // koniec obslugi eventow

		oknoAplikacji.clear();
		oknoAplikacji.draw(tlo);

		for (int i = 0; i < 36; i++) oknoAplikacji.draw(czarny[i]); // klawiatura
		for (int i = 0; i < 15; i++) rysuj(oknoAplikacji,bialyP[i], bialyP[i].bok);
		for (int i = 0; i < 15; i++) rysuj(oknoAplikacji,bialyL[i], bialyL[i].bok);
		for (int i = 0; i < 21; i++) rysuj(oknoAplikacji,bialyLP[i], bialyLP[i].bok1, bialyLP[i].bok2);

		for (int i = 0; i < 6; i++) rysuj(oknoAplikacji, box_L[i], box_P[i]); // dodatkowe przyciski

																															// podswietlanie klawiatury
		if (box_L[0].IsSpriteCovered(oknoAplikacji, box_L[0]) == true || box_P[0].IsSpriteCovered(oknoAplikacji, box_P[0]) == true) {
			boxL.setPosition(sf::Vector2f(38 + dx, 0 + dy)); oknoAplikacji.draw(boxL); }
		if (box_L[1].IsSpriteCovered(oknoAplikacji, box_L[1]) == true || box_P[1].IsSpriteCovered(oknoAplikacji, box_P[1]) == true) {
			boxL.setPosition(sf::Vector2f(38 + 136 * 1 + dx, 0 + dy)); oknoAplikacji.draw(boxL);}
		if (box_L[2].IsSpriteCovered(oknoAplikacji, box_L[2]) == true || box_P[2].IsSpriteCovered(oknoAplikacji, box_P[2]) == true) {
			boxL.setPosition(sf::Vector2f(38 + 136 * 2 + dx, 0 + dy)); oknoAplikacji.draw(boxL);}
		if (box_L[3].IsSpriteCovered(oknoAplikacji, box_L[3]) == true || box_P[3].IsSpriteCovered(oknoAplikacji, box_P[3]) == true) {
			boxL.setPosition(sf::Vector2f(38 + 136 * 3 + dx, 0 + dy)); oknoAplikacji.draw(boxL);}
		if (box_L[4].IsSpriteCovered(oknoAplikacji, box_L[4]) == true || box_P[4].IsSpriteCovered(oknoAplikacji, box_P[4]) == true) {
			boxL.setPosition(sf::Vector2f(38 + 136 * 4 + dx, 0 + dy)); oknoAplikacji.draw(boxL);}
		if (box_L[5].IsSpriteCovered(oknoAplikacji, box_L[5]) == true || box_P[5].IsSpriteCovered(oknoAplikacji, box_P[5]) == true) {
			boxL.setPosition(sf::Vector2f(38 + 136 * 5 + dx, 0 + dy)); oknoAplikacji.draw(boxL);}
		if (box_L[0].IsSpriteCovered(oknoAplikacji, exit) == true) exit.setRotation(5); else exit.setRotation(0);  // maly ruch przycisku x
		if (box_L[0].IsSpriteCovered(oknoAplikacji, extra) == true) extra.setRotation(-5); else extra.setRotation(0);  // maly ruch przycisku daft punk

		oknoAplikacji.draw(linia1);
		oknoAplikacji.draw(linia2);
		oknoAplikacji.draw(title); // obrazek :)
		oknoAplikacji.draw(exit);
		oknoAplikacji.draw(extra); // daft punk
		oknoAplikacji.display();
	}
	std::cout << "koniec" << endl;

	Sleep(1000);



	return 0;
}


void rysuj( sf::RenderWindow & window ,const sf::Sprite & x)
{
	window.draw(x);
}
void rysuj(sf::RenderWindow & window, const sf::Sprite & x, const sf::Sprite & y)
{
	window.draw(x);
	window.draw(y);
}
void rysuj(sf::RenderWindow & window, const sf::Sprite & x, const sf::Sprite & y, const sf::Sprite & z)
{
	window.draw(x);
	window.draw(y);
	window.draw(z);
}
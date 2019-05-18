#include "daft_punk.h"



daft_punk::daft_punk()
{
	daft();
}


daft_punk::~daft_punk()
{
}

void daft_punk::daft()
{
	std::string sciezka;
	for (int i = 0; i < 16; i++)
	{
		sciezka = "C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\daft_punk\\" + std::to_string(i + 1) + ".wav";
		buf[i].loadFromFile(sciezka);
	}
	for (int i = 0; i < 16; i++)
		sound[i].setBuffer(buf[i]);

	textur[0].loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\daft_punk\\workit.png");
	textur[1].loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\daft_punk\\makeit.png");
	textur[2].loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\daft_punk\\doit.png");
	textur[3].loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\daft_punk\\makesus.png");
	textur[4].loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\daft_punk\\harder.png");
	textur[5].loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\daft_punk\\better.png");
	textur[6].loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\daft_punk\\faster.png");
	textur[7].loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\daft_punk\\stronger.png");
	textur[8].loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\daft_punk\\morethan.png");
	textur[9].loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\daft_punk\\hour.png");
	textur[10].loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\daft_punk\\our.png");
	textur[11].loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\daft_punk\\never.png");
	textur[12].loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\daft_punk\\ever.png");
	textur[13].loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\daft_punk\\after.png");
	textur[14].loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\daft_punk\\workis.png");
	textur[15].loadFromFile("C:\\Users\\Bhasillus\\Desktop\\projekt\\xD\\daft_punk\\over.png");

	for (int i = 0; i < 16; i++)
	{
		sprajt[i].setTexture(textur[i]);
		int j = i / 4;
		sprajt[i].setPosition(sf::Vector2f(0 + 76 * (i % 4), 0 + 76 * j));
	}
	
	sf::RenderWindow window(sf::VideoMode(304, 304, 32), "Daft Punk xD", sf::Style::None);
	while (window.isOpen())
	{
		
		sf::Event zdarzenie;
		while (window.pollEvent(zdarzenie))
		{
			if (zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape) window.close();
			
			for (int i = 0; i < 16; i++)
			{
				if (IsSpiteClicked(window, sprajt[i], zdarzenie) == true)
					sound[i].play();
			}
		}
		
		window.clear();

		for(int i=0;i<16;i++)
			window.draw(sprajt[i]);
		
		window.display();
	}
}

bool daft_punk::IsSpiteClicked(sf::RenderWindow & x, sf::Sprite y, sf::Event zdarzenie)
{
	sf::Vector2f mouse(sf::Mouse::getPosition(x));
	if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.key.code == sf::Mouse::Left && y.getGlobalBounds().contains(mouse))
		return true;
	else
	return false;
}

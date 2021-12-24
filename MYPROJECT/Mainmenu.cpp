#include "Mainmenu.h"

Mainmenu::Mainmenu(float width, float hight)
{

	//sf::Texture backGroUnd;

	//if (backGroUnd.loadFromFile("data/Mainmenu.JPEG") == 0) {
	//	
	//}
	//sf::RenderWindow window1(sf::VideoMode(1200, 600), "Mahmoud'S Game");
	//sf::RectangleShape rectangle(sf::Vector2f(1200, 600));
	//rectangle.setPosition(0, 0);
	//rectangle.setTexture(&backGroUnd);

	if (fonty.loadFromFile("data/ITCEDSCR.ttf") == false) {

		//Handel error
	}


	menu[0].setFont(fonty);
	menu[0].setCharacterSize(50);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString(" New Game ");
	menu[0].setPosition(sf::Vector2f(800, 280));


	menu[1].setFont(fonty);
	menu[1].setCharacterSize(45);
	menu[1].setFillColor(sf::Color::Black);
	menu[1].setString("Instructions");
	menu[1].setPosition(sf::Vector2f(815, 340));


	menu[2].setFont(fonty);
	menu[2].setCharacterSize(45);
	menu[2].setFillColor(sf::Color::Black);
	menu[2].setString(" Options ");
	menu[2].setPosition(sf::Vector2f(825, 400));

	menu[3].setFont(fonty);
	menu[3].setCharacterSize(45);
	menu[3].setFillColor(sf::Color::Black);
	menu[3].setString(" HighScore ");
	menu[3].setPosition(sf::Vector2f(810, 460));

	menu[4].setFont(fonty);
	menu[4].setCharacterSize(45);
	menu[4].setFillColor(sf::Color::Black);
	menu[4].setString(" Quite ");
	menu[4].setPosition(sf::Vector2f(825, 520));

	selected_Item_Index = 0;

}



Mainmenu::~Mainmenu()
{
}

void Mainmenu::draw(sf::RenderWindow &window1)
{
	for (int i = 0; i < Max_Number_items; i++) {
		window1.draw(menu[i]);

	}
}

void Mainmenu::Moveup()
{
	if (selected_Item_Index - 1 >= 0) {

		menu[selected_Item_Index].setFillColor(sf::Color::Black);
		selected_Item_Index--;
		menu[selected_Item_Index].setFillColor(sf::Color::Red);


	}

}

void Mainmenu::Movedown()
{
	if (selected_Item_Index + 1 < Max_Number_items) {

		menu[selected_Item_Index].setFillColor(sf::Color::Black);
		selected_Item_Index++;
		menu[selected_Item_Index].setFillColor(sf::Color::Red);
	}

}

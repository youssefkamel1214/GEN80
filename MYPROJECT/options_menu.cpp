#include "options_menu.h"



options_menu::options_menu(float width, float hight)
{
	if (!fonty.loadFromFile("data/ITCEDSCR.ttf")) {

		//Handel error
	}
	menuu[0].setFont(fonty);
	menuu[0].setCharacterSize(45);
	menuu[0].setFillColor(sf::Color::Blue);
	menuu[0].setString("Game options");
	menuu[0].setPosition(sf::Vector2f(810, 310));

	menuu[1].setFont(fonty);
	menuu[1].setCharacterSize(45);
	menuu[1].setFillColor(sf::Color::Black);
	menuu[1].setString("Sound options");
	menuu[1].setPosition(sf::Vector2f(810, 390));

	menuu[2].setFont(fonty);
	menuu[2].setCharacterSize(45);
	menuu[2].setFillColor(sf::Color::Black);
	menuu[2].setString("Back");
	menuu[2].setPosition(sf::Vector2f(870, 460));


	selected_Item_Index2 = 0;
}


options_menu::~options_menu()
{}
void options_menu::draw(sf::RenderWindow&window3)
{
	for (int i = 0; i < Max_Number_items; i++) {
		window3.draw(menuu[i]);

	}
}

void options_menu::Moveup2()
{
	if (selected_Item_Index2 - 1 >= 0) {

		menuu[selected_Item_Index2].setFillColor(sf::Color::Black);
		selected_Item_Index2--;
		menuu[selected_Item_Index2].setFillColor(sf::Color::Blue);


	}

}

void options_menu::Movedown2()
{
	if (selected_Item_Index2 + 1 < Max_Number_items) {

		menuu[selected_Item_Index2].setFillColor(sf::Color::Black);
		selected_Item_Index2++;
		menuu[selected_Item_Index2].setFillColor(sf::Color::Blue);
	}

}

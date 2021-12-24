#include "menu_gameoption.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

menu_gameoption::menu_gameoption(float width, float height)
{
	if (!fonty.loadFromFile("data/ITCEDSCR.ttf"))
	{
		// handle error
	}


	mainmenu_gameoption[0].setFont(fonty);
	mainmenu_gameoption[0].setCharacterSize(60);
	mainmenu_gameoption[0].setFillColor(sf::Color::Red);
	mainmenu_gameoption[0].setString("Character :");
	mainmenu_gameoption[0].setPosition(sf::Vector2f(760, 315));



	mainmenu_gameoption[1].setFont(fonty);
	mainmenu_gameoption[1].setCharacterSize(60);
	mainmenu_gameoption[1].setFillColor(sf::Color::Black);
	mainmenu_gameoption[1].setString("Block :");
	mainmenu_gameoption[1].setPosition(sf::Vector2f(760, 382));



	mainmenu_gameoption[2].setFont(fonty);
	mainmenu_gameoption[2].setCharacterSize(50);
	mainmenu_gameoption[2].setFillColor(sf::Color::Black);
	mainmenu_gameoption[2].setString("Back");
	mainmenu_gameoption[2].setPosition(sf::Vector2f(760, 455));
	menu_gameoptionSelected = 0;
}



menu_gameoption::~menu_gameoption()
{
}
//function of drawing main menu

void menu_gameoption::draw(sf::RenderWindow &window_gameoption)
{
	for (int i = 0; i < 3; i++)
	{
		window_gameoption.draw(mainmenu_gameoption[i]);
	}
}

//move down
void menu_gameoption::moveDown1()
{
	if (menu_gameoptionSelected + 1 <= Max_main_menu_gameoption)//check if not on the test item(exist)
	{
		mainmenu_gameoption[menu_gameoptionSelected].setFillColor(sf::Color::Black);
		menu_gameoptionSelected++;  //move to the lower items
		mainmenu_gameoption[menu_gameoptionSelected].setFillColor(sf::Color::Red);
	}



}



void menu_gameoption::moveUp1()
{
	if (menu_gameoptionSelected - 1 >= -1)//check if not on the first item(play)
	{
		mainmenu_gameoption[menu_gameoptionSelected].setFillColor(sf::Color::Black);
		menu_gameoptionSelected--;  //move to the lower items
		mainmenu_gameoption[menu_gameoptionSelected].setFillColor(sf::Color::Red); //change the new item color
	}



}
#include "SoundMenu.h"



SoundMenu::SoundMenu(float width, float hight)
{
	if (!fonty.loadFromFile("data/ITCEDSCR1.ttf")) {

		//Handel error
	}
	menuu[0].setFont(fonty);
	menuu[0].setCharacterSize(40);
	menuu[0].setFillColor(sf::Color::Red);
	menuu[0].setString("Sound : ");
	menuu[0].setPosition(sf::Vector2f(760, 330));

	menuu[1].setFont(fonty);
	menuu[1].setCharacterSize(40);
	menuu[1].setFillColor(sf::Color::Black);
	menuu[1].setString("Music : ");
	menuu[1].setPosition(sf::Vector2f(760, 400));


	menuu[2].setFont(fonty);
	menuu[2].setCharacterSize(35);
	menuu[2].setFillColor(sf::Color::Black);
	menuu[2].setString(" Back ");
	menuu[2].setPosition(sf::Vector2f(760, 470));

	selected_Item_Index3 = 0;
}


SoundMenu::~SoundMenu()
{}
void SoundMenu::draw(sf::RenderWindow&window_sound)
{
	for (int i = 0; i < Max_Number_items; i++) {
		window_sound.draw(menuu[i]);

	}
}

void SoundMenu::Moveup3()
{
	if (selected_Item_Index3 - 1 >= 0) {

		menuu[selected_Item_Index3].setFillColor(sf::Color::Black);
		selected_Item_Index3--;
		menuu[selected_Item_Index3].setFillColor(sf::Color::Red);


	}

}

void SoundMenu::Movedown3()
{
	if (selected_Item_Index3 + 1 < Max_Number_items) {

		menuu[selected_Item_Index3].setFillColor(sf::Color::Black);
		selected_Item_Index3++;
		menuu[selected_Item_Index3].setFillColor(sf::Color::Red);
	}

}


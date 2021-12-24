#pragma once
#include<SFML/Graphics.hpp>
#define Max_Number_items 4
class options_menu
{
public:
	options_menu(float width, float hight);

	void draw(sf::RenderWindow &window);
	void Moveup2();
	void Movedown2();
	int GetItem() {
		return selected_Item_Index2;
	}



	~options_menu();



private:
	int selected_Item_Index2;
	sf::Font fonty;
	sf::Text menuu[Max_Number_items];

};


#pragma once
#include<SFML/Graphics.hpp>
#define Max_Number_items 3
class SoundMenu
{
public:
	SoundMenu(float width, float hight);
	void draw(sf::RenderWindow &window_sound);
	void Moveup3();
	void Movedown3();
	int GetItem() {
		return selected_Item_Index3;
	}






	~SoundMenu();


private:
	int selected_Item_Index3;
	sf::Font fonty;
	sf::Text menuu[Max_Number_items];

};


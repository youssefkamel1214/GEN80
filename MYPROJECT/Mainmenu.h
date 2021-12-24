#pragma once
#include<SFML/Graphics.hpp>
#define Max_Number_items 5
class Mainmenu
{
public:

	Mainmenu(float width, float hight);


	void draw(sf::RenderWindow &window1);
	void Moveup();
	void Movedown();
	int GetSelectedItem() {
		return selected_Item_Index;
	}
	~Mainmenu();
private:
	int selected_Item_Index;
	sf::Font fonty;
	sf::Text menu[Max_Number_items];
	sf::RectangleShape background;
	sf::Texture photo;
};

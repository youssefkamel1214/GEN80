#include<SFML/Graphics.hpp>
#define Max_main_menu_gameoption 3
using namespace std;
using namespace sf;
class menu_gameoption
{
public:
	menu_gameoption(float width, float height);

	void draw(sf::RenderWindow &window_gameoption);
	void moveUp1();
	void moveDown1();

	int menu_gameoptionPressed()
	{
		return menu_gameoptionSelected;
	}
	~menu_gameoption();
private:
	int menu_gameoptionSelected;
	sf::Font fonty;
	sf::Text mainmenu_gameoption[Max_main_menu_gameoption];
	RectangleShape background;
	Texture photo;
};
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<fstream>
#include<cmath>
#include<sstream>
#include"Mainmenu.h"
#include"options_menu.h"
#include"SoundMenu.h"
#include "menu_gameoption.h"
#include<map>
#include<vector>
#include<string>
#define rectangels 10
using namespace std;
using namespace sf;

int main()
{
	vector <  pair<int, String> >vecx;
	bool Left = false;
	bool enter = 0;
	bool escape = 0;
	int pagenumber = 0;
	int page_number = 0; // for properties inside a class
	int pp = 0, glong = 1, musx, musy;// by7fzo el music

//------------------------------------------------------------------------------------------------------------------------
	//leaderboards
	ifstream infile, hisfile;
	infile.open("data/ops.txt");
	//taking inputs
	infile >> pp >> glong >> musx >> musy;
	infile.close();

	//----------------------------------------------------------------------------------------------------------------------------

	hisfile.open("data/his.txt");
	string jx;
	int j;
	while (!hisfile.eof()) // t2ara el file le a5ro
	{
		hisfile >> jx >> j;
		vecx.push_back(make_pair(j, jx));
	}
	hisfile.close();

	//----------------------------------------------------------------------------------------------------------------------------


		//MAIN GAME SOUND

	sf::Music music, show;
	if (music.openFromFile("data/music2.ogg") == false) {
		cout << "Music Wasn't loaded" << endl;
		return 0;
	}
	music.setVolume(musy);
	music.play();
	music.setLoop(true);
	show.setVolume(musx);

	auto newpos = music.getPlayingOffset();
	music.setPlayingOffset(newpos);
	sf::SoundBuffer buffy;
	if (buffy.loadFromFile("data/5osh.wav") == false) {
		cout << "sound didnot attend" << endl;
	}
	sf::Sound Tom;
	Tom.setBuffer(buffy);
	Tom.setVolume(musx);

	// sound of up and down
	sf::SoundBuffer Up_and_down;
	if (Up_and_down.loadFromFile("data/up and down.wav") == false) {
		cout << "bla bla bla" << endl;
	}
	sf::Sound upndown;
	upndown.setBuffer(Up_and_down);
	upndown.setVolume(musx);
	while (true) {

		//Creation
		sf::RenderWindow window1(sf::VideoMode(1200, 600), "Mahmoud'S Game");
		window1.setFramerateLimit(60);
		Mainmenu menu(window1.getSize().x, window1.getSize().y);
		sf::RectangleShape recc;
		recc.setSize(sf::Vector2f(1200, 600));
		sf::Texture MainPhoto;
		if (MainPhoto.loadFromFile("data/background.png") == false) {
			cout << "failuer" << endl;
		}
		recc.setTexture(&MainPhoto);


		while (window1.isOpen())
		{



			//Events for the game
			sf::Event event;



			while (window1.pollEvent(event)) {

				if (event.type == sf::Event::Closed) {
					return 0;

				}

				if (event.type == sf::Event::KeyPressed &&event.key.code == sf::Keyboard::Up) {
					menu.Moveup();
					upndown.play();
				}
				if (event.type == sf::Event::KeyPressed &&event.key.code == sf::Keyboard::Down) {
					menu.Movedown();
					upndown.play();
				}
				if (event.type == sf::Event::KeyPressed &&event.key.code == sf::Keyboard::Return) {
					menu.GetSelectedItem();
					if (menu.GetSelectedItem() == 0) {
						music.openFromFile("data/end.wav");
						music.play();
						music.setLoop(true);


						cout << "playButton has been Pressed" << endl;
						window1.close();
						Tom.play();
						pagenumber = 0;
					}

					if (menu.GetSelectedItem() == 1) {
						Tom.play();
						cout << "Instructions" << endl;
						window1.close();
						pagenumber = 1;
					}

					if (menu.GetSelectedItem() == 2) {
						Tom.play();
						cout << "Options" << endl;
						window1.close();
						pagenumber = 2;
					}

					if (menu.GetSelectedItem() == 3) {
						Tom.play();
						cout << "high Score" << endl;
						window1.close();
						pagenumber = 3;
					}

					if (menu.GetSelectedItem() == 4) {
						Tom.play();
						cout << "Quite" << endl;
						window1.close();
						pagenumber = 4;
					}
				}


			}
			//Rendering
			window1.clear();

			//draw
			window1.draw(recc);
			menu.draw(window1);

			window1.display();

		}

		//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		if (pagenumber == 0) // STARTING THE GAME :D
		{

			bool ingame = 1, esp = 0, changex = false; //game bda2t
			string test2;//ba5od asm user
			int indx = -1;//tartib el leaderboard

			RenderWindow window(sf::VideoMode(1200, 600), "SFML Game");

			//Settign the framerate limit to 60 FPS

			window.setFramerateLimit(60);

			window.setKeyRepeatEnabled(false);

			//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

						//the game varibals
			bool leftButton = false, rightButton = false, upButton = false, SpaceButton = false,
				fa = true, // falling
				play = true,
				rendertest = 0, // low 3ada 50
				rotation = 0,  //bdayt 7arkt el dwran
				logfallright = 0,
				logfallleft = 0,
				rotatz = 0; //yfadal ylef l7ad ma ynzle 3la ard

			float xVelocity = 0, yVelocity = 0,
				zv = 0.4, //SPEED OF NORMAL RENDERING OF BLOCKS
				Gravityjump = 0.65,
				GravityFall = 0.7,
				xi = 0,
				delx = 0,
				counter2 = 0,
				bf = 0; // barfill

			int y[6] = { 0,1,2,3,4,5 }, Score = 0, counter = 0, combos = 0, prs = 0, index10 = 0, counter3 = 0, maximumcombos = 0, timer1 = 0, timer2 = 0;
			map<int, int> mp;
			Event event;


			Font font;
			if (font.loadFromFile("data/JOKERMAN.ttf") == 0)
			{
				//failed
			}

			//Text msg
			Text score;
			score.setFont(font);
			score.setCharacterSize(40);
			score.setPosition(160, 540);
			score.setFillColor(Color::White);

			Text Combos;
			Combos.setFont(font);
			Combos.setCharacterSize(30);
			Combos.setPosition(15, 260);
			Combos.setFillColor(Color::White);
			Text Combosshow;
			Combosshow.setFont(font);
			Combosshow.setCharacterSize(80);
			Combosshow.setPosition(550, 275);
			Combosshow.setFillColor(Color::Green);

			Text Score10s;
			Score10s.setFont(font);
			Score10s.setFillColor(Color::White);
			Score10s.setCharacterSize(20);

			Text timer;
			timer.setFont(font);
			timer.setPosition(1100, 545);
			timer.setFillColor(Color::White);
			timer.setCharacterSize(40);

			//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

			//Shapes
			RectangleShape wall, bar, bfill, z, x[6], w1, w2, scour10s;

			//textures

			//back wall
			Texture walltext;

			//left wall
			Texture wallleft;

			// Right wall
			Texture wallright;

			//BLOCKS
			Texture darg;

			if (glong == 1)
			{
				darg.loadFromFile("data/long2.png");
				wallleft.loadFromFile("data/left1.png");
				w1.setTexture(&wallleft);
				wallright.loadFromFile("data/right1.png");
				w2.setTexture(&wallright);
				walltext.loadFromFile("data/wall2.png");
				wall.setTexture(&walltext);

				// ice
			}
			else
			{
				darg.loadFromFile("data/long.png");
				wallleft.loadFromFile("data/left.png");
				w1.setTexture(&wallleft);
				wallright.loadFromFile("data/right.png");
				w2.setTexture(&wallright);
				walltext.loadFromFile("data/wall.png");
				wall.setTexture(&walltext);

				// wood
			}

			for (int i = 0; i <= 5; i++)
			{
				x[i].setTexture(&darg);
			}
			//player
			Texture playtext;
			playtext.loadFromFile("data/animation1.png");
			sf::Vector2u textureSize = playtext.getSize();
			textureSize.x /= 15;
			textureSize.y /= 4;
			z.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y * pp, textureSize.x, textureSize.y));

			//score10s
			Texture Rectangle;
			Rectangle.loadFromFile("data/image2.png"); //moraba3 so3'yar
			scour10s.setTexture(&Rectangle);

			Texture barr;
			barr.loadFromFile("data/bar.png");
			bar.setTexture(&barr);


			//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

						//The Game Starts
			while (ingame)
			{
				if (esp == false || z.getPosition().y >= 650) {
					rightButton = 0;
					SpaceButton = 0;
					leftButton = 0;
					changex = 0;
					timer1 = 0;
					timer2 = 0;
					upButton = 0;
					esp = 0;
					Score = 0;
					bf = 0;
					counter2 = 0;
					counter = 0;
					zv = 0.4;
					rendertest = 0;
					prs = 0;
					indx = -1;
					test2 = "";
					for (int i = 0; i < 6; i++)
						y[i] = i;
					//---------------------------------------
					buffy.loadFromFile("data/game start.wav");
					Tom.setBuffer(buffy);
					Tom.setVolume(upndown.getVolume());
					Tom.play();
					music.openFromFile("data/bum.ogg");
					music.play();
					music.setLoop(true);
					//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

										// to give a random values every time
					srand(time(0));

					//Sizes

					//wall
					wall.setSize(Vector2f(1200, 600));
					wall.setOrigin(600, 300);
					wall.setPosition(600, 300);

					//bar
					bar.setSize(Vector2f(500, 450));
					bar.setOrigin(Vector2f(250, 225));
					bar.setPosition(55, 150);

					//bar fill
					bfill.setPosition(61, 226);
					bfill.setFillColor(Color::Red);


					//player size
					z.setSize(Vector2f(55, 80));
					z.setPosition(300, 530);
					z.setOrigin(55, 80);
					z.setTexture(&playtext);
					xi = z.getPosition().x;

					// every 10 logs Rectangle count
					//RectangleShape scour10s;
					scour10s.setSize(Vector2f(70, 45));
					scour10s.setOrigin(35, 25);
					scour10s.setPosition(1300, 650);

					//BLOCKS SHAPES
					// FIRST BLOCK
					x[0].setSize(Vector2f(1000, 55));
					x[0].setOrigin(500, 55);
					x[0].setPosition(600, 600);

					//RectangleShape x[6];
					// THE REST OF BLOCKS
					for (int i = 1; i <= 5; i++)
					{
						float  random = rand() % 201 + 150; //Size

						x[i].setSize(sf::Vector2f(random, 55));
						x[i].setOrigin(random / 2, 55);
						x[i].setPosition(rand() % 501 + 350, x[i - 1].getPosition().y - 105);
					}


					//WALLS SHAPE

					//FIRST WALL
					w1.setSize(Vector2f(150, 600));
					w1.setPosition(75, 300);
					w1.setOrigin(75, 300);
					w1.setTexture(&wallleft);

					//SECOND WALL
					w2.setSize(Vector2f(150, 600));
					w2.setPosition(1125, 300);
					w2.setOrigin(75, 300);
				}
				else if (esp)
				{
					play = 1;
					esp = false;
				}


				//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

											//Game loop

				while (play == true && z.getPosition().y <= 660)
				{
					srand(time(0));

					//EVENTS
					while (window.pollEvent(event))
					{
						//Event type is window closed

						if (event.type == Event::Closed)
						{
							return 0;     //Set play to false in order to stop the game loop
						}
						//----------------------------------------------------------------------------------------------------------------------------------------------------------------------

												// THE KEYS WE USE IN GAME

												// IF THE KEY PRESSED
						if (event.type == Event::KeyPressed)
						{
							if (event.key.code == Keyboard::Left)
							{
								leftButton = true;
								xi = z.getPosition().x;
							}
							if (event.key.code == Keyboard::Right)
							{
								rightButton = true;
								xi = z.getPosition().x;
							}
							if (event.key.code == Keyboard::Up)
							{
								upButton = true;
							}
							if (event.key.code == Keyboard::Space)
							{
								SpaceButton = true;
							}
						}

						//IF THE KEY RELEASED
						if (event.type == Event::KeyReleased)
						{
							if (event.key.code == Keyboard::Left)
							{
								leftButton = false;
								xi = z.getPosition().x;
							}
							if (event.key.code == Keyboard::Right)
							{
								rightButton = false;
								xi = z.getPosition().x;
							}
							if (event.key.code == Keyboard::Up)
							{
								upButton = false;
							}
							if (event.key.code == Keyboard::Space)
							{
								SpaceButton = false;
							}
							if (event.key.code == Keyboard::Escape)
							{
								esp = 1;
								play = false;
							}
						}
					}
					//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
										//MOVEMENT
										//Movement on X axis
					if (rightButton == true)
					{
						if (fa == true)
						{
							xVelocity = 13;
						}
						else
						{
							xVelocity = 7;
						}
					}
					if (leftButton == true)
					{
						if (fa == true)
						{
							xVelocity = -13;
						}
						else
						{
							xVelocity = -7;
						}
					}


					//CALCULATING DELTA X;
					if (fa == false && SpaceButton == true)
					{
						buffy.loadFromFile("data/jump1.wav");
						delx = abs(z.getPosition().x - xi);
						if (delx >= 300)
						{
							buffy.loadFromFile("data/jump2.wav");
							rotatz = 1;
						}
						if (delx >= 600)
						{

							delx = 600;
						}if (delx >= 400)
						{
							buffy.loadFromFile("data/jump3.wav");

						}
						Tom.setBuffer(buffy);
						Tom.play();
					}

					//Stopping horizontal movement if both buttons are pressed or released
					if (leftButton == true && rightButton == true)
					{
						xVelocity = 0;
					}
					if (leftButton == false && rightButton == false)
					{
						xVelocity = 0;
					}

					//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

										//Movement on y axis
					if (upButton == true)
					{
						yVelocity = -6;
						rotatz = 1;
					}



					//IF CHARACTER IS FALLING
					if (fa == true)

					{
						if (yVelocity < 0)
						{
							yVelocity += Gravityjump; //DECREASE THE SPEED IN AIR
						}
						else
						{
							yVelocity += GravityFall; //INCREASE THE SPEED OF FALLING
						}
					}

					//IF CHARACTER ON BLOCK AND I PRESS SPACE
					//CALCULATING THE Y-VELOCITY
					else if (fa == false && SpaceButton == true)
					{
						yVelocity = -float((1 + abs(delx / 180)));
						yVelocity = -sqrt(-yVelocity * 100 * 2 * Gravityjump);

					}

					//Return IT TO ZERO WHEN IT STANDSSTILL
					else
					{
						yVelocity = 0;
					}

					//EL BUG MO2RAF
					if (yVelocity < 0 && (z.getPosition().y) <= 180)
					{
						for (int i = 0; i <= 5; i++)
						{
							x[i].move(0, -yVelocity + zv); // blocks
						}
						if ((z.getPosition().y) >= 50)
						{
							z.move(0, yVelocity * 0.08);
						}
					}

					//BLOCKS MOVE WITH RENDERSPEED ZV
					else
					{
						z.move(0, yVelocity);

						if (rendertest == true)
						{
							for (int i = 0; i <= 5; i++)
							{
								x[i].move(0, zv);
							}
							z.move(0, zv);
						}
					}
					// to not stop rendering after score 50
					if (Score >= 50)
					{
						rendertest = 1;
					}

					z.move(xVelocity, 0);  //Move the shape on X axis by adding the velocity

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

					//collision
					for (int i = 0; i <= 5; i++)
					{
						if (x[i].getPosition().y - 35 >= z.getPosition().y)
						{       //First part
							if ((z.getGlobalBounds().intersects(x[i].getGlobalBounds()) == true &&
								(yVelocity >= 0) &&
								//2nd part
								(!(x[i].getPosition().x + (x[i].getSize().x / 2) + 14 < z.getPosition().x
									&& x[i].getPosition().x + (x[i].getSize().x / 2) + 45 > z.getPosition().x)) && // interval men right w left
									//3rd part
									(!(x[i].getPosition().x - (x[i].getSize().x / 2) + 20 > z.getPosition().x &&
										x[i].getPosition().x - (x[i].getSize().x / 2) < z.getPosition().x)) // interval men right w left
								)) // end of condition
								//We check if shape1 intersects shape2

							{
								// previous score
								if (!(prs == y[i]))
								{
									if (y[i] <= prs + 1)
									{
										bf = 0; //BarFill
									}
									else {
										if (bf <= 0)
										{
											bf = 150;
										}
										else
										{
											bf += 25 * (y[i] - prs - 1);
										}

										combos += y[i] - prs;
									}

									prs = y[i];
								}
								z.setPosition(z.getPosition().x, x[i].getPosition().y - 55);
								Score = y[i] * 10;
								rotatz = 0;
								fa = 0;

								//log fall
								if (x[i].getPosition().x + (x[i].getSize().x / 2) + 3 <= z.getPosition().x
									&&
									x[i].getPosition().x + (x[i].getSize().x / 2) + 14 >= z.getPosition().x)
								{
									logfallright = 1;
								}

								else if (x[i].getPosition().x - (x[i].getSize().x / 2) + 15 <= z.getPosition().x
									&&
									x[i].getPosition().x - (x[i].getSize().x / 2) + 39 >= z.getPosition().x)

								{
									logfallleft = 1;
								}


								else
								{
									logfallleft = 0;
									logfallright = 0;
								}


								break;
							}

						}


						else
						{
							fa = 1;
						}

					}

					//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

					//Rendering the blocks again and again
					for (int i = 0; i <= 5; i++)
					{
						float  random = rand() % 201 + 150;

						if (x[i].getPosition().y > 650 && i > 0)
						{
							y[i] = y[i] + 6;

							if (y[i] % 10 == 0)
							{
								index10 = i;//getting the current block we are on
							}

							if (y[i] % 50 == 0)
							{
								x[i].setSize(Vector2f(1000, 55));
								x[i].setOrigin(500, 55);
								x[i].setPosition(600, x[i - 1].getPosition().y - 105);
							}

							else
							{
								x[i].setSize(Vector2f(random, 55));
								x[i].setOrigin(random / 2, 55);
								x[i].setPosition(rand() % 501 + 350, x[i - 1].getPosition().y - 105);
							}

						}

						if (x[i].getPosition().y > 650 && i == 0)
						{
							y[i] = y[i] + 6;

							if (y[i] % 10 == 0)
							{
								index10 = i; // getting the current block we are on
							}

							if (y[i] % 50 == 0)
							{
								x[i].setSize(Vector2f(1000, 55));
								x[i].setOrigin(500, 55);
								x[i].setPosition(600, x[5].getPosition().y - 105);

							}
							else
							{
								x[i].setSize(Vector2f(random, 55));
								x[i].setOrigin(random / 2, 55);
								x[i].setPosition(rand() % 501 + 350, x[5].getPosition().y - 105);
							}
						}
					}

					//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

										// knowing where to put the score rectangle
					if (y[index10] % 10 == 0 && y[index10] != 0)
					{
						scour10s.setPosition(x[index10].getPosition().x, x[index10].getPosition().y);
					}
					//Rendering the score rectangle
					Score10s.setPosition(scour10s.getPosition().x - 10, scour10s.getPosition().y - 15);


					if (rendertest)
					{
						counter++;
						timer1++;// when the speed of the game increase
						if (timer1 == 60)
						{
							timer1 = 0;
							timer2++;
							if (timer2 == 30)
							{
								timer2 = 0;
							}
						}

					}


					if (counter == 1800)
					{

						counter = 0;
						zv *= 1.5;
						if (zv > 5)
						{
							zv = 5;
						}
					}


					//wallcollision
					if (z.getPosition().x <= 160 || z.getPosition().x >= 1075)
					{

						if (z.getPosition().x > 600)
						{
							rightButton = 0;
							z.setPosition(Vector2f(1075, z.getPosition().y));
							z.move(Vector2f(-1 * xVelocity, 0));
						}
						else
						{
							leftButton = 0;
							z.setPosition(Vector2f(160, z.getPosition().y));
							z.move(Vector2f(-1 * xVelocity, 0));
						}
					}

					//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

										//Animation
					IntRect uvr;
					uvr.width = playtext.getSize().x / 15;
					uvr.height = playtext.getSize().y / 4;
					uvr.top = pp * uvr.height;
					uvr.width = -abs(uvr.width);

					//Stand
					if (fa == 0 || yVelocity == 0.7)
					{
						z.setRotation(0.1f);
						rotation = 0;
						z.setOrigin(45, 75);

						//low wa2f 3la tarf el block men lemen w byo2a3
						if (logfallright)
						{
							if (counter2 < 10)
							{
								z.setTextureRect(sf::IntRect(textureSize.x * 12, textureSize.y * pp, textureSize.x, textureSize.y));
							}
							else if (counter2 <= 20)
							{
								z.setTextureRect(sf::IntRect(textureSize.x * 13, textureSize.y * pp, textureSize.x, textureSize.y));
								if (counter2 == 20)
								{
									counter2 = 0;
								}

							}

						}

						//low wa2f 3la tarf el block men shemale w byo2a3
						else if (logfallleft)
						{
							if (counter2 < 10)
							{
								uvr.left = 13 * abs(uvr.width);

								z.setTextureRect(uvr);

							}
							else if (counter2 <= 20)
							{
								uvr.top = pp * uvr.height;
								uvr.left = 14 * abs(uvr.width);

								z.setTextureRect(uvr);

								if (counter2 == 20)
								{
									counter2 = 0;
								}

							}
						}

						//low wa2f fe mkano
						else if (!leftButton && !rightButton)
						{
							if (fa == 1)
							{
								z.setTextureRect(sf::IntRect(textureSize.x * 7, textureSize.y * pp, textureSize.x, textureSize.y));
							}
							else  //fa != 0
							{
								if (counter2 < 10)
								{
									z.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y * pp, textureSize.x, textureSize.y));
								}
								else if (counter2 < 20)
								{
									z.setTextureRect(sf::IntRect(textureSize.x * 1, textureSize.y * pp, textureSize.x, textureSize.y));
								}
								else if (counter2 <= 30)
								{
									z.setTextureRect(sf::IntRect(textureSize.x * 2, textureSize.y * pp, textureSize.x, textureSize.y));
									if (counter2 == 30)
									{
										counter2 = 0;
									}
								}

							}
						}

						//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

												//right side
						else if (!leftButton && rightButton)
						{     //first character
							if (pp != 1)
							{
								z.setRotation(0);

								if (counter2 < 10)
								{
									z.setTextureRect(sf::IntRect(textureSize.x * 3, textureSize.y * pp, textureSize.x, textureSize.y));
								}
								else if (counter2 < 20)
								{
									z.setTextureRect(sf::IntRect(textureSize.x * 4, textureSize.y * pp, textureSize.x, textureSize.y));
								}
								else if (counter2 < 30)
								{
									z.setTextureRect(sf::IntRect(textureSize.x * 5, textureSize.y * pp, textureSize.x, textureSize.y));
								}
								else if (counter2 <= 40)
								{
									z.setTextureRect(sf::IntRect(textureSize.x * 6, textureSize.y * pp, textureSize.x, textureSize.y));
									if (counter2 == 40)
									{
										counter2 = 0;
									}
								}
							}

							//2nd player
							else if (pp == 1)
							{
								if (counter2 < 10)
								{
									z.setTextureRect(sf::IntRect(textureSize.x * 4, textureSize.y*pp, textureSize.x, textureSize.y));
								}
								else if (counter2 < 20)
								{
									z.setTextureRect(sf::IntRect(textureSize.x * 5, textureSize.y*pp, textureSize.x, textureSize.y));
								}

								else if (counter2 <= 30)
								{
									z.setTextureRect(sf::IntRect(textureSize.x * 6, textureSize.y*pp, textureSize.x, textureSize.y));
									if (counter2 == 30)
									{
										counter2 = 0;
									}

								}
							}
						}

						//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

												//left side
						else if (leftButton && !rightButton)
						{
							if (pp != 1)
							{
								if (counter2 < 10)
								{
									uvr.left = 4 * abs(uvr.width);
									z.setTextureRect(uvr);
								}

								else if (counter2 < 20)
								{
									uvr.left = 5 * abs(uvr.width);
									z.setTextureRect(uvr);
								}

								else if (counter2 < 30)
								{
									uvr.left = 6 * abs(uvr.width);
									z.setTextureRect(uvr);
								}

								else if (counter2 <= 40)
								{
									uvr.left = 7 * abs(uvr.width);
									z.setTextureRect(uvr);
									if (counter2 == 40)
									{
										counter2 = 0;
									}
								}
							}
							else if (pp == 1)
							{
								if (counter2 < 10)
								{
									uvr.left = 5 * abs(uvr.width);
									z.setTextureRect(uvr);
								}

								else if (counter2 < 20)
								{
									uvr.left = 6 * abs(uvr.width);
									z.setTextureRect(uvr);
								}
								else if (counter2 <= 30)
								{
									uvr.left = 7 * abs(uvr.width);
									z.setTextureRect(uvr);
									if (counter2 == 30)
									{
										counter2 = 0;
									}
								}
							}
						}
					}


					//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

										//rotation
					else if (rotatz)
					{
						if (rotation)
						{
							z.rotate(20.f);
						}
						else
						{
							z.setTextureRect(sf::IntRect(textureSize.x * 11, textureSize.y*pp, textureSize.x, textureSize.y));
							z.setOrigin(22.5, 37.5);
							z.rotate(20.f);
							rotation = 1;
						}

					}

					//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

										//down
					else if (yVelocity > 0.7)
					{
						//bent wes5a double
						z.setRotation(0.1f);
						rotation = 0;
						z.setOrigin(45, 75);

						if (!leftButton && !rightButton)
						{
							z.setTextureRect(sf::IntRect(textureSize.x * 7, textureSize.y*pp, textureSize.x, textureSize.y));
						}
						else if (!leftButton && rightButton)
						{
							z.setTextureRect(sf::IntRect(textureSize.x * 10, textureSize.y*pp, textureSize.x, textureSize.y));
						}
						else  if (leftButton && !rightButton)
						{
							uvr.left = 11 * abs(uvr.width);
							z.setTextureRect(uvr);
						}
					}

					//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

										//up
					else if (yVelocity < 0)
					{
						if (!leftButton && !rightButton)
						{

							rotation = 0;
							z.setRotation(0.1f);
							z.setOrigin(45, 75);
							z.setTextureRect(sf::IntRect(textureSize.x * 7, textureSize.y*pp, textureSize.x, textureSize.y));
						}
						else  if (!leftButton&&rightButton)
						{

							rotation = 0;
							z.setRotation(0.1f);
							z.setOrigin(45, 75);
							z.setTextureRect(sf::IntRect(textureSize.x * 8, textureSize.y*pp, textureSize.x, textureSize.y));
						}
						else  if (leftButton && !rightButton)
						{

							rotation = 0;
							z.setRotation(0.1f);
							z.setOrigin(45, 75);
							uvr.left = 9 * abs(uvr.width);
							z.setTextureRect(uvr);
						}

					}
					counter2 += 0.5;
					if (counter2 > 40)
					{
						counter2 = 0;
					}

					//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

										//barfill
					if (bf > 150)
					{
						bf = 150;
					}
					bfill.setSize(Vector2f(23, bf));
					bfill.setOrigin(23, bf);
					if (bf > 0)
					{
						bf -= 0.56;
					}
					else {
						if (combos > maximumcombos)
						{
							maximumcombos = combos;
						}
						bf = 0;
						combos = 0;
						for (int i = 1; i <= 4; i++)
							mp[i] = 0;
					}
					if (combos > 0) {
						if (combos >= 25) { Combosshow.setString("Wow!");  mp[4]++; counter3 = 4; }
						else if (combos >= 15) { Combosshow.setString("Great!");  mp[3]++; counter3 = 3; }
						else if (combos >= 7) { Combosshow.setString("Sweet!");  mp[2]++; counter3 = 2; }
						else if (combos >= 4) { Combosshow.setString("Good!");  mp[1]++; counter3 = 1; }
						if (counter3 == 4 && mp[counter3] == 1) { show.openFromFile("data/show4.wav"); show.play(); }
						else if (counter3 == 3 && mp[counter3] == 1) { show.openFromFile("data/show3.wav"); show.play(); }
						else if (counter3 == 2 && mp[counter3] == 1) { show.openFromFile("data/show2.wav"); show.play(); }
						else if (counter3 == 1 && mp[counter3] == 1) { show.openFromFile("data/show1.wav"); show.play(); }
					}
					//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

					stringstream tx, ti, to, tim;
					tx << "SCORE : " << Score;
					score.setString(tx.str());
					ti << "COMBO SCORE : " << combos;
					Combos.setString(ti.str());
					to << y[index10];
					Score10s.setString(to.str());
					tim << 0 << " : " << timer2;
					timer.setString(tim.str());
					window.clear();
					window.draw(wall);

					for (int i = 0; i <= 5; i++)

					{
						window.draw(x[i]);
					}


					window.draw(w1);
					window.draw(w2);
					window.draw(scour10s);// Rectangle
					window.draw(Score10s);// Text
					window.draw(z);
					if (mp[counter3] > 0 && mp[counter3] <= 105) { window.draw(Combosshow); }
					window.draw(score);
					if (mp[counter3] <= 105 && mp[counter3] > 0) { window.draw(Combosshow); }
					window.draw(bar);
					window.draw(bfill);
					window.draw(timer);
					if (combos > 0)
					{
						window.draw(Combos);
					}


					window.display();



				}
				// low hwa mat

				if (!esp)
				{
					for (int i = 9; i >= 0; i--)
					{

						if (Score >= vecx[i].first) {
							changex = 1;
							indx = i;
							break;
						}
					}


					for (int i = 0; i <= indx; i++)
					{
						if (i == indx)
						{
							vecx[indx].first = Score;
						}
						else
						{
							vecx[i].first = vecx[i + 1].first;
							vecx[i].second = vecx[i + 1].second;
						}

					}
					buffy.loadFromFile("data/game loose.wav");
					Tom.setBuffer(buffy);
					Tom.setVolume(upndown.getVolume());
					Tom.play();
					music.openFromFile("data/end.ogg");
					music.play();
					music.setLoop(true);
				}
				//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
				int counter4 = 0;
				RectangleShape tabot;
				Texture tabot1;
				tabot1.loadFromFile("data/tabot.png");
				tabot.setTexture(&tabot1);
				tabot.setPosition(440, 120);
				Vector2u textureSize1 = tabot1.getSize();
				tabot.setSize(Vector2f(306, 300));
				textureSize1.x /= 4;
				textureSize1.y /= 1;
				tabot.setOrigin(0, textureSize1.y / 2);
				tabot.setTextureRect(sf::IntRect(textureSize1.x * 0, textureSize1.y * 0, textureSize1.x, textureSize1.y));



				//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
								//replay and back to menu
				Text tx1[2], maxcombo, tx3, name;
				tx1[0].setCharacterSize(50);
				tx1[0].setFont(font);
				tx1[0].setFillColor(Color::Blue);
				tx1[0].setString("START GAME");
				tx1[0].setPosition(480, 320);
				tx1[1].setCharacterSize(50);
				tx1[1].setFont(font);
				tx1[1].setFillColor(Color::White);
				tx1[1].setString("Back To Menu");
				tx1[1].setPosition(480, 370);

				//bytl3lk el 7rof el tktbha 3la screen
				tx3.setCharacterSize(40);
				tx3.setFont(font);
				tx3.setFillColor(Color::Blue);
				tx3.setPosition(895, 90);

				//Max combo
				maxcombo.setFont(font);
				maxcombo.setFillColor(Color::White);
				maxcombo.setCharacterSize(40);
				maxcombo.setPosition(160, 500);

				//write your name 
				name.setFont(font);
				name.setFillColor(Color::Cyan);
				name.setCharacterSize(40);
				name.setPosition(700, 90);



				stringstream tm, tn;
				tm << "MaxCombos : " << maximumcombos;
				maxcombo.setString(tm.str());
				tn << "Enter Name : " << endl;
				name.setString(tn.str());
				//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

				int st = 1; //wa2f 3la anhy wa7eda game start / back to menu
				bool selected = 0; //Pressed enter

				//at end game
				while (true)
				{
					bool esp2 = 0;
					while (window.pollEvent(event))
					{
						//Event type is window closed

						if (event.type == Event::Closed)
						{
							return 0;
						}
						if (event.type == Event::KeyReleased)
						{
							if (event.key.code == Keyboard::Down)
							{
								if (st != 2)
								{
									tx1[st - 1].setFillColor(Color::White);
									st++;
									tx1[st - 1].setFillColor(Color::Blue);
								}
								else
								{
									tx1[st - 1].setFillColor(Color::White);
									st = 1;
									tx1[st - 1].setFillColor(Color::Blue);
								}
							}

							else if (event.key.code == Keyboard::Enter)
							{
								selected = true;

							}

							else if (event.key.code == Keyboard::Escape)
							{
								ingame = 0;
								esp2 = 1;// ytl3k 3la menu
							}
							else if (event.key.code == Keyboard::Up)
							{
								if (st != 1)
								{
									tx1[st - 1].setFillColor(Color::White);
									st--;
									tx1[st - 1].setFillColor(Color::Blue);
								}
								else
								{
									tx1[st - 1].setFillColor(Color::White);
									st = 2;
									tx1[st - 1].setFillColor(Color::Blue);
								}
							}
							else if (event.key.code == Keyboard::BackSpace)
							{
								if (test2.empty() == false)
								{
									test2.pop_back();
								}
							}
							else
							{

								if (changex) {
									// ay 7ga ydos 3leha
									int za;
									za = event.key.code;
									if ((za < 36 && za > -1) || za == 56)
									{
										char bc;
										if (za < 26) { bc = za + 97; }
										else if (za < 56)
										{

											bc = za + 22;

										}
										else
										{
											bc = 95;
										}
										test2 += bc;
									}
								}

							}

						}
					}
					if (changex)
					{
						vecx[indx].second = test2;
					}

					if (selected)
					{
						if (st == 1)
						{
							break;
						}
						else {
							ingame = 0;
							break;
						}


					}
					//break while loop el gwaha
					if (esp2)
					{
						break;
					}
					//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
					counter4++;
					if (counter4 <= 15)
					{
						tabot.setTextureRect(sf::IntRect(textureSize1.x * 0, textureSize1.y * 0, textureSize1.x, textureSize1.y));

					}
					else if (counter4 <= 30)
					{
						tabot.setTextureRect(sf::IntRect(textureSize1.x * 1, textureSize1.y * 0, textureSize1.x, textureSize1.y));

					}
					else if (counter4 <= 45)
					{
						tabot.setTextureRect(sf::IntRect(textureSize1.x * 2, textureSize1.y * 0, textureSize1.x, textureSize1.y));

					}
					else if (counter4 <= 60)
					{
						tabot.setTextureRect(sf::IntRect(textureSize1.x * 3, textureSize1.y * 0, textureSize1.x, textureSize1.y));
						if (counter4 >= 60) { counter4 = 0; }
					}


					stringstream tx, ti, to;
					tx << "SCORE : " << Score;
					score.setString(tx.str());
					ti << "combo score : " << combos;
					Combos.setString(ti.str());
					to << y[index10];
					Score10s.setString(to.str());
					tx3.setString(test2);

					window.clear();
					window.draw(wall);

					for (int i = 0; i <= 5; i++)

					{
						window.draw(x[i]);
					}
					window.draw(w1);
					window.draw(w2);
					window.draw(scour10s);
					window.draw(z);
					if (!esp)
					{
						window.draw(tabot);
						if (changex) { window.draw(name); }
						window.draw(maxcombo);
						window.draw(tx3);

					}
					window.draw(score);
					window.draw(bar);
					window.draw(bfill);
					if (combos > 0) { window.draw(Combos); }
					window.draw(Score10s);
					for (int i = 0; i < 2; i++)
						window.draw(tx1[i]);
					window.display();
				}
				if (changex) {
					ofstream hisfile2;
					if (test2.empty()) {
						vecx[indx].second = "defult";
					}
					hisfile2.open("data/his.txt");
					for (int i = 0; i <= 9; i++)
					{
						string j1;
						j1 = vecx[i].second;
						hisfile2 << j1 << " " << vecx[i].first << endl;
					}
					hisfile2.close();

				}
			}

			//Clean up and close the window

			window.close();
			//----------------------------------------------------------------------------------------------------------------------------

			//-----------------------------------------------------------------------------------------------------------------------------
			if (music.openFromFile("data/music2.ogg") == false)
			{
				cout << "Music Wasn't loaded" << endl;
			}
			music.play();
			music.setLoop(true);
			buffy.loadFromFile("data/5osh.wav");
			Tom.setBuffer(buffy);
			//Close the program
		}

		//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		//instruction menu
		if (pagenumber == 1) {
			sf::RenderWindow window(sf::VideoMode(1200, 600), "Instructions");
			window.setFramerateLimit(60);
			//Images
			sf::Texture pic;

			if (pic.loadFromFile("data/Icy Tower.png") == false)
			{
				return 1;
			}

			//Shapes
			// background
			sf::RectangleShape backGround;
			backGround.setSize(sf::Vector2f(1200, 600));
			backGround.setPosition(0, 0);
			backGround.setTexture(&pic);

			//Game loop
			while (window.isOpen())
			{
				//Events for the game
				sf::Event event;
				while (window.pollEvent(event)) {

					if (event.type == sf::Event::Closed) {
						return 0;
					}
					if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
					{
						window.close();
						menu.draw(window1);
					}

					//Rendering
					window.clear();
					//draw
					window.draw(backGround);

					window.display();

				}

			}

		}

		//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		//Option menu
		if (pagenumber == 2)
		{
			ofstream onfile;
			onfile.open("data/ops.txt");
			bool options = true;
			while (options)
			{
				sf::RenderWindow window3(sf::VideoMode(1200, 600), "Options menu");
				options_menu menu1(1200, 600);
				window3.setFramerateLimit(60);
				sf::RectangleShape recc2;
				recc2.setSize(sf::Vector2f(1200, 600));
				sf::Texture option_photo;
				if (option_photo.loadFromFile("data/background.png") == false)
				{
				}
				recc2.setTexture(&option_photo);
				while (window3.isOpen())
				{
					sf::Event event;
					while (window3.pollEvent(event))
					{
						if (event.type == sf::Event::Closed)
						{
							return 0;
						}

						if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Escape)
						{
							onfile << pp << endl << glong << endl << musx << endl << musy;
							onfile.close();
							options = 0;
							window3.close();
						}
						if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Up)
						{
							menu1.Moveup2();
							upndown.play();
						}
						if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Down)
						{
							menu1.Movedown2();
							upndown.play();
						}
						if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Return)
						{
							enter = true;
							menu1.GetItem();

							if (menu1.GetItem() == 0)
							{
								cout << "Game optios button" << endl;
								Tom.play();
								window3.close();
								page_number = 0;
							}
							if (menu1.GetItem() == 1)
							{
								cout << "Game optios Sound" << endl;
								Tom.play();
								window3.close();
								page_number = 1;
							}
							if (menu1.GetItem() == 2)
							{
								cout << "Game optios back" << endl;
								Tom.play();
								window3.close();
								page_number = 2;

							}
						}
					}

					window3.clear();
					window3.draw(recc2);
					menu1.draw(window3);
					window3.display();


				}

				//Game option
				if (page_number == 0)
				{
					int x = 1;
					sf::RenderWindow window_gameoption(sf::VideoMode(1200, 600), "Game Options");
					window_gameoption.setFramerateLimit(60);
					sf::RectangleShape recc3;
					recc3.setSize(sf::Vector2f(1200, 600));
					sf::Texture gameoption_photo;
					if (gameoption_photo.loadFromFile("data/background.png") == false)
					{
					}
					recc3.setTexture(&gameoption_photo);

					Texture playtext, longtext;
					//changing the  character
					playtext.loadFromFile("data/animation1.png");
					sf::Vector2u textureSize = playtext.getSize();
					textureSize.x /= 15;
					textureSize.y /= 4;

					//changing the logs
					if (glong == 1)
					{
						longtext.loadFromFile("data/long2.png"); //ice

					}
					else
					{
						longtext.loadFromFile("data/long.png"); //wood
					}

					RectangleShape y, b;
					// Y ----> rectangle of character , b ----> rectangle of block
					y.setSize(Vector2f(50, 75));
					y.setPosition(1015, 305);
					y.setTexture(&playtext);
					y.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y * pp, textureSize.x, textureSize.y));

					b.setSize(Vector2f(100, 50));
					b.setPosition(990, 400);
					b.setTexture(&longtext);

					//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

					menu_gameoption menu3(1200, 600);
					while (window_gameoption.isOpen())
					{
						sf::Event event;
						while (window_gameoption.pollEvent(event))
						{
							if (event.type == sf::Event::Closed)
							{
								return 0;
							}
							if (event.type == sf::Event::KeyPressed &&event.key.code == sf::Keyboard::Return)
							{
								if (menu3.menu_gameoptionPressed() == 2)
								{
									window_gameoption.close();
								}
							}
							if (event.type == sf::Event::KeyReleased&&event.key.code == sf::Keyboard::Escape)
							{
								window_gameoption.close();
							}

							if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Up)
							{
								x--; //pointer
								if (x < 1)
								{
									x = 1;
								}
								menu3.moveUp1();
							}
							if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Down)
							{
								x++; //pointer
								if (x > 3)
								{
									x = 3;
								}
								menu3.moveDown1();
							}
							if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Right)
							{
								if (x == 1)
								{
									pp++;
									if (pp > 3) { pp = 3; }
									y.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y * pp, textureSize.x, textureSize.y));
								}
								else if (x == 2)
								{
									glong = 2;
									longtext.loadFromFile("data/long.png"); // ice
									b.setTexture(&longtext);
								}
							}
							if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Left)
							{
								if (x == 1)
								{
									pp--;
									if (pp < 0) { pp = 0; }
									y.setTextureRect(sf::IntRect(textureSize.x * 0, textureSize.y * pp, textureSize.x, textureSize.y));
								}
								else if (x == 2)
								{
									glong = 1;
									longtext.loadFromFile("data/long2.png");// wood
									b.setTexture(&longtext);
								}
							}
						}

						window_gameoption.clear();
						window_gameoption.draw(recc3);
						menu3.draw(window_gameoption);
						window_gameoption.draw(y);
						window_gameoption.draw(b);
						window_gameoption.display();

					}
				}

				//Sound options
				if (page_number == 1)
				{
					sf::RenderWindow window_sound(sf::VideoMode(1200, 600), "Sound Options");
					window_sound.setFramerateLimit(60);
					sf::RectangleShape recc4;
					recc4.setSize(sf::Vector2f(1200, 600));
					sf::Texture sound_photo;
					if (sound_photo.loadFromFile("data/background.png") == false)
					{
					}
					recc4.setTexture(&sound_photo);

					sf::RectangleShape rectangle[rectangels];
					sf::RectangleShape rectangle2[rectangels];
					window_sound.setKeyRepeatEnabled(false);

					Texture musv;
					musv.loadFromFile("data/musicv.png");
					int distx = 0;
					for (int i = 0; i < rectangels; i++) {
						rectangle[i].setSize(sf::Vector2f(12, 30));
						rectangle[i].setPosition(875 + distx, 350);
						distx += 20;
						rectangle[i].setTexture(&musv);
					}
					int distx2 = 0;
					for (int i = 0; i < rectangels; i++) {
						rectangle2[i].setSize(sf::Vector2f(12, 30));
						rectangle2[i].setPosition(875 + distx2, 415);
						distx2 += 20;
						rectangle2[i].setTexture(&musv);
					}

					//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

					SoundMenu menu2(1200, 600);
					while (window_sound.isOpen()) {
						sf::Event event;
						while (window_sound.pollEvent(event)) {
							if (event.type == sf::Event::Closed) {
								return 0;
							}

							if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Return) {
								if (menu2.GetItem() == 2) {
									window_sound.close();
									menu2.draw(window3);
								}
							}
							if (event.type == sf::Event::KeyReleased&&event.key.code == sf::Keyboard::Escape) {
								window_sound.close();


							}

							if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Up) {
								menu2.Moveup3();
								upndown.play();

							}
							if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Down) {
								menu2.Movedown3();
								upndown.play();
							}
							menu2.GetItem();
							if (menu2.GetItem() == 0) {
								if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Right)
								{

									upndown.setVolume(upndown.getVolume() + 10);
									if (upndown.getVolume() > 100)
									{
										upndown.setVolume(100);
									}
									//cout << menu2.GetItem() << endl;
									//cout << upndown.getVolume() << endl;
								}
								if (event.type == sf::Event::KeyReleased&&event.key.code == sf::Keyboard::Left)
								{
									if (upndown.getVolume() < 10)
									{
										upndown.setVolume(0);
									}
									upndown.setVolume(upndown.getVolume() - 10);
									//cout << upndown.getVolume() << endl;

								}


								Tom.setVolume(upndown.getVolume());
								show.setVolume(upndown.getVolume());
								musx = upndown.getVolume();
							}

							menu2.GetItem();
							if (menu2.GetItem() == 1) {
								if (event.type == sf::Event::KeyReleased&&event.key.code == sf::Keyboard::Right)
								{

									music.setVolume(music.getVolume() + 10);
									if (music.getVolume() > 100)
									{
										music.setVolume(100);
									}
									//cout << music.getVolume() << endl;
									//cout << menu2.GetItem() << endl;

								}
								if (event.type == sf::Event::KeyReleased&&event.key.code == sf::Keyboard::Left)
								{
									Left = true;
									if (music.getVolume() < 10)
									{
										music.setVolume(0);
									}
									music.setVolume(music.getVolume() - 10);
									//cout << music.getVolume() << endl;
								}
								musy = music.getVolume();
							}

						}

						window_sound.clear();
						window_sound.draw(recc4);

						for (int i = 10; i <= upndown.getVolume() + 1; i += 10)
						{
							window_sound.draw(rectangle[i / 10 - 1]);
						}
						for (int i = 10; i <= music.getVolume() + 1; i += 10)
						{
							window_sound.draw(rectangle2[i / 10 - 1]);
						}
						menu2.draw(window_sound);
						window_sound.display();

					}
				}

				//Back button
				int Index_options_menu = menu1.GetItem();

				if (page_number == 2 && Index_options_menu == 2 && enter == true)
				{
					onfile << pp << endl << glong << endl << musx << endl << musy;
					onfile.close();
					options = 0;
					window3.close();
					menu1.draw(window3);

				}

			}

		}
		if (pagenumber == 3)
		{
			sf::RenderWindow window_high(sf::VideoMode(1200, 600), "HIGH SCORE");
			window_high.setFramerateLimit(60);
			sf::RectangleShape recc3;
			recc3.setSize(sf::Vector2f(1200, 600));
			sf::Texture gameoption_photo;
			if (gameoption_photo.loadFromFile("data/Highscore.png") == false)
			{
				cout << "la2";
			}
			recc3.setTexture(&gameoption_photo);
			Font fontx;
			fontx.loadFromFile("data/ITCEDSCR.ttf");
			Text tx4[10];
			for (int i = 9, j = 0; i > -1; i--, j++)
			{
				string jy;
				tx4[i].setCharacterSize(38);
				tx4[i].setFont(fontx);
				tx4[i].setFillColor(Color::Black);
				tx4[i].setPosition(450, 100 + (j * 38));
				stringstream tx;
				jy = vecx[i].second;
				tx << j + 1 << " . " << jy << " " << vecx[i].first;
				tx4[i].setString(tx.str());
			}
			while (window_high.isOpen())
			{
				sf::Event event;
				while (window_high.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
					{
						return 0;
					}

					if (event.type == sf::Event::KeyPressed&&event.key.code == sf::Keyboard::Escape)
					{
						window_high.close();
					}

				}
				window_high.clear();
				window_high.draw(recc3);
				for (int i = 0; i < 10; i++)
				{
					window_high.draw(tx4[i]);
				}
				window_high.display();
			}
		}
		if (pagenumber == 4)
		{
			break;
		}
	}
	return 0;
}

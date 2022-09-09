// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <iostream>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	// Create a video mode object
	VideoMode vm(1000, 1000);

	// Create and open a window for the game
	RenderWindow window(vm, "ChaosGame", Style::Default);

	vector<RectangleShape> parr;

	RectangleShape point(Vector2f(1, 1));

	RectangleShape v1(Vector2f(4, 4));
	RectangleShape v2(Vector2f(4, 4));
	RectangleShape v3(Vector2f(4, 4));
	RectangleShape v4(Vector2f(4, 4));
	RectangleShape v5(Vector2f(4, 4));
	RectangleShape v6(Vector2f(4, 4));

	RectangleShape spoint(Vector2f(4, 4));

	int mouseclicks = 0;
	bool start = false;
	bool mouse_locked = false;
	int mode = 0;

	srand((int)time(0));

	Font font;
	font.loadFromFile("fonts/editundo.ttf");

	Text instructions;
	instructions.setFont(font);
	instructions.setCharacterSize(21);
	instructions.setColor(Color::White);
	instructions.setStyle(Text::Regular);
	instructions.setString("Welcome to the Chaos Game!\n1. Start by pressing number keys (1-4)\n	to choose fractal mode\n2. Place the vertices\n	by left-clicking on the window\n3. Last click to start the algorithm\n	(also for the starting point)");
	instructions.setPosition(15, 15);

	Text modeText;
	modeText.setFont(font);
	modeText.setCharacterSize(31);
	modeText.setColor(Color::White);
	modeText.setStyle(Text::Regular);
	modeText.setString("Mode: ");
	modeText.setPosition(775, 15);

	Text md;
	md.setFont(font);
	md.setCharacterSize(31);
	md.setColor(Color::Green);
	md.setStyle(Text::Regular);
	md.setString("Triangle");
	md.setPosition(860, 15);

	while (window.isOpen())
	{
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left)
			{
				mouse_locked = false;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		if (mouseclicks == 0)
		{
			if (Keyboard::isKeyPressed(Keyboard::Num1))
			{
				mode = 0;
				md.setString("Triangle");
			}
			else if (Keyboard::isKeyPressed(Keyboard::Num2))
			{
				mode = 1;
				md.setString("Square");
			}
			else if (Keyboard::isKeyPressed(Keyboard::Num3))
			{
				mode = 2;
				md.setString("Pentagon");
			}
			else if (Keyboard::isKeyPressed(Keyboard::Num4))
			{
				mode = 3;
				md.setString("Hexagon");
			}
		}

		if (Mouse::isButtonPressed(Mouse::Left) && mouseclicks < mode + 3 && !mouse_locked)
		{
			mouseclicks++;
			if (mode == 0)
			{
				switch (mouseclicks)
				{
				case 1:
					v1.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
					v1.setFillColor(Color(0, 255, 0));
					break;
				case 2:
					v2.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
					v2.setFillColor(Color(0, 255, 0));
					break;
				case 3:
					v3.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
					v3.setFillColor(Color(0, 255, 0));
					break;
				}
			}
			else if (mode == 1)
			{
				switch (mouseclicks)
				{
				case 1:
					v1.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
					v1.setFillColor(Color(0, 255, 0));
					break;
				case 2:
					v2.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
					v2.setFillColor(Color(0, 255, 0));
					break;
				case 3:
					v3.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
					v3.setFillColor(Color(0, 255, 0));
					break;
				case 4:
					v4.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
					v4.setFillColor(Color(0, 255, 0));
					break;
				}
			}
			else if (mode == 2)
			{
				switch (mouseclicks)
				{
				case 1:
					v1.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
					v1.setFillColor(Color(0, 255, 0));
					break;
				case 2:
					v2.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
					v2.setFillColor(Color(0, 255, 0));
					break;
				case 3:
					v3.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
					v3.setFillColor(Color(0, 255, 0));
					break;
				case 4:
					v4.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
					v4.setFillColor(Color(0, 255, 0));
					break;
				case 5:
					v5.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
					v5.setFillColor(Color(0, 255, 0));
					break;
				}
			}
			else if (mode == 3)
			{
				switch (mouseclicks)
				{
				case 1:
					v1.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
					v1.setFillColor(Color(0, 255, 0));
					break;
				case 2:
					v2.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
					v2.setFillColor(Color(0, 255, 0));
					break;
				case 3:
					v3.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
					v3.setFillColor(Color(0, 255, 0));
					break;
				case 4:
					v4.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
					v4.setFillColor(Color(0, 255, 0));
					break;
				case 5:
					v5.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
					v5.setFillColor(Color(0, 255, 0));
					break;
				case 6:
					v6.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
					v6.setFillColor(Color(0, 255, 0));
					break;
				}
			}
			mouse_locked = true;
		}

		if (Mouse::isButtonPressed(Mouse::Left) && mouseclicks == mode + 3 && start == false && !mouse_locked)
		{
			start = true;
			int pos1 = (rand() % 1000);
			int pos2 = (rand() % 1000); //[0, 999]
			spoint.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
			spoint.setFillColor(Color(255, 0, 0));
			parr.push_back(spoint);
			mouse_locked = true;
		}

		/*
		****************************************
		Update the scene
		****************************************
		*/

		if (parr.size() < (1000 * 1000) && start)
		{
			static int previous = 100;
			parr.push_back(point);
			int pos1, pos2, rvert;
			rvert = (rand() % (mode + 3));

			if (mode == 0)
			{
				switch (rvert)
				{
				case 0:
					pos1 = (abs(v1.getPosition().x) + abs(parr[parr.size() - 2].getPosition().x)) / 2;
					pos2 = (abs(v1.getPosition().y) + abs(parr[parr.size() - 2].getPosition().y)) / 2;
					break;
				case 1:
					pos1 = (abs(v2.getPosition().x) + abs(parr[parr.size() - 2].getPosition().x)) / 2;
					pos2 = (abs(v2.getPosition().y) + abs(parr[parr.size() - 2].getPosition().y)) / 2;
					break;
				case 2:
					pos1 = (abs(v3.getPosition().x) + abs(parr[parr.size() - 2].getPosition().x)) / 2;
					pos2 = (abs(v3.getPosition().y) + abs(parr[parr.size() - 2].getPosition().y)) / 2;
					break;
				}
			}
			else if (mode == 1)
			{
				do
				{
					rvert = (rand() % (mode + 3));
				} while (rvert == previous);
				previous = rvert;

				switch (rvert)
				{
				case 0:
					pos1 = (abs(v1.getPosition().x) + abs(parr[parr.size() - 2].getPosition().x)) / 2;
					pos2 = (abs(v1.getPosition().y) + abs(parr[parr.size() - 2].getPosition().y)) / 2;
					break;
				case 1:
					pos1 = (abs(v2.getPosition().x) + abs(parr[parr.size() - 2].getPosition().x)) / 2;
					pos2 = (abs(v2.getPosition().y) + abs(parr[parr.size() - 2].getPosition().y)) / 2;
					break;
				case 2:
					pos1 = (abs(v3.getPosition().x) + abs(parr[parr.size() - 2].getPosition().x)) / 2;
					pos2 = (abs(v3.getPosition().y) + abs(parr[parr.size() - 2].getPosition().y)) / 2;
					break;
				case 3:
					pos1 = (abs(v4.getPosition().x) + abs(parr[parr.size() - 2].getPosition().x)) / 2;
					pos2 = (abs(v4.getPosition().y) + abs(parr[parr.size() - 2].getPosition().y)) / 2;
					break;
				}
			}
			else if (mode == 2)
			{
				do
				{
					rvert = (rand() % (mode + 3));
				} while (rvert == previous);
				
				previous = rvert;

				switch (rvert)
				{
				case 0:
					pos1 = (abs(v1.getPosition().x) + abs(parr[parr.size() - 2].getPosition().x)) / 2;
					pos2 = (abs(v1.getPosition().y) + abs(parr[parr.size() - 2].getPosition().y)) / 2;
					break;
				case 1:
					pos1 = (abs(v2.getPosition().x) + abs(parr[parr.size() - 2].getPosition().x)) / 2;
					pos2 = (abs(v2.getPosition().y) + abs(parr[parr.size() - 2].getPosition().y)) / 2;
					break;
				case 2:
					pos1 = (abs(v3.getPosition().x) + abs(parr[parr.size() - 2].getPosition().x)) / 2;
					pos2 = (abs(v3.getPosition().y) + abs(parr[parr.size() - 2].getPosition().y)) / 2;
					break;
				case 3:
					pos1 = (abs(v4.getPosition().x) + abs(parr[parr.size() - 2].getPosition().x)) / 2;
					pos2 = (abs(v4.getPosition().y) + abs(parr[parr.size() - 2].getPosition().y)) / 2;
					break;
				case 4:
					pos1 = (abs(v5.getPosition().x) + abs(parr[parr.size() - 2].getPosition().x)) / 2;
					pos2 = (abs(v5.getPosition().y) + abs(parr[parr.size() - 2].getPosition().y)) / 2;
					break;
				}
			}
			else if (mode == 3)
			{
				do
				{
					rvert = (rand() % (mode + 3));
				} while (rvert == previous);

				previous = rvert;

				switch (rvert)
				{
				case 0:
					pos1 = (abs(v1.getPosition().x) + abs(parr[parr.size() - 2].getPosition().x)) / 2;
					pos2 = (abs(v1.getPosition().y) + abs(parr[parr.size() - 2].getPosition().y)) / 2;
					break;
				case 1:
					pos1 = (abs(v2.getPosition().x) + abs(parr[parr.size() - 2].getPosition().x)) / 2;
					pos2 = (abs(v2.getPosition().y) + abs(parr[parr.size() - 2].getPosition().y)) / 2;
					break;
				case 2:
					pos1 = (abs(v3.getPosition().x) + abs(parr[parr.size() - 2].getPosition().x)) / 2;
					pos2 = (abs(v3.getPosition().y) + abs(parr[parr.size() - 2].getPosition().y)) / 2;
					break;
				case 3:
					pos1 = (abs(v4.getPosition().x) + abs(parr[parr.size() - 2].getPosition().x)) / 2;
					pos2 = (abs(v4.getPosition().y) + abs(parr[parr.size() - 2].getPosition().y)) / 2;
					break;
				case 4:
					pos1 = (abs(v5.getPosition().x) + abs(parr[parr.size() - 2].getPosition().x)) / 2;
					pos2 = (abs(v5.getPosition().y) + abs(parr[parr.size() - 2].getPosition().y)) / 2;
					break;
				case 5:
					pos1 = (abs(v6.getPosition().x) + abs(parr[parr.size() - 2].getPosition().x)) / 2;
					pos2 = (abs(v6.getPosition().y) + abs(parr[parr.size() - 2].getPosition().y)) / 2;
					break;
				}
			}

			parr[parr.size() - 1].setPosition(pos1, pos2);
		}

		/*
		****************************************
		Draw the scene
		****************************************
		*/
		window.clear();

		for (int i = 0; i < parr.size(); i++) window.draw(parr[i]);
		window.draw(v1);
		window.draw(v2);
		window.draw(v3);
		window.draw(v4);
		window.draw(v5);
		window.draw(v6);

		window.draw(instructions);
		window.draw(modeText);
		window.draw(md);

		// Show everything we just drew
		window.display();

	}

	return 0;
}



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

	RectangleShape spoint(Vector2f(4, 4));

	int mouseclicks = 0;
	bool start = false;
	bool mouse_locked = false;

	srand((int)time(0));


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

		if (Mouse::isButtonPressed(Mouse::Left) && mouseclicks < 3 && !mouse_locked)
		{
			mouseclicks++;
			switch (mouseclicks)
			{
			case 1:
				v1.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
				v1.setFillColor(Color(0, 255, 0));
			case 2:
				v2.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
				v2.setFillColor(Color(0, 255, 0));
			case 3:
				v3.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
				v3.setFillColor(Color(0, 255, 0));
			}
			mouse_locked = true;

		}

		if (Mouse::isButtonPressed(Mouse::Left) && mouseclicks == 3 && start == false && !mouse_locked)
		{
			start = true;
			int pos1 = (rand() % 1000);
			int pos2 = (rand() % 1000); //[0, 999]
			spoint.setPosition(pos1, pos2);
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
			parr.push_back(point);
			int pos1 = (rand() % 1000);  
			int pos2 = (rand() % 1000);	//[0, 999]

			int rvert = (rand() % 3);

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

			parr[parr.size() - 1].setPosition(pos1, pos2);
		}

		//sleep(seconds(1));

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

		// Show everything we just drew
		window.display();


	}

	return 0;
}



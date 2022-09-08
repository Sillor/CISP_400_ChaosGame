// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <iostream>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	// Create a video mode object
	VideoMode vm(500, 500);

	// Create and open a window for the game
	RenderWindow window(vm, "ChaosGame", Style::Default);

	vector<RectangleShape> parr;

	RectangleShape point(Vector2f(2, 2));

	RectangleShape v1(Vector2f(4, 4));
	RectangleShape v2(Vector2f(4, 4));
	RectangleShape v3(Vector2f(4, 4));
	v1.setPosition(249, 49);
	v2.setPosition(49, 449);
	v3.setPosition(449, 449);
	v1.setFillColor(Color(0, 255, 0));
	v2.setFillColor(Color(0, 255, 0));
	v3.setFillColor(Color(0, 255, 0));

	v1.getPosition();

	RectangleShape spoint(Vector2f(4, 4));
	spoint.setPosition(249, 249);
	spoint.setFillColor(Color(255, 0, 0));
	parr.push_back(spoint);



	srand((int)time(0));


	while (window.isOpen())
	{

		/*
		****************************************
		Handle the players input
		****************************************
		*/

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		/*
		****************************************
		Update the scene
		****************************************
		*/

		if (parr.size() < 1000 * 1000)
		{
			parr.push_back(point);
			int pos1 = (rand() % 500);  
			int pos2 = (rand() % 500);	//[0, 499]

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



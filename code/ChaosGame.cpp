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

	RectangleShape point1(Vector2f(2, 2));
	RectangleShape point2(Vector2f(2, 2));
	RectangleShape point3(Vector2f(2, 2));
	point1.setPosition(50, 50);
	point2.setPosition(100, 50);
	point3.setPosition(75, 100);


	RectangleShape parr[100];

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

		srand((int)time(0));

		for (int i = 0; i < 100; i++)
		{
			parr[i].setSize(Vector2f(2, 2));
			int pos1 = (rand() % 500);  //[0, 499]
			int pos2 = (rand() % 500);
			parr[i].setPosition(pos1, pos2);
			window.draw(parr[i]);
		}

		/*
		****************************************
		Draw the scene
		****************************************
		*/
		window.draw(point1);

		// Show everything we just drew
		window.display();


	}

	return 0;
}



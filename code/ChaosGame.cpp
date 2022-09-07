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


		/*
		****************************************
		Draw the scene
		****************************************
		*/
		window.draw(point1);
		window.draw(point2);
		window.draw(point3);

		// Show everything we just drew
		window.display();


	}

	return 0;
}



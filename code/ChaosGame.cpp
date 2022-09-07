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

	RectangleShape point(Vector2f(2, 2));

	RectangleShape v1(Vector2f(4, 4));

	vector<RectangleShape> parr;

	srand((int)time(0));

	int x = 0;
	int y = 0;

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

		if (parr.size() < 500 * 500)
		{
			parr.push_back(point);
			int pos1 = (rand() % 500);  
			int pos2 = (rand() % 500);	//[0, 499]

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

		// Show everything we just drew
		window.display();


	}

	return 0;
}



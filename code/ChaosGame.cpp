// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <iostream>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main() {
    // Create a video mode object
    VideoMode vm(1000, 1000);

    // Create and open a window for the game
    RenderWindow window(vm, "ChaosGame", Style::Titlebar | Style::Close);

    // Vector that contains all points
    vector < RectangleShape > parr;

    // Template point to start the vector
    RectangleShape point(Vector2f(1, 1));

    // Declaring vertex points
    RectangleShape v1(Vector2f(4, 4));
    RectangleShape v2(Vector2f(4, 4));
    RectangleShape v3(Vector2f(4, 4));
    RectangleShape v4(Vector2f(4, 4));
    RectangleShape v5(Vector2f(4, 4));
    RectangleShape v6(Vector2f(4, 4));

    // Starting point
    RectangleShape spoint(Vector2f(4, 4));

    // Some variables
    int mouseClicks = 0; // Counts mouse clicks
    bool start = false; // Starts drawing all the points when user is done chosing points
    bool mouseLocked = false; // Puts only one point per click
    int mode = 0; // Indicates what current mode is (triangle, square, pentagon, hexagon)

    // Seeding random
    srand((int)time(0));

    // Font object
    Font font;
    font.loadFromFile("fonts/editundo.ttf");

    // Instructions text
    Text instructions;
    instructions.setFont(font);
    instructions.setCharacterSize(21);
    instructions.setColor(Color::White);
    instructions.setStyle(Text::Regular);
    instructions.setString("Welcome to the Chaos Game!\n1. Start by pressing number keys (1-4)\n	to choose fractal mode\n2. Place the vertices\n	by left-clicking on the window\n3. Last click to start the algorithm\n	(also for the starting point)");
    instructions.setPosition(15, 15);

    // "Mode: " text
    Text modeText;
    modeText.setFont(font);
    modeText.setCharacterSize(31);
    modeText.setColor(Color::White);
    modeText.setStyle(Text::Regular);
    modeText.setString("Mode: ");
    modeText.setPosition(775, 15);

    // Text for current mode
    Text md;
    md.setFont(font);
    md.setCharacterSize(31);
    md.setColor(Color::Green);
    md.setStyle(Text::Regular);
    md.setString("Triangle");
    md.setPosition(860, 15);

    // Frame-updating loop
    while (window.isOpen()) {
        /*
        ****************************************
        Handle the players input
        ****************************************
        */

        // Mouse releasing event to unlock the mouse
        Event event;

        while (window.pollEvent(event)) {
            if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Left) {
                mouseLocked = false;
            }
        }

        // Close the window
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        // Allows to change the mode with number (1-4) keys if 3 or less vertices picked
        if (mouseClicks <= 3) {
            if (Keyboard::isKeyPressed(Keyboard::Num1)) {
                mode = 0;
                md.setString("Triangle");
            }
            else if (Keyboard::isKeyPressed(Keyboard::Num2)) {
                mode = 1;
                md.setString("Square");
            }
            else if (Keyboard::isKeyPressed(Keyboard::Num3)) {
                mode = 2;
                md.setString("Pentagon");
            }
            else if (Keyboard::isKeyPressed(Keyboard::Num4)) {
                mode = 3;
                md.setString("Hexagon");
            }
        }

        // Places the vertices depending on the current mode
        if (Mouse::isButtonPressed(Mouse::Left) && mouseClicks < mode + 3 && !mouseLocked) {
            mouseClicks++;
            if (mode == 0) // Triangle
            {
                switch (mouseClicks) {
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
            else if (mode == 1) // Square
            {
                switch (mouseClicks) {
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
            else if (mode == 2) // Pentagon
            {
                switch (mouseClicks) {
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
            else if (mode == 3) // Hexagon
            {
                switch (mouseClicks) {
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
            mouseLocked = true;
        }

        // If placed vertices, place the starting point and start the drawing
        if (Mouse::isButtonPressed(Mouse::Left) && mouseClicks == mode + 3 && start == false && !mouseLocked) {
            start = true;
            spoint.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
            spoint.setFillColor(Color(255, 0, 0));
            parr.push_back(spoint);
            mouseLocked = true;
        }

        /*
        ****************************************
        Update the scene
        ****************************************
        */

        // Places new point in the middle between random vertex and last point
        if (parr.size() < (1000 * 1000) && start) {
            static int previous = 100;
            parr.push_back(point);
            int pos1, pos2, rvert;
            rvert = (rand() % (mode + 3));

            if (mode == 0) // Triangle
            {
                switch (rvert) {
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
            else if (mode == 1) // Square
            {
                do {
                    rvert = (rand() % (mode + 3));
                } while (rvert == previous);
                previous = rvert;

                switch (rvert) {
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
            else if (mode == 2) // Pentagon
            {
                do {
                    rvert = (rand() % (mode + 3));
                } while (rvert == previous);

                previous = rvert;

                switch (rvert) {
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
            else if (mode == 3) // Hexagon
            {
                do {
                    rvert = (rand() % (mode + 3));
                } while (rvert == previous);

                previous = rvert;

                switch (rvert) {
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

        // Clear the frame
        window.clear();

        // Vector
        for (int i = 0; i < parr.size(); i++) window.draw(parr[i]);

        // Vertices
        window.draw(v1);
        window.draw(v2);
        window.draw(v3);
        window.draw(v4);
        window.draw(v5);
        window.draw(v6);

        // Text
        window.draw(instructions);
        window.draw(modeText);
        window.draw(md);

        // Show everything we just drew
        window.display();

    }

    return 0;
}
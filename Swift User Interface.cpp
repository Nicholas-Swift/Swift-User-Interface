// Swift User Interface.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Button.h"
#include "DropDown.h"

void Argh()
{
	std::cout<<"This is something amazing!"<<std::endl;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Swift User Interface");
    
	// Button
	/*swui::Button button(sf::Vector2f(200, 100), sf::Vector2f(20, 20));
	button.setOnClick(Argh);*/

	// Drop Down
	swui::DropDown dropdown(sf::Vector2f(200, 50), sf::Vector2f(20, 20), 5);

    while (window.isOpen())
    {
        sf::Event Event;
        while (window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
                window.close();
        }

		// Update
		//button.update(window);
		dropdown.update(window);

		// Draw
        window.clear();

		//window.draw(button);
		window.draw(dropdown);

        window.display();
    }

    return 0;
}
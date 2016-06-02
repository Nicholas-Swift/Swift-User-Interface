// Swift User Interface.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Swift User Interface");

	swui::Slider slider(sf::Vector2f(100, 100), sf::Vector2f(100, 100), sf::Vector2f(10, 10));

    while (window.isOpen())
    {
        sf::Event Event;
        while (window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
                window.close();
        }

		slider.update(window);

		// Draw
        window.clear();

		window.draw(slider);

        window.display();
    }

    return 0;
}
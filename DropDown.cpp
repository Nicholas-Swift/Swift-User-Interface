#include "stdafx.h"
#include "DropDown.h"
#include <SFML/Graphics.hpp>

swui::DropDown::DropDown(const sf::Vector2f& size, const sf::Vector2f& pos, const float& listNumber)
{
	// Create and add the different options
	for(int i = 0; i < listNumber; i++)
	{
		swui::Button button(size, pos + sf::Vector2f(0, size.y*i));
		m_buttons.push_back(button);
	}

	//
	m_showAll = true;
	
	m_currentlySelected = 0;
}

void swui::DropDown::update(sf::RenderWindow& window)
{
	mouseUpdate(window);
}

void swui::DropDown::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if(m_showAll)
		for(auto i = m_buttons.begin(); i != m_buttons.end(); ++i)
			target.draw(*i, states);
	else
		target.draw(m_buttons[0], states);
}

void swui::DropDown::mouseUpdate(sf::RenderWindow& window)
{
	// Hovering, Clicking, and Releasing
	for(std::size_t i = 0; i < m_buttons.size(); ++i)
	{
		m_buttons[i].update(window);
		if(i == m_currentlySelected)
			m_buttons[i].setFillColor(sf::Color::Yellow);
	}
}
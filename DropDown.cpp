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

	m_showAll = false;
	
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
		target.draw(m_buttons[m_currentlySelected], states);
}

void swui::DropDown::mouseUpdate(sf::RenderWindow& window)
{
	// Hovering, Clicking, and Releasing
	if(!m_showAll)
	{
		m_buttons[m_currentlySelected].update(window);
		buttonClicked(m_currentlySelected);
	}
	else
	{
		for(std::size_t i = 0; i < m_buttons.size(); ++i)
		{
			m_buttons[i].update(window);
			buttonClicked(i);
		}
	}

	auto tempColor = m_buttons[m_currentlySelected].getFillColor();
	tempColor.a = 150;
	m_buttons[m_currentlySelected].setFillColor(tempColor);
}

void swui::DropDown::buttonClicked(std::size_t i)
{
	if(m_buttons[i].getIsClicked())
	{
		m_buttons[i].setIsClicked(false);
		m_currentlySelected = i;
		m_showAll = !m_showAll;

		if(m_showAll)
		{
			for(std::size_t i = 0; i < m_buttons.size(); ++i)
			{
				m_buttons[i].setPosition(m_buttons[0].getPosition().x, m_buttons[0].getPosition().y + m_buttons[i].getSize().y*i);
			}
		}
		else
		{
			for(std::size_t i = 0; i < m_buttons.size(); ++i)
			{
				m_buttons[i].setPosition(m_buttons[0].getPosition());
			}
		}
	}
}
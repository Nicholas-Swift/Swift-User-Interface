////////////////////////////////////////////////////////////
//
// SwUI - Swift User Interface
// Copyright (C) 2016 Nicholas Swift (nicholas-swift.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

// Headers
#include "stdafx.h"
#include "DropDown.h"

// Default constructor
// size -> Size of the button
// pos -> Position of the button
// listNumber -> Initial number of elements in the drop down men
swui::DropDown::DropDown(const sf::Vector2f& size, const sf::Vector2f& pos, const int& listNumber)
{
	// Create and add the different options ------------ NOTE SWITCH THIS TO APPEND!!!!
	for(int i = 0; i < listNumber; i++)
	{
		swui::Button button(size, pos + sf::Vector2f(0, size.y*i));
		m_buttons.push_back(button);
	}

	m_showAll = false;
	m_changed = true;

	m_currentlySelected = 0;
}

// Update drop down menu
void swui::DropDown::update(const sf::RenderWindow& window)
{
	mouseUpdate(window);
}

// Draw the drop down menu
// target -> Target to draw to
void swui::DropDown::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if(m_showAll)
		for(auto i = m_buttons.begin(); i != m_buttons.end(); ++i)
			target.draw(*i, states);
	else
		target.draw(m_buttons[m_currentlySelected], states);
}

////////////////////////////////////////////////////////////

// Update drop down menu with mouse over -- used by update
void swui::DropDown::mouseUpdate(const sf::RenderWindow& window)
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

// Update drop down menu with click -- used by mouseUpdate
void swui::DropDown::buttonClicked(std::size_t i)
{
	if(m_buttons[i].getClicked())
	{
		m_buttons[i].setClicked(false);
		m_changed = true;
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

////////////////////////////////////////////////////////////

// Add button to the drop down
void swui::DropDown::append()
{
	//append button to vector at end
}

// Add button to the drop down
void swui::DropDown::append(int i)
{
	//add button to the vector at position i
}

// Remove button from the drop down
void swui::DropDown::remove()
{
	//remove button from end of vector
}

// Remove button from the drop down
void swui::DropDown::remove(int i)
{
	//remove button from vector at position i
}

// Set size of buttons
void swui::DropDown::setButtonSize(const sf::Vector2f& size)
{
	for(auto i = m_buttons.begin(); i != m_buttons.end(); ++i)
	{
		i->setSize(size);
	}
}

// Set size of buttons
void swui::DropDown::setButtonSize(const float& x, const float& y)
{
	for(auto i = m_buttons.begin(); i != m_buttons.end(); ++i)
	{
		i->setSize(x, y);
	}
}

// Get size of buttons
const sf::Vector2f& swui::DropDown::getButtonSize() const
{
	auto tempVector = sf::Vector2f(0, 0);
	if(m_buttons.size() > 0)
		tempVector = m_buttons[0].getSize();

	return(tempVector);
}

// Get size of button vector
const float& swui::DropDown::getSize() const
{
	return(m_buttons.size());
}

// Set position of the top right of drop down menu
void swui::DropDown::setPosition(const sf::Vector2f& pos)
{
	for(std::size_t i = 0; i < m_buttons.size(); ++i)
	{
		m_buttons[i].setPosition(pos.x, pos.y + m_buttons[i].getSize().y*i);
	}
}

// Set position of the top right of drop down menu
void swui::DropDown::setPosition(const float& x, const float& y)
{
	for(std::size_t i = 0; i < m_buttons.size(); ++i)
	{
		m_buttons[i].setPosition(x, y + m_buttons[i].getSize().y*i);
	}
}

// Get position of the top right of drop down menu
const sf::Vector2f& swui::DropDown::getPosition() const
{
	sf::Vector2f tempVector = sf::Vector2f(0, 0);
	if(m_buttons.size() > 0)
		tempVector = m_buttons[0].getPosition();

	return(tempVector);
}

// Set and get if the default element in drop down was changed
void swui::DropDown::setChanged(const bool& b)
{
	m_changed = b;
}

// Get whether the default element in drop down was changed
const bool& swui::DropDown::getChanged() const
{
	return(m_changed);
}

// Set what button is currently selected
void swui::DropDown::setCurrentlySelected(const int& f)
{
	if(f > m_buttons.size())
		printf("swui::DropDown::setCurrentlySelected(const int& f) failed. f > m_buttons.size().", 'a');
	else
		m_currentlySelected = f;
}

// Get what button is currently selected
const int& swui::DropDown::getCurrentlySelected() const
{
	return(m_currentlySelected);
}

// Set whether the drop down menu is currently showing all elements
void swui::DropDown::setShowAll(const bool& b)
{
	m_showAll = b;
}

// Get whether the drop down menu is currently showing all elements
const bool& swui::DropDown::getShowAll() const
{
	return(m_showAll);
}
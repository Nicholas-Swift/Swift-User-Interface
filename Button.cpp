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
#include "Button.h"

// Default constructor
// size -> Size of the button
// pos -> Position of the button
swui::Button::Button(const sf::Vector2f& pos, const sf::Vector2f& size)
{
	// Set the size and position of the RectangleShape
	setPosition(pos);
	setSize(size);

	// Make sure nothing is hovered when initalized
	m_hovered = m_held = m_clicked = false;
}

// Update button with mouse over and click
void swui::Button::update(const sf::RenderWindow &window)
{
	// Update RectangleShape
	sf::RectangleShape::update();

	// Update Button with mouse
	mouseUpdate(window);
}

////////////////////////////////////////////////////////////

// Update the button with mouse over and click -- used by update
void swui::Button::mouseUpdate(const sf::RenderWindow& window)
{
	// Hovering, Clicking, and Releasing
	if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
			? m_hovered = true : m_hovered = false;

		if(m_held && m_hovered)
			m_clicked = true;
		m_held = false;
	}
	else
	{
		if(m_hovered)
			m_held = true;
	}

	// Change color of m_rect
	if(m_held)
		setFillColor(sf::Color::Blue);
	else if(m_hovered)
		setFillColor(sf::Color::Green);
	else
		setFillColor(sf::Color::Red);
}

////////////////////////////////////////////////////////////

// Set if button is hovered
void swui::Button::setHovered(const bool& b)
{
	m_hovered = b;
}

// Get if button is hovered
const bool& swui::Button::getHovered() const
{
	return m_hovered;
}

// Set if button is held
void swui::Button::setHeld(const bool& b)
{
	m_held = b;
}

// Get if button is held
const bool& swui::Button::getHeld() const
{
	return m_held;
}

// Set if button is clicked
void swui::Button::setClicked(const bool& b)
{
	m_clicked = b;
}

// Get if button is clicked
const bool& swui::Button::getClicked() const
{
	return m_clicked;
}
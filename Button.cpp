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
swui::Button::Button(const sf::Vector2f& size, const sf::Vector2f& pos, void (*func)(void))
{
	// Set the size and position of the RectangleShape
	m_rect.setSize(size);
	m_rect.setPosition(pos);

	// Set the size and position of the Sprite
	m_sprite.setTextureRect(sf::IntRect(m_rect.getGlobalBounds()));
	m_sprite.setPosition(pos);

	// Make sure nothing is hovered when initalized
	m_isHovered = m_isHeld = m_isClicked = false;

	//FMEWTEMPTEMPTEPMTPEWFOIEJWOFIJ EJTEMP TJEOWIFJOEW TEMP
	m_func = func;
}

// Update button with mouse over and click
void swui::Button::update(const sf::RenderWindow &window)
{
	// Hovering, Clicking, and Releasing
	if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_rect.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
			? m_isHovered = true : m_isHovered = false;

		if(m_isHeld && m_isHovered)
		{
			//TEMPJFIOEWIJOTEMPTMEOMFIWOJOETMPEOFWIEJOTEMP
			if(m_func)
				m_func();

			m_isClicked = true;
		}
		m_isHeld = false;
	}
	else
	{
		if(m_isHovered)
			m_isHeld = true;
	}

	// Change color of m_rect
	if(m_isHeld)
		m_rect.setFillColor(sf::Color::Blue);
	else if(m_isHovered)
		m_rect.setFillColor(sf::Color::Green);
	else
		m_rect.setFillColor(sf::Color::Red);
}

// Draw the button
void swui::Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Draw m_rect
	target.draw(m_rect, states);

	// Draw m_sprite
	target.draw(m_sprite, states);
}

void swui::Button::setSize(const sf::Vector2f& size)
{
	m_rect.setSize(size);
	m_sprite.setTextureRect(sf::IntRect(m_rect.getGlobalBounds()));
}

const sf::Vector2f& swui::Button::getSize() const
{
	return(m_rect.getSize());
}

void swui::Button::setPosition(const sf::Vector2f& pos)
{
	m_rect.setPosition(pos);
	m_sprite.setPosition(pos);
}

void swui::Button::setPosition(const float& x, const float& y)
{
	m_rect.setPosition(x, y);
	m_sprite.setPosition(x, y);
}

const sf::Vector2f& swui::Button::getPosition() const
{
	return(m_rect.getPosition());
}

void swui::Button::setFillColor(const sf::Color& color)
{
	m_rect.setFillColor(color);
}

const sf::Color& swui::Button::getFillColor() const
{
	return(m_rect.getFillColor());
}

void swui::Button::setIsClicked(const bool& b)
{
	m_isClicked = b;
}

const bool& swui::Button::getIsClicked() const
{
	return m_isClicked;
}

void swui::Button::setOnClick(void (*func)())
{
	m_func = func;
}
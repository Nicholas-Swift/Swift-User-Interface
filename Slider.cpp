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

#include "stdafx.h"
#include "Slider.h"

#include <iostream>

// Default constructor
// pos -> Position of the slider
// barSize -> Size of the bar
// buttonSize -> Size of the button
swui::Slider::Slider(sf::Vector2f pos, sf::Vector2f barSize, sf::Vector2f buttonSize)
{
	sf::RectangleShape::setPosition(pos);
	setSize(barSize);

	m_button.setPosition(pos);
	m_button.setSize(buttonSize);

	setPercent(0.f);
}

// Update slider
// window -> Window to get info from (size, relative mouse, etc.)
void swui::Slider::update(const sf::RenderWindow& window)
{
	// Update Bar and Button
	sf::RectangleShape::update();
	m_button.update(window);

	// Update the position of button with mouse
	mouseUpdate(window);

	// Update the percentage
	percentUpdate();
}

// Draw slider
// target -> Target to draw to
void swui::Slider::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//DRAW THE SHIT??
	target.draw(m_button);
}

////////////////////////////////////////////////////////////

// Update button with mouse over and click -- used by update
void swui::Slider::mouseUpdate(const sf::RenderWindow& window)
{
	if(m_button.getHeld())
	{
		// Moving and setting position of the actual 
		auto pos = sf::Mouse::getPosition(window).x;

		if(pos < getPosition().x)
			pos = getPosition().x - m_button.getSize().x/2;
		else if(pos > getPosition().x + getSize().x)
			pos = getPosition().x + getSize().x - m_button.getSize().x/2;
		else
			pos = pos - m_button.getSize().x/2;

		m_button.setPosition(pos, m_button.getPosition().y);
	}
}

// Update float percentage -- used by update
void swui::Slider::percentUpdate()
{
	if(m_button.getHeld())
	{
		// Calculating the float percent for where the button is
		auto buttonPos = m_button.getPosition().x + m_button.getSize().x/2;
		((buttonPos - getPosition().x) > 0) ?
			m_percent = (buttonPos - getPosition().x) / getSize().x :
			m_percent = 0;
		m_percent = ceil(m_percent*100 - 0.5)/100;

		if(m_percent < 0)
			setPercent(0.f);
	}
}

////////////////////////////////////////////////////////////

// Set float percentage
void swui::Slider::setPercent(const float& f)
{
	m_percent = ceil(f*100 - 0.5)/100;
	m_button.setPosition(getPosition().x + getSize().x*m_percent - m_button.getSize().x/2, m_button.getPosition().y);
}

// Get float percentage
const float& swui::Slider::getPercent() const
{
	return(m_percent);
}
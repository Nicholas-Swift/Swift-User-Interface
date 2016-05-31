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
// size -> Size of the button
// pos -> Position of the button
swui::Slider::Slider(sf::Vector2f barSize, sf::Vector2f buttonSize, sf::Vector2f pos)
{
	m_bar.setSize(barSize);
	m_bar.setPosition(pos);
	m_bar.setFillColor(sf::Color::Red);

	m_button.setSize(buttonSize);
	m_button.setPosition(pos.x, m_bar.getPosition().y + m_bar.getSize().y/2 - m_button.getSize().y/2);

	setPercent(0.f);
}

// Update slider
void swui::Slider::update(const sf::RenderWindow& window)
{
	m_button.update(window);
	if(m_button.getHeld())
	{
		// Moving and setting position of the actual 
		auto pos = sf::Mouse::getPosition(window).x;

		if(pos < m_bar.getPosition().x)
			pos = m_bar.getPosition().x - m_button.getSize().x/2;
		else if(pos > m_bar.getPosition().x + m_bar.getSize().x)
			pos = m_bar.getPosition().x + m_bar.getSize().x - m_button.getSize().x/2;
		else
			pos = pos - m_button.getSize().x/2;

		m_button.setPosition(pos, m_button.getPosition().y);

		// Calculating the float percent for where the button is
		auto buttonPos = m_button.getPosition().x + m_button.getSize().x/2;
		((buttonPos - m_bar.getPosition().x) > 0) ?
			m_percent = (buttonPos - m_bar.getPosition().x) / m_bar.getSize().x :
			m_percent = 0;
		m_percent = ceil(m_percent*100 - 0.5)/100;

		if(m_percent < 0)
			setPercent(0.f);
	}
}

// Draw slider
// target -> Target to draw to
void swui::Slider::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_bar);
	target.draw(m_button);
}

////////////////////////////////////////////////////////////

// Set position
void swui::Slider::setPosition(const float& x, const float& y)
{
	m_bar.setPosition(x, y);

	m_button.setPosition(x, m_bar.getPosition().y + m_bar.getSize().y/2 - m_button.getSize().y/2);
}

// Set position
void swui::Slider::setPosition(const sf::Vector2f& pos)
{
	m_bar.setPosition(pos);

	m_button.setPosition(pos.x, m_bar.getPosition().y + m_bar.getSize().y/2 - m_button.getSize().y/2);
}

// Get position
const sf::Vector2f& swui::Slider::getPosition() const
{
	return(m_bar.getPosition());
}

// Set bar size
void swui::Slider::setBarSize(const float& x, const float& y)
{
	m_bar.setSize(sf::Vector2f(x, y ));

	setPosition(m_bar.getPosition());
}

// Set bar size
void swui::Slider::setBarSize(const sf::Vector2f& size)
{
	m_bar.setSize(size);

	setPosition(m_bar.getPosition());
}

// Get bar size
const sf::Vector2f& swui::Slider::getBarSize() const
{
	return(m_bar.getSize());
}

// Set button size
void swui::Slider::setButtonSize(const float& x, const float& y)
{
	m_button.setSize(x, y);

	setPosition(m_bar.getPosition());
}

// Set button size
void swui::Slider::setButtonSize(const sf::Vector2f& size)
{
	m_button.setSize(size);

	setPosition(m_bar.getPosition());
}

// Get button size
const sf::Vector2f& swui::Slider::getButtonSize() const
{
	return(m_button.getSize());
}

// Set float percentage
void swui::Slider::setPercent(const float& f)
{
	m_percent = ceil(f*100 - 0.5)/100;
	m_button.setPosition(m_bar.getPosition().x + m_bar.getSize().x*m_percent - m_button.getSize().x/2, m_button.getPosition().y);
}

// Get float percentage
const float& swui::Slider::getPercent() const
{
	return(m_percent);
}
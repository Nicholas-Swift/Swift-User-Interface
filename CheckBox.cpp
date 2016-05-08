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
#include "CheckBox.h"

// Default constructor
// size -> Size of the button
// pos -> Position of the button
// checked -> Whether the button is initially checked or not
swui::CheckBox::CheckBox(const sf::Vector2f& size, const sf::Vector2f& pos, const bool& checked)
{
	m_button.setSize(size);
	m_button.setPosition(pos);

	m_checked = checked;
}

// Update check box
void swui::CheckBox::update(sf::RenderWindow& window)
{
	m_button.update(window);
	if(m_button.getClicked())
	{
		m_button.setClicked(false);
		m_checked = !m_checked;
	}

	if(m_checked)
	{
		auto tempColor = m_button.getFillColor();
		tempColor.a = 150;
		m_button.setFillColor(tempColor);
	}
}

// Draw check box
// target -> Target to draw to
void swui::CheckBox::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_button, states);
}

////////////////////////////////////////////////////////////

// Set and get whether the check box is checked
void swui::CheckBox::setChecked(bool& b)
{
	m_checked = b;
}

const bool& swui::CheckBox::getChecked() const
{
	return(m_checked);
}


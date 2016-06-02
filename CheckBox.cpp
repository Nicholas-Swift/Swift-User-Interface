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
swui::CheckBox::CheckBox(const sf::Vector2f& pos, const sf::Vector2f& size, const bool& checked)
{
	setPosition(pos);
	setSize(size);

	m_checked = checked;
}

// Update check box
void swui::CheckBox::update(sf::RenderWindow& window)
{
	// Update Button
	swui::Button::update(window);

	// Update the Check Box portion
	checkedUpdate();
}

////////////////////////////////////////////////////////////

void swui::CheckBox::checkedUpdate()
{
	// The Check Box is clicked!
	if(getClicked())
	{
		setClicked(false);
		m_checked = !m_checked;
	}

	// If it's checked, change the color
	if(m_checked)
	{
		auto tempColor = getFillColor();
		tempColor.a = 150;
		setFillColor(tempColor);
	}
}

////////////////////////////////////////////////////////////

// Set whether the check box is checked
void swui::CheckBox::setChecked(bool& b)
{
	m_checked = b;
}

// Get whether the check box is checked
const bool& swui::CheckBox::getChecked() const
{
	return(m_checked);
}


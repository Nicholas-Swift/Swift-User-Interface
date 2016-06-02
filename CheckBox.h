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

#ifndef CHECKBOX_H
#define CHECKBOX_H

// Headers
#include "Button.h"

namespace swui
{
// Specialized object representing a check box
class CheckBox : public swui::Button
{
public:

	// Default constructor
    // size -> Size of the button
	// pos -> Position of the button
	// checked -> Whether the button is initially checked or not
	explicit CheckBox(const sf::Vector2f& pos = sf::Vector2f(0, 0), const sf::Vector2f& size = sf::Vector2f(0, 0), const bool& checked = false);

	// Update check box
	// window -> Window to get info from (size, relative mouse, etc.)
	void update(sf::RenderWindow& window);

private:

	// Update check box with click and color
	void checkedUpdate();

public:

	// Set and get whether the check box is checked
	void setChecked(bool& b);
	const bool& getChecked() const;

private:

	// Bool for whether check box is checked
	bool m_checked;
};

} //namespace swui

#endif
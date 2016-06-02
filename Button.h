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

#ifndef BUTTON_H
#define BUTTON_H

// Headers
#include <SFML/Graphics.hpp>

namespace swui
{
// Specialized object representing a button
class Button : public sf::RectangleShape
{
public:

    // Default constructor
    // size -> Size of the button
	// pos -> Position of the button
	explicit Button(const sf::Vector2f& pos = sf::Vector2f(0, 0), const sf::Vector2f& size = sf::Vector2f(0, 0));

	// Update button
	// window -> Window to get info from (size, relative mouse, etc.)
	void update(const sf::RenderWindow& window);
	
private:

	// Update button with mouse over and click -- used by update
	void mouseUpdate(const sf::RenderWindow& window);

public:

	// Set and get if button is hovered
	void setHovered(const bool& b);
	const bool& getHovered() const;

	// Set and get if button is held
	void setHeld(const bool& b);
	const bool& getHeld() const;

	// Set and get if button is clicked
	void setClicked(const bool& b);
	const bool& getClicked() const;

private:

	// Bools for button hovering, holding, and clicking
	bool m_hovered, m_held, m_clicked;
};

} //namespace sf

#endif
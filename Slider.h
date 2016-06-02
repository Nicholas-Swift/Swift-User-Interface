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

#ifndef SLIDER_H
#define SLIDER_H

// Headers
#include "Button.h"

namespace swui
{
// Specialized object representing a slider
class Slider : public sf::RectangleShape
{
public:

	// Default constructor
    // pos -> Position of the slider
	// barSize -> Size of the bar
	// buttonSize -> Size of the button
	explicit Slider(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f barSize = sf::Vector2f(0, 0), sf::Vector2f buttonSize = sf::Vector2f(0, 0));

	// Update slider
	// window -> Window to get info from (size, relative mouse, etc.)
	void update(const sf::RenderWindow& window);

	// Draw slider
	// target -> Target to draw to
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	
	// Update button with mouse over and click -- used by update
	void mouseUpdate(const sf::RenderWindow& window);

	// Update float percentage -- used by update
	void percentUpdate();

public:

	// Set and get float percentage
	void setPercent(const float& f);
	const float& getPercent() const;

public:

	//Button
	swui::Button m_button;

private:

	// Float
	float m_percent;
};

} //namespace swui

#endif
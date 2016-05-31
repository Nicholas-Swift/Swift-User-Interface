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

#ifndef DROPDOWN_H
#define DROPDOWN_H

// Headers
#include "Button.h"

namespace swui
{
// Specialized object representing a drop down menu
class DropDown : public sf::Drawable
{
public:

	// Default constructor
    // size -> Size of the button
	// pos -> Position of the button
	// listNumber -> Initial number of elements in the drop down menu
	explicit DropDown(const sf::Vector2f& size = sf::Vector2f(0, 0), const sf::Vector2f& pos = sf::Vector2f(0, 0), const int& listNumber = 0);

	// Update drop down menu
	void update(const sf::RenderWindow& window);

	// Draw the drop down menu
    // target -> Target to draw to
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

	// Update drop down menu with mouse over -- used by update
	void mouseUpdate(const sf::RenderWindow& window);

	// Update drop down menu with click -- used by mouseUpdate
	void buttonClicked(std::size_t i);

public:

	// Add and remove buttons from the drop down
	void append();
	void append(int i);
	void remove();
	void remove(int i);

	// Set and get size of buttons
	void setButtonSize(const sf::Vector2f& size);
	void setButtonSize(const float& x, const float& y);
	const sf::Vector2f& getButtonSize() const;

	// Get size of button vector
	const float& getSize() const;

	// Set and get position of the top right of drop down menu
	void setPosition(const sf::Vector2f& pos);
	void setPosition(const float& x, const float& y);
	const sf::Vector2f& getPosition() const;

	// Set and get if the default element in drop down was changed
	void setChanged(const bool& b);
	const bool& getChanged() const;

	// Set and get what button is currently selected
	void setCurrentlySelected(const int& f);
	const int& getCurrentlySelected() const;

	// Set and get whether the drop down menu is currently showing all elements
	void setShowAll(const bool& b);
	const bool& getShowAll() const;

private:

	// Vector of buttons in drop down menu
	std::vector<Button> m_buttons;

	// If something in the drop down menu was clicked / changed
	bool m_changed;

	// The button that is currently selected
	int m_currentlySelected;

	// Whether the drop down menu is showing all elements or not
	bool m_showAll;
};

} //namespace swui

#endif
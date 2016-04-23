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

#ifndef UIBUTTON_H
#define UIBUTTON_H

// Headers
#include <SFML/Graphics.hpp>

namespace swui
{
// Specialized object representing a button
class SFML_GRAPHICS_API Button : public sf::Drawable
{
public:

    // Default constructor
    // size -> Size of the button
	// pos -> Position of the button
	explicit Button(const sf::Vector2f& size = sf::Vector2f(0, 0), const sf::Vector2f& pos = sf::Vector2f(0, 0), void (*func)(void) = NULL);

	// Update button with mouse over and click
	void update(const sf::RenderWindow& window);

    // Draw the button
    // target -> Target to draw to
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:

	// Set and get size of button
	void setSize(const sf::Vector2f& size);
	const sf::Vector2f& getSize() const;

	// Set and get position of button
	void setPosition(const sf::Vector2f& pos);
	void setPosition(const float& x, const float& y);
	const sf::Vector2f& getPosition() const;

	// Set and get color of button
	void setFillColor(const sf::Color& color);
	const sf::Color& getFillColor() const;

	// Set and get default texture of button
	void setDefaultTexture(const sf::Texture& texture);
	const sf::Texture& getDefaultTexture() const;

	// Set and get hover texture of button
	void setHoverTexture(const sf::Texture& texture);
	const sf::Texture& getHoverTexture() const;

	// Set and get held texture of button
	void setHeldTexture(const sf::Texture& texture);
	const sf::Texture& getHeldTexture() const;

	// Set and get if button is clicked
	void setIsClicked(const bool& b);
	const bool& getIsClicked() const;

	// Set on click function TEMP TEMP TEMP TEMPT EMPTE MTPEMTPEPTEMPTMEJTOEJTOETMEPTJWIEOJRORJ
	void setOnClick(void (*myFunc)());

private:
	// Rectangle for button
	sf::RectangleShape m_rect;

	// Sprite for button
	sf::Sprite m_sprite;

	// Bools for button hovering, holding, and clicking
	bool m_isHovered, m_isHeld, m_isClicked;

	// Button onClick function
	void (*m_func)();
};

} //namespace sf

#endif
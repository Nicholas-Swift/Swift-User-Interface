////////////////////////////////////////////////////////////
//
// SwUI - Swift User Interface
// Copyright (C) 2016 Nicholas Swift (nicholas@nicholas-swift.com)
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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Export.hpp>

namespace swui
{
////////////////////////////////////////////////////////////
/// \brief Specialized object representing a button
///
////////////////////////////////////////////////////////////
class SFML_GRAPHICS_API Button : public sf::Drawable
{
public:

    /// \brief Default constructor
    /// \param size Size of the button
	/// \param pos Position of the button
	explicit Button(const sf::Vector2f& size = sf::Vector2f(0, 0), const sf::Vector2f& pos = sf::Vector2f(0, 0), void (*func)(void) = nullptr);

	/// \brief Update button with mouse over and click
	void update(sf::RenderWindow& window);

    /// \brief Draw the button
    /// \param target Target to draw to
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:

	// Set size of button
	void setSize(const sf::Vector2f& size);
	const sf::Vector2f& getSize() const;

	// Set color of button
	void setFillColor(const sf::Color& color);
	const sf::Color& getColor() const;

	// Set default texture of button
	void setDefaultTexture(const sf::Texture& texture);
	const sf::Texture& getDefaultTexture() const;

	// Set hover texture of button
	void setHoverTexture(const sf::Texture& texture);
	const sf::Texture& getHoverTexture() const;

	// Set held texture of button
	void setHeldTexture(const sf::Texture& texture);
	const sf::Texture& getHeldTexture() const;

	// Get state of button
	const std::size_t getState() const;

	// Set on click function
	void setOnClick(void (*func)(void));

private:

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
	sf::RectangleShape m_rect; ///< Rect for button

	sf::Sprite m_sprite; ///< Sprite for button

	bool m_isHovered, m_isHeld, m_isClicked;///< Bools for button

	void (*m_myFunc)(void);
};

} //namespace sf

#endif
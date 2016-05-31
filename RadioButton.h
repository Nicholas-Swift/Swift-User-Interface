#ifndef RADIO_BUTTON_H
#define RADIO_BUTTON_H

#include "Button.h"

namespace swui
{
class RadioButton : public sf::Drawable
{
public:

	// Default constructor
    // size -> Size of the button
	// pos -> Position of the button
	// listNumber -> Initial number of elements in the drop down menu
	explicit RadioButton(const sf::Vector2f& size = sf::Vector2f(0, 0), const sf::Vector2f& pos = sf::Vector2f(0, 0), const int& listNumber = 1);

	// Update drop down menu
	void update(const sf::RenderWindow& window);

	// Draw the drop down menu
    // target -> Target to draw to
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

	// Update drop down menu with mouse over -- used by update
	void mouseUpdate(const sf::RenderWindow& window);

	// Update radio buton menu with click -- used by mouseUpdate
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

	// Set and get position of the top right of the radio button
	void setPosition(const sf::Vector2f& pos);
	void setPosition(const float& x, const float& y);
	const sf::Vector2f& getPosition() const;

	// Set and get if the default element in drop down was changed
	void setChanged(const bool& b);
	const bool& getChanged() const;

	// Set and get what button is currently selected
	void setCurrentlySelected(const int& f);
	const int& getCurrentlySelected() const;

private:

	// Vector of buttons in drop down menu
	std::vector<swui::Button> m_buttons;

	// If something in the drop down menu was clicked / changed
	bool m_changed;

	// The button that is currently selected
	int m_currentlySelected;
};
}

#endif
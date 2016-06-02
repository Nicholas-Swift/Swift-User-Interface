#ifndef MENU_H
#define MENU_H

#include "Button.h"
#include "CheckBox.h"
#include "Slider.h"
#include "RadioButton.h"
#include "DropDown.h"

namespace swui
{
class Menu : public sf::Drawable
{
public:
	// Default constructor
	// size -> Size of the button
	// pos -> Position of the button
	explicit Menu(sf::Vector2f position = sf::Vector2f(0, 0), sf::Vector2f size = sf::Vector2f(0, 0));
	
	void update(sf::RenderWindow &window);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	//Set and get position of menu
	void setPosition(sf::Vector2f& position);
	void setPosition(float& x, float& y);
	const sf::Vector2f& getPosition() const;

	//Set size of menu
	void setSize(sf::Vector2f& size);
	void setSize(float& x, float& y);
	const sf::Vector2f& getSize() const;

	//append and get buttons
	void appendButton(swui::Button button);
	void removeButton();
	void removeButton(int i);

	//append and get checkboxes
	void appendCheckBox(swui::CheckBox checkbox);
	void removeCheckBox();
	void removeCheckBox(int i);

	//append and get sliders
	void appendSlider(swui::Slider slider);
	void removeSlider();
	void removeSlider(int i);

	//append and get radiobuttons
	void appendRadioButton(swui::RadioButton radiobutton);
	void removeRadioButton();
	void removeRadioButton(int i);

	//append and get dropdowns
	void appendDropDown(swui::DropDown dropdown);
	void removeDropDown();
	void removeDropDown(int i);

private:
	void clearLists();

private:
	sf::RectangleShape m_rect;

	std::vector<swui::Button> m_buttonList;
	std::vector<swui::CheckBox> m_checkboxList;
	std::vector<swui::Slider> m_sliderList;
	std::vector<swui::RadioButton> m_radiobuttonList;
	std::vector<swui::DropDown> m_dropdownList;
};
}

#endif
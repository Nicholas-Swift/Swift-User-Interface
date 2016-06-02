#include "stdafx.h"
#include "Menu.h"

swui::Menu::Menu(sf::Vector2f position, sf::Vector2f size)
{
	m_rect.setPosition(position);
	m_rect.setSize(size);

	sf::Color color = sf::Color::White; color.a = 150;
	m_rect.setFillColor(color);

	clearLists();
}

void swui::Menu::update(sf::RenderWindow& window)
{
	for(auto i = m_buttonList.begin(); i != m_buttonList.end(); ++i)
		i->update(window);

	for(auto i = m_checkboxList.begin(); i != m_checkboxList.end(); ++i)
		i->update(window);

	for(auto i = m_sliderList.begin(); i != m_sliderList.end(); ++i)
		i->update(window);

	for(auto i = m_radiobuttonList.begin(); i != m_radiobuttonList.end(); ++i)
		i->update(window);

	for(auto i = m_dropdownList.begin(); i != m_dropdownList.end(); ++i)
		i->update(window);
}

void swui::Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_rect);

	for(auto i = m_buttonList.begin(); i != m_buttonList.end(); ++i)
		target.draw(*i);

	for(auto i = m_checkboxList.begin(); i != m_checkboxList.end(); ++i)
		target.draw(*i);

	for(auto i = m_sliderList.begin(); i != m_sliderList.end(); ++i)
		target.draw(*i);

	for(auto i = m_radiobuttonList.begin(); i != m_radiobuttonList.end(); ++i)
		target.draw(*i);

	for(auto i = m_dropdownList.begin(); i != m_dropdownList.end(); ++i)
		target.draw(*i);
}

////////////////////////////////////

// Set position of menu
void swui::Menu::setPosition(sf::Vector2f& position)
{
	m_rect.setPosition(position);
}

// Set position of menu
void swui::Menu::setPosition(float& x, float& y)
{
	setPosition(sf::Vector2f(x, y));
}

// Get position of menu
const sf::Vector2f& swui::Menu::getPosition() const
{
	return(m_rect.getPosition());
}

// Set size of menu
void swui::Menu::setSize(sf::Vector2f& size)
{
	m_rect.setSize(size);
}

// Set size of menu
void swui::Menu::setSize(float& x, float& y)
{
	setSize(sf::Vector2f(x, y));
}

// Get size of menu
const sf::Vector2f& swui::Menu::getSize() const
{
	return(m_rect.getSize());
}

void swui::Menu::appendButton(swui::Button button)
{
	m_buttonList.push_back(button);
}

void swui::Menu::removeButton()
{
	m_buttonList.erase(m_buttonList.end());
}

//////
void swui::Menu::appendCheckBox(swui::CheckBox checkbox)
{
	m_checkboxList.push_back(checkbox);
}

void swui::Menu::removeCheckBox()
{
	m_checkboxList.erase(m_checkboxList.end());
}

///////
void swui::Menu::appendSlider(swui::Slider slider)
{
	m_sliderList.push_back(slider);
}

void swui::Menu::removeSlider()
{
	m_sliderList.erase(m_sliderList.end());
}

void swui::Menu::appendRadioButton(swui::RadioButton radiobutton)
{
	m_radiobuttonList.push_back(radiobutton);
}

void swui::Menu::removeRadioButton()
{
	m_radiobuttonList.erase(m_radiobuttonList.end());
}

void swui::Menu::appendDropDown(swui::DropDown dropdown)
{
	m_dropdownList.push_back(dropdown);
}

void swui::Menu::removeDropDown()
{
	m_dropdownList.erase(m_dropdownList.end());
}

/////////////
void swui::Menu::clearLists()
{
	m_buttonList.clear();
	m_checkboxList.clear();
	m_sliderList.clear();
	m_radiobuttonList.clear();
	m_dropdownList.clear();
}
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
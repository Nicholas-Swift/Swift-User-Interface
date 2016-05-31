#include "stdafx.h"
#include "RadioButton.h"

swui::RadioButton::RadioButton(const sf::Vector2f& size, const sf::Vector2f& pos, const int& listNumber)
{
	for(int i = 0; i < listNumber; ++i)
	{
		auto button = swui::Button(size, pos + sf::Vector2f(size.x * i, 0));

		m_buttons.push_back(button);
	}

	m_currentlySelected = 0;
}

void swui::RadioButton::update(const sf::RenderWindow &window)
{
	mouseUpdate(window);
}

// Draw the drop down menu
// target -> Target to draw to
void swui::RadioButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(auto i = m_buttons.begin(); i != m_buttons.end(); ++i)
		target.draw(*i, states);
}

//////////////////////////

// Update drop down menu with mouse over -- used by update
void swui::RadioButton::mouseUpdate(const sf::RenderWindow& window)
{
	for(std::size_t i = 0; i < m_buttons.size(); ++i)
	{
		m_buttons[i].update(window);
		buttonClicked(i);
	}

	if(m_buttons.size() > 0)
	{
		auto tempColor = m_buttons[m_currentlySelected].getFillColor();
		tempColor.a = 150;
		m_buttons[m_currentlySelected].setFillColor(tempColor);
	}
}

// Update drop down menu with click -- used by mouseUpdate
void swui::RadioButton::buttonClicked(std::size_t i)
{
	if(m_buttons[i].getClicked())
	{
		m_buttons[i].setClicked(false);
		m_changed = true;
		m_currentlySelected = i;
	}
}

///////////////////////////

const int& swui::RadioButton::getCurrentlySelected() const
{
	return(m_currentlySelected);
}
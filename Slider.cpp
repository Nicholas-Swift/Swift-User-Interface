#include "stdafx.h"
#include "Slider.h"

// Default constructor
// size -> Size of the button
// pos -> Position of the button
swui::Slider::Slider(sf::Vector2f size, sf::Vector2f pos)
{
	m_bar.setSize(sf::Vector2f(size.x, size.y/2));
	m_bar.setPosition(pos);
	m_bar.setFillColor(sf::Color::Red);

	m_button.setSize(size.y, size.y);
	m_button.setPosition(pos.x, pos.y);
}

// Update slider
void swui::Slider::update(const sf::RenderWindow& window)
{
	m_button.update(window);
	if(m_button.getHeld())
	{
		auto pos = sf::Mouse::getPosition(window).x;

		if(pos < m_bar.getPosition().x)
			pos = m_bar.getPosition().x - m_button.getSize().x/2;
		else if(pos > m_bar.getPosition().x + m_bar.getSize().x)
			pos = m_bar.getPosition().x + m_bar.getSize().x - m_button.getSize().x/2;
		else
			pos = pos - m_button.getSize().x/2;

		m_button.setPosition(pos, m_button.getPosition().y);
	}
}

// Draw slider
// target -> Target to draw to
void swui::Slider::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_bar);
	target.draw(m_button);
}
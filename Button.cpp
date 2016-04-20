#include "stdafx.h"
#include "Button.h"
#include <SFML/Graphics.hpp>

swui::Button::Button(const sf::Vector2f& size, const sf::Vector2f& pos, void (*func)(void))
{
	m_rect.setSize(size);
	m_rect.setPosition(pos);

	m_sprite.setTextureRect(sf::IntRect(m_rect.getGlobalBounds()));
	m_sprite.setPosition(pos);

	m_isHovered = m_isHeld = m_isClicked = false;

	m_myFunc = func;
}

void swui::Button::update(sf::RenderWindow &window)
{
	// Hovering, Clicking, and Releasing
	if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		m_rect.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)
			? m_isHovered = true : m_isHovered = false;

		if(m_isHeld && m_isHovered)
		{
			//m_myFunc(); // PROBLEMS WITH THIS WHEN NOTHING THERE!!!!!!!!
			printf("Button was clicked!", 'c');
			m_isClicked = true;
		}
		m_isHeld = false;
	}
	else
	{
		if(m_isHovered)
			m_isHeld = true;
	}

	// Change color of m_rect
	if(m_isHeld)
		m_rect.setFillColor(sf::Color::Blue);
	else if(m_isHovered)
		m_rect.setFillColor(sf::Color::Green);
	else
		m_rect.setFillColor(sf::Color::Red);
}

void swui::Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// Draw m_rect
	target.draw(m_rect, states);

	// Draw m_sprite
	target.draw(m_sprite, states);
}

void swui::Button::setSize(const sf::Vector2f& size)
{
	m_rect.setSize(size);
	m_sprite.setTextureRect(sf::IntRect(m_rect.getGlobalBounds()));
}

const sf::Vector2f& swui::Button::getSize() const
{
	return(m_rect.getSize());
}

void swui::Button::setFillColor(const sf::Color& color)
{
	m_rect.setFillColor(color);
}

const sf::Color& swui::Button::getColor() const
{
	return(m_rect.getFillColor());
}

const std::size_t swui::Button::getState() const
{
	if(m_isClicked)
		return(3);
	else if(m_isHeld)
		return(2);
	else if(m_isHovered)
		return(1);
	else
		return(0);
}

void swui::Button::setOnClick(void (*func)(void))
{
	m_myFunc = func;
}
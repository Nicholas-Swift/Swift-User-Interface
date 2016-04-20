#ifndef UIDROPDOWN_H
#define UIDROPDOWN_H

#include "Button.h"

namespace swui
{

class DropDown : public sf::Drawable
{
public:
	explicit DropDown(const sf::Vector2f& size = sf::Vector2f(0, 0), const sf::Vector2f& pos = sf::Vector2f(0, 0), const float& listNumber = 0.f);

	void update(sf::RenderWindow& window);
	void append();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	void mouseUpdate(sf::RenderWindow& window);

private:
	std::vector<Button> m_buttons;
	int m_currentlySelected;
	bool m_showAll;
};

} //namespace swui

#endif
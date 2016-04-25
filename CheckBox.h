#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "Button.h"

class CheckBox : public sf::Drawable
{
public:
	explicit CheckBox(const sf::Vector2f& size = sf::Vector2f(0, 0), const sf::Vector2f& pos = sf::Vector2f(0, 0), const bool& checked = false);

	void update(sf::RenderWindow& window);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:

private:

};

#endif
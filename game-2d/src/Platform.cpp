#include "Platform.h"

Platform::Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position)
{
    block.setTexture(texture);
    block.setOrigin(size / 2.0f);
    block.setSize(size);
    block.setPosition(position);
}
void Platform::draw(sf::RenderWindow& window)
{
    window.draw(block);
}
Platform::~Platform()
{
    //dtor
}

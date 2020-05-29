#include "Collecatable.h"
#include <SFML\Graphics.hpp>
Collecatable::Collecatable(sf::Texture* texture,sf::Vector2u imageCount,float switchTime, sf::Vector2f size, sf::Vector2f Positiion):
animation(texture, imageCount, switchTime)
{
    item.setTexture(texture);
    item.setOrigin(size / 2.0f);
    item.setSize(size);
    item.setPosition(Positiion);
}
void Collecatable::draw(sf::RenderWindow& window)
{
    window.draw(item);
}
void Collecatable::update(float deltaTime)
{
    animation.UpdateItem(deltaTime);
    item.setTextureRect(animation.uvRect);

}
void Collecatable::removeElement()
{
    item.setPosition(-1000.0f,0.0f);
    item.setSize(sf::Vector2f(0.0f,0.0f));
}
Collecatable::~Collecatable()
{
    //dtor
}

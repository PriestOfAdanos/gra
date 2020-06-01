#include <iostream>
#include "Box.h"
#include <SFML\Graphics.hpp>

Box::Box(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position):
    Platform(texture, size, position)
{

}
void Box::update(float deltatime)
{

    block.move(velocity*deltatime);
}
void Box::onCollision(sf::Vector2f direction, float deltatime)
{
    if(direction.x<0.0f)
    {
        velocity.x=0.0f;    //collison on the left
    }
    else if(direction.x > 0.0f)
    {
       velocity.x=0.0f;
    }    //collison on the right
    if(direction.y<0.0f)
    {
        velocity.y=0.0f;

    } else if(direction.y>0.0f)
    {
        velocity.y=0.0f;
    } else {
        velocity.y += 981*deltatime;
    }
}
Box::~Box()
{
    //dtor
}

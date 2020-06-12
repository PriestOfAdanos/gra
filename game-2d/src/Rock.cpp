#include "Rock.h"
#include <iostream>
#include "Animation.h"


Rock::Rock(sf::Texture* texture,sf::Vector2f position ,float speed, float switchTime, bool faceRight):
    animationRock(texture,sf::Vector2u(1,1),switchTime),faceRight(faceRight)
{
     std::cout<<position.x<<'\n';
    this->speedRock = speed;
    isFlying = 1;
    shape.setSize(sf::Vector2f(25.0f,25.0f));
   // shape.setOrigin(shape.getSize()/2.0f);
    shape.setTexture(texture);
    shape.setPosition(position);
    velocity.x=70.0f;

}
void Rock::dispatchTheRock(float deltatime) {
    float y = 0.1;
    if(velocity.x < 0.05f)
    {
        velocity.x=0.01f;
        shape.setPosition(-100.0f,-100.0f);
    } else {
        velocity.x -= 0.01f;
    }
//std::cout<<velocity.x;
    if(!faceRight)
    {
        velocity.y = -sqrt(velocity.x);
      //  velocity.y-=0.9f;
        shape.move(-(velocity) * deltatime * isFlying * y);
    } else {
        velocity.y = sqrt(velocity.x)-2.0f;
        shape.move(velocity * deltatime * isFlying * y);
    }

}
void Rock::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
void Rock::onCollisionWithEnemy(){
    isFlying = 0;
    shape.setPosition(-100.0f,-100.0f);
}
void Rock::onCollisionWithPlatforms() {
    isFlying = 0;
    shape.setPosition(-100.0f,-100.0f);
}
Rock::~Rock()
{
    //dtor
}

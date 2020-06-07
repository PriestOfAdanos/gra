#include "Rock.h"
#include "Animation.h"


Rock::Rock(sf::Texture* texture,sf::Vector2f position ,float speed, float switchTime, bool faceRight):
    animationRock(texture,sf::Vector2u(1,1),switchTime),faceRight(faceRight)
{
    this->speedRock = speed;
    shape.setSize(sf::Vector2f(25.0f,25.0f));
    shape.setOrigin(shape.getSize()/2.0f);
    shape.setTexture(texture);
    shape.setPosition(position);
    velocity.x=60.0f;

}
void Rock::dispatchTheRock(float deltatime) {
    velocity.x -= 0.01f;

    if(!faceRight)
    {
        velocity.y = -sqrt(velocity.x)-2.0f;
        velocity.y-=0.9f;
        shape.move(-(velocity) * deltatime);
    } else {
        velocity.y = sqrt(velocity.x)-2.0f;
        shape.move(velocity * deltatime);
    }

}
void Rock::draw(sf::RenderWindow& window) {
    window.draw(shape);
}
void Rock::onCollisionWithEnemy(){
    velocity.x=0.1f;
}
void Rock::onCollisionWithPlatforms() {
    velocity.x=0.1f;
}
Rock::~Rock()
{
    //dtor
}

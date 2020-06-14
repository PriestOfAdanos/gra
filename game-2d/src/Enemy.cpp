#include "Enemy.h"
#include <iostream>
#include <SFML\Graphics.hpp>

Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount,  float switchTime, float speed, sf::Vector2f position):
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    totalDistance=0;
    row=2;
    leftDirectionForward = true;
    faceRight=false;
    body.setSize(sf::Vector2f(66.0f,67.0f));
    body.setOrigin(body.getSize()/2.0f);
    body.setPosition(position);
    body.setTexture(texture);
}
void Enemy::update(float deltatime)
{
    if(!leftDirectionForward)
    {
        if(totalDistance>0.0f)
            leftDirectionForward = !leftDirectionForward;
        else{
            animation.Update(0,deltatime,faceRight);
            body.setTextureRect(animation.uvRect);
            body.move(0.4f,0);
            totalDistance += 0.4f;
        }
    } else {
        if(totalDistance<-220.0f)
            leftDirectionForward = !leftDirectionForward;
        else {
            animation.Update(1,deltatime,faceRight);
            body.setTextureRect(animation.uvRect);
            body.move(-0.4f,0);
            totalDistance -=0.4f;
        }
    }
}
void Enemy::killDragon()
{
    body.setPosition(-200.0f,-700.0f);
}
void Enemy::draw(sf::RenderWindow& window){
    window.draw(body);
}
Enemy::~Enemy()
{
    //dtor
}

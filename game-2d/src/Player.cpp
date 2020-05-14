#include <iostream>
#include "Player.h"
#include <SFML\Graphics.hpp>

Player::Player(sf::Texture* texture, sf::Vector2u imageCount,  float switchTime, float speed, float jumpHeight):
    animation(texture, imageCount, switchTime)
{
    this->jumpHeight=jumpHeight;
    this->speed = speed;
    row=0;
    faceRight=true;
    body.setSize(sf::Vector2f(100.0f,150.0f));
    body.setOrigin(body.getSize()/2.0f);
    body.setPosition(206.0f,206.0f);
    body.setTexture(texture);
}
void Player::update(float deltatime){
    velocity.x=0.0f;  //prêdkoœæ zmniejszana 0 pó³ w dó³ co deltatime
    //sf::Vector2f velocity(0.0f,0.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        velocity.x -=speed;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        velocity.x +=speed;
   // if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        //velocity.y +=speed;
  //  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        //velocity.y -=speed;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&canJump)
        {
            canJump = false;
            velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
        }


        if(velocity.x==0.0f)
        {
            row=0;
        }
        else{
            row=1;
            if(velocity.x>0.0f)
                faceRight= true;
            else
                faceRight= false;
            }
            animation.Update(row,deltatime,faceRight);
            body.setTextureRect(animation.uvRect);
            body.move(velocity*deltatime);
}
void Player::draw(sf::RenderWindow& window){
    window.draw(body);
}
void Player::onCollision(sf::Vector2f direction, float deltatime)
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
        canJump=true;
    } else if(direction.y>0.0f)
    {
        velocity.y=0.0f;
    } else {
        velocity.y += 981*deltatime;
    }
}
void Player::settingTheVelocity(float deltatime, bool isCollision){
    if(isCollision)
    {
        velocity.y=0.0f;
        canJump=true;
    } else {
        velocity.y += 981*deltatime;
    }
}
Player::~Player()
{
    //dtor
}

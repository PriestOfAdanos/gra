#include <iostream>
#include "Player.h"
#include "Rock.h"
#include <SFML\Graphics.hpp>

Player::Player(sf::Texture* texture, sf::Vector2u imageCount,  float switchTime, float speed, float jumpHeight,int score, int lives):
    animation(texture, imageCount, switchTime),lives(lives),score(score)
{
    this->jumpHeight=jumpHeight;
    this->speed = speed;
    row=0;
    faceRight=true;
    body.setSize(sf::Vector2f(66.0f,100.0f));
    body.setOrigin(body.getSize()/2.0f);
        body.setPosition(206.0f,206.0f);
    body.setTexture(texture);
}
void Player::update(float deltatime){
    velocity.x=0.0f;  //pr�dko�� zmniejszana 0 p� w d� co deltatime
    //sf::Vector2f velocity(0.0f,0.0f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        velocity.x -=speed;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        velocity.x +=speed;

  //  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        //velocity.y -=speed;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)&&canJump)
        {
            canJump = false;
            velocity.y = -sqrtf(2.0f * 600.0f * jumpHeight);
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
        canJump=false;
        if(velocity.y > 3000.0f)
        {
            onCollisionWithEnemy();
        }
    }
}
void Player::onCollisionWithCoin(){
    canJump=false;
    score+=1;
}
void Player::onCollisionWithEnemy(){
    lives-=1;
    body.setPosition(206.0f,206.0f);
    velocity.y=0;
    velocity.x=0;
    canJump=false;
}

Player::~Player()
{
    //dtor
}

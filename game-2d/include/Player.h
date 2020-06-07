#ifndef PLAYER_H
#define PLAYER_H
#include "Animation.h"
#include "Collider.h"
#include "Rock.h"
#include <SFML\Graphics.hpp>

class Player
{
    public:
        Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight,int score, int lives);
        Collider GetCollider(){return Collider(body);}
        void update(float deltatime);
        void onCollisionWithEnemy();
        void draw(sf::RenderWindow& window);
        void onCollision(sf::Vector2f direction, float deltatime);
        void onCollisionWithCoin();
        sf::Vector2f GetPosition() {return body.getPosition();}
        virtual ~Player();
    protected:

     //   Rock rock;
    private:
        float speed;
        unsigned int row;

        sf::RectangleShape body;
        Animation animation;
    public:
        bool faceRight;
        sf::Vector2f velocity;
        bool canJump;
        float jumpHeight;
        int score;
        int lives;
        int amountOfRocks=0;
};

#endif // PLAYER_H

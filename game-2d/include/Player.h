#ifndef PLAYER_H
#define PLAYER_H
#include "Animation.h"
#include "Collider.h"
#include <SFML\Graphics.hpp>

class Player
{
    public:
        Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
        Collider GetCollider(){return Collider(body);}
        void update(float deltatime);
        void draw(sf::RenderWindow& window);
        void onCollision(sf::Vector2f direction, float deltatime);
        void settingTheVelocity(float deltatime, bool isCollision);
        sf::Vector2f GetPosition() {return body.getPosition();}
        virtual ~Player();

    protected:

    private:
        float speed;
        unsigned int row;
        bool faceRight;
        sf::RectangleShape body;
        Animation animation;
    public:
        sf::Vector2f velocity;
        bool canJump;
        float jumpHeight;
};

#endif // PLAYER_H

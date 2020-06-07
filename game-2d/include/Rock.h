#ifndef ROCK_H
#define ROCK_H
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

class Rock
{
    public:
        Rock(sf::Texture* texture,sf::Vector2f position, float speed, float switchTime,  bool faceRight);
        void dispatchTheRock(float);
        void draw(sf::RenderWindow& window);
        void onCollisionWithEnemy();
        void onCollisionWithPlatforms();
        Collider GetCollider(){return Collider(shape);}
        virtual ~Rock();
        sf::Vector2f velocity;
    protected:
        float speedRock;

        sf::RectangleShape shape;
        Animation animationRock;

    private:
        bool faceRight;
};

#endif // ROCK_H

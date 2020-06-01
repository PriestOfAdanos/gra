#ifndef BOX_H
#define BOX_H
#include "Platform.h"
#include <SFML\Graphics.hpp>

class Box : virtual public Platform
{
    public:
        Box(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
        void onCollision(sf::Vector2f direction, float deltatime);
        void update(float);

        Collider GetCollider(){return Collider(block);}
        virtual ~Box();

    protected:

    private:
        sf::Vector2f velocity;
};

#endif // BOX_H

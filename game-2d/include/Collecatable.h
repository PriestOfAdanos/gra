#ifndef COLLECATABLE_H
#define COLLECATABLE_H
#include <SFML\Graphics.hpp>
#include "Collider.h"

class Collecatable
{
    public:
        Collecatable(sf::Texture* texture, sf::Vector2f size, sf::Vector2f Positiion);
        void draw(sf::RenderWindow& window);
        void removeElement();
        Collider GetCollider(){return Collider(item);}
        virtual ~Collecatable();

    protected:

    private:
        sf::RectangleShape item;
};

#endif // COLLECATABLE_H

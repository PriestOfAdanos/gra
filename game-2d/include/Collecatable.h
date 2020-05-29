#ifndef COLLECATABLE_H
#define COLLECATABLE_H
#include <SFML\Graphics.hpp>
#include "Collider.h"
#include "Animation.h"

class Collecatable
{
    public:
        Collecatable(sf::Texture* texture,sf::Vector2u imageCount,float switchTime, sf::Vector2f size, sf::Vector2f Positiion);
        void draw(sf::RenderWindow& window);
        void update(float deltaTime);
        void removeElement();
        Collider GetCollider(){return Collider(item);}
        virtual ~Collecatable();

    protected:

    private:
        Animation animation;
        sf::RectangleShape item;
};

#endif // COLLECATABLE_H

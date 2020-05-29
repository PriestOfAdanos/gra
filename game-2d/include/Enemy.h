#ifndef ENEMY_H
#define ENEMY_H
#include "Animation.h"
#include "Collider.h"


class Enemy
{
    public:
        Enemy(sf::Texture* texture, sf::Vector2u imageCount,  float switchTime, float speed);
        void draw(sf::RenderWindow &Window);
        Collider GetCollider(){return Collider(body);}
        Animation animation;
        void update(float);


        virtual ~Enemy();

    protected:

    private:
        float totalDistance;
        bool leftDirectionForward;
        sf::RectangleShape body;
        sf::Vector2f velocity;
        bool faceRight;
        float speed;
        int row;

};

#endif // ENEMY_H

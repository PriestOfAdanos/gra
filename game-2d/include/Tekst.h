#ifndef TEKST_H
#define TEKST_H
#include <string>
#include <SFML\Graphics.hpp>

class Tekst
{
    public:
        Tekst(sf::Font* font,std::string content,int fontSize,sf::Color color, sf::Vector2f pos);
        void draw(sf::RenderWindow& window);
        void updateText(int lives,int content,sf::Vector2f position);
        sf::Text text;
        virtual ~Tekst();

    protected:

    private:
};

#endif // TEKST_H

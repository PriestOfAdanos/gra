#include "Tekst.h"
#include <SFML\Graphics.hpp>

Tekst::Tekst(sf::Font* font, std::string content, int fontSize, sf::Color color, sf::Vector2f pos)
{
    text.setFont(*font);
    text.setString(content);
    text.setCharacterSize(fontSize);
    text.setString(content);
    text.setColor(color);
    text.setPosition(50.0f,50.0f);
  //  text.setOrigin(text.getSize()/2.0f);
}
void Tekst::updateText(int lives, int score,sf::Vector2f position) {

    std::string content = "Score " + std::to_string(score) +'\n' + "Lives: " + std::to_string(lives);
    text.setString(content);
    text.setPosition(position.x - 624.0f, position.y - 360.0f);
}

void Tekst::draw(sf::RenderWindow& window){
    window.draw(text);
}
Tekst::~Tekst()
{
    //dtor
}

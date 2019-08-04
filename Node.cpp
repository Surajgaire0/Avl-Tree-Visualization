#include <SFML/Graphics.hpp>
#include "Node.hpp"

Node::Node()
{
    circle.setFillColor(sf::Color::Green);
    circle.setRadius(32.0f);
    circle.setPosition(sf::Vector2f(200.0f,200.0f));

    font.loadFromFile("Assets/unispace.ttf");

    text.setFont(font);
    text.setFillColor(sf::Color::Blue);
    text.setCharacterSize(18);

    linestrip.setPrimitiveType(sf::LinesStrip);
    linestrip.resize(3);
}
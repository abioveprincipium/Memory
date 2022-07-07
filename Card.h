#ifndef MEMORY_ONV_CARD_H
#define MEMORY_ONV_CARD_H
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <string>
struct str{
    std::string one;
    std::string two;
};

class Card{

public:
    sf::RectangleShape body;
    sf::Text text;
    std::string data;
    int pairindex;
    bool isOpen = false;
    bool isOk = false;

    Card(std::string dat);
    Card();
    void setPos(int x, int y);
    void drawCard(sf::RenderWindow &window);

    std::vector<str> pary = {
            {"1", "2-1"},
            {"2", "2"},
            {"3", "3*1"},
            {"4", "2+2"},
            {"5", "2+3"}
    };
};


#endif //MEMORY_ONV_CARD_H

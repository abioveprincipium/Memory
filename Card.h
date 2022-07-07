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
            {"5", "2+3"},
            {"6", "2-1"},
            {"7", "2"},
            {"8", "3*1"},
            {"9", "2+2"},
            {"10", "2+3"},
            {"11", "2-1"},
            {"12", "2"},
            {"13", "3*1"},
            {"14", "2+2"},
            {"15", "2+3"},
            {"16", "2"},
            {"17", "3*1"},
            {"18", "2+2"},
            {"19", "2+3"},
            {"20", "2+3"},
            {"21", "2-1"},
            {"22", "2"},
            {"23", "3*1"},
            {"24", "2+2"},
            {"25", "2+3"},

    };
};


#endif //MEMORY_ONV_CARD_H

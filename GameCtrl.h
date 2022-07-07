
#ifndef MEMORY_ONV_GAMECTRL_H
#define MEMORY_ONV_GAMECTRL_H
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
#include "Card.h"
#include "SFMLScreen.h"

class GameCtrl: public SFMLScreen, Card{
public:
    std::vector <Card> cards;
    int click1;
    int click2;



    GameCtrl();

    void gameLogic(int i);
    void drawScreen(sf::RenderWindow &window);
};



#endif //MEMORY_ONV_GAMECTRL_H

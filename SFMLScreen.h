#ifndef MEMORY_ONV_SFMLSCREEN_H
#define MEMORY_ONV_SFMLSCREEN_H
#include "Card.h"
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>
class SFMLScreen{
public:
    SFMLScreen();
    sf::Font font;
    sf::Text title;
    bool active = false;

};
class GameCtrl: public SFMLScreen, Card{
public:
    std::vector <Card> cards;
    int click1;
    int click2;



    GameCtrl();
    void zerowanie();
    void resetGame();
    void gameLogic(int i);
    void drawScreen(sf::RenderWindow &window);
};

class MainMenu : public SFMLScreen{
public:
    explicit MainMenu();
    sf::RectangleShape button1;
    sf::RectangleShape button2;
    sf::Text button1Text;
    sf::Text button2Text;
   // bool active;
    void drawScreen(sf::RenderWindow &window);
};


class EndScreen : public SFMLScreen{
public:
    sf::Text text;
    EndScreen();

    void drawScreen(sf::RenderWindow &window);
};
#endif //MEMORY_ONV_SCREEN_H

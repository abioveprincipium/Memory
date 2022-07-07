#include "SFMLScreen.h"
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>

SFMLScreen:: SFMLScreen(){
    font.loadFromFile("../hp.ttf");
    title.setCharacterSize(30);title.setFont(font);title.setString("Memory Game");
}


MainMenu::MainMenu(){
    active = true;
    button1.setSize({150, 75});button1.setPosition(300, 300);button1.setFillColor(sf::Color::White);

    button1Text.setFont(font);button1Text.setCharacterSize(30);button1Text.setPosition(305, 305);
    button1Text.setString("Play");button1Text.setFillColor(sf::Color::Black);

    button2.setSize({150, 75});button2.setPosition(300, 400);button2.setFillColor(sf::Color::White);

    button2Text.setFont(font);button2Text.setCharacterSize(30);button2Text.setPosition(305, 405);
    button2Text.setString("Exit");button2Text.setFillColor(sf::Color::Black);
}
void MainMenu::drawScreen(sf::RenderWindow &window){

    window.draw(button1);
    window.draw(button2);
    window.draw(button1Text);
    window.draw(button2Text);
}



EndScreen::EndScreen(){

    text.setFont(font);text.setCharacterSize(30);text.setPosition(305, 305);text.setString("You won! CONGRATS!");
}
void EndScreen::drawScreen(sf::RenderWindow &window){
    window.draw(text);
}

//
// Created by lenovo on 2021/5/26.
//

#ifndef LOGOMAKER_COLORBOX_H
#define LOGOMAKER_COLORBOX_H

//#include "ColorItem.h"
#include "ColorPicher.h"

class ColorBox {
private:
    sf::RectangleShape red;
    sf::RectangleShape yellow;
    sf::RectangleShape green;
    sf::RectangleShape cyan;
    sf::RectangleShape blue;
    sf::RectangleShape purple;
    sf::RectangleShape box;
    const int BOX_WIDTH = 30;
    const int BOX_HEIGHT = 30;
    const int BOX_BETWEEN = 10;
    ColorPicher colorPicker;
    int box_x, box_y;
    int choice_r, choice_g, choice_b;
    bool openPicker;
    bool choice;

public:
    ColorBox();
    void setPosition(int x, int y);
    void draw(sf::RenderTarget& window);
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
    void setChoiceColor(sf::Color color);
    int get_rNum();
    int get_gNum();
    int get_bNum();
    bool getChoice();
    void reChoice();
};

#include "ColorBox.cpp"

#endif //LOGOMAKER_COLORBOX_H

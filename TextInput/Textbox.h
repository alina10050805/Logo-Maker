//
// Created by lenovo on 2021/5/25.
//

#ifndef LOGOMAKER_TEXTBOX_H
#define LOGOMAKER_TEXTBOX_H

#include <sfml/graphics.hpp>
#include "Type.h"

class TextBox{
private:
    sf::RectangleShape textBox;
    sf::Font font;
    sf::Text text;
    int box_height = 30;
    int box_width = 500;

    Type type;
    int text_x, text_y;

public:
    TextBox(std::string str, int x, int y);
    TextBox(std::string str, int x, int y, int width);
    void update();
    void draw(sf::RenderTarget& window);
    void addEventHandler(sf::Event event);
    std::string getinputText();
    void resetType();
    void setText(std::string str);
};

#include "Textbox.cpp"

#endif //LOGOMAKER_TEXTBOX_H

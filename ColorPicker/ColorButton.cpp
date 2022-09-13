//
// Created by lenovo on 2021/6/3.
//

#include "ColorButton.h"

ColorButton::ColorButton(std::string str, int x, int y) {
    open = false;

    font.loadFromFile("../text/OpenSans-Bold.ttf");
    colorText.setFont(font);
    colorText.setCharacterSize(23);
    colorText.setString(str);
    colorText.setPosition(sf::Vector2f(x, y));
    if (dark)
        colorText.setFillColor(sf::Color::White);
    else
        colorText.setFillColor(sf::Color::Black);


    box_x = colorText.findCharacterPos(str.length()+1).x + 10;
    box_y = colorText.findCharacterPos(str.length()+1).y;

    colorChoice.setFillColor(sf::Color(0, 0, 0));
//    colorChoice.setFillColor(sf::Color(colorBox.get_rNum(), colorBox.get_gNum(), colorBox.get_bNum()));
    colorChoice.setSize(sf::Vector2f(BOX_WIDTH,BOX_HEIGHT));
    colorChoice.setPosition(sf::Vector2f(box_x, box_y));
    colorChoice.setOutlineThickness(1);
    if (dark)
        colorChoice.setOutlineColor(sf::Color::White);
    else
        colorChoice.setOutlineColor(sf::Color::Black);


//    colorBox.setAllColorBox(box_x - 850, box_y - 260);
//    colorPicher.setPosition(box_x - (256 - BOX_WIDTH), box_y - 256 - 5);
//    colorPicher.setColor(ColorPicher::mainColor::PURPLE);
    colorBox.setPosition(box_x + BOX_WIDTH + 5, box_y);
}

void ColorButton::draw(sf::RenderTarget &window) {
    window.draw(colorText);
    window.draw(colorChoice);

    if (open)
        colorBox.draw(window);
}

void ColorButton::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        int mouseX = sf::Mouse::getPosition(window).x;
        int mouseY = sf::Mouse::getPosition(window).y;

        if (mouseX >= box_x && mouseX <= (box_x + BOX_WIDTH)
            && mouseY >= box_y && mouseY <= (box_y + BOX_HEIGHT))
        {
            if (open)
            {
                open = false;
                colorBox.reChoice();
            }
            else
                open = true;
        }
    }
    if (open)
        colorBox.addEventHandler(window, event);
}

void ColorButton::update() {
    if (open && colorBox.getChoice())
    {
        colorBox.reChoice();
        open = false;
        colorChoice.setFillColor(sf::Color(colorBox.get_rNum(), colorBox.get_gNum(), colorBox.get_bNum()));
    }

//    colorChoice.setFillColor(sf::Color(colorBox.get_rNum(), colorBox.get_gNum(), colorBox.get_bNum()));

    if (open)
        colorBox.update();


    if (dark)
        colorText.setFillColor(sf::Color::White);
    else
        colorText.setFillColor(sf::Color::Black);

    if (dark)
        colorChoice.setOutlineColor(sf::Color::White);
    else
        colorChoice.setOutlineColor(sf::Color::Black);
}

sf::Color ColorButton::getColor() {
    return sf::Color(colorBox.get_rNum(), colorBox.get_gNum(), colorBox.get_bNum());
}

void ColorButton::setColor(sf::Color color) {
    colorBox.setChoiceColor(color);
    colorChoice.setFillColor(color);
}

bool ColorButton::getOpen() {
    return open;
}

void ColorButton::resetOpen() {
    open = false;
}
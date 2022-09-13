//
// Created by lenovo on 2021/5/26.
//

#include "ColorBox.h"

ColorBox::ColorBox() {
    choice = false;
    openPicker = false;

    choice_r = 0;
    choice_g = 0;
    choice_b = 0;
}

void ColorBox::setPosition(int x, int y) {
    box_x = x;
    box_y = y;

    box.setPosition(sf::Vector2f(x, y));
    box.setSize(sf::Vector2f(130, 90));
    box.setOutlineThickness(2);
    if (dark)
    {
        box.setOutlineColor(sf::Color::White);
        box.setFillColor(sf::Color(96, 96, 96));
    }
    else
    {
        box.setOutlineColor(sf::Color::Black);
        box.setFillColor(sf::Color(192, 192, 192));
    }

    red.setPosition(sf::Vector2f(x + BOX_BETWEEN, y + BOX_BETWEEN));
    red.setSize(sf::Vector2f(BOX_WIDTH, BOX_HEIGHT));
    red.setOutlineColor(sf::Color::Black);
    red.setOutlineThickness(2);
    red.setFillColor(sf::Color::Red);

    yellow.setPosition(sf::Vector2f(x + BOX_WIDTH + 2*BOX_BETWEEN, y + BOX_BETWEEN));
    yellow.setSize(sf::Vector2f(BOX_WIDTH, BOX_HEIGHT));
    yellow.setOutlineColor(sf::Color::Black);
    yellow.setOutlineThickness(2);
    yellow.setFillColor(sf::Color::Yellow);

    green.setPosition(sf::Vector2f(x + 2*BOX_WIDTH + 3*BOX_BETWEEN, y + BOX_BETWEEN));
    green.setSize(sf::Vector2f(BOX_WIDTH, BOX_HEIGHT));
    green.setOutlineColor(sf::Color::Black);
    green.setOutlineThickness(2);
    green.setFillColor(sf::Color::Green);

    cyan.setPosition(sf::Vector2f(x + BOX_BETWEEN, y + BOX_HEIGHT + 2*BOX_BETWEEN));
    cyan.setSize(sf::Vector2f(BOX_WIDTH, BOX_HEIGHT));
    cyan.setOutlineColor(sf::Color::Black);
    cyan.setOutlineThickness(2);
    cyan.setFillColor(sf::Color::Cyan);

    blue.setPosition(sf::Vector2f(x + BOX_WIDTH + 2*BOX_BETWEEN, y + BOX_HEIGHT + 2*BOX_BETWEEN));
    blue.setSize(sf::Vector2f(BOX_WIDTH, BOX_HEIGHT));
    blue.setOutlineColor(sf::Color::Black);
    blue.setOutlineThickness(2);
    blue.setFillColor(sf::Color::Blue);

    purple.setPosition(sf::Vector2f(x + 2*BOX_WIDTH + 3*BOX_BETWEEN, y + BOX_HEIGHT + 2*BOX_BETWEEN));
    purple.setSize(sf::Vector2f(BOX_WIDTH, BOX_HEIGHT));
    purple.setOutlineColor(sf::Color::Black);
    purple.setOutlineThickness(2);
    purple.setFillColor(sf::Color::Magenta);

    colorPicker.setPosition(x - 130, y - 260);
}

void ColorBox::draw(sf::RenderTarget &window) {
    window.draw(box);
    window.draw(red);
    window.draw(yellow);
    window.draw(green);
    window.draw(cyan);
    window.draw(blue);
    window.draw(purple);

    if (openPicker)
        colorPicker.draw(window);
}

void ColorBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    int mouseX = sf::Mouse::getPosition(window).x;
    int mouseY = sf::Mouse::getPosition(window).y;

    if (event.type == sf::Event::MouseButtonPressed) {
        mouseX = sf::Mouse::getPosition(window).x;
        mouseY = sf::Mouse::getPosition(window).y;

        if (mouseX >= red.getPosition().x && mouseX <= (red.getPosition().x + BOX_WIDTH)
            && mouseY >= red.getPosition().y && mouseY <= (red.getPosition().y + BOX_HEIGHT))
        {
            openPicker = true;
            colorPicker.setColor(ColorPicher::mainColor::RED);
        }
        if (mouseX >= yellow.getPosition().x && mouseX <= (yellow.getPosition().x + BOX_WIDTH)
            && mouseY >= yellow.getPosition().y && mouseY <= (yellow.getPosition().y + BOX_HEIGHT))
        {
            openPicker = true;
            colorPicker.setColor(ColorPicher::mainColor::YELLOW);
        }
        if (mouseX >= green.getPosition().x && mouseX <= (green.getPosition().x + BOX_WIDTH)
            && mouseY >= green.getPosition().y && mouseY <= (green.getPosition().y + BOX_HEIGHT))
        {
            openPicker = true;
            colorPicker.setColor(ColorPicher::mainColor::GREEN);
        }
        if (mouseX >= cyan.getPosition().x && mouseX <= (cyan.getPosition().x + BOX_WIDTH)
            && mouseY >= cyan.getPosition().y && mouseY <= (cyan.getPosition().y + BOX_HEIGHT))
        {
            openPicker = true;
            colorPicker.setColor(ColorPicher::mainColor::CYAN);
        }
        if (mouseX >= blue.getPosition().x && mouseX <= (blue.getPosition().x + BOX_WIDTH)
            && mouseY >= blue.getPosition().y && mouseY <= (blue.getPosition().y + BOX_HEIGHT))
        {
            openPicker = true;
            colorPicker.setColor(ColorPicher::mainColor::BLUE);
        }
        if (mouseX >= purple.getPosition().x && mouseX <= (purple.getPosition().x + BOX_WIDTH)
            && mouseY >= purple.getPosition().y && mouseY <= (purple.getPosition().y + BOX_HEIGHT))
        {
            openPicker = true;
            colorPicker.setColor(ColorPicher::mainColor::PURPLE);
        }
    }

    if (openPicker)
    {
        colorPicker.addEventHandler(window, event);
    }
}

void ColorBox::update() {
    if (colorPicker.getChoice())
    {
        choice_r = colorPicker.getIndexColor(colorPicker.getChoiceIndex()).r;
        choice_g = colorPicker.getIndexColor(colorPicker.getChoiceIndex()).g;
        choice_b = colorPicker.getIndexColor(colorPicker.getChoiceIndex()).b;

        colorPicker.reChoice();
        openPicker = false;
        choice = true;
    }

    if (openPicker)
        colorPicker.update();

//    colors[0][0].update();
    if (dark)
    {
        box.setOutlineColor(sf::Color::White);
        box.setFillColor(sf::Color(96, 96, 96));
    }
    else
    {
        box.setOutlineColor(sf::Color::Black);
        box.setFillColor(sf::Color(192, 192, 192));
    }
}

void ColorBox::setChoiceColor(sf::Color color) {
    choice_r = color.r;
    choice_g = color.g;
    choice_b = color.b;
}

int ColorBox::get_rNum() {
    return choice_r;
}

int ColorBox::get_gNum() {
    return choice_g;
}

int ColorBox::get_bNum() {
    return choice_b;
}

bool ColorBox::getChoice() {
    return choice;
}

void ColorBox::reChoice() {
    choice = false;
    openPicker = false;
}
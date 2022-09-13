//
// Created by lenovo on 2021/6/3.
//

#include "ColorPicher.h"

ColorPicher::ColorPicher() {
    box_x = 0;
    box_y = 0;
    choice = false;
    choiceIndex = 0;
}

void ColorPicher::draw(sf::RenderTarget &window) {
    window.draw(colors);
}

void ColorPicher::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    int mouseX = sf::Mouse::getPosition(window).x;
    int mouseY = sf::Mouse::getPosition(window).y;

    if (event.type == sf::Event::MouseButtonPressed)
    {
        mouseX = sf::Mouse::getPosition(window).x;
        mouseY = sf::Mouse::getPosition(window).y;

        std::cout << mouseX << ", " << mouseY<<endl;
        std::cout << box_x << ", " << (box_x + 256) << ", " << box_y << ", " << (box_y + 256)<<endl;
        if (mouseX >= box_x && mouseX <= (box_x + 256) && mouseY >= box_y && mouseY <= (box_y + 256))
        {
            choice = true;
            choiceIndex = (mouseY - box_y)*256 + (mouseX - box_x);
        }
    }
}

void ColorPicher::update() {

}

void ColorPicher::setColor(mainColor colorChoice) {
    for (int i=0; i<=255; i++)
    {
        for (int j = 0; j < 255; j++)
        {
            double s = i/255.0;
            double v = j/255.0;

            double p = v * (1-s);
            double q = v;
            double t = v * (1 - s);

            switch (colorChoice) {
                case RED:
                    colors[i * 256 + j].color = sf::Color(v * 255, t * 255, p * 255);
                    break;
                case YELLOW:
                    colors[i * 256 + j].color = sf::Color(q * 255, v * 255, p * 255);
                    break;
                case GREEN:
                    colors[i * 256 + j].color = sf::Color(p * 255, v * 255, t * 255);
                    break;
                case CYAN:
                    colors[i * 256 + j].color = sf::Color(p * 255, q * 255, v * 255);
                    break;
                case BLUE:
                    colors[i * 256 + j].color = sf::Color(t * 255, p * 255, v * 255);
                    break;
                case PURPLE:
                    colors[i * 256 + j].color = sf::Color(v * 255, p * 255, q * 255);
                    break;
            }
        }
    }
}

void ColorPicher::setPosition(int x, int y) {
    box_x = x;
    box_y = y;
    int color_x = x;
    int color_y = y;
    for (int i=0; i<=256*256; i++)
    {
        if (i != 0 && i%256 == 0)
        {
            color_x = x;
            color_y += BOX_SIZE;
        }
        else if (i != 0)
        {
            color_x += BOX_SIZE;
        }

        colors[i].position = sf::Vector2f(color_x, color_y);
    }
}

sf::Color ColorPicher::getIndexColor(int index) {
    return colors[index].color;
}

bool ColorPicher::getChoice() {
    return choice;
}

void ColorPicher::reChoice() {
    choice = false;
}

int ColorPicher::getChoiceIndex() {
    return choiceIndex;
}
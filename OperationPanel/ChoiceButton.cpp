//
// Created by lenovo on 2021/6/7.
//

#include "ChoiceButton.h"

ChoiceButton::ChoiceButton(std::string str, int x, int y) {
    choice = false;

    button.setPosition(sf::Vector2f(x, y));
    button.setSize(sf::Vector2f(RECT_SIZE, RECT_SIZE));
    button.setOutlineThickness(1);
    if (dark)
    {
        button.setOutlineColor(sf::Color::White);
        button.setFillColor(sf::Color::Black);
    }
    else
    {
        button.setOutlineColor(sf::Color::Black);
        button.setFillColor(sf::Color::White);
    }

    showChoice.setPosition(sf::Vector2f(x + 5, y + 5));
    showChoice.setSize(sf::Vector2f(RECT_SIZE - 10, RECT_SIZE - 10));
    if (dark)
    {
        if (choice)
            showChoice.setFillColor(sf::Color::White);
        else
            showChoice.setFillColor(sf::Color::Black);
    }
    else
    {
        if (choice)
            showChoice.setFillColor(sf::Color::Black);
        else
            showChoice.setFillColor(sf::Color::White);
    }

    font.loadFromFile("../text/OpenSans-Bold.ttf");
    buttonStr.setFont(font);
    buttonStr.setCharacterSize(20);
    buttonStr.setString(str);
    buttonStr.setPosition(sf::Vector2f(x + RECT_SIZE + 5, y));
    if (dark)
        buttonStr.setFillColor(sf::Color::White);
    else
        buttonStr.setFillColor(sf::Color::Black);
}

void ChoiceButton::draw(sf::RenderTarget &window) {
    window.draw(button);
    window.draw(showChoice);
    window.draw(buttonStr);
}

void ChoiceButton::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    int mouseX = sf::Mouse::getPosition(window).x;
    int mouseY = sf::Mouse::getPosition(window).y;

    if (event.type == sf::Event::MouseButtonPressed) {
        mouseX = sf::Mouse::getPosition(window).x;
        mouseY = sf::Mouse::getPosition(window).y;

        if (mouseX >= button.getPosition().x && mouseX <= (button.getPosition().x + RECT_SIZE)
        && mouseY >= button.getPosition().y && mouseY <= (button.getPosition().y + RECT_SIZE))
        {
            if (choice)
                choice = false;
            else
                choice = true;
        }
    }
}

void ChoiceButton::update() {
    if (dark)
    {
        button.setOutlineColor(sf::Color::White);
        button.setFillColor(sf::Color::Black);
    }
    else
    {
        button.setOutlineColor(sf::Color::Black);
        button.setFillColor(sf::Color::White);
    }

    if (dark)
    {
        if (choice)
            showChoice.setFillColor(sf::Color::White);
        else
            showChoice.setFillColor(sf::Color::Black);
    }
    else
    {
        if (choice)
            showChoice.setFillColor(sf::Color::Black);
        else
            showChoice.setFillColor(sf::Color::White);
    }

    if (dark)
        buttonStr.setFillColor(sf::Color::White);
    else
        buttonStr.setFillColor(sf::Color::Black);
}

bool ChoiceButton::getChoice() {
    return choice;
}

void ChoiceButton::setChoice(bool choiceValue) {
    choice = choiceValue;
}
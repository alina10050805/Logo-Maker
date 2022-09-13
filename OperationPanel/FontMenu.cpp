//
// Created by lenovo on 2021/5/26.
//

#include "FontMenu.h"

FontMenu::FontMenu(int x, int y) {
    font_x = x;
    font_y = y;
    fontDropdowm = DropdownMenu(fontMenu, 9, font_x, font_y + BOX_HEIGHT, BOX_HEIGHT);
    choice = 4;
    getFontFile(choice);
    fontDropdowm.setValueIndex(choice);

    openFontList = false;
    font.loadFromFile("../text/OpenSans-Bold.ttf");
    fontType.setFont(font);
    fontType.setCharacterSize(23);
    fontType.setString(fontMenu[choice]);
    fontType.setPosition(sf::Vector2f(font_x, font_y));
    if (dark)
        fontType.setFillColor(sf::Color::White);
    else
        fontType.setFillColor(sf::Color::Black);


    fontBox.setOutlineThickness(2);
    fontBox.setSize(sf::Vector2f(BOX_WIDTH,BOX_HEIGHT));
    fontBox.setPosition(sf::Vector2f(font_x, font_y));
    if (dark)
    {
        fontBox.setOutlineColor(sf::Color::White);
        fontBox.setFillColor(sf::Color::Black);
    }
    else
    {
        fontBox.setOutlineColor(sf::Color::Black);
        fontBox.setFillColor(sf::Color::White);
    }
}

void FontMenu::draw(sf::RenderTarget &window) {
    window.draw(fontBox);
    window.draw(fontType);
    if (openFontList)
        fontDropdowm.draw(window);
}

void FontMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        int mouseX = sf::Mouse::getPosition(window).x;
        int mouseY = sf::Mouse::getPosition(window).y;

        if (mouseX >= font_x && mouseX <= (font_x + BOX_WIDTH)
            && mouseY >= font_y && mouseY <= (font_y + BOX_HEIGHT)) {
            if (openFontList) {
                openFontList = false;
            }
            else
            {
                openFontList = true;
            }
        }
    }

    if (openFontList) {
        fontDropdowm.addEventHandler(window, event);

        if (fontDropdowm.getClick())
        {
            choice = fontDropdowm.getValueIndex() + 1;
            getFontFile(choice);
            fontDropdowm.resetClick();
            openFontList = false;
        }
    }
}

void FontMenu::update() {
    fontType.setString(fontMenu[choice]);

    if (openFontList)
        fontDropdowm.update();

    if (dark)
        fontType.setFillColor(sf::Color::White);
    else
        fontType.setFillColor(sf::Color::Black);

    if (dark)
    {
        fontBox.setOutlineColor(sf::Color::White);
        fontBox.setFillColor(sf::Color::Black);
    }
    else
    {
        fontBox.setOutlineColor(sf::Color::Black);
        fontBox.setFillColor(sf::Color::White);
    }
}

void FontMenu::getFontFile(int index) {
    if (index == 1)
        fontFile = "../text/BebasNeue-Regular.ttf";
    else if (index == 2)
        fontFile = "../text/DancingScript-Bold.ttf";
    else if (index == 3)
        fontFile = "../text/OdibeeSans-Regular.ttf";
    else if (index == 4)
        fontFile = "../text/OpenSans-Bold.ttf";
    else if (index == 5)
        fontFile = "../text/Pattaya-Regular.ttf";
    else if (index == 6)
        fontFile = "../text/SquadaOne-Regular.ttf";
    else if (index == 7)
        fontFile = "../text/StintUltraCondensed-Regular.ttf";
    else if (index == 8)
        fontFile = "../text/ZCOOLKuaiLe-Regular.ttf";
}

std::string FontMenu::getFontFile() {
    return fontFile;
}

void FontMenu::findFontChoice(std::string file) {
    if (file == "../text/BebasNeue-Regular.ttf")
        choice = 1;
    else if (file == "../text/DancingScript-Bold.ttf")
        choice = 2;
    else if (file == "../text/OdibeeSans-Regular.ttf")
        choice = 3;
    else if (file == "../text/OpenSans-Bold.ttf")
        choice = 4;
    else if (file == "../text/Pattaya-Regular.ttf")
        choice = 5;
    else if (file == "../text/SquadaOne-Regular.ttf")
        choice = 6;
    else if (file == "../text/StintUltraCondensed-Regular.ttf")
        choice = 7;
    else if (file == "../text/ZCOOLKuaiLe-Regular.ttf")
        choice = 8;

    fontDropdowm.setValueIndex(choice);
}
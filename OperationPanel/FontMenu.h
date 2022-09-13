//
// Created by lenovo on 2021/5/26.
//

#ifndef LOGOMAKER_FONTMENU_H
#define LOGOMAKER_FONTMENU_H

#include "../TopDropdownMenu/DropdownMenu.h"

class FontMenu {
private:
    const int BOX_HEIGHT = 30;
    const int BOX_WIDTH = 200;
    int font_x, font_y;
    std::string fontMenu[9] = {"", "Bebas Neue", "Dancing Script", "Odibee Sans", "Open Sans",
                               "Pattaya", "Squada One", "Stint Ultra", "ZCOOL KuaiLe"};
    sf::Font font;
    sf::RectangleShape fontBox;
    sf::Text fontType;
    DropdownMenu fontDropdowm;
    bool openFontList;
    int choice;
    std::string fontFile;

    void getFontFile(int index);

public:
    FontMenu(int x, int y);
    void draw(sf::RenderTarget& window);
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
    std::string getFontFile();
    void findFontChoice(std::string file);
};

#include "FontMenu.cpp"

#endif //LOGOMAKER_FONTMENU_H

//
// Created by lenovo on 2021/5/24.
//

#ifndef LOGOMAKER_OPERATIONPANEL_H
#define LOGOMAKER_OPERATIONPANEL_H

#include "Slider.h"
#include "../TextInput/Textbox.h"
#include "../LogoPanel/LogoPanel.h"

#include "../TopDropdownMenu/DropdownMenu.h"
#include "FontMenu.h"
#include "../ColorPicker/ColorButton.h"
#include "ChoiceButton.h"

class OperationPanel {
private:
    TextBox logoText = TextBox("Logo Text:", 10, 610);

    Slider textOpacity = Slider("Text Opacity:", 10, 660, 255, 100);
    Slider fontSize = Slider("Font Size:", 310, 660, 200, 100);
    Slider skew = Slider("Skew:", 580, 660, 2, 90, true, true);

    Slider text_x_axis = Slider("Text X-Axis:", 10, 710, 1200, 500);
    Slider text_y_axis = Slider("Text Y-Axis:", 10, 760, 600, 500);

    ChoiceButton shadowChoice = ChoiceButton("Shadow", 10, 810);
    Slider shadow_x_axis = Slider("Shadow X-Axis:", 150, 810, 1200, 500);
    Slider shadow_y_axis = Slider("Shadow Y-Axis:", 150, 860, 600, 500);

    FontMenu fontMenu = FontMenu(650, 610);

    ColorButton textColorButton = ColorButton("Text Color:", 860, 610);
    ColorButton backgroundColor = ColorButton("Background Color:", 810, 660);

    sf::RectangleShape panel;

    LogoPanel logoPanel;
    void initialSliders();

public:
    OperationPanel();
    void setData(FileData data);
    void draw(sf::RenderTarget& window);
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
    FileData getData();
    void saveLogoImage(sf::RenderWindow& window, std::string fileName);
};

#include "OperationPanel.cpp"

#endif //LOGOMAKER_OPERATIONPANEL_H

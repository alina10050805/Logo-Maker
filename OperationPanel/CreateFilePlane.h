//
// Created by lenovo on 2021/5/31.
//

#ifndef LOGOMAKER_CREATEFILEPLANE_H
#define LOGOMAKER_CREATEFILEPLANE_H

#include "../TextInput/Textbox.h"
#include "../TopDropdownMenu/DropdownMenu.h"

class CreateFilePlane {
private:
    sf::Font font;
    TextBox fileNameBox = TextBox("File Name:", 100, 200, 300);
    sf::RectangleShape button;
    sf::Text text;
    std::string inputStr;
    bool creat;

    const int BOX_WIDTH = 200 - 2;
    const int BOX_HEIGHT = 30;

    sf::Text folderText;
    std::string folderMenu[5] = {"", "Main", "Folder", "folder 2", "folder 3"};
    const int FOLDER_BOX_HEIGHT = 30;
    const int FOLDER_BOX_WIDTH = 200;
    int folder_x = 250;
    int folder_y = 250;
    sf::RectangleShape folderBox;
    sf::Text folderChoice;
    DropdownMenu folderDropdowm;
    bool openFolderList;
    int choice;

public:
    CreateFilePlane();
    void draw(sf::RenderTarget& window);
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
    std::string getInput();
    bool clickCreate();
//    void offCreate();
    std::string getFolderName();
    void reset();
};

#include "CreateFilePlane.cpp"

#endif //LOGOMAKER_CREATEFILEPLANE_H

//
// Created by lenovo on 2021/5/31.
//

#include "CreateFilePlane.h"

CreateFilePlane::CreateFilePlane() {
    creat = false;

    font.loadFromFile("../text/OpenSans-Bold.ttf");
    text.setFont(font);
    text.setCharacterSize(20);
    text.setString("Create");
    text.setPosition(sf::Vector2f(500,250));
    if (dark)
        text.setFillColor(sf::Color::White);
    else
        text.setFillColor(sf::Color::Black);


    button.setOutlineThickness(2);
    button.setSize(sf::Vector2f(BOX_WIDTH,BOX_HEIGHT));
    button.setPosition(sf::Vector2f(500,250));
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

    folderText.setFont(font);
    folderText.setCharacterSize(20);
    folderText.setString("Choice Folder:");
    folderText.setPosition(sf::Vector2f(100,250));
    if (dark)
        folderText.setFillColor(sf::Color::White);
    else
        folderText.setFillColor(sf::Color::Black);

    folderDropdowm = DropdownMenu(folderMenu, 5, folder_x, folder_y + FOLDER_BOX_HEIGHT, FOLDER_BOX_HEIGHT);
    choice = 1;
    folderDropdowm.setValueIndex(choice);

    openFolderList = false;
    folderChoice.setFont(font);
    folderChoice.setCharacterSize(23);
    folderChoice.setString(folderMenu[choice]);
    folderChoice.setPosition(sf::Vector2f(folder_x, folder_y));
    if (dark)
        folderChoice.setFillColor(sf::Color::White);
    else
        folderChoice.setFillColor(sf::Color::Black);

    folderBox.setOutlineThickness(2);
    folderBox.setSize(sf::Vector2f(FOLDER_BOX_WIDTH,FOLDER_BOX_HEIGHT));
    folderBox.setPosition(sf::Vector2f(folder_x, folder_y));
    if (dark)
    {
        folderBox.setOutlineColor(sf::Color::White);
        folderBox.setFillColor(sf::Color::Black);
    }
    else
    {
        folderBox.setOutlineColor(sf::Color::Black);
        folderBox.setFillColor(sf::Color::White);
    }
}

void CreateFilePlane::draw(sf::RenderTarget &window) {
    fileNameBox.draw(window);

    window.draw(folderText);
    window.draw(folderBox);
    window.draw(folderChoice);
    if (openFolderList)
        folderDropdowm.draw(window);

    window.draw(button);
    window.draw(text);
}

void CreateFilePlane::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    fileNameBox.addEventHandler(event);

    int mouseX = sf::Mouse::getPosition(window).x;
    int mouseY = sf::Mouse::getPosition(window).y;

    if (event.type == sf::Event::MouseButtonPressed) {
        mouseX = sf::Mouse::getPosition(window).x;
        mouseY = sf::Mouse::getPosition(window).y;

        if (mouseX >= button.getPosition().x && mouseX <= button.getPosition().x+BOX_WIDTH
            && mouseY >= button.getPosition().y && mouseY <= button.getPosition().y+BOX_HEIGHT)
        {
            inputStr = fileNameBox.getinputText();
            creat = true;
            std::cout << inputStr <<endl;
        }

        if (mouseX >= folder_x && mouseX <= (folder_x + FOLDER_BOX_WIDTH)
            && mouseY >= folder_y && mouseY <= (folder_y + FOLDER_BOX_HEIGHT)) {
            if (openFolderList) {
                openFolderList = false;
            }
            else
            {
                openFolderList = true;
            }
        }
    }

    if (openFolderList) {
        folderDropdowm.addEventHandler(window, event);

        if (folderDropdowm.getClick())
        {
            choice = folderDropdowm.getValueIndex() + 1;
            folderDropdowm.resetClick();
            openFolderList = false;
        }
    }
}

void CreateFilePlane::update() {
    fileNameBox.update();

    folderChoice.setString(folderMenu[choice]);

    if (openFolderList)
        folderDropdowm.update();

    if (dark)
        text.setFillColor(sf::Color::White);
    else
        text.setFillColor(sf::Color::Black);

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
        folderText.setFillColor(sf::Color::White);
    else
        folderText.setFillColor(sf::Color::Black);

    if (dark)
        folderChoice.setFillColor(sf::Color::White);
    else
        folderChoice.setFillColor(sf::Color::Black);

    if (dark)
    {
        folderBox.setOutlineColor(sf::Color::White);
        folderBox.setFillColor(sf::Color::Black);
    }
    else
    {
        folderBox.setOutlineColor(sf::Color::Black);
        folderBox.setFillColor(sf::Color::White);
    }
}

std::string CreateFilePlane::getInput() {
    return inputStr;
}

bool CreateFilePlane::clickCreate() {
    return creat;
}

//void CreateFilePlane::offCreate() {
//    creat = false;
//}

std::string CreateFilePlane::getFolderName() {
    return folderChoice.getString();
}

void CreateFilePlane::reset() {
    creat = false;
    choice = 1;
    fileNameBox.resetType();
}
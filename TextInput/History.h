//
// Created by lenovo on 2021/5/25.
//

#ifndef LOGOMAKER_HISTORY_H
#define LOGOMAKER_HISTORY_H

#include <stack>
using namespace std;

class History {
private:
    stack<string> stackString;

public:
    void pushHistory(string str);
    string topHistory();
    void popHistory();
    bool emptyHistory();
    int sizeHistory();
    void resetHistory();
    //static void addEventHandler(sf::RenderWindow& window, sf::Event event);
};

#include "History.cpp"

#endif //LOGOMAKER_HISTORY_H

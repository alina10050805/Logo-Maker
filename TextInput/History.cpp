//
// Created by lenovo on 2021/5/25.
//

#include "History.h"

void History::pushHistory(string str) {
    stackString.push(str);
}

string History::topHistory() {
    return stackString.top();
}

void History::popHistory() {
    stackString.pop();
}

bool History::emptyHistory() {
    return stackString.empty();
}

int History::sizeHistory() {
    return stackString.size();
}

void History::resetHistory() {
    while (!stackString.empty())
    {
        stackString.pop();
    }
}
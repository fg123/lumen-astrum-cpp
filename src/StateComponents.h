//
// Created by Felix on 5/13/2018.
//

#ifndef STATECOMPONENTS_H
#define STATECOMPONENTS_H

enum class Side {
    RED, BLUE
};

enum class Status {
    IN_PROGRESS, RED_WIN, BLUE_WIN
};

class Player {
public:
    std::string username;
    int turnCount;
    int money;

};

class ChatEntry {
public:
    Side from;
    std::string message;

    ChatEntry(Side from, std::string message) : from(from), message(message) {}
};

#endif //STATECOMPONENTS_H

#ifndef SEAT_H
#define SEAT_H

#include <QPicture>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

#include <iostream>
#include <vector>
#include <memory>

class CountdownTimer;
class Player;

typedef QString JsonString;

class Seat {
    friend class Player;
public:
    Seat() = default;
    Seat(int id);

    Player* player;

    int id;
    void clear();
    void display();

    bool isTaken = false;
    bool empty(){ return isTaken; }

    QPushButton* buttonSitInSeat;
    QLabel* playerName;
    QLabel* chipCount;
    QLabel* labelCard1;
    QLabel* labelCard2;
    QLabel* placeholder;

    QLabel* labelTimer;
    CountdownTimer* timer;
    //std::unique_ptr<CountdownTimer> timer;
    //CountdownTimer timer;

    std::vector<QLabel*> chipStacks;

    void addPlayer(JsonString json_player);
    void addPlayer(Player* player);
    void seat(Player* player);
};

#endif // SEAT_H
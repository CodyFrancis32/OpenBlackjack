#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <vector>

class Player
{
public:
    Player();

    void PrintHand();
    void AddCard(Card* newCard);
    int GetScore();
    bool InitialBlackJack();
    bool CheckifAceinHand();
    void ChangeAce();

protected:
    std::vector<Card*> hand_;
    int score_;
};

#endif // PLAYER_H

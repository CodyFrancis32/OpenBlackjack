#ifndef DEALER_H
#define DEALER_H

#include "player.h"
#include "deck.h"

class Dealer : public Player
{
public:
    Dealer();

    Card* DealCard();
    void PrintHand();
    void TakeTurn(int PlayerScore);
private:
    Deck* gameDeck_;
};

#endif // DEALER_H

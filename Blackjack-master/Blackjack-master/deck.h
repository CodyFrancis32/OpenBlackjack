#ifndef DECK_H
#define DECK_H

#include <stdlib.h>
#include <vector>
#include <random>
#include <string>
#include "card.h"

class Deck
{
public:
    Deck();

    void Shuffle();
    Card* GetTopCard();
    void InitializeDeck();

    void PrintDeck();

private:
    std::vector<Card*> gameDeck_;
};

#endif // DECK_H

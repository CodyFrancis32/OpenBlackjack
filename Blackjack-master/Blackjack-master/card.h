#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
#include <iomanip>

class Card
{
public:
    Card();
    Card(std::string suit, int value, std::string face);

    std::string GetSuit();
    int GetValue();
    std::string GetFace();

    void PrintCard();
    void SetValue(int newValue);

private:
    std::string suit_;
    int value_;
    std::string face_;
};

#endif // CARD_H

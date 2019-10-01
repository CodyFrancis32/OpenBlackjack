#include "card.h"

Card::Card()
{
    suit_ = "NULL";
    value_ = 0;
    face_ = "NULL";
}

Card::Card(std::string suit, int value, std::string face){
    suit_ = suit;
    value_ = value;
    face_ = face;
}

std::string Card::GetSuit(){
    return suit_;
}

int Card::GetValue(){
    return value_;
}

std::string Card::GetFace(){
    return face_;
}

void Card::PrintCard(){
    using std::setw;
    using std::left;

    std::cout<<setw(5)<<left<<face_<<" of "<<suit_<<std::endl;
}

void Card::SetValue(int newValue){
    value_ = newValue;
}


#include "player.h"

Player::Player()
{
    score_ = 0;
}

void Player::PrintHand(){
    std::cout<<"Player's Hand"<<std::endl;
    for(int i = 0; i < hand_.size(); i++){
        hand_.at(i)->PrintCard();
    }
    std::cout<<"Score: "<<score_<<std::endl;
}

void Player::AddCard(Card* newCard){
    hand_.push_back(newCard);
    score_ += newCard->GetValue();
}

int Player::GetScore(){
    return score_;
}
bool Player::InitialBlackJack(){
    if (score_ == 21){
        return true;
    }
    else{
        return false;
    }
}
bool Player::CheckifAceinHand(){
    for(int i=0; i< hand_.size(); i++){
        if (hand_.at(i)->GetValue() == 11){
            //Debugging
                //std::cout<<"Yes we have ace in hand...TEST\n";
            return true;
        }
    }
}

void Player::ChangeAce(){
    for(int i=0; i< hand_.size(); i++){
        if (hand_.at(i)->GetValue() == 11){
            //Debugging
                //NEED SET VALUEhand_.at(i) = 1;
                //std::cout<<"VALUE ACE BEFORE: "<<hand_.at(i)->GetValue()<<"\n";
            hand_.at(i)->SetValue(1);
                //std::cout<<"VALUE ACE AFTER: "<<hand_.at(i)->GetValue()<<"\n";
            score_ = score_ - 10;
            break;
        }
    }
}

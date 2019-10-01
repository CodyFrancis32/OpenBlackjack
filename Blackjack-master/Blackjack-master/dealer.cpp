#include "dealer.h"

Dealer::Dealer()
{
    gameDeck_ = new Deck();
    score_ = 0;
}

Card* Dealer::DealCard(){
    return gameDeck_->GetTopCard();
}

void Dealer::PrintHand(){
    std::cout<<std::endl<<"Dealer's Hand"<<std::endl;
    for(int i = 0; i < hand_.size(); i++){
        hand_.at(i)->PrintCard();
    }
    std::cout<<"Score: "<<score_<<std::endl;
}


void Dealer::TakeTurn(int playerScore){
    while(score_ < playerScore && (score_ < 17 || score_ > 21)){
        hand_.push_back(gameDeck_->GetTopCard());
        score_ += hand_.back()->GetValue();
        PrintHand();
    }

    //if(score_ > 21){
      //  std::cout<<"Dealer Busted! You WIN!"<<std::endl;
        //return 0;
    //}
}

#include "deck.h"

Deck::Deck()
{
    InitializeDeck();
    Shuffle();
}

void Deck::Shuffle(){
    int random;

    for(int i = 0; i < 1000; i++){
        random = rand() % 52;
        gameDeck_.push_back(gameDeck_.at(random));
        gameDeck_.erase(gameDeck_.begin()+random);
    }
}

Card* Deck::GetTopCard(){
    Card* temp = gameDeck_.back();
    gameDeck_.pop_back();
    return temp;
}

void Deck::InitializeDeck(){
    std::string currentSuit;
    std::string currentFace;

    for(int i = 0; i < 4; i++){

        switch(i){
        case 0:
            currentSuit = "Hearts";
            break;
        case 1:
            currentSuit = "Clubs";
            break;
        case 2:
            currentSuit = "Diamonds";
            break;
        case 3:
            currentSuit = "Spades";
            break;
        }

        for(int j = 2; j < 15; j++){
            if(j == 11){
                currentFace = "Ace";
            }else if(j == 10){
                currentFace = "10";
            }else if(j == 12){
                currentFace = "Jack";
            }else if(j == 13){
                currentFace = "Queen";
            }else if(j == 14){
                currentFace = "King";
            }else{
                currentFace = j + '0';
            }
            gameDeck_.push_back(new Card(currentSuit, (j > 11)?10:j, currentFace));
        }
    }
}

void Deck::PrintDeck(){
    using std::setw;
    using std::left;

    Card* temp;
    size_t size = gameDeck_.size();
    std::cout<<setw(7)<<left<<"Face"<<setw(10)<<left<<"Suit"<<"Value"<<std::endl;
    std::cout<<"----------------------"<<std::endl;
    for(int i = size-1; i >0; i--){
        temp = gameDeck_.at(i);
        std::cout<<setw(7)<<left<<temp->GetFace()<<""
                <<setw(10)<<left<<temp->GetSuit()<<""
               <<temp->GetValue()<<std::endl;
    }
}

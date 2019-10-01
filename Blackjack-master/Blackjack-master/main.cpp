#include "dealer.h"

/*
 * ISSUES I forsee.
 * No cards at start
 * Always Hits on first turn
 * 21 on first deal = win
 * Aces are always 11, need to make a code to switch to one if we have and ace and we are over..
 *         --->also check to see if there are multiple aces
 * user friendly input(has to be a captial h or s, anything else it hits)
 * multiple player
 *
 * DO any depend on any other fixes first
 * 1. Always hits on first turn //DONE
 * 2. No cards at start //DONE
 * 3. 21 on first deal should win // DONE
 * 4. Aces needed to be updates //DONE
 * 5. User friendly input //DONE
 * 6. Mulitple rounds (put all of main in a loop... do you want to play another round? yes or no) //DONE
 * */

//Debugging
    //player.addcard(new card("Test",10,"TEST"))
    //player.addcard(new card("Test",11,"TEST"))


int firsthand = 0;

int main()
{
    std::string AnotherRound;
    ANOTHERROUND:               //using a jump if we want another round

    srand(time(NULL));

    Player* player = new Player();
    Dealer* dealer = new Dealer();

    if (firsthand == 0){                    //to check for first hand blackjack
        player->AddCard(dealer->DealCard());
        player->AddCard(dealer->DealCard());
        //Debugging/Testing
            //player->AddCard(new Card("Test",8,"8"));
            //player->AddCard(new Card("Test",10,"TEST"));
            //player->AddCard(new Card("Test",11,"Ace"));
        dealer->AddCard(dealer->DealCard());
        dealer->AddCard(dealer->DealCard());
        player->PrintHand();
        dealer->PrintHand();
        firsthand++;
        if(player->InitialBlackJack() == true){     //selfexplanatory
            std::cout<<"You Win because you got 21 on first deal";
            std::cout<<"Do you want to play Another Round? Please enter either Y or N";
            std::getline(std::cin, AnotherRound);
            while(AnotherRound != "Y" && AnotherRound != "N"){      //Loop to make sure user either enters a Y or a N. Wont accept any other input, otherwise will prompt for another input
                std::cout<<"Please enter either Y or N";
                std::getline(std::cin, AnotherRound);
                if(AnotherRound == "Y" || AnotherRound == "N"){
                    break;
                }
            }
            if(AnotherRound == "Y"){
                firsthand = 0;
                goto ANOTHERROUND;  //play another round by jumping to top of code
            }
            else{
                return 0;   //N is entered so we end program... I repeat these lines of code throughout the program whenever I have a case where the game can end
            }
        }
        if(dealer->InitialBlackJack() == true){ //same deal as above for initial player blackjack
            std::cout<<"You Lose because dealer got 21 on first deal";
            std::cout<<"Do you want to play Another Round? Please enter either Y or N";
            std::getline(std::cin, AnotherRound);
            while(AnotherRound != "Y" && AnotherRound != "N"){
                std::cout<<"Please enter either Y or N";
                std::getline(std::cin, AnotherRound);
                if(AnotherRound == "Y" || AnotherRound == "N"){
                    break;
                }
            }
            if(AnotherRound == "Y"){
                firsthand = 0;
                goto ANOTHERROUND;
            }
            else{
                return 0;
            }
        }
    }

    std::string playerChoice;

    std::cout<<"Hit or Stand? Please use either H or S ";
    std::getline(std::cin, playerChoice);

    while (playerChoice != "H" && playerChoice != "S"){ //loop to make sure user enters either H or S, wont accept any other input otherwise will keep prompting
        std::cout<<"Please enter either H or S";
        std::getline(std::cin, playerChoice);
        if(playerChoice == "H" || playerChoice == "S"){
            break;
    }
}

    HIT:    //using jumps... first time- google's resources ftw 
    //while(playerChoice == "H"){
    if(playerChoice == "H"){
        player->AddCard(dealer->DealCard());    //add a card from deck to player
        //player->PrintHand();

        if(player->GetScore() > 21){    //if player is above 21 we check for an ace
            if(player->CheckifAceinHand() == true){
                player->ChangeAce();    //if we found an ace and were above 21 we make give it a value of 1 in function call change ace
                player->PrintHand();
                //break;
            }
            else{
                player->PrintHand();    //we busted since were over 21 and there is no ace in hand to change
                std::cout<<"You lose!"<<std::endl;
                std::cout<<"Do you want to play Another Round? Please enter either Y or N";
                std::getline(std::cin, AnotherRound);
                while(AnotherRound != "Y" && AnotherRound != "N"){
                    std::cout<<"Please enter either Y or N";
                    std::getline(std::cin, AnotherRound);
                    if(AnotherRound == "Y" || AnotherRound == "N"){
                        break;
                    }
                }
                if(AnotherRound == "Y"){
                    firsthand = 0;
                    goto ANOTHERROUND;
                }
                else{
                    return 0;
                }
            }
        }
        else{
            player->PrintHand();
            //break;
        }
    }
    else if(playerChoice == "S"){   //if player stands we jump to bottom of code where stand is.
        goto STAND;
    }

    dealer->TakeTurn(player->GetScore()); //this line hits if player is under 21.. dealer only hits if he is less than 17 and player score is higher than dealers

    if(dealer->GetScore() > 21 || (player->GetScore() > dealer->GetScore())){   //checking to make sure dealer busted or if player score is higher... again this only happens after dealer made all of his moves because of the loop in dealer take turn function!
        std::cout<<"You win!"<<std::endl;
        std::cout<<"Do you want to play Another Round? Please enter either Y or N";
        std::getline(std::cin, AnotherRound);
        while(AnotherRound != "Y" && AnotherRound != "N"){
            std::cout<<"Please enter either Y or N";
            std::getline(std::cin, AnotherRound);
            if(AnotherRound == "Y" || AnotherRound == "N"){
                break;
            }
        }
        if(AnotherRound == "Y"){
            firsthand = 0;
            goto ANOTHERROUND;
        }
        else{
            return 0;
        }
    }

    std::cout<<"Hit or Stand? Please use either H or S ";   //same code as on line 96
    std::getline(std::cin, playerChoice);
    while (playerChoice != "H" && playerChoice != "S"){
        std::cout<<"Please enter either H or S";
        std::getline(std::cin, playerChoice);
        if(playerChoice == "H" || playerChoice == "S"){
            break;
        }
    }
    if(playerChoice == "H"){
        goto HIT;
    }
    else if(playerChoice == "S"){   //player chooses to stand so than dealer will take his move(s) and than we show cards!
        goto STAND;
    }

    STAND:

    dealer->TakeTurn(player->GetScore());

    std::cout<<std::endl<<"Player's Score: "<<player->GetScore()<<std::endl;
    std::cout<<"Dealer's Score: "<<dealer->GetScore()<<std::endl<<std::endl;

    if(dealer->GetScore() > 21 || (player->GetScore() > dealer->GetScore())){ //same code as line 149
        std::cout<<"You win!"<<std::endl;
        std::cout<<"Do you want to play Another Round? Please enter either Y or N";
        std::getline(std::cin, AnotherRound);
        while(AnotherRound != "Y" && AnotherRound != "N"){
            std::cout<<"Please enter either Y or N";
            std::getline(std::cin, AnotherRound);
            if(AnotherRound == "Y" || AnotherRound == "N"){
                break;
            }
        }
        if(AnotherRound == "Y"){
            firsthand = 0;
            goto ANOTHERROUND;
        }
        else{
            return 0;
        }
    }
    else{                               //we hit here because our score is less than dealer and we stood
        std::cout<<"You lose!"<<std::endl;
        std::cout<<"Do you want to play Another Round? Please enter either Y or N";
        std::getline(std::cin, AnotherRound);
        while(AnotherRound != "Y" && AnotherRound != "N"){
            std::cout<<"Please enter either Y or N";
            std::getline(std::cin, AnotherRound);
            if(AnotherRound == "Y" || AnotherRound == "N"){
                break;
            }
        }
        if(AnotherRound == "Y"){
            firsthand = 0;
            goto ANOTHERROUND;
        }
        else{
            return 0;
        }
    }
}

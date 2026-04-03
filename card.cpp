#include "./card.hpp"

// Constructors
Card::Card() : suit('H'){
    // TODO:  initialize missing member(s)
    this->suit = suit;
    this->rank = rand() % 14 + 1;
    //11=jack,12=queen,13=king,14=ace.
}

Card::Card(Suit suit, int rank) : suit(suit.suit){
    // TODO:  initialize missing member(s)
    this->suit = suit;
    this->rank = rank;
}

// TODO: implement missing functions



/**
 * @brief prints the card in the format of { (rank) of (suit) }
 * where rank is the full string representation of the rank (ace is 1 or 14, jack is 11, queen is 12, king is 13)
 * and suit is the full string representation of spades (S), clovers (C), diamonds (D), and hearts (H).
 */
void Card::printCard() const{
    string rankStr, suitStr;
    switch(this->rank){
        case 14:
            rankStr = "Ace";
            break;
        case 11:
            rankStr = "Jack";
            break;
        case 12:
            rankStr = "Queen";
            break;
        case 13:
            rankStr = "King";
            break;
        default:
            rankStr = to_string(this->rank);
    }
    switch(this->suit.suit){
        case 'S':
            suitStr = "Spades";
            break;
        case 'C':
            suitStr = "Clovers";
            break;
        case 'D':
            suitStr = "Diamonds";
            break;
        case 'H':
            suitStr = "Hearts";
            break;
        default:
            suitStr = "Unknown";
    }
    if(this->suit.valid)
        cout << "{ " << rankStr << " of " << suitStr << " }" << endl;
    else
        cout << "Invalid card!" << endl;
}

Suit Card::getSuit(){
    return this->suit;
}

void Card::setSuit(Suit suit){
    this->suit = suit;
}

void Card::setRank(int rank){
    this->rank = rank;
}

int Card::getRank(){
    return this->rank;
}

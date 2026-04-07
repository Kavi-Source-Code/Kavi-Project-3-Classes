#include "./hand.hpp"
/// @file hand.cpp

Hand::Hand(int capacity){
    // TODO: implement this constructor
    this->num_cards = 0;
    cards = new Card[capacity];
}
    
Hand::~Hand(){
    delete[] cards;
}

Hand::Hand(const Hand& hand){
    num_cards = hand.num_cards;
    
    cards = new Card[5];
    
    for (int i = 0; i < num_cards; i++) {
        cards[i] = hand.cards[i];
    }
}

Hand& Hand::operator=(const Hand& hand){
    delete[] cards;
    
    num_cards = hand.num_cards;
    
    cards = new Card[5];
    
    for (int i = 0; i < num_cards; i++) {
        cards[i] = hand.cards[i];
    }
    
    return *this;
}

// Sorting function
void Hand::sort_by_rank(Card* copy) const{
    // Sort the hand by rank using selection sort
    // Given to you: do not change this.
    for(int i = 0; i < this->num_cards - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < this->num_cards; j++){
            if(copy[j].getRank() < copy[minIndex].getRank()){
                minIndex = j;
            }
        }
        Card temp = copy[i];
        copy[i] = copy[minIndex];
        copy[minIndex] = temp;
    }
}


bool Hand::one_pair() const{
    // TODO: throw an exception if there isn't 5 cards in the hand.
    if (this->num_cards != 5){
        throw Exception("Sorry, your number is invalid.");
    }

    // Create a copy of the hand and sort it by rank
    Card copy[this->num_cards];
    for(int i = 0; i < this->num_cards; i++){
        copy[i] = this->cards[i];
    }
    this->sort_by_rank(copy);

    // TODO: complete this function using the copied hand
    Card current_card = copy[0];
    for(int i=1;i<5;i++){
        if(current_card.getRank() == copy[i].getRank()){
            return true;
        }
        current_card = copy[i];
    }
    return false;
}


bool Hand::straight() const{
    if (this->num_cards != 5){
        throw Exception("Sorry, your number is invalid.");
    }

    // Create a copy of the hand and sort it by rank
    Card copy[this->num_cards];
    for(int i = 0; i < this->num_cards; i++){
        copy[i] = this->cards[i];
    }
    this->sort_by_rank(copy);
    
    Card current_card = copy[0];
    for(int i = 1; i < 5; i++){
        if(current_card.getRank() != copy[i].getRank() - 1){
            return false;
        }
        current_card = copy[i];
    }
    return true;
}


bool Hand::two_pair() const{
    if (this->num_cards != 5){
        throw Exception("Sorry, your number is invalid.");
    }

    // Create a copy of the hand and sort it by rank
    Card copy[this->num_cards];
    for(int i = 0; i < this->num_cards; i++){
        copy[i] = this->cards[i];
    }
    this->sort_by_rank(copy);
    
     /** @brief : < Sort the rank, then check for three possible combinations
        @note : < There will ALWAYS be three possible combinations.
    */
    
    bool combo1 = copy[0].getRank() == copy[1].getRank() && copy[2].getRank() == copy[3].getRank() && copy[0].getRank() != copy[2].getRank();
    bool combo2 = copy[0].getRank() == copy[1].getRank() && copy[3].getRank() == copy[4].getRank() && copy[0].getRank() != copy[3].getRank();
    bool combo3 = copy[1].getRank() == copy[2].getRank() && copy[3].getRank() == copy[4].getRank() && copy[1].getRank() != copy[3].getRank();
    return combo1 || combo2 || combo3;
}

bool Hand::four_of_a_kind() const{
    if (this->num_cards != 5){
        throw Exception("Sorry, your number is invalid.");
    }

    // Create a copy of the hand and sort it by rank
    Card copy[this->num_cards];
    for(int i = 0; i < this->num_cards; i++){
        copy[i] = this->cards[i];
    }
    this->sort_by_rank(copy);
    
    bool combo1 = copy[0] == copy[1] && copy[1] == copy[2] && copy[2] == copy[3];
    bool combo2 = copy[1] == copy[2] && copy[2] == copy[3] && copy[3] == copy[4];
    return combo1 || combo2;
}

bool Hand::full_house(){
    if (this->num_cards != 5){
        throw Exception("Sorry, your number is invalid.");
    }

    // Create a copy of the hand and sort it by rank
    Card copy[this->num_cards];
    for(int i = 0; i < this->num_cards; i++){
        copy[i] = this->cards[i];
    }
    this->sort_by_rank(copy);
    
    // There's ONLY ONE possible way. Ex: With a list of [8, 8, 7, 8, 7], when sorted, will become [7, 7, 7, 8, 8]. With this information, we can hopefully make the right conditional.
    
    // Create the conditional in a variable.
    bool combo1 = copy[0] == copy[1] && copy[1] == copy[2] && copy[3] == copy[4] && copy[0] != copy[3];
    return combo1; //we could have done this in one line, but it's cleaner this way.
}

bool Hand::flush() const{
    if (this->num_cards != 5){
        throw Exception("Sorry, your number is invalid.");
    }

    // Create a copy of the hand and sort it by rank
    Card copy[this->num_cards];
    for(int i = 0; i < this->num_cards; i++){
        copy[i] = this->cards[i];
    }
    this->sort_by_rank(copy);
    
    // ...
    for (int i = 14; i > 0; i--){
        if (i - 5 <= 0){
            break;
        }
        check = cards[0] == i && cards[1] == i-- && cards[2] == i - 2 && cards[3] == i - 3 && cards[4] == i - 4;
    }
    return check;
}

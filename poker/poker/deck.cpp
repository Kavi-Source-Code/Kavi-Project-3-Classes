#include "./deck.hpp"

Deck::Deck(){
    // Initialize the deck with 52 cards, 13 of each suit
    char suits[4] = {'S', 'C', 'D', 'H'};
    for(int i = 0; i < 4; i++){
        for(int j = 1; j <= 13; j++){
            this->cards[i*13 + j - 1] = Card(Suit(suits[i]), j);
        }
    }

    // Then, randomly shuffle the deck 100 times
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 52; j++){
            int randIndex = rand() % 52;
            Card temp = this->cards[j];
            this->cards[j] = this->cards[randIndex];
            this->cards[randIndex] = temp;
        }
    }
}

Card Deck::draw_card(){
    // If there are no more cards in the deck before drawing, throw an Exception.
    // This is to prevent undefined behavior.  For other functions that need an Exception, use this as a reference. 
    if(this->num_cards == 0){
        throw Exception("No more cards in the deck.");
    }

    // TODO: complete this function
    Card card = cards[num_cards-- - 1];
    return card;
}

// TODO: add missing functions below

int Deck::get_num_cards(){
    return this->num_cards;
}

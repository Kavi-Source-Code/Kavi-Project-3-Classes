#ifndef DECK_HPP
#define DECK_HPP

#include "./card.hpp"

class Deck{
private:
    // TODO: add missing attributes here
    Card cards[52];
    int num_cards = 52;
    
public:
    Deck();             

    Card draw_card();
    int get_num_cards();
};

#endif

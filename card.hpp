/**
 * @file : card.hpp
 * @brief : this file contains the Card class, which consists of a Suit and a rank.
 *          The ranks go from 1-14, where ace is either 1 or 14, jack is 11, queen is 12, king is 13.
 */

#ifndef CARD_HPP
#define CARD_HPP

#include<cstdlib>
#include <random>
#include "./suit.hpp"
#include "./exception.hpp"

class Card{
private:
    // add missing attributes here
    Suit suit;
    int rank;
public:
    // Constructors
    Card();
    Card(Suit, int);

    // Other member functions
    void printCard() const; 
};


#endif

#ifndef HAND_HPP
#define HAND_HPP

#include "./card.hpp"

/**
 * @file hand.hpp
 * @brief this file contains the declaration of the Hand class, which contains an array of Cards the player has from the deck.
 */
class Hand{
private:
    // Sorting functions
    void sort_by_rank(Card*) const;   // sorts the hand by rank using a copy of the original hand (the hand itself should stay the same)
    Card* cards;
    int num_cards;

    // Add missing functions below
    bool one_pair() const;
    bool two_pair() const;
    bool three_of_a_kind() const;
    bool straight() const;
    bool flush() const;
    bool full_house() const;
    bool four_of_a_kind() const;
    bool straight_flush() const;
    

public:
    // Included constructor with default argument.  Defaults to 5 if no argument is provided.  
    Hand(int = 5);     // default to the hand holding a maximum of 5 cards
    ~Hand();
    Hand(const Hand&);
    Hand& operator=(const Hand&);
    int get_num_cards();
    void add_to_hand(const Card&);
    void clear_hand();
    int score();
    
    // Add missing functions below


};

#endif

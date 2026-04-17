/**
 * @file suit.hpp
 * @brief this file contains the Suit struct, which consists of 4 suits:
 * - Spades ('S') -> value of 1
 * - Clovers ('C') -> value of 2
 * - Diamonds ('D') -> value of 3
 * - Hearts ('H') -> value of 4
 * 
 * @note do not alter this file.
 */
struct Suit{
    char suit;  
    int value;
    bool valid = true;

    // Constructor that presets the values of the given suit
    // and ensures validity
    Suit(char suit){
        this->suit = suit;
        this->value = this->suitValue();

        // Invalid suit provided, so mark the instance as invalid
        if(suit != 'S' && suit != 'C' && suit != 'D' && suit != 'H'){
            this->valid = false;
        }
    }

// Normally structs are always public.  However, we can also make certain
// attributes and member functions private.
private:
    /**
     * Function that returns a value based on the suit.
     * Spades = 1, Clubs/Clovers = 2, Diamonds = 3, Hearts = 4
     * Invalid suit = -1
     */
    int suitValue(){
        switch(this->suit){
            case 'S':
                return 1;
            case 'C':
                return 2;
            case 'D':
                return 3;
            case 'H':
                return 4;
            default: 
                return -1;
        }
    }
    

};

#include "./hand.hpp"
#include "./deck.hpp"
#include <assert.h>

int main(int argc, char* argv[]){
    srand(time(NULL)); // seed the RNG with the current timestamp (0)
    
    // TODO: create a deck, create a hand, draw 5 cards from the deck onto the hand, and then print the score of the hand.

    
    // For extra credit, play anywhere between 3 and 10 rounds by repeating the above and keeping track of the score across those rounds.
    Deck deck;
    Hand hand;
    for(int i = 0; i < 5; i++){
        Card card;
        card = deck.draw_card();
        hand.add_to_hand(card);
    }
    
    cout << "Your Score: " << to_string(hand.score()) <<endl;
    



    // TEST: test all poker hand combinations
    // Do not alter this
    Hand hands[9];  // array of 9 hands, where each hand will represent 1 unique combination 
    try{
        // Straight flush (test with ace and clover and different straight)
        hands[0].add_to_hand(Card(Suit('H'), 10));
        hands[0].add_to_hand(Card(Suit('H'), 11));
        hands[0].add_to_hand(Card(Suit('H'), 12));
        hands[0].add_to_hand(Card(Suit('H'), 13));
        hands[0].add_to_hand(Card(Suit('H'), 14));
        assert(hands[0].score() == 100);
        hands[0].clear_hand();
        hands[0].add_to_hand(Card(Suit('C'), 4));
        hands[0].add_to_hand(Card(Suit('C'), 6));
        hands[0].add_to_hand(Card(Suit('C'), 8));
        hands[0].add_to_hand(Card(Suit('C'), 7));
        hands[0].add_to_hand(Card(Suit('C'), 5));
        assert(hands[0].score() == 100);

        // Four of a kind
        hands[1].add_to_hand(Card(Suit('H'), 5));
        hands[1].add_to_hand(Card(Suit('D'), 5));
        hands[1].add_to_hand(Card(Suit('S'), 5));
        hands[1].add_to_hand(Card(Suit('C'), 5));
        hands[1].add_to_hand(Card(Suit('H'), 2));
        assert(hands[1].score() == 90);

        // Full house
        hands[2].add_to_hand(Card(Suit('H'), 6));
        hands[2].add_to_hand(Card(Suit('D'), 6));
        hands[2].add_to_hand(Card(Suit('S'), 6));
        hands[2].add_to_hand(Card(Suit('C'), 9));
        hands[2].add_to_hand(Card(Suit('H'), 9));
        assert(hands[2].score() == 75);

        // Flush
        hands[3].add_to_hand(Card(Suit('S'), 2));
        hands[3].add_to_hand(Card(Suit('S'), 5));
        hands[3].add_to_hand(Card(Suit('S'), 7));
        hands[3].add_to_hand(Card(Suit('S'), 9));
        hands[3].add_to_hand(Card(Suit('S'), 12));
        assert(hands[3].score() == 60);

        // Straight
        hands[4].add_to_hand(Card(Suit('H'), 3));
        hands[4].add_to_hand(Card(Suit('D'), 4));
        hands[4].add_to_hand(Card(Suit('S'), 5));
        hands[4].add_to_hand(Card(Suit('C'), 6));
        hands[4].add_to_hand(Card(Suit('H'), 7));
        assert(hands[4].score() == 50);

        // Three of a kind
        hands[5].add_to_hand(Card(Suit('H'), 8));
        hands[5].add_to_hand(Card(Suit('D'), 8));
        hands[5].add_to_hand(Card(Suit('S'), 8));
        hands[5].add_to_hand(Card(Suit('C'), 2));
        hands[5].add_to_hand(Card(Suit('H'), 3));
        assert(hands[5].score() == 35);

        // Two pair
        hands[6].add_to_hand(Card(Suit('H'), 10));
        hands[6].add_to_hand(Card(Suit('D'), 10));
        hands[6].add_to_hand(Card(Suit('S'), 4));
        hands[6].add_to_hand(Card(Suit('C'), 4));
        hands[6].add_to_hand(Card(Suit('H'), 7));
        assert(hands[6].score() == 20);

        // One pair
        hands[7].add_to_hand(Card(Suit('H'), 11));
        hands[7].add_to_hand(Card(Suit('D'), 11));
        hands[7].add_to_hand(Card(Suit('S'), 3));
        hands[7].add_to_hand(Card(Suit('C'), 6));
        hands[7].add_to_hand(Card(Suit('H'), 9));
        assert(hands[7].score() == 15);

        // High card: ace high
        hands[8].add_to_hand(Card(Suit('H'), 14));
        hands[8].add_to_hand(Card(Suit('D'), 3));
        hands[8].add_to_hand(Card(Suit('S'), 5));
        hands[8].add_to_hand(Card(Suit('C'), 7));
        hands[8].add_to_hand(Card(Suit('H'), 9));
        assert(hands[8].score() == 14);

        // All tests passed
        cout << "All tests passed!" << endl;
    }
    catch(Exception e){
        cout << e.print_message() << endl;
    }

    return 0;
}

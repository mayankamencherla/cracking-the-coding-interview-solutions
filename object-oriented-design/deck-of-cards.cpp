#include <iostream>
#include <vector>

using namespace std;

enum Suit {hearts, diamonds, spades, clubs};

enum Value {two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

enum Color {red, black};

class Card
{
    private:
        /**
         * The value of the card
         * @param Value val
         */
        Value val;

        /**
         * The suit of the card
         * @param Suit suit
         */
        Suit suit;

        /**
         * The color of the card
         * @param Color color
         */
        Color color;

        /**
         * The index of the card
         * @param int index
         */
        int index;

    public:
        Card(Value v, Suit s, int ind)
        {
            this->val = v;

            this->suit = s;

            this->index = ind;

            this->setColor();
        }

        /**
         * Sets the color of the card
         * @returns void
         */
        void setColor()
        {
            this->color = (this->suit == Suit::hearts || this->suit == Suit::diamonds) ? Color::red : Color::black;
        }

        /**
         * Returns the suit of the card
         * @returns Suit
         */
        Suit getSuit()
        {
            return this->suit;
        }

        /**
         * Returns the value of the card
         * @returns Suit
         */
        Value getValue()
        {
            return this->val;
        }

        /**
         * Returns the index of the card
         * @returns int
         */
        int getIndex()
        {
            return this->index;
        }

        void print()
        {
            printf("Suit : %u and Value : %u and Index : %d\n", this->getSuit(), this->getValue(), this->getIndex());
        }
};

class Deck
{
    private:
        /**
         * The 52 cards in a deck
         * @param vector<Card> cards
         */
        vector<Card> cards;

    public:
        Deck()
        {
            int index = 1;

            for (Suit s = Suit::hearts; s <= Suit::clubs; s = Suit(s+1))
            {
                for (Value t = Value::two; t <= Value::ace; t = Value(t+1))
                {
                    Card c = Card(t, s, index);

                    cards.push_back(c);

                    index++;
                }
            }
        }

        /**
         * Shuffles the deck of cards
         * @returns void
         */
        void shuffle()
        {
            for (int i=0; i<52; i++)
            {
                int randInt = rand() % 52;

                swap(cards[i], cards[randInt]);
            }
        }

        /**
         * Prints the entire deck of cards
         * @returns void
         */
        void print()
        {
            printf("Printing the entire deck\n");

            for (Card c : cards) c.print();
        }
};

int main()
{
    // Creates a deck of 52 cards
    Deck d = Deck();

    d.print();

    cout << endl;

    d.shuffle();

    d.print();
}

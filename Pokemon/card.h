#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

class Card {
protected:
    string cardName; 

public:
    Card(string name) : cardName(name) {}
    virtual ~Card() = default; 
    virtual void displayInfo() const = 0; 

    string getCardName() const {
        return cardName;
    }
};

#endif // CARD_H

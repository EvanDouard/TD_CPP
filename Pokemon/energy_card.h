#ifndef ENERGY_CARD_H
#define ENERGY_CARD_H

#include "card.h" 

#include <string>
#include <iostream>

using namespace std;

class EnergyCard : public Card { 
protected:
    string energyType;

public:
    EnergyCard(string energyType);

    void displayInfo() const override;
};

#endif // ENERGY_CARD_H

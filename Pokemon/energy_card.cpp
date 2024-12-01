#include "energy_card.h"

EnergyCard::EnergyCard(string energyType) : Card(energyType), energyType(energyType) {}

void EnergyCard::displayInfo() const {
    cout << "Energy type: " << energyType << endl;
}

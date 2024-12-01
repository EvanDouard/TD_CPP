#include "trainer_card.h"
#include <iostream>

using namespace std;

// Constructor
TrainerCard::TrainerCard(const string& trainerName, const string& trainerEffect)
    : Card(trainerName), trainerEffect(trainerEffect) {}

// Getter for trainerEffect
string TrainerCard::getTrainerEffect() const {
    return trainerEffect;
}

// Setter for trainerEffect
void TrainerCard::setTrainerEffect(string& newTrainerEffect) {
    trainerEffect = newTrainerEffect;
}

// Display information about the Trainer card
void TrainerCard::displayInfo() const {
    cout << "Trainer Card: " << cardName << endl;
    cout << "Effect: " << trainerEffect << endl;
}

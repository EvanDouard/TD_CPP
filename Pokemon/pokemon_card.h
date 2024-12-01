#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H

#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include "card.h"

using namespace std;

class PokemonCard : public Card {
protected:
    string pokemonType;
    string familyName;
    int evolutionLevel;
    int maxHP;
    int hp; // Current HP

    using CostEnerg = int;
    using Descrpattaque = string;
    using degatattaque = int;
    using CostEnergactual = int;

    vector<tuple<CostEnerg, CostEnergactual, Descrpattaque, degatattaque>> attacks;

    int totalEnergyAttached = 0; // Tracks total energy attached to this Pokémon

public:
    // Constructor
    PokemonCard(string cardName, string pokemonType, string familyName, int evolutionLevel,
                int maxHP,
                CostEnerg attack1Cost, Descrpattaque attack1Description, degatattaque attack1Damage,
                CostEnerg attack2Cost, Descrpattaque attack2Description, degatattaque attack2Damage)
        : Card(cardName), 
          pokemonType(pokemonType), familyName(familyName),
          evolutionLevel(evolutionLevel), maxHP(maxHP), hp(maxHP) {

        attacks.push_back(make_tuple(attack1Cost, 0, attack1Description, attack1Damage));
        attacks.push_back(make_tuple(attack2Cost, 0, attack2Description, attack2Damage));
    }

    // Display card information
    void displayInfo() const override {
        cout << "Pokemon: " << cardName << ", Type: " << pokemonType 
             << ", Family: " << familyName << ", Evolution Level: " 
             << evolutionLevel << ", Max HP: " << maxHP 
             << ", Current HP: " << hp << endl;

        cout << "Attacks:" << endl;
        for (const auto& attack : attacks) {
            cout << "  Attack Description: " << get<2>(attack)
                 << " (Energy Cost: " << get<0>(attack)
                 << ", Current Energy Attached: " << get<1>(attack)
                 << ", Damage: " << get<3>(attack) << ")" << endl;
        }
    }

    // Attach energy to the Pokémon card
    void attachEnergy() {
        totalEnergyAttached++; // Increment total energy attached
    }

    // Getter for total energy attached
    int getEnergyAttached() const {
        return totalEnergyAttached;
    }

    // Setter for total energy attached
    void setEnergyAttached(int energy) {
        totalEnergyAttached = energy;
    }

    // Get the current HP
    int getHP() const {
        return hp;
    }

    // Set the current HP
    void setHP(int newHP) {
        hp = max(0, min(newHP, maxHP)); // Ensure HP stays within bounds
    }

    // Getter for attacks
    vector<tuple<CostEnerg, CostEnergactual, Descrpattaque, degatattaque>> getAttacks() const {
        return attacks;
    }
};

#endif // POKEMON_CARD_H

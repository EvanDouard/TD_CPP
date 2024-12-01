#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "card.h"
#include "pokemon_card.h"
#include "energy_card.h"
#include "trainer_card.h"

using namespace std;

class Player {
private:
    string playerName;
    vector<Card*> benchCards;
    vector<PokemonCard*> actionCards;
    
public:
    // Constructeur avec nom
    Player(string name) : playerName(name) {}
    // Constructeur par défaut
    Player() : playerName("Unknown") {}
    
    // Destructeur
    ~Player() {
        for (Card* card : benchCards) {
            delete card;  // Libère la mémoire allouée pour les cartes
        }
    }
    
    
    void addCardToBench(Card* card);
    void displayBench() const;
    void displayAction() const;
    void activatePokemonCard(int index);
    void attachEnergyCard(int pokemonIndex, int energyIndex);
    void attack(int attackerIndex, int targetIndex, Player& targetPlayer, int energyCost);
    void useTrainer(int index); 
};

#endif // PLAYER_H

#include "player.h"
#include <iostream>

void Player::useTrainer(int index) {
    if (index < 0 || index >= (int)benchCards.size()) {
        cout << "Invalid Trainer card index!" << endl;
        return;
    }
    TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(benchCards[index]);
    if (trainerCard) {
        cout << "Using trainer: " << trainerCard->getTrainerEffect() << endl;
        
        if (trainerCard->getTrainerEffect() == "heal all your action pokemon") {
            for (PokemonCard* pokemon : actionCards) {
                if (pokemon && pokemon->getHP() > 0) {
                    pokemon->setHP(pokemon->getHP());
                    cout << pokemon->getCardName() << " has been healed!" << endl;
                }
            }
        }
    } else {
        cout << "This is not a Trainer card!" << endl;
    }
}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);  // Ajoute la carte à la "banque" du joueur
}

void Player::activatePokemonCard(int index) {
    if (index >= 0 && index < (int)benchCards.size()) {
        PokemonCard* pokemon = dynamic_cast<PokemonCard*>(benchCards[index]);
        if (pokemon) {
            actionCards.push_back(pokemon);  // Active le Pokémon et le place dans l'équipe
        } else {
            cout << "Ce n'est pas une carte Pokémon!" << endl;
        }
    } else {
        cout << "Index invalide pour activer un Pokémon." << endl;
    }
}

void Player::attachEnergyCard(int pokemonIndex, int energyIndex) {
    if (pokemonIndex >= 0 && pokemonIndex < (int)actionCards.size()) {
        PokemonCard* pokemon = actionCards[pokemonIndex];
        if (energyIndex >= 0 && energyIndex < (int)benchCards.size()) {
            EnergyCard* energy = dynamic_cast<EnergyCard*>(benchCards[energyIndex]);
            if (energy) {
                pokemon->attachEnergy();  // Attache l'énergie au Pokémon
                cout << "Energie attachée à " << pokemon->getCardName() << endl;
            } else {
                cout << "Ce n'est pas une carte d'énergie!" << endl;
            }
        } else {
            cout << "Index d'énergie invalide!" << endl;
        }
    } else {
        cout << "Index de Pokémon invalide!" << endl;
    }
}


void Player::displayBench() const {
    cout << "Cartes sur le banc de " << playerName << ":" << endl;
    for (const auto& card : benchCards) {
        card->displayInfo();  // Affiche les informations de chaque carte
    }
}



void Player::displayAction() const {
    cout << "Cartes actives de " << playerName << ":" << endl;
    for (const auto& pokemon : actionCards) {
        pokemon->displayInfo();  // Affiche les informations du Pokémon
    }
}

void Player::attack(int indexactioncard, int indexattaque, Player& player2, int indexpokemonattaque) {
    // Utilisez directement actionCards au lieu de getActionCards()
    vector<PokemonCard*> actualActionCards = this->actionCards;  // Accès direct
    vector<PokemonCard*> player2ActionCards = player2.actionCards;  // Accès direct

    if (indexactioncard >= 0 && indexactioncard < (int) actualActionCards.size() && 
        indexpokemonattaque >= 0 && indexpokemonattaque < (int) player2ActionCards.size()) {
        
        PokemonCard* actualPokemonCard = actualActionCards[indexactioncard];
        PokemonCard* player2PokemonCard = player2ActionCards[indexpokemonattaque];

        if (actualPokemonCard != nullptr && player2PokemonCard != nullptr) {
            vector<tuple<int, int, string, int>> attacks = actualPokemonCard->getAttacks();
            if (indexattaque >= 0 && indexattaque < (int) attacks.size() && actualPokemonCard->getEnergyAttached() >= get<0>(attacks[indexattaque])) {
                int energyCost = get<0>(attacks[indexattaque]);
                int damage = get<3>(attacks[indexattaque]);

                player2PokemonCard->setHP(player2PokemonCard->getHP() - damage);
                actualPokemonCard->setEnergyAttached(actualPokemonCard->getEnergyAttached() - energyCost);

                cout << actualPokemonCard->getCardName() << " attaque " << player2PokemonCard->getCardName() 
                     << " avec l'attaque " << get<2>(attacks[indexattaque]) 
                     << " infligeant " << damage << " dégâts!" << endl;

            } else {
                cout << "Numéro d'attaque invalide ou pas assez d'énergie attachée!" << endl;
            }
        } else {
            cout << "Une des cartes n'est pas une carte Pokémon valide!" << endl;
        }
    } else {
        cout << "Numéro de carte invalide!" << endl;
    }
}





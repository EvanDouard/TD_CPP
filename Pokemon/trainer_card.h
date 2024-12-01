#ifndef TRAINER_CARD_H
#define TRAINER_CARD_H

#include <string>
#include "card.h"

using namespace std;

class TrainerCard : public Card{
    private:
        string trainerEffect;

    public:
        TrainerCard(const string& trainerName, const string& trainerEffect);
        string getTrainerEffect() const;
        void setTrainerEffect(string& trainerEffect);
        void displayInfo() const override;
};

#endif
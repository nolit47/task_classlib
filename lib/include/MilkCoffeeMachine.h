#ifndef MILK_COFFEE_MACHINE_H
#define MILK_COFFEE_MACHINE_H

#include "CoffeeMachine.h"

class MilkCoffeeMachine : public CoffeeMachine {
private:
    static constexpr int MAX_MILK_ML = 500;
    int milkMl_;

public:
    MilkCoffeeMachine(const std::string& model, int waterMl, int beansG, int milkMl, int cupsSinceCleaning = 0);

    int refillMilk(int ml);
    bool brewLatte(int cupMl);
    void printStatus() const override;
};

#endif
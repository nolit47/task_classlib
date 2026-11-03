#include "MilkCoffeeMachine.h"

#include <iostream>

MilkCoffeeMachine::MilkCoffeeMachine(const std::string& model, int waterMl, int beansG,
                                     int milkMl, int cupsSinceCleaning)
    : CoffeeMachine(model, waterMl, beansG, cupsSinceCleaning), milkMl_(milkMl) {
    if (milkMl_ < 0) milkMl_ = 0;
    if (milkMl_ > MAX_MILK_ML) milkMl_ = MAX_MILK_ML;
}

int MilkCoffeeMachine::refillMilk(int ml) {
    if (ml <= 0) {
        std::cout << "[" << model_ << "] Invalid amount of milk.\n";
        return 0;
    }
    int free = MAX_MILK_ML - milkMl_;
    int added = (ml < free) ? ml : free;
    milkMl_ += added;

    std::cout << "[" << model_ << "] Added milk: " << added << " ml (tank: "
              << milkMl_ << "/" << MAX_MILK_ML << " ml).\n";
    return added;
}

bool MilkCoffeeMachine::brewLatte(int cupMl) {
    if (cupMl <= 0) {
        std::cout << "[" << model_ << "] Invalid cup volume.\n";
        return false;
    }
    int milkNeeded = cupMl / 2;
    if (milkMl_ < milkNeeded) {
        std::cout << "[" << model_ << "] Cannot brew latte: not enough milk (need "
                  << milkNeeded << " ml, have " << milkMl_ << " ml).\n";
        return false;
    }
    // Coffee part uses the base-class logic.
    if (!brewCoffee(cupMl - milkNeeded)) return false;

    milkMl_ -= milkNeeded;
    std::cout << "[" << model_ << "] Latte ready: " << cupMl << " ml (milk left: "
              << milkMl_ << " ml).\n";
    return true;
}

void MilkCoffeeMachine::printStatus() const {
    std::cout << "[" << model_ << "] Status: water " << waterMl_ << " ml, beans "
              << beansG_ << " g, milk " << milkMl_ << " ml, cups since cleaning "
              << cupsSinceCleaning_ << ".\n";
}

#include "CapsuleCoffeeMachine.h"

#include <iostream>

CapsuleCoffeeMachine::CapsuleCoffeeMachine(const std::string& model, int waterMl, int capsules, int cupsSinceCleaning): CoffeeMachine(model, waterMl, 0, cupsSinceCleaning), capsules_(capsules) {
    if (capsules_ < 0) capsules_ = 0;
    if (capsules_ > MAX_CAPSULES) capsules_ = MAX_CAPSULES;
}

int CapsuleCoffeeMachine::addCapsules(int count) {
    if (count <= 0) {
        std::cout << "[" << model_ << "] Invalid number of capsules.\n";
        return 0;
    }

    int free = MAX_CAPSULES - capsules_;
    int added = (count < free) ? count : free;
    capsules_ += added;

    std::cout << "[" << model_ << "] Added capsules: " << added << " (container: " << capsules_ << "/" << MAX_CAPSULES << ").\n";
    return added;
}

int CapsuleCoffeeMachine::addBeans(int) {
    std::cout << "[" << model_ << "] This machine uses capsules, not beans.\n";
    return 0;
}

bool CapsuleCoffeeMachine::brewCoffee(int cupMl) {
    if (!checkReady(cupMl)) return false;


    if (capsules_ < 1) {
        std::cout << "[" << model_ << "] Cannot brew: no capsules left.\n";
        return false;
    }


    waterMl_ -= cupMl;
    --capsules_;
    ++cupsSinceCleaning_;


    std::cout << "[" << model_ << "] Capsule coffee brewed: " << cupMl << " ml! Remaining: water " << waterMl_ << " ml, capsules " << capsules_ << ", cups until cleaning: " << (CUPS_BEFORE_CLEANING - cupsSinceCleaning_) << ".\n";
    return true;
}

void CapsuleCoffeeMachine::printStatus() const {
    std::cout << "[" << model_ << "] Status: water " << waterMl_ << " ml, capsules " << capsules_ << ", cups since cleaning " << cupsSinceCleaning_ << ".\n";
}
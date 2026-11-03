#include "CoffeeMachine.h"

#include <iostream>

CoffeeMachine::CoffeeMachine(const std::string& model, int waterMl, int beansG, int cupsSinceCleaning): model_(model), waterMl_(waterMl), beansG_(beansG), cupsSinceCleaning_(cupsSinceCleaning) {

    if (waterMl_ < 0) waterMl_ = 0;
    if (waterMl_ > MAX_WATER_ML) waterMl_ = MAX_WATER_ML;
    if (beansG_ < 0) beansG_ = 0;
    if (beansG_ > MAX_BEANS_G) beansG_ = MAX_BEANS_G;
    if (cupsSinceCleaning_ < 0) cupsSinceCleaning_ = 0;

}

int CoffeeMachine::beansNeeded(int cupMl) const {
    return (cupMl + ML_PER_GRAM_OF_BEANS - 1) / ML_PER_GRAM_OF_BEANS;
}

bool CoffeeMachine::checkReady(int cupMl) const {
    if (cupMl <= 0) {
        std::cout << "[" << model_ << "] Invalid cup volume.\n";
        return false;
    }

    if (cupsSinceCleaning_ >= CUPS_BEFORE_CLEANING) {
        std::cout << "[" << model_ << "] Cannot brew: coffee machine needs cleaning (" << cupsSinceCleaning_ << " cups since last cleaning).\n";
        return false;
    }

    if (waterMl_ < cupMl) {
        std::cout << "[" << model_ << "] Cannot brew: not enough water (need " << cupMl << " ml, have " << waterMl_ << " ml).\n";
        return false;
    }

    return true;
}

int CoffeeMachine::refillWater(int ml) {
    if (ml <= 0) {
        std::cout << "[" << model_ << "] Invalid amount of water.\n";
        return 0;
    }

    int free = MAX_WATER_ML - waterMl_;
    int added = (ml < free) ? ml : free;
    waterMl_ += added;

    std::cout << "[" << model_ << "] Added water: " << added << " ml (tank: " << waterMl_ << "/" << MAX_WATER_ML << " ml)";

    if (added < ml) {
        std::cout << " - tank is full, extra " << (ml - added) << " ml could not be added";
    }
    
    std::cout << ".\n";
    return added;
}

int CoffeeMachine::addBeans(int grams) {
    if (grams <= 0) {
        std::cout << "[" << model_ << "] Invalid amount of beans.\n";
        return 0;
    }

    int free = MAX_BEANS_G - beansG_;
    int added = (grams < free) ? grams : free;

    beansG_ += added;

    std::cout << "[" << model_ << "] Added beans: " << added << " g (container: " << beansG_ << "/" << MAX_BEANS_G << " g)";

    if (added < grams) {
        std::cout << " - container is full, extra " << (grams - added) << " g could not be added";
    }
    std::cout << ".\n";

    return added;
}

bool CoffeeMachine::brewCoffee(int cupMl) {
    if (!checkReady(cupMl)) return false;

    int needBeans = beansNeeded(cupMl);
    
    if (beansG_ < needBeans) {
        std::cout << "[" << model_ << "] Cannot brew: not enough beans (need " << needBeans << " g, have " << beansG_ << " g).\n";
        return false;
    }

    waterMl_ -= cupMl;
    beansG_ -= needBeans;
    ++cupsSinceCleaning_;

    std::cout << "[" << model_ << "] Coffee brewed: " << cupMl << " ml! Remaining: water " << waterMl_ << " ml, beans " << beansG_ << " g, cups until cleaning: " << (CUPS_BEFORE_CLEANING - cupsSinceCleaning_) << ".\n";
    return true;
}

bool CoffeeMachine::runCleaning() {
    if (waterMl_ < CLEANING_WATER_ML) {
        std::cout << "[" << model_ << "] Cannot clean: the cleaning program requires " << CLEANING_WATER_ML << " ml of water, but only " << waterMl_ << " ml is available.\n";
        return false;
    }

    waterMl_ -= CLEANING_WATER_ML;
    cupsSinceCleaning_ = 0;

    std::cout << "[" << model_ << "] Cleaning completed. Used " << CLEANING_WATER_ML << " ml of water, remaining " << waterMl_ << " ml.\n";

    return true;
}

void CoffeeMachine::printStatus() const {
    std::cout << "[" << model_ << "] Status: water " << waterMl_ << " ml, beans " << beansG_ << " g, cups since cleaning " << cupsSinceCleaning_ << ".\n";
}
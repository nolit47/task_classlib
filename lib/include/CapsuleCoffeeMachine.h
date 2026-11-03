#ifndef CAPSULE_COFFEE_MACHINE_H
#define CAPSULE_COFFEE_MACHINE_H

#include "CoffeeMachine.h"

class CapsuleCoffeeMachine : public CoffeeMachine {
private:
    static constexpr int MAX_CAPSULES = 10;
    int capsules_;

public:
    CapsuleCoffeeMachine(const std::string& model, int waterMl, int capsules, int cupsSinceCleaning = 0);

    int addCapsules(int count);
    int addBeans(int grams) override;
    bool brewCoffee(int cupMl) override;
    void printStatus() const override;
};
#endif
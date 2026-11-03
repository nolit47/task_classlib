#include <iostream>
#include <memory>
#include <array>

#include "CapsuleCoffeeMachine.h"
#include "CoffeeMachine.h"
#include "MilkCoffeeMachine.h"

int main() {
    CoffeeMachine home("Philips EP1220", 300, 20, 4);

    std::cout << "--- Philips EP1220 (CoffeeMachine) ---\n";

    home.brewCoffee(250);
    home.brewCoffee(100);
    home.runCleaning();
    home.refillWater(600);
    home.runCleaning();
    home.brewCoffee(100);
    home.addBeans(50);
    home.brewCoffee(100);

    CapsuleCoffeeMachine capsule("Nespresso Vertuo", 500, 2);

    std::cout << "\n--- Nespresso Vertuo (CapsuleCoffeeMachine) ---\n";

    capsule.brewCoffee(150);
    capsule.brewCoffee(150);
    capsule.brewCoffee(150);
    capsule.addCapsules(5);
    capsule.addBeans(100);
    capsule.brewCoffee(150);

    MilkCoffeeMachine office("DeLonghi Magnifica", 1000, 100, 200);

    std::cout << "\n--- DeLonghi Magnifica (MilkCoffeeMachine) ---\n";

    office.brewCoffee(40);
    office.brewLatte(300);
    office.brewLatte(300);
    office.refillMilk(400);
    office.brewLatte(300);

    std::cout << "\n--- Polymorphism ---\n";

    std::array<std::unique_ptr<CoffeeMachine>, 3> machines;

    machines[0] = std::make_unique<CoffeeMachine>("Generic", 500, 50);
    machines[1] = std::make_unique<CapsuleCoffeeMachine>("Dolce Gusto", 500, 3);
    machines[2] = std::make_unique<MilkCoffeeMachine>("Jura E8", 800, 100, 300);

    for (auto& m : machines) {
        m->brewCoffee(100);
        m->printStatus();
    }
    return 0;
}
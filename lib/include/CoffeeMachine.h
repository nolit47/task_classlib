#ifndef COFFEE_MACHINE_H
#define COFFEE_MACHINE_H

#include <string>

class CoffeeMachine {
protected:
    static constexpr int MAX_WATER_ML = 1200;
    static constexpr int MAX_BEANS_G = 250;
    static constexpr int CUPS_BEFORE_CLEANING = 5;
    static constexpr int CLEANING_WATER_ML = 200;
    static constexpr int ML_PER_GRAM_OF_BEANS = 15;

    std::string model_;
    int waterMl_;
    int beansG_;
    int cupsSinceCleaning_;

    int beansNeeded(int cupMl) const;
    bool checkReady(int cupMl) const;

public:
    CoffeeMachine(const std::string& model, int waterMl, int beansG, int cupsSinceCleaning = 0);
    virtual ~CoffeeMachine() = default;

    const std::string& model() const { return model_; }

    int refillWater(int ml);
    virtual int addBeans(int grams);
    virtual bool brewCoffee(int cupMl);
    bool runCleaning();
    virtual void printStatus() const;
};

#endif
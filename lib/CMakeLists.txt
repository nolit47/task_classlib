add_library(coffee_lib STATIC
    src/CoffeeMachine.cpp
    src/CapsuleCoffeeMachine.cpp
    src/MilkCoffeeMachine.cpp
)

target_include_directories(coffee_lib PUBLIC include)

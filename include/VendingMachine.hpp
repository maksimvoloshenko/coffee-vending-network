#pragma once

#include "Ingredient.hpp"
#include "Recipe.hpp"

class VendingMachine
{
public:
    VendingMachine(const std::string& id, int maxCoffee, int maxMilk);
    ~VendingMachine();

    std::string GetId() const;

    bool AddCoffee(int amount);
    bool AddMilk(int amount);
    bool MakeDrink(const Recipe& recipe);

    // Новые методы для наблюдателя (NetworkOperator)
    int GetCoffeeAmount() const;
    int GetMilkAmount() const;

private:
    std::string m_id;
    Ingredient m_coffee;
    Ingredient m_milk;
};

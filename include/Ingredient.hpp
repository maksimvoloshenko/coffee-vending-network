#pragma once

#include <string>

class Ingredient
{
public:
    Ingredient(const std::string& name, int maxAmount);
    ~Ingredient();

    std::string GetName() const;
    int GetAmount() const;
    int GetMaxAmount() const;

    bool Add(int amount);
    bool Consume(int amount);

private:
    std::string m_name;
    int m_amount;
    int m_maxAmount;
};

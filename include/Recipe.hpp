#pragma once

#include <string>

class Recipe
{
public:
    Recipe(const std::string& name, int requiredCoffee, int requiredMilk);
    ~Recipe();

    std::string GetName() const;
    int GetRequiredCoffee() const;
    int GetRequiredMilk() const;

private:
    std::string m_name;
    int m_requiredCoffee;
    int m_requiredMilk;
};

#include "Recipe.hpp"
#include <iostream>

Recipe::Recipe(const std::string& name, int coffee, int milk)
    : m_name(name), m_requiredCoffee(coffee), m_requiredMilk(milk)
{
    std::cout << "Recipe '" << m_name << "' created\n";
}

Recipe::~Recipe()
{
    std::cout << "Recipe '" << m_name << "' destroyed\n";
}

std::string Recipe::GetName() const { return m_name; }
int Recipe::GetRequiredCoffee() const { return m_requiredCoffee; }
int Recipe::GetRequiredMilk() const { return m_requiredMilk; }

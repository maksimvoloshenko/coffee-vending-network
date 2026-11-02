#include "Ingredient.hpp"
#include <iostream>

Ingredient::Ingredient(const std::string& name, int maxAmount)
    : m_name(name), m_amount(0), m_maxAmount(maxAmount)
{
    std::cout << "Ingredient '" << m_name << "' created\n";
}

Ingredient::~Ingredient()
{
    std::cout << "Ingredient '" << m_name << "' destroyed\n";
}

std::string Ingredient::GetName() const { return m_name; }
int Ingredient::GetAmount() const { return m_amount; }
int Ingredient::GetMaxAmount() const { return m_maxAmount; }

bool Ingredient::Add(int amount)
{
    if (m_amount + amount > m_maxAmount)
    {
        std::cout << "Cannot add " << amount << " to " << m_name
                  << ": exceeds max (" << m_maxAmount << ")\n";
        return false;
    }
    m_amount += amount;
    return true;
}

bool Ingredient::Consume(int amount)
{
    if (amount > m_amount)
    {
        std::cout << "Not enough " << m_name << " to consume " << amount << "\n";
        return false;
    }
    m_amount -= amount;
    return true;
}

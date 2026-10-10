#include "VendingMachine.hpp"
#include <iostream>

VendingMachine::VendingMachine(const std::string& id, int maxCoffee, int maxMilk)
    : m_id(id), m_coffee("coffee", maxCoffee), m_milk("milk", maxMilk)
{
    std::cout << "VendingMachine '" << m_id << "' created\n";
}

VendingMachine::~VendingMachine()
{
    std::cout << "VendingMachine '" << m_id << "' destroyed\n";
}

std::string VendingMachine::GetId() const { return m_id; }

bool VendingMachine::AddCoffee(int amount)
{
    return m_coffee.Add(amount);
}

bool VendingMachine::AddMilk(int amount)
{
    return m_milk.Add(amount);
}

bool VendingMachine::MakeDrink(const Recipe& recipe)
{
    if (m_coffee.GetAmount() < recipe.GetRequiredCoffee() ||
        m_milk.GetAmount() < recipe.GetRequiredMilk())
    {
        std::cout << "Cannot make " << recipe.GetName()
                  << ": not enough ingredients\n";
        return false;
    }

    m_coffee.Consume(recipe.GetRequiredCoffee());
    m_milk.Consume(recipe.GetRequiredMilk());
    std::cout << "Drink '" << recipe.GetName() << "' is ready!\n";
    return true;
}

int VendingMachine::GetCoffeeAmount() const
{
    return m_coffee.GetAmount();
}

int VendingMachine::GetMilkAmount() const
{
    return m_milk.GetAmount();
}

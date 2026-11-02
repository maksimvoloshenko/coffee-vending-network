#include "NetworkOperator.hpp"
#include "VendingMachine.hpp"
#include <iostream>

NetworkOperator::NetworkOperator(const std::string& name)
    : m_name(name)
{
    std::cout << "NetworkOperator '" << m_name << "' created\n";
}

NetworkOperator::~NetworkOperator()
{
    std::cout << "NetworkOperator '" << m_name << "' destroyed\n";
}

void NetworkOperator::Watch(const std::shared_ptr<VendingMachine>& machine)
{
    m_machine = machine;
}

void NetworkOperator::Report() const
{
    if (std::shared_ptr<VendingMachine> machine = m_machine.lock())
    {
        std::cout << "Operator '" << m_name << "': machine '"
                  << machine->GetId() << "' is online (coffee: "
                  << machine->GetCoffeeAmount() << ", milk: "
                  << machine->GetMilkAmount() << ")\n";
    }
    else
    {
        std::cout << "Operator '" << m_name
                  << "': machine is gone, report unavailable\n";
    }
}


#include "SnackMachine.hpp"

SnackMachine::SnackMachine(const std::string& id, const std::string& location, int slots)
    : BaseMachine(id, location), m_slots(slots)
{
    std::cout << "SnackMachine() created: " << m_id << "\n";
}

SnackMachine::~SnackMachine()
{
    std::cout << "~SnackMachine() destroyed: " << m_id << "\n";
}

std::string SnackMachine::Describe() const
{
    // Не вызываем GetHeader(), полностью меняем формат
    return "SNACK MACHINE -> ID: " + m_id + ", slots: " + std::to_string(m_slots);
}

std::unique_ptr<BaseMachine> SnackMachine::Clone() const
{
    return std::make_unique<SnackMachine>(*this);
}

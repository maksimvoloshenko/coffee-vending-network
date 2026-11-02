#include "BaseMachine.hpp"

BaseMachine::BaseMachine(const std::string& id, const std::string& location)
    : m_id(id), m_location(location)
{
    s_totalMachines++;
    std::cout << "BaseMachine() created: " << m_id << "\n";
}

BaseMachine::~BaseMachine()
{
    std::cout << "~BaseMachine() destroyed: " << m_id << "\n";
}

std::string BaseMachine::GetHeader() const
{
    return "Machine [" + m_id + "] at " + m_location;
}

#include "TeaMachine.hpp"
#include <iostream>

TeaMachine::TeaMachine(const std::string& id, const std::string& location)
    : BaseMachine(id, location), m_teaBags(1) {
    std::cout << "TeaMachine() created: " << m_id << "\n";
}

TeaMachine::~TeaMachine() noexcept {
    std::cout << "~TeaMachine() destroyed: " << m_id << "\n";
}

std::string TeaMachine::Describe() const {
    return "TeaMachine -> ID: " + m_id;
}

std::unique_ptr<BaseMachine> TeaMachine::Clone() const {
    return std::make_unique<TeaMachine>(*this);
}

void TeaMachine::PrepareDrink(std::string_view drinkName) {
    if (m_teaBags == 0) {
        throw NoIngredientsException(drinkName);
    }
    m_teaBags--;
    std::cout << "Чайный автомат " << m_id << " заварил: " << drinkName << "\n";
}

bool TeaMachine::IsReady() const {
    return m_teaBags > 0;
}

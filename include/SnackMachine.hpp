#pragma once
#include "BaseMachine.hpp"

class SnackMachine final : public BaseMachine 
{
public:
    SnackMachine(const std::string& id, const std::string& location, int slots);
    ~SnackMachine() noexcept override;

    std::string Describe() const override;
    std::unique_ptr<BaseMachine> Clone() const override;

    std::string GetCategory() const { return "Снековый автомат"; }

private:
    int m_slots;
};

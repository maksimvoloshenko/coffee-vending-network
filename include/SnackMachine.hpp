#pragma once
#include "BaseMachine.hpp"

// final запрещает дальнейшее наследование
class SnackMachine final : public BaseMachine 
{
public:
    SnackMachine(const std::string& id, const std::string& location, int slots);
    ~SnackMachine() override;

    // Переопределение БЕЗ вызова базового метода
    std::string Describe() const override;
    std::unique_ptr<BaseMachine> Clone() const override;

private:
    int m_slots;
};

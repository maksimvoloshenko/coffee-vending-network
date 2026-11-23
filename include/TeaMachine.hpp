#pragma once
#include "BaseMachine.hpp"
#include "IPreparable.hpp"

class TeaMachine : public BaseMachine, public IPreparable {
public:
    TeaMachine(const std::string& id, const std::string& location);
    ~TeaMachine() noexcept override;

    std::string Describe() const override;
    std::unique_ptr<BaseMachine> Clone() const override;

    std::string GetCategory() const { return "Чайный автомат"; }

    // Реализация интерфейса
    void PrepareDrink(std::string_view drinkName) override;
    bool IsReady() const override;

private:
    int m_teaBags{ 0 };
};

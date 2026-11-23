#pragma once
#include "BaseMachine.hpp"
#include "Recipe.hpp"
#include "IPreparable.hpp"

class CoffeeMachine : public BaseMachine, public IPreparable 
{
public:
    CoffeeMachine(const std::string& id, const std::string& location, 
                  const std::string& coffeeType, std::shared_ptr<Recipe> recipe);
    
    CoffeeMachine(const CoffeeMachine& other);
    CoffeeMachine(CoffeeMachine&& other) noexcept;
    CoffeeMachine& operator=(const CoffeeMachine& other);

    ~CoffeeMachine() noexcept override;

    std::string Describe() const override;
    std::unique_ptr<BaseMachine> Clone() const override;

    std::string GetCategory() const { return "Кофейный автомат"; }

    void PrepareDrink(std::string_view drinkName) override;
    bool IsReady() const override;

private:
    std::string m_coffeeType;
    std::shared_ptr<Recipe> m_recipe;
    int m_cupsAvailable{ 1 }; 
};

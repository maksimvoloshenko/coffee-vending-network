#pragma once
#include "BaseMachine.hpp"
#include "Recipe.hpp"

class CoffeeMachine : public BaseMachine
{
public:
    CoffeeMachine(const std::string& id, const std::string& location, 
                  const std::string& coffeeType, std::shared_ptr<Recipe> recipe);
    
    // Конструктор копирования (Глубокая копия)
    CoffeeMachine(const CoffeeMachine& other);
    
    // Конструктор перемещения
    CoffeeMachine(CoffeeMachine&& other) noexcept;

    // Оператор присваивания (демонстрация this)
    CoffeeMachine& operator=(const CoffeeMachine& other);

    ~CoffeeMachine() override;

    // Переопределение с вызовом базового метода
    std::string Describe() const override;
    
    std::unique_ptr<BaseMachine> Clone() const override;

private:
    std::string m_coffeeType;
    std::shared_ptr<Recipe> m_recipe;
};

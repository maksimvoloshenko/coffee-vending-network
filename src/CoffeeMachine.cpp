#include "CoffeeMachine.hpp"

CoffeeMachine::CoffeeMachine(const std::string& id, const std::string& location,
                             const std::string& coffeeType, std::shared_ptr<Recipe> recipe)
    : BaseMachine(id, location), m_coffeeType(coffeeType), m_recipe(recipe)
{
    std::cout << "CoffeeMachine() created: " << m_id << "\n";
}

// Глубокая копия: создаем НОВЫЙ Recipe
CoffeeMachine::CoffeeMachine(const CoffeeMachine& other)
    : BaseMachine(other)
    , m_coffeeType(other.m_coffeeType)
    , m_recipe(std::make_shared<Recipe>(*other.m_recipe)) 
{
    std::cout << "CoffeeMachine() COPY created: " << m_id << "\n";
}

CoffeeMachine::CoffeeMachine(CoffeeMachine&& other) noexcept
    : BaseMachine(std::move(other))
    , m_coffeeType(std::move(other.m_coffeeType))
    , m_recipe(std::move(other.m_recipe))
{
    std::cout << "CoffeeMachine() MOVE created: " << m_id << "\n";
}

CoffeeMachine& CoffeeMachine::operator=(const CoffeeMachine& other)
{
    if (this == &other) { // Демонстрация this: проверка самоприсваивания
        return *this; 
    }
    BaseMachine::operator=(other);
    m_coffeeType = other.m_coffeeType;
    m_recipe = std::make_shared<Recipe>(*other.m_recipe); // Глубокая копия
    return *this;
}

CoffeeMachine::~CoffeeMachine()
{
    std::cout << "~CoffeeMachine() destroyed: " << m_id << "\n";
}

std::string CoffeeMachine::Describe() const
{
    // Вызов базового protected-метода + строки
    std::string desc = GetHeader() + " | Coffee: " + m_coffeeType;
    if (m_recipe->GetName().find("Cappuccino") != std::string::npos) {
        desc += " (Premium)";
    }
    return desc;
}

std::unique_ptr<BaseMachine> CoffeeMachine::Clone() const
{
    return std::make_unique<CoffeeMachine>(*this);
}

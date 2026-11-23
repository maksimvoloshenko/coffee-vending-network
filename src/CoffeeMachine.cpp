#include "CoffeeMachine.hpp"

CoffeeMachine::CoffeeMachine(const std::string& id, const std::string& location,
                             const std::string& coffeeType, std::shared_ptr<Recipe> recipe)
    : BaseMachine(id, location), m_coffeeType(coffeeType), m_recipe(recipe)
{
    std::cout << "CoffeeMachine() created: " << m_id << "\n";
}

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
    if (this == &other) return *this; 
    BaseMachine::operator=(other);
    m_coffeeType = other.m_coffeeType;
    m_recipe = std::make_shared<Recipe>(*other.m_recipe); 
    return *this;
}

CoffeeMachine::~CoffeeMachine() noexcept
{
    std::cout << "~CoffeeMachine() destroyed: " << m_id << "\n";
}

std::string CoffeeMachine::Describe() const
{
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

void CoffeeMachine::PrepareDrink(std::string_view drinkName) {
    if (m_cupsAvailable == 0) {
        throw NoIngredientsException(drinkName); 
    }
    m_cupsAvailable--;
    std::cout << "Кофейный автомат " << m_id << " приготовил: " << drinkName << "\n";
}

bool CoffeeMachine::IsReady() const {
    return m_cupsAvailable > 0;
}

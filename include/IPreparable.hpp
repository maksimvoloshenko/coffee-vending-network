#pragma once
#include <stdexcept>
#include <string>
#include <string_view>

// Наш контракт: "Я умею готовить напитки"
class IPreparable {
public:
    virtual ~IPreparable() = default;
    virtual void PrepareDrink(std::string_view drinkName) = 0;
    virtual bool IsReady() const = 0;
};

// Собственное исключение предметной области
class NoIngredientsException : public std::runtime_error {
public:
    explicit NoIngredientsException(std::string_view drinkName)
        : std::runtime_error("Не хватает ингредиентов для: " + std::string(drinkName)) {}
};

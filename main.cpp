#include <windows.h>
#include <iostream>
#include <memory>
#include <vector>
#include "BaseMachine.hpp"
#include "CoffeeMachine.hpp"
#include "SnackMachine.hpp"
#include "TeaMachine.hpp"
#include "DiscountPolicy.hpp"
#include "IPreparable.hpp"

void ServeDrink(IPreparable& item, std::string_view drink) {
    try {
        item.PrepareDrink(drink);
    } catch (const NoIngredientsException& e) {
        std::cout << "[Исключение] " << e.what() << " — Пополните автомат!\n";
    }
}

void CheckMachine(BaseMachine& machine) {
    std::cout << "\nПроверка автомата " << machine.GetId() << ":\n";
    if (auto* preparable = dynamic_cast<IPreparable*>(&machine)) {
        std::cout << " -> Умеет готовить!\n";
        ServeDrink(*preparable, "Cappuccino");
        ServeDrink(*preparable, "Latte"); 
    } else {
        std::cout << " -> Не умеет готовить напитки (только снеки).\n";
    }
}

int main() {
SetConsoleOutputCP(CP_UTF8);
    std::cout << "=== 1. Раннее и позднее связывание ===\n";
    std::vector<std::unique_ptr<BaseMachine>> network;
    
    network.push_back(std::make_unique<CoffeeMachine>("CM-01", "Холл", "Arabica", std::make_shared<Recipe>("Espresso", 10, 0)));
    network.push_back(std::make_unique<TeaMachine>("TM-01", "2 этаж"));
    network.push_back(std::make_unique<SnackMachine>("SM-01", "1 этаж", 20));

    for (const auto& machine : network) {
        std::cout << "Категория: " << machine->GetCategory() << "\n";
        std::cout << "Описание: " << machine->Describe() << "\n";
    }

    std::cout << "\n=== 2. dynamic_cast и Исключения ===\n";
    for (const auto& machine : network) {
        CheckMachine(*machine);
    }

    std::cout << "\n=== 3. Конфигурирование поведения (Скидки) ===\n";
    Order myOrder(200, std::make_unique<NoDiscount>());
    std::cout << "Обычная цена: " << myOrder.GetFinalPrice() << " руб.\n";

    myOrder.SetPolicy(std::make_unique<StudentDiscount>());
    std::cout << "Студенческая цена: " << myOrder.GetFinalPrice() << " руб.\n";

    return 0;
}

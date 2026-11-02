#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "CoffeeMachine.hpp"
#include "SnackMachine.hpp"

int main() {
    std::cout << "=== 1. Polymorphism and Virtual Destructor ===\n";
    {
        auto recipe1 = std::make_shared<Recipe>("Cappuccino", 10, 20);
        
        // Массив указателей на базовый класс
        std::vector<std::unique_ptr<BaseMachine>> machines;
        machines.push_back(std::make_unique<CoffeeMachine>("CM-01", "Hall", "Arabica", recipe1));
        machines.push_back(std::make_unique<SnackMachine>("SM-01", "Lobby", 10));

        for (const auto& m : machines) {
            std::cout << m->Describe() << "\n";
        }
    } // Виртуальные деструкторы вызовутся автоматически

    std::cout << "\n=== 2. Deep Copy and Assignment (this) ===\n";
    auto recipe2 = std::make_shared<Recipe>("Latte", 5, 15);
    CoffeeMachine original("CM-02", "Office", "Latte", recipe2);
    
    // Вызов конструктора копирования (Глубокая копия)
    CoffeeMachine deepCopy = original;
    
    std::cout << "Original: " << original.Describe() << "\n";
    std::cout << "DeepCopy: " << deepCopy.Describe() << "\n";
    
    // Присваивание (вызовет наш оператор с this)
    CoffeeMachine another("CM-03", "Floor", "Espresso", recipe2);
    another = original;
    std::cout << "Another after assignment: " << another.Describe() << "\n";

    std::cout << "\n=== 3. Clone ===\n";
    std::unique_ptr<BaseMachine> cloned = original.Clone();
    std::cout << "Cloned: " << cloned->Describe() << "\n";

    std::cout << "\n=== 4. Static Members ===\n";
    std::cout << "Total machines created: " << BaseMachine::GetTotalMachines() << "\n";

    std::cout << "\n=== 5. String operations ===\n";
    std::string text = "Coffee Vending Network";
    std::cout << "Original: " << text << "\n";
    std::cout << "Length: " << text.length() << "\n";
    std::cout << "Find 'Vending': " << text.find("Vending") << "\n";
    std::cout << "Substr (0, 6): " << text.substr(0, 6) << "\n";
    if (text == "Coffee Vending Network") std::cout << "Strings are equal\n";

    std::cout << "\n=== End of program ===\n";
    return 0;
}

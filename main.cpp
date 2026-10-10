#include <iostream>
#include <memory>
#include <vector>
#include "VendingMachine.hpp"
#include "Recipe.hpp"
#include "NetworkOperator.hpp"

int main()
{
    // ============================================================
    // Блок 1. unique_ptr — один владелец
    // ============================================================
    std::cout << "=== unique_ptr: single owner ===\n";
    {
        std::unique_ptr<VendingMachine> machine =
            std::make_unique<VendingMachine>("VM-01", 100, 100);

        machine->AddCoffee(50);
        machine->AddMilk(50);

        std::unique_ptr<Recipe> cappuccino =
            std::make_unique<Recipe>("Cappuccino", 10, 20);

        machine->MakeDrink(*cappuccino);

        machine->AddCoffee(100);

        std::unique_ptr<VendingMachine> movedMachine = std::move(machine);
        std::cout << "After std::move machine is empty: "
                  << (machine == nullptr ? "true" : "false") << "\n";
    }

    // ============================================================
    // Блок 2. shared_ptr и weak_ptr
    // ============================================================
    std::cout << "\n=== shared_ptr and weak_ptr ===\n";
    {
        std::shared_ptr<VendingMachine> machine =
            std::make_shared<VendingMachine>("VM-02", 100, 100);

        machine->AddCoffee(50);
        machine->AddMilk(40);

        NetworkOperator op("Operator-1");
        op.Watch(machine);

        std::cout << "use_count after creation: " << machine.use_count() << "\n";

        {
            std::shared_ptr<VendingMachine> copy = machine;
            std::cout << "use_count after copy: " << machine.use_count() << "\n";
        }
        std::cout << "use_count after copy is destroyed: " << machine.use_count() << "\n";

        op.Report();

        machine.reset();
        std::cout << "use_count after last owner released: " << machine.use_count() << "\n";

        op.Report();
    }

    // ============================================================
    // Блок 3. Массив динамических объектов
    // ============================================================
    std::cout << "\n=== Array of dynamic objects ===\n";    {
        std::vector<std::unique_ptr<VendingMachine>> machines;

        machines.push_back(std::make_unique<VendingMachine>("VM-03", 50, 50));
        machines.push_back(std::make_unique<VendingMachine>("VM-04", 60, 60));

        for (auto& m : machines)
        {
            m->AddCoffee(30);
            m->AddMilk(30);
        }

        std::cout << "Machines in network: " << machines.size() << "\n";
    }

    std::cout << "\n=== Program finished ===\n";
    return 0;
}

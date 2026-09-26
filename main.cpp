#include <iostream>
#include "VendingMachine.hpp"
#include "Recipe.hpp"

int main()
{
    std::cout << "=== Static objects ===\n";
    {
        VendingMachine machine("VM-01", 100, 100);
        machine.AddCoffee(50);
        machine.AddMilk(50);
    }

    std::cout << "\n=== Dynamic objects ===\n";
    VendingMachine* dynMachine = new VendingMachine("VM-02", 80, 80);
    dynMachine->AddCoffee(40);
    dynMachine->AddMilk(40);

    Recipe* cappuccino = new Recipe("Cappuccino", 10, 20);
    dynMachine->MakeDrink(*cappuccino);

    dynMachine->AddCoffee(100);

    delete dynMachine;
    std::cout << "After machine deletion, recipe is still alive: "
              << cappuccino->GetName() << "\n";
    delete cappuccino;

    std::cout << "\n=== Array of dynamic objects ===\n";
    const int N = 2;
    VendingMachine** machines = new VendingMachine*[N];
    machines[0] = new VendingMachine("VM-03", 50, 50);
    machines[1] = new VendingMachine("VM-04", 60, 60);
    for (int i = 0; i < N; ++i)
    {
        machines[i]->AddCoffee(30);
        machines[i]->AddMilk(30);
    }
    for (int i = 0; i < N; ++i)
        delete machines[i];
    delete[] machines;

    return 0;
}

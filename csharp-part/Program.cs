using System;
using System.Collections.Generic;

namespace CoffeeVendingNetwork
{
    public class Program
    {
        public static void Main()
        {
            Console.WriteLine("=== 1. Базовые классы и абстракция ===\n");
            var recipe1 = new Recipe("Cappuccino", 10, 20);
            
            var machines = new List<BaseMachine>
            {
                new CoffeeMachine("CM-01", "Зал", "Arabica", recipe1),
                new SnackMachine("SM-01", "Лобби", 10)
            };

            foreach (var m in machines)
            {
                Console.WriteLine(m.Describe());
            }

            Console.WriteLine("\n=== 2. Глубокое копирование и Equals ===\n");
            var original = new CoffeeMachine("CM-02", "Офис", "Latte", new Recipe("Latte", 5, 15));
            var deepCopy = new CoffeeMachine(original);
            
            Console.WriteLine($"Оригинал: {original.Describe()}");
            Console.WriteLine($"Копия: {deepCopy.Describe()}");
            Console.WriteLine($"Равны по содержимому? {original.Equals(deepCopy)}");

            Console.WriteLine("\n=== 3. Статические члены ===\n");
            Console.WriteLine($"Всего создано автоматов: {BaseMachine.TotalMachines}");

            Console.WriteLine("\n=== 4. Использование using в C# ===\n");
            using var log = new OperationLog("VM-01");
            log.Write("Система инициализирована, все автоматы онлайн");
        }
    }
}

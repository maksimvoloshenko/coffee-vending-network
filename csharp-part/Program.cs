using System;
using System.Collections.Generic;

namespace CoffeeVendingNetwork
{
    public class Program
    {
        // Демонстрация работы через интерфейс
        static void ServeDrink(IPreparable item, string drink)
        {
            try
            {
                item.PrepareDrink(drink);
            }
            catch (NoIngredientsException e)
            {
                Console.WriteLine($"[Исключение] {e.Message} — Пополните автомат!");
            }
        }

        // Проверка типа через is и as
        static void CheckMachine(BaseMachine machine)
        {
            Console.WriteLine($"\nПроверка автомата {machine.Id}:");
            
            // В C# используем 'is' для проверки типа (аналог dynamic_cast)
            if (machine is IPreparable preparable)
            {
                Console.WriteLine(" -> Умеет готовить! (сработал is)");
                ServeDrink(preparable, "Cappuccino");
                ServeDrink(preparable, "Latte"); 
            }
            else
            {
                Console.WriteLine(" -> Не умеет готовить напитки (только снеки).");
            }
            
            // Использование 'as' (возвращает null, если тип не совпадает)
            var preparableAs = machine as IPreparable;
            if (preparableAs == null)
            {
                Console.WriteLine(" (проверка через as: null, не IPreparable)");
            }
        }

        public static void Main()
        {
            Console.OutputEncoding = System.Text.Encoding.UTF8; // Для русского текста
            
            Console.WriteLine("=== 1. Раннее и позднее связывание ===");
            var network = new List<BaseMachine>
            {
                new CoffeeMachine("CM-01"),
                new SnackMachine("SM-01")
            };

            foreach (var machine in network)
            {
                // Раннее (вызывается метод из BaseMachine)
                Console.WriteLine($"Категория: {machine.GetCategory()}");
                // Позднее (вызывается метод наследника)
                Console.WriteLine($"Описание: {machine.Describe()}");
            }

            Console.WriteLine("\n=== 2. is / as и Исключения ===");
            foreach (var machine in network)
            {
                CheckMachine(machine);
            }

            Console.WriteLine("\n=== 3. IComparable (Сортировка) ===");
            network.Sort(); // Сортировка массива с помощью IComparable
            foreach (var machine in network)
            {
                Console.WriteLine($"Автомат: {machine.Id}");
            }

            Console.WriteLine("\n=== 4. Исключения в предметной области ===");
            try
            {
                Ingredient coffee = new Ingredient("coffee", 100);
                coffee.Add(50);
                coffee.Add(100); // Здесь вылетит исключение InvalidOperationException
            }
            catch (InvalidOperationException ex)
            {
                Console.WriteLine($"[Ошибка правила] {ex.Message}");
            }
            finally
            {
                // Блок finally выполнится в любом случае (требование ЛР5)
                Console.WriteLine("Блок finally выполнен (проверка правила завершена).");
            }

            Console.WriteLine("\n=== 5. Освобождение ресурса (using) ===");
            using (OperationLog log = new OperationLog("VM-01"))
            {
                log.Write("продажа: Cappuccino");
                log.Write("событие: уровень кофе ниже критического");
            }
            
            GC.Collect();
            GC.WaitForPendingFinalizers();
            Console.WriteLine("\n=== Программа завершена ===");
        }
    }
}

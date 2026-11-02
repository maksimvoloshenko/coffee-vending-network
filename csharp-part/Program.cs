using System;

namespace CoffeeVendingNetwork
{
    public class Program
    {
        public static void Main()
        {
            Console.WriteLine("=== Композиция и агрегация ===\n");
            DemoCompositionAndAggregation();

            Console.WriteLine("\n=== Ссылки и копии (классы) ===\n");
            DemoReferencesAndCopies();

            Console.WriteLine("\n=== Значимые типы (struct) ===\n");
            DemoStruct();

            Console.WriteLine("\n=== Освобождение ресурса (IDisposable + using) ===\n");
            DemoDisposable();

            Console.WriteLine("\n=== Сборщик мусора (финализатор) ===\n");
            DemoGarbageCollector();

            // ------------------------------------------------------------
            // Финальная сборка — ловим "отставшие" финализаторы.
            // К этому моменту все локальные переменные вышли из области
            // видимости, и сборщик может уничтожить оставшиеся объекты.
            // ------------------------------------------------------------
            GC.Collect();
            GC.WaitForPendingFinalizers();
            GC.Collect();
            GC.WaitForPendingFinalizers();
            System.Threading.Thread.Sleep(200);

            Console.WriteLine("\n=== Программа завершена ===");
        }

        // ------------------------------------------------------------
        // 1. Композиция и агрегация
        // ------------------------------------------------------------
        static void DemoCompositionAndAggregation()
        {
            // Композиция: автомат создаёт свои ингредиенты ВНУТРИ
            VendingMachine machine = new VendingMachine("VM-01", 100, 100);

            // Пополняем ингредиенты
            machine.AddCoffee(50);
            machine.AddMilk(50);
            Console.WriteLine($"Состояние: {machine}");

            // Агрегация: рецепт создаётся СНАРУЖИ и передаётся автомату
            Recipe cappuccino = new Recipe("Cappuccino", 10, 20);

            // Автомат использует рецепт, но не владеет им
            machine.MakeDrink(cappuccino);
            Console.WriteLine($"Состояние после приготовления: {machine}");

            // Проверка правила: пытаемся нарушить
            Console.WriteLine("\nПопытка нарушить правило (добавить 100 кофе при максимуме 100):");
            machine.AddCoffee(100);

            // Рецепт cappuccino всё ещё жив — агрегация
            Console.WriteLine($"Рецепт '{cappuccino.Name}' жив после использования: {cappuccino}");
        }

        // ------------------------------------------------------------
        // 2. Ссылки и копии (классы — ссылочные типы)
        // ------------------------------------------------------------
        static void DemoReferencesAndCopies()
        {
            // Создаём ингредиент
            Ingredient first = new Ingredient("coffee", 100);
            first.Add(50);
            Console.WriteLine($"first: {first}");

            // В C# переменная хранит ССЫЛКУ, а не объект.
            // Присваивание копирует ССЫЛКУ — обе переменные указывают на один объект.
            Ingredient second = first;

            // Меняем через вторую переменную
            second.Add(20);

            // Первая переменная "тоже изменилась" — это тот же объект!
            Console.WriteLine($"first после изменения через second: {first}");
            Console.WriteLine($"second: {second}");
            Console.WriteLine($"first == second (один и тот же объект?): {ReferenceEquals(first, second)}");

            // Чтобы получить НЕЗАВИСИМУЮ копию, нужно создать новый объект явно
            Ingredient third = new Ingredient("coffee", 100);
            third.Add(50);
            Console.WriteLine($"\nТретий объект (создан явно): {third}");
            Console.WriteLine($"first == third (разные объекты?): {ReferenceEquals(first, third)}");
        }

        // ------------------------------------------------------------
        // 3. Значимые типы (struct) — копируются по значению
        // ------------------------------------------------------------
        static void DemoStruct()
        {
            // Создаём struct (значимый тип)
            Money a = new Money(150, 50);
            Console.WriteLine($"a: {a}");

            // Присваивание КОПИРУЕТ значение, а не ссылку
            Money b = a;

            // Меняем b — a НЕ меняется
            b.Rubles = 300;
            b.Kopecks = 0;

            Console.WriteLine($"a после изменения b: {a}");   // 150 руб. 50 коп.
            Console.WriteLine($"b: {b}");                       // 300 руб. 0 коп.
            Console.WriteLine("Структура скопирована по значению — a не изменилась.");
        }

        // ------------------------------------------------------------
        // 4. Освобождение ресурса через IDisposable
        // ------------------------------------------------------------
        static void DemoDisposable()
        {
            // Ключевое слово using гарантирует вызов Dispose()
            // при выходе из блока — даже если внутри произойдёт исключение.
            using (OperationLog log = new OperationLog("VM-01"))
            {
                log.Write("продажа: Cappuccino, оплата картой");
                log.Write("продажа: Latte, оплата наличными");
                log.Write("событие: уровень кофе ниже критического");
            }
            // Здесь НЕЯВНО вызван log.Dispose()

            Console.WriteLine("После блока using журнал закрыт, ресурс освобождён.");
        }

        // ------------------------------------------------------------
        // 5. Сборщик мусора — через ФИНАЛИЗАТОР
        // ------------------------------------------------------------
        static void DemoGarbageCollector()
        {
            Console.WriteLine("Создаём объект во вложенном блоке.");
            Console.WriteLine("В C++ деструктор вызвался бы при выходе из блока — детерминированно.");
            Console.WriteLine("В C# финализатор НЕ вызывается при выходе из блока.\n");

            {
                // Создаём объект в блоке
                Ingredient temp = new Ingredient("temporary", 50);
                temp.Add(10);
                Console.WriteLine($"temp создан: {temp}");
            }
            // ← ВЫХОД ИЗ БЛОКА. В C++ здесь был бы вызван деструктор.
            // В C# финализатор НЕ вызывается — объект ещё жив.

            Console.WriteLine("\nВышли из блока. Финализатор НЕ вызван — объект ещё жив.");
            Console.WriteLine("Просим сборщик мусора...\n");

            // Форсированная полная сборка мусора всех поколений
            GC.Collect(GC.MaxGeneration, GCCollectionMode.Forced, blocking: true, compacting: true);
            GC.WaitForPendingFinalizers();   // ждём, пока финализаторы отработают
            GC.Collect(GC.MaxGeneration, GCCollectionMode.Forced, blocking: true, compacting: true);

            Console.WriteLine("\nЕсли выше появилось сообщение 'finalized by GC' —");
            Console.WriteLine("значит, сборщик мусора уничтожил объект. Это ключевое отличие от C++.");
        }
    }
}
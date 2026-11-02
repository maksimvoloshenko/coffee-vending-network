using System;

namespace CoffeeVendingNetwork
{
    public class CoffeeMachine : BaseMachine
    {
        public string CoffeeType { get; }
        public Recipe Recipe { get; set; }

        // Вызов конструктора базового класса через : base(...)
        public CoffeeMachine(string id, string location, string coffeeType, Recipe recipe) 
            : base(id, location)
        {
            CoffeeType = coffeeType;
            Recipe = recipe;
            Console.WriteLine($"CoffeeMachine() создан: {Id}");
        }

        // Конструктор копирования (Глубокая копия)
        public CoffeeMachine(CoffeeMachine other) : base(other.Id, other.Location)
        {
            CoffeeType = other.CoffeeType;
            // Создаем новый рецепт, чтобы изменения в копии не затрагивали оригинал
            Recipe = new Recipe(other.Recipe.Name, other.Recipe.RequiredCoffee, other.Recipe.RequiredMilk);
            Console.WriteLine($"CoffeeMachine() КОПИЯ создана: {Id}");
        }

        public override string Describe()
        {
            return base.Header() + $" | Кофе: {CoffeeType}";
        }

        // Сравнение по содержимому
        public override bool Equals(object obj)
        {
            if (obj is CoffeeMachine other)
            {
                return Id == other.Id && CoffeeType == other.CoffeeType;
            }
            return false;
        }

        public override int GetHashCode()
        {
            return HashCode.Combine(Id, CoffeeType);
        }
    }
}

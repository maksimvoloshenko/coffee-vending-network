using System;

namespace CoffeeVendingNetwork
{
    /// <summary>
    /// Рецепт — правило приготовления напитка.
    /// Хранит название напитка и необходимое количество ингредиентов.
    /// </summary>
    public class Recipe
    {
        // Поля — приватные
        private string _name;
        private int _requiredCoffee;
        private int _requiredMilk;

        // Свойство только для чтения — название напитка
        public string Name
        {
            get { return _name; }
        }

        // Свойство только для чтения — сколько нужно кофе
        public int RequiredCoffee
        {
            get { return _requiredCoffee; }
        }

        // Свойство только для чтения — сколько нужно молока
        public int RequiredMilk
        {
            get { return _requiredMilk; }
        }

        // Конструктор с параметрами
        public Recipe(string name, int requiredCoffee, int requiredMilk)
        {
            _name = name;
            _requiredCoffee = requiredCoffee;
            _requiredMilk = requiredMilk;
            Console.WriteLine($"Recipe '{_name}' created");
        }

        // ToString() — текстовое представление
        public override string ToString()
        {
            return $"{_name} (coffee: {_requiredCoffee}, milk: {_requiredMilk})";
        }
    }
}
using System;

namespace CoffeeVendingNetwork
{
    /// <summary>
    /// Ингредиент — расходный материал внутри автомата (кофе, молоко).
    /// Хранит название, текущее количество и максимальную вместимость.
    /// </summary>
    public class Ingredient
    {
        // Поля — приватные, доступ только через свойства
        private string _name;
        private int _amount;
        private int _maxAmount;

        // Свойство только для чтения — название не меняется после создания
        public string Name
        {
            get { return _name; }
        }

        // Свойство для чтения текущего количества
        public int Amount
        {
            get { return _amount; }
        }

        // Свойство для чтения максимума
        public int MaxAmount
        {
            get { return _maxAmount; }
        }

        // Конструктор с параметрами
        public Ingredient(string name, int maxAmount)
        {
            _name = name;
            _amount = 0;
            _maxAmount = maxAmount;
            Console.WriteLine($"Ingredient '{_name}' created");
        }

        // Финализатор — аналог деструктора в C++.
        // Вызывается сборщиком мусора перед удалением объекта.
        ~Ingredient()
        {
            Console.WriteLine($"Ingredient '{_name}' finalized by GC");
        }

        // Содержательный метод: пополнить ингредиент
        public bool Add(int amount)
        {
            if (_amount + amount > _maxAmount)
            {
                Console.WriteLine($"Cannot add {amount} to {_name}: exceeds max ({_maxAmount})");
                return false;
            }
            _amount += amount;
            return true;
        }

        // Содержательный метод: израсходовать ингредиент
        public bool Consume(int amount)
        {
            if (amount > _amount)
            {
                Console.WriteLine($"Not enough {_name} to consume {amount}");
                return false;
            }
            _amount -= amount;
            return true;
        }

        // ToString() — вызывается автоматически при выводе объекта
        public override string ToString()
        {
            return $"{_name}: {_amount}/{_maxAmount}";
        }
    }
}
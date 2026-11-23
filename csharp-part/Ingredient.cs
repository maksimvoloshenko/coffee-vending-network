using System;

namespace CoffeeVendingNetwork
{
    public class Ingredient
    {
        private string _name;
        private int _amount;
        private int _maxAmount;

        public string Name => _name;
        public int Amount => _amount;
        public int MaxAmount => _maxAmount;

        public Ingredient(string name, int maxAmount)
        {
            _name = name;
            _amount = 0;
            _maxAmount = maxAmount;
            Console.WriteLine($"Ingredient '{_name}' created");
        }

        ~Ingredient()
        {
            Console.WriteLine($"Ingredient '{_name}' finalized by GC");
        }

        // Теперь бросает исключение вместо return false
        public void Add(int amount)
        {
            if (_amount + amount > _maxAmount)
            {
                throw new InvalidOperationException($"Cannot add {amount} to {_name}: exceeds max ({_maxAmount})");
            }
            _amount += amount;
        }

        // Теперь бросает исключение вместо return false
        public void Consume(int amount)
        {
            if (amount > _amount)
            {
                throw new InvalidOperationException($"Not enough {_name} to consume {amount}");
            }
            _amount -= amount;
        }

        public override string ToString()
        {
            return $"{_name}: {_amount}/{_maxAmount}";
        }
    }
}

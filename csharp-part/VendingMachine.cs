using System;

namespace CoffeeVendingNetwork
{
    public class VendingMachine
    {
        private string _id;
        private Ingredient _coffee;
        private Ingredient _milk;

        public string Id => _id;
        public Ingredient Coffee => _coffee;
        public Ingredient Milk => _milk;

        public VendingMachine(string id, int maxCoffee, int maxMilk)
        {
            _id = id;
            _coffee = new Ingredient("coffee", maxCoffee);
            _milk = new Ingredient("milk", maxMilk);
            Console.WriteLine($"VendingMachine '{_id}' created");
        }

        // Изменено на void, так как Ingredient.Add теперь бросает исключение, а не возвращает bool
        public void AddCoffee(int amount)
        {
            _coffee.Add(amount);
        }

        public void AddMilk(int amount)
        {
            _milk.Add(amount);
        }

        public bool MakeDrink(Recipe recipe)
        {
            // Проверка правила: хватает ли ингредиентов?
            // В ЛР5 мы переводим проверки на исключения
            if (_coffee.Amount < recipe.RequiredCoffee ||
                _milk.Amount < recipe.RequiredMilk)
            {
                throw new InvalidOperationException($"Cannot make {recipe.Name}: not enough ingredients");
            }

            // Списываем ингредиенты (они тоже теперь могут бросить исключение)
            _coffee.Consume(recipe.RequiredCoffee);
            _milk.Consume(recipe.RequiredMilk);
            Console.WriteLine($"Drink '{recipe.Name}' is ready!");
            return true;
        }

        public override string ToString()
        {
            return $"VendingMachine '{_id}' [coffee: {_coffee.Amount}/{_coffee.MaxAmount}, milk: {_milk.Amount}/{_milk.MaxAmount}]";
        }
    }
}

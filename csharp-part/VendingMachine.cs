using System;

namespace CoffeeVendingNetwork
{
    /// <summary>
    /// Кофейный автомат. Хранит ингредиенты (композиция)
    /// и умеет готовить напитки по рецептам (агрегация).
    /// </summary>
    public class VendingMachine
    {
        // Поля
        private string _id;
        private Ingredient _coffee;   // композиция: часть автомата
        private Ingredient _milk;     // композиция: часть автомата

        // Свойство для чтения идентификатора
        public string Id
        {
            get { return _id; }
        }

        // Свойство для чтения имени ингредиента кофе
        public Ingredient Coffee
        {
            get { return _coffee; }
        }

        // Свойство для чтения имени ингредиента молоко
        public Ingredient Milk
        {
            get { return _milk; }
        }

        // Конструктор: создаёт автомат с двумя ингредиентами ВНУТРИ (композиция)
        public VendingMachine(string id, int maxCoffee, int maxMilk)
        {
            _id = id;
            _coffee = new Ingredient("coffee", maxCoffee);  // создаём ВНУТРИ
            _milk = new Ingredient("milk", maxMilk);        // создаём ВНУТРИ
            Console.WriteLine($"VendingMachine '{_id}' created");
        }

        // Содержательный метод: пополнить кофе
        public bool AddCoffee(int amount)
        {
            return _coffee.Add(amount);
        }

        // Содержательный метод: пополнить молоко
        public bool AddMilk(int amount)
        {
            return _milk.Add(amount);
        }

        // Содержательный метод: приготовить напиток по рецепту (агрегация)
        // Рецепт передаётся СНАРУЖИ — автомат им не владеет.
        public bool MakeDrink(Recipe recipe)
        {
            // Проверка правила: хватает ли ингредиентов?
            if (_coffee.Amount < recipe.RequiredCoffee ||
                _milk.Amount < recipe.RequiredMilk)
            {
                Console.WriteLine($"Cannot make {recipe.Name}: not enough ingredients");
                return false;
            }

            // Списываем ингредиенты
            _coffee.Consume(recipe.RequiredCoffee);
            _milk.Consume(recipe.RequiredMilk);
            Console.WriteLine($"Drink '{recipe.Name}' is ready!");
            return true;
        }

        // ToString() — текстовое представление
        public override string ToString()
        {
            return $"VendingMachine '{_id}' [coffee: {_coffee.Amount}/{_coffee.MaxAmount}, milk: {_milk.Amount}/{_milk.MaxAmount}]";
        }
    }
}
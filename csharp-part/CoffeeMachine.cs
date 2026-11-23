using System;

namespace CoffeeVendingNetwork
{
    // Множественное наследование: класс + интерфейс
    public class CoffeeMachine : BaseMachine, IPreparable
    {
        private int _cupsAvailable = 1;

        public CoffeeMachine(string id) : base(id) { }

        // В C# раннее связывание делается через new (скрытие метода базы)
        public new string GetCategory() => "Кофейный автомат";

        // Позднее связывание через override
        public override string Describe() => $"CoffeeMachine {Id} (готова)";

        public bool IsReady => _cupsAvailable > 0;

        public void PrepareDrink(string drinkName)
        {
            if (_cupsAvailable == 0)
            {
                throw new NoIngredientsException(drinkName); // Бросаем исключение
            }
            _cupsAvailable--;
            Console.WriteLine($"Кофейный автомат {Id} приготовил: {drinkName}");
        }
    }
}

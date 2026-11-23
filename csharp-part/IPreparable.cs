using System;

namespace CoffeeVendingNetwork
{
    public interface IPreparable
    {
        void PrepareDrink(string drinkName);
        bool IsReady { get; }
    }

    // Собственное исключение предметной области (наследник Exception)
    public class NoIngredientsException : Exception
    {
        public NoIngredientsException(string drinkName) 
            : base($"Не хватает ингредиентов для: {drinkName}") { }
    }
}

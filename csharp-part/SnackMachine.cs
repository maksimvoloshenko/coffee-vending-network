using System;

namespace CoffeeVendingNetwork
{
    // sealed запрещает наследование (аналог final в C++)
    public sealed class SnackMachine : BaseMachine 
    {
        private int Slots { get; }

        public SnackMachine(string id, string location, int slots) : base(id, location)
        {
            Slots = slots;
            Console.WriteLine($"SnackMachine() создан: {Id}");
        }

        public override string Describe()
        {
            // БЕЗ вызова base.Header()
            return $"АВТОМАТ СНЕКОВ -> ID: {Id}, слотов: {Slots}";
        }
    }
}

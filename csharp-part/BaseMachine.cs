using System;

namespace CoffeeVendingNetwork
{
    public abstract class BaseMachine
    {
        protected string Id { get; }
        protected string Location { get; }
        
        public static int TotalMachines { get; private set; }

        protected BaseMachine(string id, string location)
        {
            Id = id;
            Location = location;
            TotalMachines++;
            Console.WriteLine($"BaseMachine() создан: {Id}");
        }

        public abstract string Describe();

        protected string Header() => $"Автомат [{Id}] на {Location}";
    }
}

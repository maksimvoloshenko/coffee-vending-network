using System;

namespace CoffeeVendingNetwork
{
    public class SnackMachine : BaseMachine
    {
        public SnackMachine(string id) : base(id) { }

        // Скрываем метод (раннее связывание)
        public new string GetCategory() => "Снековый автомат";

        public override string Describe() => $"SnackMachine {Id}";
    }
}

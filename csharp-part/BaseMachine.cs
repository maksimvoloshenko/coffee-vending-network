using System;

namespace CoffeeVendingNetwork
{
    public abstract class BaseMachine : IComparable<BaseMachine>
    {
        public string Id { get; }

        protected BaseMachine(string id)
        {
            Id = id;
        }

        // НЕВИРТУАЛЬНЫЙ метод (для раннего связывания)
        public string GetCategory() => "Базовая машина";

        // Виртуальный метод (позднее связывание)
        public virtual string Describe() => $"Автомат {Id}";

        // Реализация стандартного интерфейса IComparable (сортировка по Id)
        // Добавлен '?' чтобы убрать предупреждение о null
        public int CompareTo(BaseMachine? other)
        {
            return string.Compare(Id, other?.Id, StringComparison.Ordinal);
        }
    }
}

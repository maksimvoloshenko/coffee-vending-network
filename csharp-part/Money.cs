using System;

namespace CoffeeVendingNetwork
{
    /// <summary>
    /// Денежная сумма — ЗНАЧИМЫЙ тип (struct).
    /// В отличие от классов, struct копируется ПО ЗНАЧЕНИЮ,
    /// а не по ссылке.
    /// </summary>
    public struct Money
    {
        public int Rubles;
        public int Kopecks;

        public Money(int rubles, int kopecks)
        {
            Rubles = rubles;
            Kopecks = kopecks;
        }

        public override string ToString()
        {
            return $"{Rubles} руб. {Kopecks} коп.";
        }
    }
}
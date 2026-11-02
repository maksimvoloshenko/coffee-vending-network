using System;

namespace CoffeeVendingNetwork
{
    /// <summary>
    /// Журнал операций автомата. Демонстрирует освобождение ресурса
    /// через интерфейс IDisposable и блок using.
    /// </summary>
    public class OperationLog : IDisposable
    {
        private string _machineId;

        public OperationLog(string machineId)
        {
            _machineId = machineId;
            Console.WriteLine($"[+] журнал открыт для автомата: {_machineId}");
        }

        public void Write(string line)
        {
            Console.WriteLine($"    {line}");
        }

        // Dispose() вызывается автоматически при выходе из блока using
        public void Dispose()
        {
            Console.WriteLine($"[-] журнал закрыт для автомата: {_machineId}");
        }
    }
}
#pragma once

#include <iostream>
#include <memory>
#include <string>

class BaseMachine
{
public:
    BaseMachine(const std::string& id, const std::string& location);
    virtual ~BaseMachine(); // Виртуальный деструктор

    // Чисто виртуальные методы (делают класс абстрактным)
    virtual std::string Describe() const = 0;
    virtual std::unique_ptr<BaseMachine> Clone() const = 0;

    std::string GetId() const { return m_id; }
    static int GetTotalMachines() { return s_totalMachines; }

protected:
    // Protected метод: доступен наследникам, но не внешнему коду
    std::string GetHeader() const;
    
    // Защищенный конструктор копирования (защита от срезки)
    BaseMachine(const BaseMachine& other) = default;

    std::string m_id;
    std::string m_location;

private:
    inline static int s_totalMachines{ 0 }; // Статический счетчик
};

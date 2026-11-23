#pragma once
#include <iostream>
#include <memory>
#include <string>

class BaseMachine
{
public:
    BaseMachine(const std::string& id, const std::string& location);
    virtual ~BaseMachine() noexcept; // Добавлен noexcept

    virtual std::string Describe() const = 0;
    virtual std::unique_ptr<BaseMachine> Clone() const = 0;

    // НЕВИРТУАЛЬНЫЙ метод (Раннее связывание)
    std::string GetCategory() const { return "Базовая машина"; }

    std::string GetId() const { return m_id; }
    static int GetTotalMachines() { return s_totalMachines; }

protected:
    std::string GetHeader() const;
    BaseMachine(const BaseMachine& other) = default;

    std::string m_id;
    std::string m_location;

private:
    inline static int s_totalMachines{ 0 };
};

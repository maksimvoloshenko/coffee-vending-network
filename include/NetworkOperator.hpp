#pragma once

#include <memory>
#include <string>

class VendingMachine;

class NetworkOperator
{
public:
    NetworkOperator(const std::string& name);
    ~NetworkOperator();

    void Watch(const std::shared_ptr<VendingMachine>& machine);
    void Report() const;

private:
    std::string m_name;
    std::weak_ptr<VendingMachine> m_machine;
};

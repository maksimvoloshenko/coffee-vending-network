#pragma once
#include <memory>

class IDiscountPolicy {
public:
    virtual ~IDiscountPolicy() = default;
    virtual int CalculatePrice(int basePrice) const = 0;
};

class NoDiscount : public IDiscountPolicy {
public:
    int CalculatePrice(int basePrice) const override { return basePrice; }
};

class StudentDiscount : public IDiscountPolicy {
public:
    int CalculatePrice(int basePrice) const override { return basePrice * 80 / 100; }
};

class Order {
public:
    Order(int basePrice, std::unique_ptr<IDiscountPolicy> policy)
        : m_basePrice(basePrice), m_policy(std::move(policy)) {}
        
    ~Order() noexcept = default;

    void SetPolicy(std::unique_ptr<IDiscountPolicy> policy) { m_policy = std::move(policy); }
    int GetFinalPrice() const { return m_policy->CalculatePrice(m_basePrice); }

private:
    int m_basePrice;
    std::unique_ptr<IDiscountPolicy> m_policy;
};

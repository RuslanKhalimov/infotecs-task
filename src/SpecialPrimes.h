#pragma once
/// @brief Специальные контейнеры простых чисел
/// @author Ruslan Khalimov
/// @date 2020

#include "Primes.h"

/// @brief Контейнер суперпростых чисел
class SuperPrimes : public Primes {
private:
    int next_index = 0;
    Primes primes;
protected:
    void extend_prime_numbers(uint32_t max) override;

public:
    SuperPrimes();

    SuperPrimes(uint32_t max);
};

/// @brief Контейнер простых чисел Софи Жермен
class SophieGermainPrimes : public Primes {
private:
    int small_index = 0, big_index = 0;
    Primes primes;
protected:
    void extend_prime_numbers(uint32_t max) override;

public:
    SophieGermainPrimes();

    SophieGermainPrimes(uint32_t max);
};

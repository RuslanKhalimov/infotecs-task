#pragma once

#include <cstdint>
#include <iterator>
#include <vector>

class Primes {
private:
    void extend_prime_numbers();

protected:
    bool is_limited;
    std::vector<uint32_t> prime_numbers;
    static const uint32_t extension_step = 1000000;

    virtual void extend_prime_numbers(uint32_t max);

public:
    Primes(uint32_t max);

    Primes();

    Primes(const Primes &container) = default;

    Primes &operator=(const Primes &container) = default;

    class Iterator;

    Iterator begin();

    Iterator end();

    uint32_t size();

    uint32_t operator[](uint32_t index);
};

class Primes::Iterator {
private:
    Primes *container;
    std::vector<uint32_t>::iterator iter;
public:
    Iterator(Primes *container, std::vector<uint32_t>::iterator iter);

    Iterator &operator++();

    Iterator operator++(int);

    uint32_t &operator*() const;

    bool operator==(const Iterator &other) const;

    bool operator!=(const Iterator &other) const;
};

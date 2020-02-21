#pragma once

#include <cstdint>
#include <iterator>
#include <vector>

class Primes {
private:
    bool is_limited;
    std::vector<uint32_t> prime_numbers;
public:
    Primes(uint32_t max);

    Primes();

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

    const Iterator operator++(int);

    uint32_t &operator*();

    bool operator==(const Iterator &other) const;

    bool operator!=(const Iterator &other) const;
};

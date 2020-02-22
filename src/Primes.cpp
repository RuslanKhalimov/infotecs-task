#include "Primes.h"

Primes::Primes(uint32_t max) : is_limited(true) {
    extend_prime_numbers(max);
}

Primes::Primes() : is_limited(false) {
}

Primes::Iterator Primes::begin() {
    return Iterator(this, prime_numbers.begin());
}

Primes::Iterator Primes::end() {
    return Iterator(this, prime_numbers.end());
}

uint32_t Primes::size() {
    return prime_numbers.size();
}

uint32_t Primes::operator[](uint32_t index) {
    while (!is_limited && index >= prime_numbers.size()) {
        extend_prime_numbers();
    }
    if (index >= prime_numbers.size()) {
        throw std::out_of_range("Index out of range : " + std::to_string(index));
    }
    return prime_numbers[index];
}

void Primes::extend_prime_numbers() {
    extend_prime_numbers((prime_numbers.empty() ? 0 : prime_numbers.back()) + extension_step);
}

void Primes::extend_prime_numbers(uint32_t max) {
    if (max < 2) return;
    if (prime_numbers.empty()) {
        prime_numbers = {2};
    }
    while (true) {
        uint32_t next_prime = prime_numbers.back();
        bool is_prime = false;
        while (!is_prime && next_prime <= max) {
            is_prime = true;
            ++next_prime;
            for (const uint32_t &x : prime_numbers) {
                if (x * x > next_prime) {
                    break;
                }
                if (next_prime % x == 0) {
                    is_prime = false;
                    break;
                }
            }
        }
        if (next_prime > max) {
            return;
        }
        prime_numbers.push_back(next_prime);
    }
}

/* ---- Iterator ---- */

Primes::Iterator::Iterator(Primes *container, std::vector<uint32_t>::iterator iter) :
        container(container),
        iter(iter) {}

Primes::Iterator Primes::Iterator::operator++(int) {
    while (!container->is_limited && iter == container->prime_numbers.end()) {
        container->extend_prime_numbers();
    }
    return Iterator(container, iter++);
}

Primes::Iterator &Primes::Iterator::operator++() {
    while (!container->is_limited && iter == container->prime_numbers.end()) {
        container->extend_prime_numbers();
    }
    ++iter;
    return *this;
}

uint32_t &Primes::Iterator::operator*() const {
    return *iter;
}

bool Primes::Iterator::operator==(const Primes::Iterator &other) const {
    return container == other.container && iter == other.iter;
}

bool Primes::Iterator::operator!=(const Primes::Iterator &other) const {
    return container != other.container || iter != other.iter;
}

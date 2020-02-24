#include <iostream>

#include "SpecialPrimes.h"

void SuperPrimes::extend_prime_numbers(uint32_t max) {
    while (true) {
        uint32_t next = primes[primes[next_index] - 1];
        if (next > max) {
            break;
        }
        ++next_index;
        prime_numbers.push_back(next);
    }
}

SuperPrimes::SuperPrimes() : Primes() {}

SuperPrimes::SuperPrimes(uint32_t max) {
    is_limited = true;
    SuperPrimes::extend_prime_numbers(max);
}

void SophieGermainPrimes::extend_prime_numbers(uint32_t max) {
    while (true) {
        uint32_t next = primes[small_index];
        if (next > max) {
            break;
        }
        while (primes[big_index] < 2 * next + 1) {
            ++big_index;
        }
        if (primes[big_index] == 2 * next + 1) {
            prime_numbers.push_back(next);
        }
        ++small_index;
    }
}

SophieGermainPrimes::SophieGermainPrimes() : Primes() {}

SophieGermainPrimes::SophieGermainPrimes(uint32_t max) {
    is_limited = true;
    SophieGermainPrimes::extend_prime_numbers(max);
}

#pragma once
/// @brief Контейнер простых чисел
/// @author Ruslan Khalimov
/// @date 2020

#include <cstdint>
#include <iterator>
#include <vector>

/// @brief Контейнер простых чисел
class Primes {
private:
    void extend_prime_numbers();

protected:
    /// @brief Признак ограниченности
    bool is_limited;
    /// @brief Контейнер простых чисел
    std::vector<uint32_t> prime_numbers;
    /// @brief На сколлько расширять контейнер
    static const uint32_t extension_step = 1000000;

    /// @brief Добавляет новые простые числа
    /// @param max - максимальное новое простое число
    virtual void extend_prime_numbers(uint32_t max);

public:
    /// @brief Конструктор ограниченного контейнера
    /// @param max - максимальное простое число в контейнера
    Primes(uint32_t max);

    /// @brief Конструктор неограниченного контейнера
    Primes();

    /// @brief Конструктор копирование
    Primes(const Primes &container) = default;

    /// @brief Оператор присваивания
    Primes &operator=(const Primes &container) = default;

    /// @brief Итератор по контейнеру
    class Iterator;

    /// @brief Возвращает итератор, который указывает на первый элемент в контейнере
    Iterator begin();

    /// @brief Возвращает итератор, который указывает на элемент следующий за последним в контейнере
    Iterator end();

    /// @brief Возвращает текущий размер контейнера
    uint32_t size();

    /// @brief Доступ к простому числу с индексом index
    uint32_t operator[](uint32_t index);
};

class Primes::Iterator {
private:
    Primes *container;
    std::vector<uint32_t>::iterator iter;
public:
    /// @brief Конструкор
    /// @param container - контейнер, из которого получен итератор
    /// @param iter - начальное полоэение итератора
    Iterator(Primes *container, std::vector<uint32_t>::iterator iter);

    /// @brief Постинкремент
    Iterator &operator++();

    /// @brief Преинкремент
    Iterator operator++(int);

    /// @brief Оператор рызменования
    uint32_t &operator*() const;

    /// @brief Оператор равенства
    bool operator==(const Iterator &other) const;

    /// @brief Оператор неравенства
    bool operator!=(const Iterator &other) const;
};

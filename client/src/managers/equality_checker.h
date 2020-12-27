#ifndef LAST_SAVIORS_EQUALITY_CHECKER_H
#define LAST_SAVIORS_EQUALITY_CHECKER_H

/*
 * FunctorEventHandler поддерживает 4 вида обработчиков: функторы, lambda, std::function, функции
 * Объекты-функторы, lambda и std::function нужно сранивать по адресу
 * Функции будем сравнивать просто через operator==
 * Этот файл предоставляет единый интерфейс сравнения обработчиков-функторов
 * Использовал SFINAE.
*/

#include <type_traits>

template<typename T>
class IsEquatable {
private:

    template<typename U>
    static constexpr std::true_type exists(decltype(std::declval<U>() == std::declval<U>()) * = nullptr);

    template<typename U>
    static constexpr std::false_type exists(...);

public:

    static constexpr bool value = decltype(exists<T>(nullptr))::value;
};

template<typename TEqu, typename TEnabled = void>
struct EqualityChecker;

template<typename TEquatable>
struct EqualityChecker<TEquatable, typename std::enable_if<IsEquatable<TEquatable>::value>::type> {
    static constexpr bool equals(const TEquatable &lhs, const TEquatable &rhs) {
        return (lhs == rhs);
    }
};

template<typename TNonEquatable>
struct EqualityChecker<TNonEquatable, typename std::enable_if<!IsEquatable<TNonEquatable>::value>::type> {
    static constexpr bool equals(const TNonEquatable &lhs, const TNonEquatable &rhs) {
        return (&lhs == &rhs);
    }
};

#endif //LAST_SAVIORS_EQUALITY_CHECKER_H

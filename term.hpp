//
// Created by tima on 26.05.2019.
//

#ifndef AUTOCOMPLETE_TERM_HPP
#define AUTOCOMPLETE_TERM_HPP

#include <iostream>
#include <functional>

class term
{
public:
    term(std::string name, size_t weight);
    term(const term &term);

    std::string to_string() const;

    friend std::ostream &operator<<(std::ostream &os, const term &term);
    bool operator<(const term &rhs) const;
    bool operator>(const term &rhs) const;
    bool operator<=(const term &rhs) const;
    bool operator>=(const term &rhs) const;
    bool operator==(const term &rhs) const;
    bool operator!=(const term &rhs) const;
    term& operator=(const term &rhs);
    term& operator=(term &&rhs) noexcept;

    static std::function <bool(const term &first, const term &second)> by_reverse_weight_order();
    static std::function <bool(const term &first, const term &second)> by_prefix_order(size_t r);

    const std::string &getString() const;
    size_t getWeight() const;
private:
    std::string m_string;
    size_t m_weight;
};

#endif //AUTOCOMPLETE_TERM_HPP
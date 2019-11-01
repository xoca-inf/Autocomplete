//
// Created by tima on 26.05.2019.
//
#include "term.hpp"

term::term(std::string name, size_t weight) : m_string(std::move(name)),
                                              m_weight(weight) {}

bool term::operator==(const term &rhs) const {
    return m_string == rhs.m_string &&
           m_weight == rhs.m_weight;
}

bool term::operator!=(const term &rhs) const {
    return !(rhs == *this);
}

bool term::operator<(const term &rhs) const {
    if (getString() < rhs.getString())
        return true;
    if (rhs.getString() < getString())
        return false;
    return getWeight() < rhs.getWeight();
}

bool term::operator>(const term &rhs) const {
    return rhs < *this;
}

bool term::operator<=(const term &rhs) const {
    return !(rhs < *this);
}

bool term::operator>=(const term &rhs) const {
    return !(*this < rhs);
}

std::string term::to_string() const {
    std::string res;
    res += getString();
    res += " ";
    res += std::to_string(getWeight());
    return res;
}

std::ostream &operator<<(std::ostream &os, const term &term) {
    os << term.to_string();
    return os;
}

term::term(const term &term) : m_string(term.m_string), m_weight(term.m_weight) {}

term &term::operator=(const term &rhs) {
    if (*this != rhs) {
        m_weight = rhs.m_weight;
        m_string = rhs.m_string;
    }
    return *this;
}

term &term::operator=(term &&rhs) noexcept {
    m_string = std::move(rhs.m_string);
    m_weight = rhs.m_weight;
    return *this;
}

std::function<bool(const term &first, const term &second)> term::by_prefix_order(size_t r) {
    return [r](const term &first, const term &second) {
        size_t prefix_length = std::min(std::min(r, first.getString().length()), second.getString().length());
        return first.getString().substr(0, prefix_length) < second.getString().substr(0, prefix_length);
    };
}

std::function<bool(const term &lhs, const term &rhs)> term::by_reverse_weight_order() {
    return [](const term &lhs, const term &rhs) {
        return lhs.getWeight() > rhs.getWeight();
    };
}

const std::string &term::getString() const {
    return m_string;
}

size_t term::getWeight() const {
    return m_weight;
}

//
// Created by tima on 26.05.2019.
//

#ifndef AUTOCOMPLETE_AUTOCOMPLETE_HPP
#define AUTOCOMPLETE_AUTOCOMPLETE_HPP

#include "binary_search_deluxe.hpp"
#include <algorithm>

class autocomplete {
public:
    explicit autocomplete(std::vector<term> vector);
    std::vector<term> all_matches(const std::string &prefix) const;
    size_t number_of_matches(const std::string &prefix) const;
    const std::vector<term> &getVector() const;
private:
    std::vector<term> m_vector;
};

#endif //AUTOCOMPLETE_AUTOCOMPLETE_HPP

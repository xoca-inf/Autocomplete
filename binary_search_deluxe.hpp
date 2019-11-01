//
// Created by tima on 26.05.2019.
//

#ifndef AUTOCOMPLETE_BINARY_SEARCH_DELUXE_HPP
#define AUTOCOMPLETE_BINARY_SEARCH_DELUXE_HPP

#include <vector>
#include "term.hpp"

class binary_search_deluxe {
public:
    binary_search_deluxe() = delete;

    static int first_index_of(const std::vector<term> &array_of_terms, const term &key,
                              const std::function <bool(const term &first, const term &second)> &comparator);
    static int last_index_of(const std::vector<term> &array_of_terms, const term &key,
                             const std::function <bool(const term &first, const term &second)> &comparator);
};

#endif //AUTOCOMPLETE_BINARY_SEARCH_DELUXE_HPP
//
// Created by tima on 26.05.2019.
//

#include "binary_search_deluxe.hpp"

int binary_search_deluxe::first_index_of(const std::vector<term> &array_of_terms, const term &key,
                                         const std::function<bool(const term &first, const term &second)> &comparator) {
    int left = -1;
    int right = array_of_terms.size() - 1;
    while (right - left >  1) {
        int mid = (left + right) / 2;
        if (comparator(array_of_terms[mid], key)) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return right;
}

int binary_search_deluxe::last_index_of(const std::vector<term> &array_of_terms, const term &key,
                                        const std::function<bool(const term &first, const term &second)> &comparator) {
    int left = 0;
    int right = array_of_terms.size();
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (!comparator(key, array_of_terms[mid])) {
            left = mid;
        } else {
            right = mid;
        }
    }
    return left;
}


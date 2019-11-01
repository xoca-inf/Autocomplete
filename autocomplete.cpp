//
// Created by tima on 26.05.2019.
//

#include "autocomplete.hpp"

autocomplete::autocomplete(std::vector <term> vector) : m_vector(std::move(vector)) {
    std::sort(m_vector.begin(), m_vector.end());
}

std::vector<term> autocomplete::all_matches(const std::string &prefix) const {
    std::vector<term> result;
    int begin = binary_search_deluxe::first_index_of(m_vector, {prefix, 0}, term::by_prefix_order(prefix.length()));
    int end = binary_search_deluxe::last_index_of(m_vector, {prefix, 0}, term::by_prefix_order(prefix.length()));
    if (begin == -1 || end == -1) {
        return result;
    }
    for (int i = begin; i <= end; ++i) {
        result.emplace_back(m_vector[i]);
    }
    std::stable_sort(result.begin(), result.end(), term::by_reverse_weight_order());
    return result;
}

size_t autocomplete::number_of_matches(const std::string &prefix) const {
    unsigned begin = binary_search_deluxe::first_index_of(m_vector, {prefix, 0}, term::by_prefix_order(prefix.length()));
    unsigned end = binary_search_deluxe::last_index_of(m_vector, {prefix, 0}, term::by_prefix_order(prefix.length()));
    if (prefix != m_vector[begin].to_string().substr(0, prefix.length())) {
        return 0;
    }
    return end - begin + 1;
}

const std::vector<term> &autocomplete::getVector() const {
    return m_vector;
}

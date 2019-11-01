#include <iostream>
#include "autocomplete.hpp"

void test_term() {
    std::cout << "\t\tTESTING AUTOCOMPLETE HW\n\n";
    std::cout << "\t=======================================\n\n";
    std::cout << "\t\tTESTING TERM CLASS\n\n";
    term forTest("for test constructor", 12);
    std::cout << "====== Test 1: ======\nMake with param : {\"for test constructor\", 12} ::: " << forTest.getString() << ' ' << forTest.getWeight() << std::endl;
    term forTest2(forTest);
    std::cout << "====== Test 2: ======\nCopy constructor : copy of Test 1 ::: " << forTest2.getString() << ' ' << forTest2.getWeight() << std::endl;
    std::cout << "====== Test 3: ======\nTesting method to string ::: " << forTest.to_string() << std::endl;
    term tick("not like in test 1", 13);
    std::cout << "====== Test 4: ====== \nTesting assignment operator ::: Was: " << tick.getString() << ' ' << tick.getWeight() << std::endl;
    tick = forTest;
    std::cout << "Become: " << tick.getString() << ' ' << tick.getWeight() << std::endl;
    term forTest5("for test 5", 228);
    std::cout << "====== Test 5: ======\nTesting ostream operator ::: " << forTest5 << std::endl;
    term forTest61("aaa", 0);
    term forTest62("aab", 1);
    std::cout << "====== Test 6: ====== \nTesting operators <, >, <=, >=, ==, != ::: " << forTest61 << " ||||| " << forTest62 << std::endl;
    std::cout << "testing (<) ::: " << ((forTest61 < forTest62) ? "true" : "false") << "\n";
    std::cout << "testing (>) ::: " << ((forTest61 > forTest62) ? "true" : "false") << "\n";
    std::cout << "testing (<=) ::: " << ((forTest61 <= forTest62) ? "true" : "false") << "\n";
    std::cout << "testing (>=) ::: " << ((forTest61 >= forTest62) ? "true" : "false") << "\n";
    std::cout << "testing (==) ::: " << ((forTest61 == forTest62) ? "true" : "false") << "\n";
    std::cout << "testing (!=) ::: " << ((forTest61 != forTest62) ? "true" : "false") << "\n";
}

void test_binary_search_deluxe() {
    std::cout << "\n\n\t=======================================\n\n";
    std::cout << "\t\tTESTING BINARY SEARCH DELUXE CLASS\n\n";
    std::vector<term> dic {
            {"also", 1},
            {"KZzz", 2},
            {"KZahstan", 3},
            {"KZmaza", 4},
            {"KZlol", 5},
            {"adidas", 6},
            {"nikeeeee", 8}
    };
    std::cout << "TEST DICTIONARY:\n";
    unsigned i = 0;
    for (const auto& item : dic) {
        std::cout << i << ") " << item.to_string() << '\n';
        i++;
    }
    unsigned first, last;
    std::cout << "====== Test 1: ====== \nTesting first_index_of method with \"KZ\" prefix::: \n first is --> " << binary_search_deluxe::first_index_of(dic, {"KZ", 0}, term::by_prefix_order(2)) << std::endl;
    std::cout << "====== Test 2: ====== \nTesting last_index_of method with \"KZ\" prefix::: \n last is --> " << binary_search_deluxe::last_index_of(dic, {"KZ", 0}, term::by_prefix_order(2)) << std::endl;
    std::cout << "====== Test 3: ====== \nTesting first_index_of method with \"nike\" prefix::: \n first is --> " << binary_search_deluxe::first_index_of(dic, {"nike", 0}, term::by_prefix_order(4)) << std::endl;
    std::cout << "====== Test 4: ====== \nTesting last_index_of method with \"nike\" prefix::: \n last is --> " << binary_search_deluxe::last_index_of(dic, {"nike", 0}, term::by_prefix_order(4)) << std::endl;
    std::cout << "====== Test 5: ====== \nTesting first_index_of method with \"not exist\" prefix::: \n first is --> " << binary_search_deluxe::first_index_of(dic, {"not exist", 0}, term::by_prefix_order(9)) << std::endl;
    std::cout << "====== Test 6: ====== \nTesting last_index_of method with \"not exist\" prefix::: \n last is --> " << binary_search_deluxe::last_index_of(dic, {"not exist", 0}, term::by_prefix_order(9)) << std::endl;
}

void test_autocomplete() {
    std::cout << "\n\n\t=======================================\n\n";
    std::cout << "\t\tTESTING AUTOCOMPLETE CLASS\n\n";
    std::vector<term> dic {
            {"also", 1},
            {"KZzz", 2},
            {"KZahstan", 3},
            {"KZmaza", 4},
            {"KZlol", 5},
            {"adidas", 6},
            {"nikel", 7},
            {"nikeeeee", 8}
    };
    std::cout << "TEST DICTIONARY:\n";
    unsigned i = 0;
    for (const auto& item : dic) {
        std::cout << i << ") " << item.to_string() << '\n';
        i++;
    }
    autocomplete dir(dic);
    std::vector<term> res = dir.all_matches("KZ");
    std::cout << "====== Test 1: ====== \nTesting all_matches method with \"KZ\" prefix:::\n";
    for (const auto& item : res) {
        std::cout << item.to_string() << "\n";
    }
    std::cout << "====== Test 2: ====== \nTesting number_of_matches method with \"KZ\" prefix:::\n";
    unsigned result = dir.number_of_matches("KZ");
    std::cout << "number of matches --> " << result << "\n";
    std::vector<term> rest = dir.all_matches("nike");
    std::cout << "====== Test 3: ====== \nTesting all_matches method with \"nike\" prefix:::\n";
    for (const auto& item : rest) {
        std::cout << item.to_string() << "\n";
    }
    std::cout << "====== Test 4: ====== \nTesting number_of_matches method with \"nike\" prefix:::\n";
    unsigned resul = dir.number_of_matches("nike");
    std::cout << "number of matches --> " << resul << "\n";
    std::vector<term> kek = dir.all_matches("long & not exist");
    std::cout << "====== Test 5: ====== \nTesting all_matches method with \"long & not exist\" prefix:::\n";
    for (const auto& item : kek) {
        std::cout << item.to_string() << "\n";
    }
    if (kek.empty()) {
        std::cout << "is empty\n";
    }
    std::cout << "====== Test 6: ====== \nTesting number_of_matches method with \"long & not exist\" prefix:::\n";
    unsigned resultt = dir.number_of_matches("long & not exist");
    std::cout << "number of matches --> " << resultt << "\n";
}


int main() {
    test_term();
    test_binary_search_deluxe();
    test_autocomplete();
    return 0;
}
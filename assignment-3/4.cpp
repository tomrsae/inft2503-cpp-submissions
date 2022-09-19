#include <iostream>

int main() {
    // a)
    std::string word1, word2, word3;

    std::cout << "a)\nEnter 3 words: \n";

    std::cout << "Word 1: ";
    std::cin >> word1;

    std::cout << "Word 2: ";
    std::cin >> word2;
    
    std::cout << "Word 3: ";
    std::cin >> word3;
    std::cout << std::endl;

    // b)
    std::string sentence = word1 + " " + word2 + " " + word3;
    std::cout << "b)\nYour words form the sentence: " << sentence << std::endl;
    std::cout << std::endl;

    // c)
    std::cout << "c)\nLength of word 1: " << word1.size() << std::endl;
    std::cout << "Length of word 2: " << word2.size() << std::endl;
    std::cout << "Length of word 3: " << word3.size() << std::endl;
    std::cout << "Length of sentence: " << sentence.size() << std::endl;
    std::cout << std::endl;

    // d)
    std::string sentence2 = sentence;

    // e)
    try {
        sentence2.replace(9, 3, "xxx");
        std::cout << "e)\nsentence: " << sentence << std::endl;
        std::cout << "sentence2: " << sentence2 << std::endl;;

    } catch (const std::out_of_range& e) {
        std::cout << "Failed to run assignment e) as the sentence was not long enough!\n";
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    // f)
    try {
        std::string sentence_start = sentence.substr(0, 5);
        std::cout << "f)\nsentence: " << sentence << std::endl;
        std::cout << "First five letters of sentence: " << sentence_start << std::endl;;
    } catch (const std::out_of_range& e) {
        std::cout << "Failed to run assignment f) as the sentence was not long enough!\n";
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    // g)
    std::string str_to_find = "hello";
    size_t found_index = sentence.find(str_to_find);
    std::cout << "g)\n";
    if (found_index != std::string::npos) {
        std::cout << "The string '" << str_to_find << "' was found at index " << found_index << std::endl;
    } else {
        std::cout << "Failed to find the string '" << str_to_find << "' in the sentence '" << sentence << "'\n";
    }
    std::cout << std::endl;

    // h)
    str_to_find = "er";
    found_index = 0;
    int occurances = 0;
    while ((found_index = sentence.find(str_to_find, found_index))++ != std::string::npos) {
        occurances++;
    }

    std::cout << "h)\nThe string '" << str_to_find << "' occurs " << occurances << " times(s) in the sentence '" << sentence << "'\n";
}
// Section 19
// Challenge 3
// Word counter

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
    int total_words     {0}; 
    int word_occurrence {0};

    std::string search_word {}; 
    std::cout << "Enter the word you would like to count: "; 
    std::cin >> search_word; 

    std::ifstream in_file; 
    in_file.open("romeoandjuliet.txt"); 

    std::string word {}; 

    if (in_file)
    {
        while (in_file >> word)
        {
            // Sanitize input
            word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), 
                       word.end()); 
            
            if (word.find(search_word) != std::string::npos)
            {
                ++word_occurrence; 
            }

            ++total_words; 
        }
    }
    else 
    {
        std::cerr << "Error opening file" << std::endl; 
    }

    in_file.close();

    std::cout << "The word \"" << search_word << "\" occurs " 
              << word_occurrence << " out of " << total_words
              << " words." << std::endl; 

    return 0;
}


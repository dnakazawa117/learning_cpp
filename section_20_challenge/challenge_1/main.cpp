// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    // Sanitize the input - remove non-alpha characters
    std::deque<int> str_characters {}; 

    for (auto c : s)
    {
        if (std::isalpha(c))
        {
            str_characters.push_back(std::tolower(c)); 
        }
    }

    // Check for palindrome
    size_t p_front {0}; 
    size_t p_back  {str_characters.size() - 1}; 

    while (p_front < p_back)
    {
        if (str_characters.at(p_front) != str_characters.at(p_back))
        {
            return false; 
        } 

        ++p_front; 
        --p_back; 
    }

    return true;
}

int main()
{

    std::vector<std::string> test_strings 
    { 
        "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", 
        "ana", "avid diva", "Amore, Roma", "A Toyota's a toyota", 
        "A Santa at NASA", "C++", 
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", 
        "This is a palindrome", "palindrome" 
    };

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << 
        "Result" << "String" << std::endl;

    for(const auto& s : test_strings) 
    {
        std::cout << std::setw(8) << std::left << 
            is_palindrome(s) << " " << s << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
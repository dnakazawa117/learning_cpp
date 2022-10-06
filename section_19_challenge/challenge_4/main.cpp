// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers

#include <fstream>
#include <iomanip>
#include <iostream>

int main() {
    std::ifstream in_file{"romeoandjuliet"}; 
    std::ofstream out_file{"romeoandjuliet_copy"}; 

    if (!in_file || !out_file)
    {
        std::cerr << "File open/create error" << std::endl; 
        return 1; 
    }

    std::string line {}; 
    int line_number {1}; 

    while (std::getline(in_file, line))
    {
        out_file << std::setw(10) << std::left << line_number 
                 << line << std::endl; 
        ++line_number; 
    }

    in_file.close(); 
    out_file.close();

    std::cout << "File copying complete" << std::endl; 
    
    return 0;
}

/*** end of file ***/
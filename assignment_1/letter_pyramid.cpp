#include <iostream>
#include <string>

using namespace std; 

static void add_spaces(int num_spaces); 
static void generate_letter_pyramid(string str); 

int main() 
{
    string user_input {}; 
    cout << "Please enter a string: "; 
    cin >> user_input; 

    generate_letter_pyramid(user_input); 

    return 0; 
}

static void add_spaces(int num_spaces)
{
    for (int i {0}; i < num_spaces; ++i)
    {
        cout << " "; 
    }
}

static void generate_letter_pyramid(string str)
{
    int num_spaces    {0};
    for (int i {0}, ending_idx {0}; 
        (i < str.length()) && (ending_idx < str.length()); 
        ++i, ++ending_idx)
    {
        num_spaces = str.length() - (i + 1);
        add_spaces(num_spaces); 

        for (int j {0}; j < ending_idx; ++j)
        {
            cout << str.at(j); 
        }

        for (int k {ending_idx}; k > -1; --k)
        {
            cout << str.at(k); 
        }
        
        add_spaces(num_spaces); 
        cout << endl;
    }
}
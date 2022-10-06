#include <iostream>
#include <vector>

using namespace std; 

static void display_menu(void); 
static void execute_user_input(char user_input, vector<int> &numbers); 
static void print_all_numbers(const vector<int> &numbers); 
static void add_a_number(vector<int> &numbers); 
static void display_mean(const vector<int> &numbers); 
static void display_min(const vector<int> &numbers); 
static void display_max(const vector<int> &numbers); 

int main() 
{
    char user_input; 
    vector<int> numbers; 

    do
    {
        display_menu(); 
        cin >> user_input; 
        execute_user_input(user_input, numbers); 
    } while (toupper(user_input) != 'Q');
    
    return 0;
}

static void display_menu(void)
{
    cout << "P - Print numbers" << endl; 
    cout << "A - Add a number" << endl; 
    cout << "M - Display mean of the numbers" << endl; 
    cout << "S - Display the smallest number" << endl; 
    cout << "L - Display the largest number" << endl; 
    cout << "Q - Quit" << endl; 
    cout << endl; 
    cout << "Enter your choice: ";

    return; 
}

static void execute_user_input(char user_input, vector<int> &numbers)
{
    switch (toupper(user_input))
    {
        case 'P':
            print_all_numbers(numbers);              
            break; 
        case 'A':
            add_a_number(numbers); 
            break; 
        case 'M':
            display_mean(numbers);  
            break;
        case 'S':
            display_min(numbers); 
            break; 
        case 'L':
            display_max(numbers);  
            break; 
        case 'Q':
            cout << "Goodbye!" << endl; 
            break; 
        default: 
            cout << "Invalid input. Please try again." << endl; 
            break; 
    }

    cout << endl; 

    return; 
}

static void print_all_numbers(const vector<int> &numbers)
{
    if (numbers.empty())
    {
        cout << "[] - the list is empty." << endl; 
        return; 
    }

    cout << "[ "; 
    for (int number : numbers)
    {
        cout << number << " "; 
    }
    cout << "]" << endl;

    return; 
}

static void add_a_number(vector<int> &numbers)
{
    cout << "Enter an integer to add to the list: "; 
    int integer_input; 
    cin >> integer_input; 
    numbers.push_back(integer_input); 

    cout << endl; 
    cout << "Added " << integer_input << " to the list." << endl;  

    return; 
}

static void display_mean(const vector<int> &numbers)
{
    if (numbers.empty())
    {
        cout << "[] - the list is empty." << endl; 
        return; 
    }

    int sum {0}; 
    for (int number : numbers) 
    {
        sum += number; 
    }

    double average = static_cast<double> (sum) / numbers.size(); 
    cout << "The mean is " << average << "." << endl; 

    return; 
}

static void display_min(const vector<int> &numbers)
{
    if (numbers.empty())
    {
        cout << "[] - the list is empty." << endl; 
        return; 
    }

    cout << "The smallest value is "                                           \
         << *min_element(numbers.begin(), numbers.end())                       \
         << "." << endl; 

    return; 
}

static void display_max(const vector<int> &numbers)
{
    if (numbers.empty())
    {
        cout << "[] - the list is empty." << endl; 
        return; 
    }

    cout << "The largest value is "                                            \
         << *max_element(numbers.begin(), numbers.end())                       \
         << "." << endl; 

    return; 
}

/*** end of file ***/
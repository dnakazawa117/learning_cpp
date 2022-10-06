// Section 19
// Challenge 2
// Automated Grader

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>


static std::string tokenize_gradebook(std::vector<std::string> &names, 
                                      std::vector<std::string> &answers); 
static int         grade_answer(const std::string &answer_key, 
                                const std::string &answer); 
static void        grade_student_answers(const std::vector<std::string> &answers, 
                                         const std::string              &answer_key,
                                         std::vector<int>               &grades);
static double      calculate_class_avg(const std::vector<int> &grades, 
                                  const int              &num_qs); 
static void        display_grades(const std::vector<std::string> &names, 
                             const std::vector<int>         &grades, 
                             const double                   class_avg);

static inline bool is_even(size_t x); 
static inline bool is_odd(size_t x); 

int main() {
    // Retrive names, answers, and answer key
    std::vector<std::string> names   {}; 
    std::vector<std::string> answers {};
    const std::string answer_key = tokenize_gradebook(names, answers); 

    // Grade student responses
    std::vector<int> grades {}; 
    grade_student_answers(answers, answer_key, grades);

    // Calculate and display results
    double class_avg = calculate_class_avg(grades, answer_key.size()); 
    display_grades(names, grades, class_avg); 
    
    return 0;
}

static std::string tokenize_gradebook(std::vector<std::string> &names, 
                                      std::vector<std::string> &answers)
{
    std::ifstream in_file; 
    std::string   line {}; 
    in_file.open("responses.txt"); 

    size_t current_idx {0}; 
    std::string answer_key {}; 

    if (in_file.is_open())
    {
        while (std::getline(in_file, line))
        {
            // Sanitize input
            line.erase(std::remove_if(line.begin(), line.end(), ::isspace), 
                       line.end());
            
            if (0 == current_idx)
            {
                answer_key = line;  
            }
            else if (is_odd(current_idx))
            {
                names.push_back(line); 
            }
            else if (is_even(current_idx))
            {
                answers.push_back(line);
            }
            else 
            {
                std::cerr << "Something went wrong" << std::endl; 
            }

            ++current_idx;
        }
    }
    else 
    {
        std::cerr << "Error opening file" << std::endl; 
    }

    in_file.close(); 

    return answer_key; 
}

static int grade_answer(const std::string &answer_key, 
                        const std::string &answer)
{
    int grade {0}; 

    for (size_t i = 0; i < answer_key.size(); ++i)
    {
        if (answer.at(i) == answer_key.at(i))
        {
            ++grade; 
        }
    }

    return grade; 
}

static void grade_student_answers(const std::vector<std::string> &answers, 
                                  const std::string              &answer_key,  
                                  std::vector<int>               &grades)
{
    for (auto answer : answers) 
    {
        grades.push_back(grade_answer(answer_key, answer)); 
    }
}

static double calculate_class_avg(const std::vector<int> &grades, 
                                  const int              &num_qs)
{
    int grade_sum {0};
    for (auto grade : grades)
    {
        grade_sum += grade; 
    }

    return static_cast<double>(grade_sum) / num_qs;
}

static void display_grades(const std::vector<std::string> &names, 
                           const std::vector<int>         &grades, 
                           const double                   class_avg)
{
    if (names.size() != grades.size())
    {
        std::cerr << "Detected error in gradebook" << std::endl; 
    }

    std::cout << std::endl; 

    // Display header
    std::cout << std::setw(20) << std::left  << "Student Name"
              << std::setw(20) << std::right << "Grade"
              << std::endl; 

    std::cout << std::setw(40) << std::setfill('-') << "" << std::endl; 
    std::cout << std::setfill(' '); 

    // Display names and grades
    for (size_t i = 0; i < names.size(); ++i)
    {
        std::cout << std::setw(20) << std::left  << names.at(i)
                  << std::setw(20) << std::right << grades.at(i)
                  << std::endl; 
    }

    std::cout << std::setw(40) << std::setfill('-') << "" << std::endl; 
    std::cout << std::setfill(' '); 

    // Display class average
    std::cout << std::setw(20) << std::left  << "Class Average"
              << std::setw(20) << std::right << class_avg 
              << std::endl << std::endl;  
}

static inline bool is_even(size_t x)
{
    return ((0 == (x % 2)) ? true : false);
}

static inline bool is_odd(size_t x)
{
    return ((1 == (x % 2)) ? true : false);
}

/*** end of file ***/
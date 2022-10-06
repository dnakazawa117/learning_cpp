// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

static void print_centered(const std::string str); 
static void print_header(void);
static void border(void);

int main()
{
    Tours tours
        { "Tour Ticket Prices from Miami",
            {
                {
                    "Colombia", { 
                        { "Bogota", 8778000, 400.98 },
                        { "Cali", 2401000, 424.12 },
                        { "Medellin", 2464000, 350.98 },
                        { "Cartagena", 972000, 345.34 } 
                    },
                },
                {
                    "Brazil", { 
                        { "Rio De Janiero", 13500000, 567.45 },
                        { "Sao Paulo", 11310000, 975.45 },
                        { "Salvador", 18234000, 855.99 }
                    },
                },
                {
                    "Chile", { 
                        { "Valdivia", 260000, 569.12 }, 
                        { "Santiago", 7040000, 520.00 }
                },
            },
                { "Argentina", { 
                    { "Buenos Aires", 3010000, 723.77 } 
                } 
            },
        }
    };

    std::cout << std::endl;

    print_centered(tours.title);
    std::cout << std::endl; 
    print_header(); 
    for(auto country : tours.countries) {   // loop through the countries
        border();
        print_centered(country.name);
        border();
        for(auto city : country.cities) {       // loop through the cities for each country
            std::cout << std::setw(20) << std::left << city.name; 
            std::cout << std::resetiosflags(std::ios::left); 

            size_t population_digits = 
                std::to_string(city.population).length();
            std::cout << std::setw(20 + (population_digits / 2)) << city.population
                      << std::setw(80 - (40 + (population_digits / 2))) << city.cost 
                      << std::endl;
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}

static void print_centered(const std::string str)
{
    std::cout << std::setw(40 + ((str.length()) / 2))  
              << str << std::endl;
}

static void print_header(void)
{
    std::cout << std::setw(20) << std::left << "City"; 
    std::cout << std::resetiosflags(std::ios::left); 
    std::cout << std::setw(25) << "Population" 
              << std::setw(35) << "Price"
              << std::endl; 
}

static void border(void)
{
    std::cout << std::setfill('-'); 
    std::cout << std::setw(80) << "" << std::endl;  
    std::cout << std::setfill(' ');
}
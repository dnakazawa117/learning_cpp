#include <iostream>
#include <string>
#include <vector>

#include "Movies.h"

// Constructor 
Movies::Movies(void)
{
    ; 
}

// Destructor
Movies::~Movies(void)
{
    ;
}

// Method Prototypes
void Movies::display_movies(void) const
{
    if (movies.empty())
    {
        std::cout << "Sorry! No movies here to display." << std::endl; 
    }
    else 
    {
        for (const Movie &movie : movies)
        {
            movie.display_movie(); 
        }
    }
}

void Movies::add_movie(std::string name, std::string rating, int times_watched)
{
    for (const Movie &movie : movies)
    {
        if (movie.get_name() == name)
        {
            std::cout << 
                "You can't add this movie b/c it already exists." << std::endl;
            return; 
        }
    }

    Movie new_movie (name, rating, times_watched); 
    movies.push_back(new_movie); 
}

void Movies::increment_times_watched(std::string movie_name)
{
    for (Movie &movie : movies)
    {
        if (movie.get_name() == movie_name)
        {
            movie.increment_times_watched(); 
            return; 
        }
    }
    
    std::cout << "You can't increment the number of times you've watched a " \
        "movie if it's not in the list!" << std::endl; 
}

/*** end of file ***/
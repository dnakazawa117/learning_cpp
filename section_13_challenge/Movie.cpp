#include <iostream>
#include "Movie.h"

// Constructor
Movie::Movie(std::string name, std::string rating, int times_watched)
    : name (name), rating (rating), times_watched (times_watched)
{
    ;
}

// Copy Constructor
Movie::Movie(const Movie &source)
    : Movie{source.name, source.rating, source.times_watched}
{
    ;
}

// Destructor 
Movie::~Movie(void)
{
    ;
}

// Method Definition
void Movie::display_movie(void) const
{
    std::cout << name << ", " << rating << ", " << times_watched << std::endl; 
}

/*** end of file ***/
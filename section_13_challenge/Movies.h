#ifndef _MOVIES_H_
#define _MOVIES_H_

#include <string>
#include <vector>

#include "Movie.h"

class Movies 
{
private:
    std::vector <Movie> movies; 
public:
    // Constructor 
    Movies(void); 

    // Destructor
    ~Movies(void);

    // Method Prototypes
    void display_movies(void) const; 
    void add_movie(std::string name, std::string rating, int times_watched); 
    void increment_times_watched(std::string movie_name); 
};

#endif /* _MOVIES_H_ */

/*** end of file ***/
#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

class Movie 
{
private:
    std::string name; 
    std::string rating; 
    int times_watched; 
public:
    // Constructor
    Movie(std::string name, std::string rating, int times_watched); 

    // Copy Constructor
    Movie(const Movie &source);

    // Destructor 
    ~Movie(void); 

    // Method Prototypes
    std::string get_name(void) const; 
    void        set_name(std::string name); 
    
    std::string get_rating(void) const; 
    void        set_rating(std::string rating);

    int  get_times_watched(void) const; 
    void increment_times_watched(void); 

    void display_movie(void) const; 
};

// Method Definitions
inline std::string Movie::get_name(void) const
{
    return name; 
}

inline void Movie::set_name(std::string name)
{
    this->name = name; 
}

inline std::string Movie::get_rating(void) const
{
    return rating; 
}

inline void Movie::set_rating(std::string rating)
{
    this->rating = rating; 
}

inline int  Movie::get_times_watched(void) const
{
    return times_watched; 
}

inline void Movie::increment_times_watched(void)
{
    ++times_watched; 
}

#endif /* _MOVIE_H */

/*** end of file ***/
// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    std::cout << "Playing: " << std::endl; 
    std::cout << song << std::endl;
}

void play_first_song(std::list<Song> &playlist, 
                     std::list<Song>::iterator &current_song)
{ 
    if (current_song != playlist.begin())
    {
        current_song = playlist.begin(); 
    }

    play_current_song(*current_song);
}

void play_next_song(std::list<Song> &playlist, 
                    std::list<Song>::iterator &current_song)
{
    auto end_song_it = playlist.end(); 
    --end_song_it;

    if (current_song == end_song_it)
    {
        current_song = playlist.begin(); 
    } 
    else
    {
        ++current_song; 
    }

    play_current_song(*current_song); 
}

void play_previous_song(std::list<Song> &playlist, 
                        std::list<Song>::iterator &current_song)
{
    if (current_song == playlist.begin())
    {
        current_song = playlist.end(); 
    }

    --current_song; 
    play_current_song(*current_song); 
}

void add_new_song_and_play(std::list<Song> &playlist, 
                           std::list<Song>::iterator &current_song)
{
    std::string name   {}; 
    std::string artist {}; 
    int         rating {0}; 

    std::cout << "Enter song name: "; 
    std::cin.ignore(); 
    std::getline(std::cin, name); 

    std::cout << "Enter artist name: "; 
    std::getline(std::cin, artist); 

    std::cout << "Enter song rating: ";
    std::cin  >> rating;  
    std::cout << std::endl; 

    Song new_song(name, artist, rating); 
    playlist.insert(current_song, new_song); 
    --current_song; 
    play_current_song(*current_song); 
}

void display_playlist(const std::list<Song> &playlist, 
                      const Song &current_song)
{
    std::cout << "Playlist: " << std::endl; 
    
    for (auto song : playlist)
    {
        std::cout << song << std::endl; 
    }

    std::cout << std::endl; 

    std::cout << "Currently Playing: " << std::endl; 
    std::cout << current_song << std::endl; 
}

void process_input(const char &input, 
                   std::list<Song> &playlist, 
                   std::list<Song>::iterator &current_song)
{
    switch (input)
    {
        case 'f':
        case 'F':
            play_first_song(playlist, current_song); 
            break; 
        case 'n':
        case 'N':
            play_next_song(playlist, current_song);  
            break; 
        case 'p':
        case 'P':
            play_previous_song(playlist, current_song); 
            break; 
        case 'a':
        case 'A':
            add_new_song_and_play(playlist, current_song); 
            break;
        case 'l':
        case 'L':
            display_playlist(playlist, *current_song); 
            break; 
        default:
            std::cerr << "Invalid input. Please try again." << std::endl; 
            break; 
    }
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weeknd and K. Lamar",   4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    char input {0};

    while (1) 
    {
        display_menu();
        std::cin >> input; 
        std::cout << std::endl; 

        if ((input == 'q') || (input == 'Q'))
            break;

        process_input(input, playlist, current_song); 
    }

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}
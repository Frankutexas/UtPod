//
// Created by chaoster on 10/19/2018.
//
#include <cstdlib>
#include <string>
#include <cstdbool>
#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H
using namespace std;
class Song{
    private:
        string title;
        string artist;
        int size;
        static const int MAX_MEMORY = 512;
    public:
        string getTitle() const{
            return title;
        };
        string getArtist() const{
            return artist;
        };
        int getSize()const{
            return size;
        };
        void setTitle(string s){
            string title(s);
        };
        void setArtist(string s){
            string artist(s);
        };
        void setSize(int s);
        Song(string title, string artist);
        Song(string title, string artist, int size);
        ~Song();
        bool operator >(Song const &rhs);
        bool operator ==(Song const &rhs);
};
Song::Song(string title, string artist){
    setTitle(title);
    setArtist(artist);
    setSize(MAX_MEMORY);
}
Song::Song(string title, string artist, int size){
    setTitle(title);
    setArtist(artist);
    setSize(size);
    if(size > 512 || size < 0)
        setSize(MAX_MEMORY);
}
Song::~Song(){
}
bool Song::operator>(Song const &rhs){
    if(this->artist != rhs.artist)
        return (this->artist > rhs.artist); //if artist is different return which artist is greater
    if(this->title != rhs.title)
        return (this->title > rhs.title); //if artist is the same but title is different, return which title is greater
    return (this->size > rhs.size); // if same artist return which size is greater
}
bool Song::operator==(Song const &rhs){
    if(this->artist == rhs.artist && this->size == rhs.size)
        return (this->title == rhs.title);
    else
        return false;
}

#endif
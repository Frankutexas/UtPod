//
// Created by chaoster on 10/19/2018.
//

#ifndef UTPOD_H
#define UTPOD_H
#include <cstdlib>
#include <string>
#include <iostream>
#include "Song.h"

using namespace std;
//UtPod class declaration
class UtPod
{
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    struct SongNode
    {
        Song s;
        SongNode *next;
    };

    SongNode *songs;  //the head pointer
    int memSize;

public:
    UtPod();
    UtPod(int size);
    int addSong(Song const &s);
    int removeSong(Song const &s);
    void shuffle();
    void showSongList();
    void sortSongList();
    int getTotalMemory() {
        return memSize;
    }

    int getRemainingMemory();

    ~UtPod();

};
UtPod::UtPod(int size){
    songs = NULL;
    memSize= size;
}
int UtPod::addSong(Song const &s) {
    SongNode *temp;
    temp = songs;
    while(temp != NULL){
        temp = temp->next;
    }
    if(songs == NULL){ //if UtPod is empty song goes in first node
        songs->s = s;
        songs->next = NULL;
    }
    else {
        temp->s = s;
        temp->next = songs->next;
        songs->next = temp;
    }
}
int UtPod::removeSong(Song const &s) {
    SongNode *temp = songs;
    SongNode *trail;
    while(temp != NULL){
        if(temp->s == s){
            temp->next = temp->next->next;
            free(trail);
        }
        trail = temp;
        temp = temp->next;
    }
}
void UtPod::showSongList() {
    SongNode *temp = songs;
    while(temp != NULL){
        cout << temp->s.getTitle() << endl;
        cout << temp->s.getArtist() << endl;
        cout << temp->s.getSize() << endl;
    }
}
#endif
#include <iostream>
#include <string>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

using namespace std;

class Song {
public:
    Song(const string& title, const string& file_path)
        : title(title), file_path(file_path), next(nullptr), prev(nullptr) {}

    string getTitle() const { return title; }
    string getFilePath() const { return file_path; }

    Song* getNext() const { return next; }
    Song* getPrev() const { return prev; }

    void setNext(Song* song) { next = song; }
    void setPrev(Song* song) { prev = song; }

private:
    string title;
    string file_path;
    Song* next;
    Song* prev;
};

class MusicPlayer {
public:
    MusicPlayer() : head(nullptr), currentSong(nullptr) {}

    // Function to add a song to the playlist
    void addSong(const string& title, const string& file_path) {
        Song* newSong = new Song(title, file_path);

        if (!head) {
            head = newSong;
            currentSong = head;
        } else {
            Song* current = head;
            while (current->getNext()) {
                current = current->getNext();
            }
            current->setNext(newSong);
            newSong->setPrev(current);
        }
    }

    // Function to play the current song
    void play() {
        if (currentSong) {
            string playCommand = "open \"" + currentSong->getFilePath() + "\" type mpegvideo alias mp3";
            PlaySound(TEXT("tuhaikahaan.wav"),NULL, SND_FILENAME | SND_SYNC);

            playCommand = "play mp3";
            mciSendStringA(playCommand.c_str(), nullptr, 0, nullptr);

            cout << "Playing: " << currentSong->getTitle() << endl;
        }
    }

    // Function to pause the current song
    void pause() {
        string pauseCommand = "pause mp3";
        mciSendStringA(pauseCommand.c_str(), nullptr, 0, nullptr);
        cout << "Pausing: " << currentSong->getTitle() << endl;
    }

    // Function to go to the next song
    void next() {
        string stopCommand = "stop mp3";
        mciSendStringA(stopCommand.c_str(), nullptr, 0, nullptr);

        if (currentSong && currentSong->getNext()) {
            currentSong = currentSong->getNext();
            play();
        } else {
            cout << "End of the playlist." << endl;
        }
    }

    // Function to go to the previous song
    void previous() {
        string stopCommand = "stop mp3";
        mciSendStringA(stopCommand.c_str(), nullptr, 0, nullptr);

        if (currentSong && currentSong->getPrev()) {
            currentSong = currentSong->getPrev();
            play();
        } else {
            cout << "Beginning of the playlist." << endl;
        }
    }

private:
    Song* head;
    Song* currentSong;
};

int main() {
    MusicPlayer player;

    //Adding songs to the playlist
    player.addSong("Tu Hai Kahaan", "tuhaikahaan.wav");

//    Control the music player
    cout << "Playing: " << endl;
    PlaySound(TEXT("tuhaikahaan.wav"), NULL, SND_FILENAME | SND_SYNC);
    cout << "Stop." << endl;
    player.next();
    player.previous();
    player.pause();

    return 0;
}
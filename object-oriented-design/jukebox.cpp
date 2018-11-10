/**
 * Design a jukebox using object oriented principles
 */

#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

class JukeBox;
class Song;
class CD;
class CDPlayer;
class Album;
class Artist;
class PlayList;

class Artist
{
    private:
        /**
         * Name of the artist
         * @param string name
         */
        string name;

    public:
        Artist() {}

        Artist(string name)
        {
            this->name = name;
        }

        /**
         * Returns name of the artist
         * @return string
         */
        string getName()
        {
            return this->name;
        }
};

class Album
{
    private:
        /**
         * Name of the album
         * @param string name
         */
        string name;

    public:
        Album() {}

        Album(string name)
        {
            this->name = name;
        }

        /**
         * Returns name of the album
         * @return string
         */
        string getName()
        {
            return this->name;
        }
};

class Song
{
    private:
        /**
         * Artist of the song
         * @param Artist artist
         */
        Artist artist;

        /**
         * Album of the song
         * @param Album album
         */
        Album album;

        /**
         * Name of the song
         * @param string name
         */
        string name;

        /**
         * Duration of the song in seconds
         * @param int duration
         */
        int duration;

        /**
         * Returns the artist of the song
         * @return Artist
         */
        Artist getArtist()
        {
            return this->artist;
        }

        /**
         * Returns the album of the song
         * @return Album
         */
        Album getAlbum()
        {
            return this->album;
        }

        /**
         * Returns the name of the song
         * @return string
         */
        string getName()
        {
            return this->name;
        }

    public:
        Song(Artist& artist, Album& album, string name, int duration)
        {
            this->artist = artist;

            this->album = album;

            this->name = name;

            this->duration = duration;
        }

        /**
         * Returns the duration of the song in seconds
         * @return int
         */
        int getDuration()
        {
            return this->duration;
        }

        /**
         * Prints the song in a human readable way
         * @return void
         */
        void print()
        {
            printf("The name of the song is : %s.\nThe song is by the artist : %s.\nThe song is in the album : %s.\nThe song lasts for %d seconds.\n",
                    this->getName().c_str(),
                    this->getArtist().getName().c_str(),
                    this->getAlbum().getName().c_str(),
                    this->getDuration());
        }
};

/**
 * Disk of songs
 */
class CD
{
    private:
        /**
         * Artist of the CD
         * @param Artist artist
         */
        Artist artist;

        /**
         * Album name of the CD
         * @param Album album
         */
        Album album;

        /**
         * Duration of all songs in seconds
         * @param int duration
         */
        int duration;

        /**
         * vector containing list of songs in the CD
         * @param vector<Song> songs
         */
        vector<Song> songs;

        /**
         * Returns the artist of the CD
         * @return Artist
         */
        Artist getArtist()
        {
            return this->artist;
        }

        /**
         * Returns the album of the CD
         * @return Album
         */
        Album getAlbum()
        {
            return this->album;
        }

        /**
         * Returns the duration of the CD in seconds
         * @return int
         */
        int getDuration()
        {
            return this->duration;
        }

        /**
         * Computes the duration of the CD
         * @return void
         */
        void computeDuration()
        {
            this->duration = 0;

            for (Song s : songs)
            {
                this->duration += s.getDuration();
            }
        }

    public:
        CD(Artist& artist, Album& album, vector<Song>& songs)
        {
            this->artist = artist;

            this->album = album;

            this->songs = songs;

            this->computeDuration();
        }

        /**
         * Returns all the songs in the CD
         * @return vector<Song>
         */
        vector<Song> getSongs()
        {
            return this->songs;
        }

        /**
         * Returns the number of songs in the CD
         * @return int
         */
        int numSongs()
        {
            return this->getSongs().size();
        }

        /**
         * Prints the CD in a human readable way
         * @return void
         */
        void print()
        {
            printf("The CD is by the artist : %s.\nThe CD has the album title : %s.\nThe CD lasts for %d seconds.\n",
                    this->getArtist().getName().c_str(),
                    this->getAlbum().getName().c_str(),
                    this->getDuration());
        }
};

/**
 * Playlist of songs
 */
class PlayList
{
    private:
        /**
         * Duration of all songs in seconds
         * @param int duration
         */
        int duration;

        /**
         * vector containing list of songs in the PlayList
         * @param vector<Song> songs
         */
        vector<Song> songs;

        /**
         * Returns the duration of the PlayList in seconds
         * @return int
         */
        int getDuration()
        {
            return this->duration;
        }

        /**
         * Computes the duration of the CD
         * @return void
         */
        void computeDuration()
        {
            this->duration = 0;

            for (Song s : songs)
            {
                this->duration += s.getDuration();
            }
        }

    public:
        PlayList(vector<Song>& songs)
        {
            this->songs = songs;

            this->computeDuration();
        }

        /**
         * Returns all the songs in the CD
         * @return vector<Song>
         */
        vector<Song> getSongs()
        {
            return this->songs;
        }

        /**
         * Returns the number of songs in the PlayList
         * @return int
         */
        int numSongs()
        {
            return this->getSongs().size();
        }

        /**
         * Prints the playlist in a human readable way
         * @return void
         */
        void print()
        {
            printf("The playlist has %d songs.\nThe playlist lasts for %d duration. \n",
                    this->numSongs(),
                    this->getDuration());
        }
};

/**
 * Plays digital playlists / songs
 */
class DigitalPlayer
{
    private:
        /**
         * Queue of songs to be played
         * @param queue<Song> songQ
         */
        queue<Song> songQ;

    public:
        DigitalPlayer(){}

        /**
         * Empties the queue of songs to be played
         * @return void
         */
        void emptyQueue()
        {
            while (!this->empty()) songQ.pop();
        }

        /**
         * Plays the selected song
         * @param Song& s
         * @return void
         */
        void selectSong(Song& s)
        {
            this->emptyQueue();

            this->enqueueSong(s);

            this->play();
        }

        /**
         * Plays the selected playlist
         * @param PlayList& pl
         * @return void
         */
        void selectPlaylist(PlayList& pl)
        {
            this->emptyQueue();

            for (Song s : pl.getSongs()) this->enqueueSong(s);

            this->play();
        }

        /**
         * Stops playing whatever it is playing now
         * @return void
         */
        void stopPlaying()
        {
            this->emptyQueue();
        }

        /**
         * Returns whether there are songs left in the queue
         * @return bool
         */
        bool empty()
        {
            return this->songQ.empty();
        }

        /**
         * Enqueues the next song
         * @param Song& s
         * @return void
         */
        void enqueueSong(Song& s)
        {
            this->songQ.push(s);
        }

        /**
         * Dequeues the first song to be played
         * @return Song
         */
        Song dequeueSong()
        {
            Song s = songQ.front();

            songQ.pop();

            return s;
        }

        /**
         * Plays the songs in the queue
         * @return void
         */
        void play()
        {
            while (!this->empty())
            {
                printf("Playing the next song in the playlist\n\n");

                Song s = this->dequeueSong();

                s.print();
            }
        }
};

/**
 * Plays songs on a CD
 */
class CDPlayer
{
    private:
        /**
         * Queue of songs to be played
         * @param queue<Song> songQ
         */
        queue<Song> songQ;

    public:
        CDPlayer(){}

        /**
         * Empties the queue of songs to be played
         * @return void
         */
        void emptyQueue()
        {
            while (!this->empty()) songQ.pop();
        }

        /**
         * Plays the selected CD
         * @param CD& cd
         * @return void
         */
        void select(CD& cd)
        {
            this->emptyQueue();

            for (Song s : cd.getSongs()) songQ.push(s);

            this->play();
        }

        /**
         * Stops playing whatever it is playing now
         * @return void
         */
        void stopPlaying()
        {
            this->emptyQueue();
        }

        /**
         * Returns whether there are songs left in the queue
         * @return bool
         */
        bool empty()
        {
            return songQ.empty();
        }

        /**
         * Dequeues the first song to be played
         * @return Song
         */
        Song dequeueSong()
        {
            Song s = songQ.front();

            songQ.pop();

            return s;
        }

        /**
         * Plays the songs in the queue
         * @return void
         */
        void play()
        {
            while (!this->empty())
            {
                printf("\nPlaying the next song in the playlist\n");

                Song s = this->dequeueSong();

                s.print();
            }
        }
};

class JukeBox
{
    private:
        /**
         * The digital player attached to the JukeBox
         * @param DigitalPlayer dp
         */
        DigitalPlayer dp;

        /**
         * The CD player attached to the JukeBox
         * @param CDPlayer cp
         */
        CDPlayer cp;

        /**
         * Returns the disk player attached to the JukeBox
         * @return DigitalPlayer
         */
        DigitalPlayer getDigitalPlayer()
        {
            return this->dp;
        }

        /**
         * Returns the digital player attached to the JukeBox
         * @return CDPlayer
         */
        CDPlayer getCDPlayer()
        {
            return this->cp;
        }

    public:
        JukeBox() {}

        JukeBox(DigitalPlayer& dp, CDPlayer& cp)
        {
            this->dp = dp;

            this->cp = cp;
        }

        /**
         * Changes state of the jukebox
         * @param CD& cd
         * @return void
         */
        void selectDisk(CD& cd)
        {
            this->stopPlaying();

            this->getCDPlayer().select(cd);
        }

        /**
         * Changes state of the jukebox
         * @param PlayList& pl
         * @return void
         */
        void selectPlaylist(PlayList& pl)
        {
            this->stopPlaying();

            this->getDigitalPlayer().selectPlaylist(pl);
        }

        /**
         * Changes state of the jukebox
         * @param Song& s
         * @return void
         */
        void selectSong(Song& s)
        {
            this->stopPlaying();

            this->getDigitalPlayer().selectSong(s);
        }

        /**
         * Clears the state of the playing items
         * @return void
         */
        void stopPlaying()
        {
            this->getDigitalPlayer().stopPlaying();

            this->getCDPlayer().stopPlaying();
        }

        // TODO: Enqueue functionality
};

class User
{
    private:
        /**
         * ID of the user
         * @param int ID
         */
        int ID;

        /**
         * A reference to the jukeBox, that the user can interact with
         * @param JukeBox box
         */
        JukeBox box;

        /**
         * Generates a unique ID for the user
         * @returns void
         */
        void generateId()
        {
            this->ID = rand() % numeric_limits<int>::max();
        }

        /**
         * Returns the JukeBox instance
         * @return JukeBox
         */
        JukeBox getJukeBox()
        {
            return this->box;
        }

    public:
        User(JukeBox& J)
        {
            this->generateId();

            this->box = J;
        }

        /**
         * User plays a song on the JukeBox
         * @param Song& s
         * @return void
         */
        void selectSong(Song& s)
        {
            this->getJukeBox().selectSong(s);
        }

        /**
         * User plays a play list on the JukeBox
         * @param PlayList& pl
         * @return void
         */
        void selectPlaylist(PlayList& pl)
        {
            this->getJukeBox().selectPlaylist(pl);
        }

        /**
         * User selects a CD on the JukeBox
         * @param CD& cd
         * @return void
         */
        void selectDisk(CD& cd)
        {
            this->getJukeBox().selectDisk(cd);
        }

        // Add play and pause feature
};

vector<Song> getSongs(Artist& a, Album& al)
{
    vector<Song> res;

    string list = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i=0; i<10; i++)
    {
        string name;

        int len = 15 + rand() % 20;

        while (len > 0)
        {
            int x = rand() % list.size();

            name += list[x];

            len--;
        }

        int duration = 180 + rand() % 1000;

        Song s = Song(a, al, name, duration);

        res.push_back(s);
    }

    return res;
}

int main()
{
    CDPlayer cp = CDPlayer();

    DigitalPlayer dp = DigitalPlayer();

    JukeBox jb = JukeBox(dp, cp);

    User u1 = User(jb);

    User u2 = User(jb);

    Artist a1 = Artist("Paul Harrison");

    Artist a2 = Artist("Govinda Dasu");

    Album alb1 = Album("Application to Simplifield");

    Album alb2 = Album("Stanford Univeristy");

    vector<Song> s1 = getSongs(a1, alb1);

    vector<Song> s2 = getSongs(a2, alb2);

    CD cd1 = CD(a1, alb1, s1);

    CD cd2 = CD(a2, alb2, s2);

    int num = (s1.size() + s2.size()) / 3;

    int ind1 = 0, ind2 = 0;

    vector<Song> s3;

    for (int i=0; i<num; i++)
    {
        if (ind2 >= s2.size() || i % 2 == 0)
        {
            Song s = s1[ind1];

            s3.push_back(s);

            ind1++;
        }
        else
        {
            Song s = s2[ind2];

            s3.push_back(s);

            ind2++;
        }
    }

    PlayList pl = PlayList(s3);

    u1.selectPlaylist(pl);

    u2.selectDisk(cd2);
}

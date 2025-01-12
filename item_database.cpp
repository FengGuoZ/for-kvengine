#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Item {
public:
    Item(const string& title, int playingTime, bool gotIt, const string& comment)
        : mTitle(title)
        , mPlayingTime(playingTime)
        , mGotIt(gotIt)
        , mComment(comment) {}
    virtual void PrintMsg() = 0;
protected:
    string mTitle;
    int mPlayingTime;   // second
    bool mGotIt;        // true: on track
    string mComment;
};

class CD: public Item {
public:
    CD(const string& artist, const string& title, int playingTime, bool gotIt, const string& comment)
        : Item(title, playingTime, gotIt, comment)
        , mArtist(artist) {}
    
    void PrintMsg() override{
        cout << "Title: " << mTitle 
            << " Artist: " << mArtist << endl;
    }
private:
    string mArtist;
};

class DVD: public Item {
public:
    DVD(const string& director, const string& title, int playingTime, bool gotIt, const string& comment)
        : Item(title, playingTime, gotIt, comment)
        , mDirector(director) {}
    
    void PrintMsg() {
        cout << "Title: " << mTitle 
            << " Director: " << mDirector << endl;
    }
private:
    string mDirector;
};

class DateBase {
public:
    void AddItem(Item* item) {
        mItems.push_back(item);
    }
    void List() {
        for (auto item : mItems) {
            item->PrintMsg();
        }
    }
private:
    vector<Item*> mItems;
};

int main(void) {
    CD obj1("Xiaomin", "Moon", 120, true, "Top 10 music");
    DVD obj2("Lihua", "Forrest Gump", 120, true, "Golden film");
    
    DateBase db;
    db.AddItem(&obj1);
    db.AddItem(&obj2);
    db.List();

    return 0;
}
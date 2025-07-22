#ifndef EVENT_H
#define EVENT_H

#include <string>
using namespace std;

class Event {
    string title;
    string desc;
    string date;
    bool isCompleted = false;

public:
    Event(string title, string desc, string date);
    string getTitle() const;
    string getDesc() const;
    string getDate() const;
    bool status() const;

    void changeStatus();
};

#endif // EVENT_H


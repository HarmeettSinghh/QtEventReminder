#include "event.h"

Event::Event(string title, string desc, string date) {
    this->title = title;
    this->desc = desc;
    this->date = date;
}

string Event::getTitle() const { return title; }
string Event::getDesc() const { return desc; }
string Event::getDate() const { return date; }
bool Event::status() const { return isCompleted; }


void Event::changeStatus() { isCompleted = !isCompleted; }

#include "remindermanager.h"

void ReminderManager::addEvent(const string &title, const string &desc, const string &date) {
    Event e(title, desc, date);
    list.push_back(e);
}

vector<Event> ReminderManager::getEvents() {
    return list;
}

vector<Event> ReminderManager::getCompletedEvents() {
    vector<Event> completed;
    for (const auto &e : list) {
        if (e.status()) completed.push_back(e);
    }
    return completed;
}

void ReminderManager::markEventAsDone(int ind) {
    if (ind >= 0 && ind < list.size())
        list[ind].changeStatus();
}

void ReminderManager::removeEvent(int ind) {
    if (ind >= 0 && ind < list.size())
        list.erase(list.begin() + ind);
}
void ReminderManager::clearAll() {
    list.clear();
}

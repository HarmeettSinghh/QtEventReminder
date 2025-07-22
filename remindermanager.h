#ifndef REMINDERMANAGER_H
#define REMINDERMANAGER_H

#include "event.h"
#include <vector>

class ReminderManager {
    std::vector<Event> list;

public:
    void addEvent(const std::string &title, const std::string &desc, const std::string &date);
    std::vector<Event> getEvents();
    std::vector<Event> getCompletedEvents();
    void markEventAsDone(int ind);
    void removeEvent(int ind);
    void clearAll();

};

#endif // REMINDERMANAGER_H


#include "workerthread.h"
#include <QThread>

WorkerThread::WorkerThread(QObject *parent) : QThread(parent) {}

void WorkerThread::run() {
    while (running) {
        emit checkEvents();
        QThread::sleep(60); // check every 60 seconds
    }
}

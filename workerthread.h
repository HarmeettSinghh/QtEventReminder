#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>

class WorkerThread : public QThread {
    Q_OBJECT

public:
    explicit WorkerThread(QObject *parent = nullptr);
    void run() override;

signals:
    void checkEvents();

private:
    bool running = true;
};

#endif // WORKERTHREAD_H


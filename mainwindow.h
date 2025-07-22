#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "remindermanager.h"
#include "workerthread.h"
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddEvent();
    void onRemoveEvent();
    void onMarkDone();
    void onViewCompletedEvents();
    void onViewAllEvents();
    void onClearAllEvents();

private:
    Ui::MainWindow *ui;
    ReminderManager manager;
    WorkerThread *worker;

    void refreshEventList(); // Refreshes the UI list view
};

#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Connect signals to slots
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddEvent);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::onRemoveEvent);
    connect(ui->doneButton, &QPushButton::clicked, this, &MainWindow::onMarkDone);
    connect(ui->viewCompletedButton, &QPushButton::clicked, this, &MainWindow::onViewCompletedEvents);

    connect(ui->viewAllButton, &QPushButton::clicked, this, &MainWindow::onViewAllEvents);

    connect(ui->clearAllButton, &QPushButton::clicked, this, &MainWindow::onClearAllEvents); // new

    // Handle clicking on event item to view details
    connect(ui->eventList, &QListWidget::itemClicked, this, [=](QListWidgetItem* item){
        int index = ui->eventList->row(item);
        auto events = manager.getEvents();
        if (index >= 0 && index < events.size()) {
            QString info = "Title: " + QString::fromStdString(events[index].getTitle()) + "\n";
            info += "Description: " + QString::fromStdString(events[index].getDesc()) + "\n";
            info += "Date: " + QString::fromStdString(events[index].getDate()) + "\n";
            info += "Status: " + QString(events[index].status() ? "Completed" : "Pending");
            QMessageBox::information(this, "Event Details", info);
        }
    });

    // Optional thread (for future reminders or notifications)
    worker = new WorkerThread();
    worker->start();
}

MainWindow::~MainWindow() {
    worker->quit();
    worker->wait();
    delete worker;
    delete ui;
}

// ------------------- Functional Slots --------------------

void MainWindow::onAddEvent() {
    QString title = ui->titleEdit->text();
    QString desc = ui->descEdit->text();
    QString date = ui->dateEdit->text();

    if (title.isEmpty() || desc.isEmpty() || date.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields are required");
        return;
    }

    manager.addEvent(title.toStdString(), desc.toStdString(), date.toStdString());
    refreshEventList();
}

void MainWindow::onRemoveEvent() {
    int index = ui->eventList->currentRow();
    if (index >= 0) {
        manager.removeEvent(index);
        refreshEventList();
    }
}

void MainWindow::onMarkDone() {
    int index = ui->eventList->currentRow();
    if (index >= 0) {
        manager.markEventAsDone(index);
        refreshEventList();
    }
}

void MainWindow::onViewCompletedEvents() {
    ui->eventList->clear();
    auto completed = manager.getCompletedEvents();
    for (const auto &e : completed) {
        QString status = "[✓] ";
        ui->eventList->addItem(status + QString::fromStdString(e.getTitle()));
    }
}

void MainWindow::onClearAllEvents() {
    manager.clearAll();  // You need to implement this method in ReminderManager
    refreshEventList();
}


// ------------------- Utility --------------------

void MainWindow::refreshEventList() {
    ui->eventList->clear();
    auto events = manager.getEvents();
    for (const auto &e : events) {
        QString status = e.status() ? "[✓] " : "[ ] ";
        QString itemText = status +
                           QString::fromStdString(e.getTitle()) + " - " +
                           QString::fromStdString(e.getDate()) + " - " +
                           QString::fromStdString(e.getDesc());
        ui->eventList->addItem(itemText);
    }

    if (!events.empty()) {
        ui->eventList->setCurrentRow(0);
    }
}


void MainWindow::onViewAllEvents() {
    refreshEventList();
}


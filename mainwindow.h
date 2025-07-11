#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QTableWidget>
#include <QListWidget>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QKeyEvent>
#include <QContextMenuEvent>
#include <QDate>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Bus {
    qint8 number;
    qlonglong duration;
    qint64 date;
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void contextMenuEvent(QContextMenuEvent *event) override;

private slots:
    void loadFromFile();
    void addRow();
    void removeRow();
    void sortAscending();
    void sortDescending();

private:
    Ui::MainWindow *ui;
    QVector<Bus> busList;
    void updateTable();
    void updateList();
    void quickSort(int low, int high, bool ascending);
    int partition(int low, int high, bool ascending);
};
#endif // MAINWINDOW_H
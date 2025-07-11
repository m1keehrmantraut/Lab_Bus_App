#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMenu>
#include <QPixmap>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(3);
    QStringList headers = {"Номер рейса", "Продолжительность", "Дата"};
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    ui->comboBox->addItems({"Отображение 1", "Отображение 2"});
    ui->imageLabel->setPixmap(QPixmap(":/images/bus.jpg").scaled(200, 150, Qt::KeepAspectRatio));

    connect(ui->btnAdd, &QPushButton::clicked, this, &MainWindow::addRow);
    connect(ui->btnRemove, &QPushButton::clicked, this, &MainWindow::removeRow);
    connect(ui->btnSortAsc, &QPushButton::clicked, this, &MainWindow::sortAscending);
    connect(ui->btnSortDesc, &QPushButton::clicked, this, &MainWindow::sortDescending);

    connect(ui->comboBox, &QComboBox::currentTextChanged, this, [=](const QString &text){
        ui->imageLabel->setPixmap(QPixmap(text == "Отображение 1" ? ":/images/bus.jpg" : ":/images/bus2.jpg")
                                      .scaled(200, 150, Qt::KeepAspectRatio));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_F5) loadFromFile();
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction("Загрузить из файла", this, &MainWindow::loadFromFile);
    menu.exec(event->globalPos());
}

void MainWindow::loadFromFile()
{
    QFile file("data.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        int n;
        in >> n;
        busList.clear();
        for (int i = 0; i < n; ++i) {
            Bus b;
            int number;
            in >> number >> b.duration >> b.date;
            b.number = static_cast<qint8>(number);
            busList.append(b);
        }
        updateTable();
        updateList();
    }
}

void MainWindow::addRow()
{
    bool ok;
    int n = ui->lineEdit->text().toInt(&ok);
    if (!ok || n <= 0) n = 1;

    for (int i = 0; i < n; ++i) {
        Bus b = {
            static_cast<qint8>(rand() % 100),
            rand() % 1000 + 100,
            QDate::currentDate().toJulianDay()
        };
        busList.append(b);
    }
    updateTable();
    updateList();
}

void MainWindow::removeRow()
{
    if (!busList.isEmpty()) {
        busList.removeLast();
        updateTable();
        updateList();
    }
}

void MainWindow::updateTable()
{
    ui->tableWidget->setRowCount(busList.size());
    for (int i = 0; i < busList.size(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(busList[i].number)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(busList[i].duration)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QDate::fromJulianDay(busList[i].date).toString("dd.MM.yyyy")));
    }
}

void MainWindow::updateList()
{
    ui->listWidget->clear();
    for (const Bus &b : busList) {
        ui->listWidget->addItem(QString("Рейс %1: %2 мин, %3")
                                    .arg(b.number)
                                    .arg(b.duration)
                                    .arg(QDate::fromJulianDay(b.date).toString("dd.MM.yyyy")));
    }
}

void MainWindow::quickSort(int low, int high, bool ascending)
{
    if (low < high) {
        int pi = partition(low, high, ascending);
        quickSort(low, pi - 1, ascending);
        quickSort(pi + 1, high, ascending);
    }
}

int MainWindow::partition(int low, int high, bool ascending)
{
    auto pivot = busList[high].number;
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        bool condition = ascending ? (busList[j].number < pivot) : (busList[j].number > pivot);
        if (condition) {
            ++i;
            qSwap(busList[i], busList[j]);
        }
    }
    qSwap(busList[i + 1], busList[high]);
    return i + 1;
}

void MainWindow::sortAscending()
{
    quickSort(0, busList.size() - 1, true);
    updateTable();
    updateList();
}

void MainWindow::sortDescending()
{
    quickSort(0, busList.size() - 1, false);
    updateTable();
    updateList();
}

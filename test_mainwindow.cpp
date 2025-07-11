#include <QtTest>
#include <QTemporaryFile>
#include <QTableWidget>
#include <QPushButton>
#include "mainwindow.h"

class TestMainWindow : public QObject {
    Q_OBJECT
public:
    TestMainWindow();
    ~TestMainWindow();

private slots:
    void testAddRow();
    void testLoadFromFile();

private:
    MainWindow* m_window;
};

TestMainWindow::TestMainWindow() {
    m_window = new MainWindow();
}

TestMainWindow::~TestMainWindow() {
    delete m_window;
}

void TestMainWindow::testAddRow() {
    int initial = m_window->findChild<QTableWidget*>("tableWidget")->rowCount();
    QTest::mouseClick(m_window->findChild<QPushButton*>("btnAdd"), Qt::LeftButton);
    QCOMPARE(m_window->findChild<QTableWidget*>("tableWidget")->rowCount(), initial + 1);
}

QTEST_APPLESS_MAIN(TestMainWindow)
#include "test_mainwindow.moc"

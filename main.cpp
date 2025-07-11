#include "mainwindow.h"
#include <QApplication>

#ifdef RUN_TESTS
#include "test_mainwindow.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    TestMainWindow tester;
    return QTest::qExec(&tester, argc, argv);
}
#else
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
#endif

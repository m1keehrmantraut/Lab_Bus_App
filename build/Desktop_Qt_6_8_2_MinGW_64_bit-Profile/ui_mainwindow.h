/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QLabel *imageLabel;
    QTableWidget *tableWidget;
    QListWidget *listWidget;
    QHBoxLayout *buttonLayout;
    QPushButton *btnAdd;
    QPushButton *btnRemove;
    QPushButton *btnSortAsc;
    QPushButton *btnSortDesc;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");

        verticalLayout->addWidget(lineEdit);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");

        verticalLayout->addWidget(comboBox);

        imageLabel = new QLabel(centralwidget);
        imageLabel->setObjectName("imageLabel");

        verticalLayout->addWidget(imageLabel);

        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");

        verticalLayout->addWidget(tableWidget);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");

        verticalLayout->addWidget(listWidget);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName("btnAdd");

        buttonLayout->addWidget(btnAdd);

        btnRemove = new QPushButton(centralwidget);
        btnRemove->setObjectName("btnRemove");

        buttonLayout->addWidget(btnRemove);

        btnSortAsc = new QPushButton(centralwidget);
        btnSortAsc->setObjectName("btnSortAsc");

        buttonLayout->addWidget(btnSortAsc);

        btnSortDesc = new QPushButton(centralwidget);
        btnSortDesc->setObjectName("btnSortDesc");

        buttonLayout->addWidget(btnSortDesc);


        verticalLayout->addLayout(buttonLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Bus App", nullptr));
        imageLabel->setText(QCoreApplication::translate("MainWindow", "Image", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        btnRemove->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        btnSortAsc->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202 \342\206\221", nullptr));
        btnSortDesc->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202 \342\206\223", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

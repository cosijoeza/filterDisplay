/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *open;
    QPushButton *clear;
    QLabel *picture_1;
    QPushButton *filter;
    QLabel *label;
    QPushButton *addFilter;
    QPushButton *close;
    QTableWidget *matrix;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(986, 602);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        open = new QPushButton(centralwidget);
        open->setObjectName(QStringLiteral("open"));
        open->setGeometry(QRect(50, 460, 100, 40));
        clear = new QPushButton(centralwidget);
        clear->setObjectName(QStringLiteral("clear"));
        clear->setGeometry(QRect(160, 460, 100, 40));
        picture_1 = new QLabel(centralwidget);
        picture_1->setObjectName(QStringLiteral("picture_1"));
        picture_1->setGeometry(QRect(50, 20, 281, 411));
        picture_1->setFrameShape(QFrame::Box);
        picture_1->setAlignment(Qt::AlignCenter);
        filter = new QPushButton(centralwidget);
        filter->setObjectName(QStringLiteral("filter"));
        filter->setGeometry(QRect(680, 280, 280, 40));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(370, 20, 281, 411));
        label->setFrameShape(QFrame::Box);
        label->setAlignment(Qt::AlignCenter);
        addFilter = new QPushButton(centralwidget);
        addFilter->setObjectName(QStringLiteral("addFilter"));
        addFilter->setGeometry(QRect(680, 230, 280, 40));
        close = new QPushButton(centralwidget);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(860, 460, 100, 40));
        matrix = new QTableWidget(centralwidget);
        matrix->setObjectName(QStringLiteral("matrix"));
        matrix->setGeometry(QRect(690, 20, 256, 192));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 986, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        open->setText(QApplication::translate("MainWindow", "Abrir", Q_NULLPTR));
        clear->setText(QApplication::translate("MainWindow", "Limpiar", Q_NULLPTR));
        picture_1->setText(QApplication::translate("MainWindow", "Original", Q_NULLPTR));
        filter->setText(QApplication::translate("MainWindow", "Aplicar filtro", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Resultado", Q_NULLPTR));
        addFilter->setText(QApplication::translate("MainWindow", "Agregar filtro", Q_NULLPTR));
        close->setText(QApplication::translate("MainWindow", "cerrar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

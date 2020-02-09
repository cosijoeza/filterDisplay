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
    QLabel *picture_2;
    QPushButton *addFilter;
    QPushButton *close;
    QTableWidget *matrix;
    QLabel *label_2;
    QLabel *picture_3;
    QLabel *picture_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1052, 995);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        open = new QPushButton(centralwidget);
        open->setObjectName(QStringLiteral("open"));
        open->setGeometry(QRect(30, 400, 150, 40));
        QFont font;
        font.setFamily(QStringLiteral("URW Gothic L"));
        font.setBold(true);
        font.setWeight(75);
        open->setFont(font);
        clear = new QPushButton(centralwidget);
        clear->setObjectName(QStringLiteral("clear"));
        clear->setGeometry(QRect(200, 400, 150, 40));
        clear->setFont(font);
        picture_1 = new QLabel(centralwidget);
        picture_1->setObjectName(QStringLiteral("picture_1"));
        picture_1->setGeometry(QRect(380, 20, 281, 411));
        QFont font1;
        font1.setFamily(QStringLiteral("URW Gothic L"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        picture_1->setFont(font1);
        picture_1->setFrameShape(QFrame::Box);
        picture_1->setAlignment(Qt::AlignCenter);
        filter = new QPushButton(centralwidget);
        filter->setObjectName(QStringLiteral("filter"));
        filter->setGeometry(QRect(30, 320, 320, 40));
        filter->setFont(font);
        picture_2 = new QLabel(centralwidget);
        picture_2->setObjectName(QStringLiteral("picture_2"));
        picture_2->setGeometry(QRect(710, 20, 281, 411));
        picture_2->setFont(font1);
        picture_2->setFrameShape(QFrame::Box);
        picture_2->setAlignment(Qt::AlignCenter);
        addFilter = new QPushButton(centralwidget);
        addFilter->setObjectName(QStringLiteral("addFilter"));
        addFilter->setGeometry(QRect(30, 270, 320, 40));
        addFilter->setFont(font);
        close = new QPushButton(centralwidget);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(891, 900, 100, 40));
        close->setFont(font);
        matrix = new QTableWidget(centralwidget);
        matrix->setObjectName(QStringLiteral("matrix"));
        matrix->setGeometry(QRect(30, 40, 320, 210));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(130, 20, 67, 17));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        picture_3 = new QLabel(centralwidget);
        picture_3->setObjectName(QStringLiteral("picture_3"));
        picture_3->setGeometry(QRect(380, 470, 281, 411));
        picture_3->setFont(font1);
        picture_3->setFrameShape(QFrame::Box);
        picture_3->setFrameShadow(QFrame::Plain);
        picture_3->setAlignment(Qt::AlignCenter);
        picture_4 = new QLabel(centralwidget);
        picture_4->setObjectName(QStringLiteral("picture_4"));
        picture_4->setGeometry(QRect(710, 470, 281, 411));
        picture_4->setFont(font1);
        picture_4->setFrameShape(QFrame::Box);
        picture_4->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1052, 22));
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
        open->setText(QApplication::translate("MainWindow", "Abrir imagen", Q_NULLPTR));
        clear->setText(QApplication::translate("MainWindow", "Limpiar", Q_NULLPTR));
        picture_1->setText(QApplication::translate("MainWindow", "Original RGB", Q_NULLPTR));
        filter->setText(QApplication::translate("MainWindow", "Aplicar filtro", Q_NULLPTR));
        picture_2->setText(QApplication::translate("MainWindow", "Resultado", Q_NULLPTR));
        addFilter->setText(QApplication::translate("MainWindow", "Agregar filtro", Q_NULLPTR));
        close->setText(QApplication::translate("MainWindow", "cerrar", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Filtro", Q_NULLPTR));
        picture_3->setText(QApplication::translate("MainWindow", "Original blanco y negro", Q_NULLPTR));
        picture_4->setText(QApplication::translate("MainWindow", "Resultado", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

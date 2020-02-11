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
    QLabel *title;
    QLabel *description;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1610, 1041);
        MainWindow->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	padding: .375rem .75rem;\n"
"  	border-radius: .25rem;\n"
"	background-color: #9C9C9C;\n"
"  	color: #fff;\n"
"  	transition: background-color .15s ease-in-out;\n"
"}\n"
"QPushButton:hover\n"
"{\n"
"	background-color: #828282 ; \n"
"}\n"
"QComboBox\n"
"{\n"
"  	background-color: #fff !important;\n"
"  	color: #000;\n"
"  	transition: background-color .15s ease-in-out;\n"
"}\n"
"#close{background-color: #F00;}\n"
"#close:hover{background-color: #D32F2F;}\n"
"#filter{background-color: #007bff;}\n"
"#filter:hover{background-color: #0069d9;}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        open = new QPushButton(centralwidget);
        open->setObjectName(QStringLiteral("open"));
        open->setGeometry(QRect(485, 670, 330, 50));
        QFont font;
        font.setFamily(QStringLiteral("URW Gothic L"));
        font.setBold(true);
        font.setWeight(75);
        open->setFont(font);
        clear = new QPushButton(centralwidget);
        clear->setObjectName(QStringLiteral("clear"));
        clear->setGeometry(QRect(1415, 910, 220, 50));
        clear->setFont(font);
        picture_1 = new QLabel(centralwidget);
        picture_1->setObjectName(QStringLiteral("picture_1"));
        picture_1->setGeometry(QRect(20, 20, 450, 600));
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
        filter->setGeometry(QRect(485, 910, 330, 50));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 123, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(255, 255, 255, 128));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush3(QColor(0, 0, 0, 128));
        brush3.setStyle(Qt::SolidPattern);
        filter->setPalette(palette);
        filter->setFont(font);
        filter->setCursor(QCursor(Qt::ArrowCursor));
        filter->setStyleSheet(QStringLiteral(""));
        picture_2 = new QLabel(centralwidget);
        picture_2->setObjectName(QStringLiteral("picture_2"));
        picture_2->setGeometry(QRect(485, 20, 450, 600));
        picture_2->setFont(font1);
        picture_2->setFrameShape(QFrame::Box);
        picture_2->setAlignment(Qt::AlignCenter);
        addFilter = new QPushButton(centralwidget);
        addFilter->setObjectName(QStringLiteral("addFilter"));
        addFilter->setGeometry(QRect(485, 730, 330, 50));
        addFilter->setFont(font);
        close = new QPushButton(centralwidget);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(1645, 910, 220, 50));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush4(QColor(255, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush4);
        QBrush brush5(QColor(255, 255, 255, 128));
        brush5.setStyle(Qt::NoBrush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush4);
        QBrush brush6(QColor(255, 255, 255, 128));
        brush6.setStyle(Qt::NoBrush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush4);
        QBrush brush7(QColor(255, 255, 255, 128));
        brush7.setStyle(Qt::NoBrush);
        close->setPalette(palette1);
        close->setFont(font);
        close->setStyleSheet(QStringLiteral(""));
        matrix = new QTableWidget(centralwidget);
        matrix->setObjectName(QStringLiteral("matrix"));
        matrix->setGeometry(QRect(20, 670, 450, 290));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 640, 67, 17));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        picture_3 = new QLabel(centralwidget);
        picture_3->setObjectName(QStringLiteral("picture_3"));
        picture_3->setGeometry(QRect(950, 20, 450, 600));
        picture_3->setFont(font1);
        picture_3->setFrameShape(QFrame::Box);
        picture_3->setFrameShadow(QFrame::Plain);
        picture_3->setAlignment(Qt::AlignCenter);
        picture_4 = new QLabel(centralwidget);
        picture_4->setObjectName(QStringLiteral("picture_4"));
        picture_4->setGeometry(QRect(1415, 20, 450, 600));
        picture_4->setFont(font1);
        picture_4->setFrameShape(QFrame::Box);
        picture_4->setAlignment(Qt::AlignCenter);
        title = new QLabel(centralwidget);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(950, 650, 300, 31));
        title->setFont(font1);
        description = new QLabel(centralwidget);
        description->setObjectName(QStringLiteral("description"));
        description->setGeometry(QRect(950, 710, 450, 200));
        QFont font2;
        font2.setPointSize(12);
        description->setFont(font2);
        description->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1610, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Filtros902A", Q_NULLPTR));
        open->setText(QApplication::translate("MainWindow", "Abrir imagen", Q_NULLPTR));
        clear->setText(QApplication::translate("MainWindow", "Limpiar", Q_NULLPTR));
        picture_1->setText(QApplication::translate("MainWindow", "Original RGB", Q_NULLPTR));
        filter->setText(QApplication::translate("MainWindow", "Aplicar filtro", Q_NULLPTR));
        picture_2->setText(QApplication::translate("MainWindow", "Resultado", Q_NULLPTR));
        addFilter->setText(QApplication::translate("MainWindow", "Agregar filtro", Q_NULLPTR));
        close->setText(QApplication::translate("MainWindow", "cerrar", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Filtro:", Q_NULLPTR));
        picture_3->setText(QApplication::translate("MainWindow", "Original blanco y negro", Q_NULLPTR));
        picture_4->setText(QApplication::translate("MainWindow", "Resultado", Q_NULLPTR));
        title->setText(QApplication::translate("MainWindow", "Nombre", Q_NULLPTR));
        description->setText(QApplication::translate("MainWindow", "Descripci\303\263n", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

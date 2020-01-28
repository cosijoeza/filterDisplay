#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <iostream>
#include <QPixmap>
#include <QFile>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;
using namespace cv;

Mat img;
int filtro[7][7];
int dimension = 0;
void getFilter(string);
#include "functions.h" 
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_clicked()
{
    QFile file;
    QTextStream io;
    QString file_name;
    String picture_path="";
    file_name = QFileDialog::getOpenFileName(this,"Abrir");
    file.setFileName(file_name);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    //Ruta de archivo
    picture_path = file_name.toStdString();
    //Lectura de imagen RGB y Escala de Grises
    img = imread(picture_path, CV_LOAD_IMAGE_COLOR);
    if(!file.isOpen() || ! img.data )
    {
        QMessageBox::critical(this,"Error","No se pudo abrir archivo");
        return;
    }
    io.setDevice(&file);
    file.flush();
    file.close();
    //Renderizar imagen en interfaz
    QPixmap pix(file_name);
    int w = ui->picture_1->width();
    int h = ui->picture_1->height();
    ui->picture_1->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->picture_1->setFrameShape(QFrame::NoFrame);
}

void MainWindow::on_close_clicked()
{
    this -> close();
}
void MainWindow::on_clear_clicked()
{
    ui->picture_1->clear();
    ui->picture_1->setFrameShape(QFrame::Box);
    ui->picture_1->setText("Original");
}

void MainWindow::on_addFilter_clicked()
{
    QFile file;
    QTextStream io;
    QString file_name;
    String file_path="";
    int renglones,columnas,fila;

    //ABRIR ARCHIVO QUE CONTIENE FILTRO
    file_name = QFileDialog::getOpenFileName(this,"Abrir");
    file.setFileName(file_name);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    //Ruta de archivo
    file_path = file_name.toStdString();
    if(!file.isOpen() )
    {
        QMessageBox::critical(this,"Error","No se pudo abrir archivo");
        return;
    }
    io.setDevice(&file);
    file.flush();
    file.close();

    getFilter(file_path); //Resultado almacenado en matriz filtro
    //TABLA FILTRO
    //Limpiar la tabla
    for(int i= ui->matrix->rowCount() - 1; i >= 0; i--)
        ui->matrix->removeRow(i);
    renglones = dimension;
    columnas = dimension;
    //Numero de columnas
    ui->matrix->setColumnCount(columnas);
    //Rellenar tabla
    for(int i = 0; i < renglones;i++)
    {
        ui->matrix->insertRow(i);
        fila = ui->matrix->rowCount() - 1;
        for(int j = 0; j < columnas;j++)
            ui->matrix->setItem(fila,j,new QTableWidgetItem(QString::number(filtro[i][j])));
    }
}


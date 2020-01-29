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

#include "functions.h" 

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}
//ABRIR IMAGEN
void MainWindow::on_open_clicked()
{
    QFile file;
    QTextStream io;
    QString file_name;
    String picture_path="";
    //Abrir archivo
    file_name = QFileDialog::getOpenFileName(this,"Abrir");
    file.setFileName(file_name);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    //Ruta de archivo
    picture_path = file_name.toStdString();
    
    //Lectura de imagen RGB 
    img = imread(picture_path, CV_LOAD_IMAGE_COLOR);
    if(!file.isOpen() || ! img.data )
    {
        QMessageBox::critical(this,"Error","No se pudo abrir archivo");
        return;
    }
    //Cerrar archivo
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
//CERRAR VENTANA
void MainWindow::on_close_clicked()
{
    this -> close();
}
//RESET AL LUGAR DONDE VAN LAS IMAGENES
void MainWindow::on_clear_clicked()
{
    ui->picture_1->clear();
    ui->picture_1->setFrameShape(QFrame::Box);
    ui->picture_1->setText("Original");
    
    ui->picture_2->clear();
    ui->picture_2->setFrameShape(QFrame::Box);
    ui->picture_2->setText("Resultado");
}
//LEER FILTRO DE UN ARCHIVO
void MainWindow::on_addFilter_clicked()
{
    QFile file;
    QTextStream io;
    QString file_name;
    String file_path="";
    int renglones,columnas,fila;

    //Abrir archivo que contiene datos del filtro
    file_name = QFileDialog::getOpenFileName(this,"Abrir");
    file.setFileName(file_name);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    //Ruta de archivo
    file_path = file_name.toStdString();
    
    //Verificar que se pueda abir archivo
    if(!file.isOpen() )
    {
        QMessageBox::critical(this,"Error","No se pudo abrir archivo");
        return;
    }

    //Cerrar archivo
    io.setDevice(&file);
    file.flush();
    file.close();

    //Datos de archivo a matriz FILTRO[][]
    getFilter(file_path);

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

//APLICAR FILTRO A IMAGEN
void MainWindow::on_filter_clicked()
{
    //Verificar que un filtro ya haya sido cargado
    //Si la tabla no tiene rengloes entonces no ha sido cargado un filtro
    if(ui->matrix->rowCount() - 1 < 0)
    {
        QMessageBox::critical(this,"Error","Agregar filtro");
        return;   
    }

    Mat resultado;
    string name = "resultado.png";
    QString qName = name.c_str();
    
    //Aplicar filtro
    resultado = addFilter(img);
    imwrite(name,resultado);

    //Rendirizar resultado en interfaz
    QPixmap pix(qName);
    int w = ui->picture_2->width();
    int h = ui->picture_2->height();
    ui->picture_2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->picture_2->setFrameShape(QFrame::NoFrame);
}

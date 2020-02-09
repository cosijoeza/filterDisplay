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
#define length(x) (sizeof(x)/sizeof(x[0]))

using namespace std;
using namespace cv;

Mat img;
Mat img_gray;
int filtro[7][7];
int dimension = 0;
bool existe_img = false;

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
    img_gray = imread(picture_path,0);
    string nameBN = "img/byn.jpg"; 
    imwrite(nameBN,img_gray);

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

    //Renderizar imagen en interfaz
    QString qnameBN = nameBN.c_str();
    QPixmap pix1(qnameBN);
    w = ui->picture_3->width();
    h = ui->picture_3->height();
    ui->picture_3->setPixmap(pix1.scaled(w,h,Qt::KeepAspectRatio));
    ui->picture_3->setFrameShape(QFrame::NoFrame);

    //Se cargo una imagen
    existe_img = true;
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
    ui->picture_1->setText("Original RGB");
    
    ui->picture_2->clear();
    ui->picture_2->setFrameShape(QFrame::Box);
    ui->picture_2->setText("Resultado");

    ui->picture_3->clear();
    ui->picture_3->setFrameShape(QFrame::Box);
    ui->picture_3->setText("Original blanco y negro");
    
    ui->picture_4->clear();
    ui->picture_4->setFrameShape(QFrame::Box);
    ui->picture_4->setText("Resultado");

    existe_img = false;
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
    //Verificar que haya sido cargada una imagen
    if(!existe_img)
    {
        QMessageBox::critical(this,"Error","Debes cargar una imagen");
        return;   
    }
    //Verificar que un filtro ya haya sido cargado
    //Si la tabla no tiene renglones entonces no ha sido cargado un filtro
    if(ui->matrix->rowCount() - 1 < 0)
    {
        QMessageBox::critical(this,"Error","Agregar filtro");
        return;   
    }

    Mat resultadoBN,resultadoRGB;

    string name = "img/resultadoBN.png";
    QString qName = name.c_str();
    //Aplicar filtro  BLANCO Y NEGRO
    resultadoBN = addFilter(img_gray);
    imwrite(name,resultadoBN);
    //Rendirizar resultadoBN en interfaz 
    QPixmap pix(qName);
    int w = ui->picture_4->width();
    int h = ui->picture_4->height();
    ui->picture_4->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->picture_4->setFrameShape(QFrame::NoFrame);

    name = "img/resultadoRGB.png";
    qName = name.c_str();
    //Aplicar filtro  RGB
    resultadoRGB = addFilterRGB(img);
    imwrite(name,resultadoRGB);
    //Rendirizar resultadoRGB en interfaz 
    QPixmap pix1(qName);
    w = ui->picture_2->width();
    h = ui->picture_2->height();
    ui->picture_2->setPixmap(pix1.scaled(w,h,Qt::KeepAspectRatio));
    ui->picture_2->setFrameShape(QFrame::NoFrame);
}
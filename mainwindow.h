#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_open_clicked();

    void on_close_clicked();

    void on_clear_clicked();

    void on_addFilter_clicked();

    void on_filter_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
   

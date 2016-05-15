#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new Scene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(10,10,800,500);
    QImage bg;
    bg.load(":/picture/cover.jpg");
    bg = bg.scaled(800,600);
    scene->setBackgroundBrush(bg);
    scene->init();
    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

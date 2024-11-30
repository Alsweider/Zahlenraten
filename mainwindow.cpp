#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zaehlerVersuche = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonRaten_clicked()
{
    zaehlerVersuche = 0;
    aktuellesMinimum = ui->spinBox->value();
    aktuellesMaximum = ui->spinBox_2->value();

    berechneSchaetzung();

    ui->pushButtonHoeher->setEnabled(true);
    ui->pushButtonTiefer->setEnabled(true);
}

void MainWindow::berechneSchaetzung(){
    aktuelleZahl = ((aktuellesMinimum + aktuellesMaximum) / 2);
    ui->labelZahl->setText(QString::number(aktuelleZahl));
    statusAktualisieren();
}

void MainWindow::on_pushButtonTiefer_clicked()
{
    aktuellesMaximum = aktuelleZahl;
    berechneSchaetzung();

}


void MainWindow::on_pushButtonHoeher_clicked()
{
    aktuellesMinimum = aktuelleZahl;
    berechneSchaetzung();

}

void MainWindow::statusAktualisieren(){
    zaehlerVersuche++;
    QString statusZeile = QString("Versuche: %1").arg(zaehlerVersuche);
    ui->statusBar->showMessage(statusZeile,0);
}

// Programmierung: Alsweider (2024)
// https://github.com/Alsweider




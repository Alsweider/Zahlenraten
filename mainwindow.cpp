#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    aktuelleZahl = 0;
    zaehlerVersuche = 0;
    zeilenNummer = 0;
    ui->listWidget->setAlternatingRowColors(true);

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
    ui->spinBox->setEnabled(false);
    ui->spinBox_2->setEnabled(false);

    berechneSchaetzung();

    ui->pushButtonHoeher->setEnabled(true);
    ui->pushButtonTiefer->setEnabled(true);
    ui->pushButtonKopieren->setEnabled(true);

    ui->listWidget->insertItem(0, "x = " + QString::number(aktuelleZahl));
    ui->pushButtonRaten->setEnabled(false);

}


void MainWindow::berechneSchaetzung(){
    aktuelleZahl = ((aktuellesMinimum + aktuellesMaximum) / 2);
    ui->labelZahl->setText(QString::number(aktuelleZahl));
    statusAktualisieren();
}


void MainWindow::on_pushButtonTiefer_clicked()
{
    int temp = aktuelleZahl;

    aktuellesMaximum = aktuelleZahl - 1;
    berechneSchaetzung();

    ui->listWidget->insertItem(0, QString("x < " + QString::number(temp) + " = " + QString::number(aktuelleZahl)));
}


void MainWindow::on_pushButtonHoeher_clicked()
{
    int temp = aktuelleZahl;

    aktuellesMinimum = aktuelleZahl + 1;
    berechneSchaetzung();

    ui->listWidget->insertItem(0, QString("x > " + QString::number(temp) + " = " + QString::number(aktuelleZahl)));
}


void MainWindow::statusAktualisieren(){
    zaehlerVersuche++;
    QString statusZeile = QString("Versuche: %1").arg(zaehlerVersuche);
    ui->statusBar->showMessage(statusZeile,0);
}


void MainWindow::on_pushButtonKopieren_clicked()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(QString::number(aktuelleZahl));
}


void MainWindow::on_pushButtonZuruecksetzen_clicked()
{
    //aktuelleZahl = 0;
    zaehlerVersuche = 0;
    ui->spinBox->setValue(0);
    ui->spinBox->setEnabled(true);
    ui->spinBox_2->setValue(100);
    ui->spinBox_2->setEnabled(true);
    ui->listWidget->clear();
    ui->pushButtonRaten->setEnabled(true);
    ui->pushButtonKopieren->setEnabled(false);
    ui->pushButtonHoeher->setEnabled(false);
    ui->pushButtonTiefer->setEnabled(false);
    ui->labelZahl->setText("Zahl");
    ui->statusBar->clearMessage();
    zeilenNummer = 0;
}

// Programmierung: Alsweider (2024-2025)
// https://github.com/Alsweider

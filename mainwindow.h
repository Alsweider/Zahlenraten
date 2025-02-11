#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QClipboard>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonRaten_clicked();

    void on_pushButtonTiefer_clicked();

    void on_pushButtonHoeher_clicked();

    void on_pushButtonKopieren_clicked();

    void on_pushButtonZuruecksetzen_clicked();

private:
    Ui::MainWindow *ui;
    int aktuellesMinimum;
    int aktuellesMaximum;
    int aktuelleZahl;
    int zaehlerVersuche;
    void berechneSchaetzung();
    void statusAktualisieren();
};
#endif // MAINWINDOW_H

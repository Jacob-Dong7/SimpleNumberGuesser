#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

namespace Ui {
    class MainWindow;
};

class MainWindow : public QMainWindow {
    Q_OBJECT
    public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    private:
    Ui::MainWindow *ui;
    int start, end;
    int randomNum;

    private slots:
    void on_btnConfirm_clicked();
    void on_btnGuess_clicked();
    void on_btnQuit_triggered();
};
#endif
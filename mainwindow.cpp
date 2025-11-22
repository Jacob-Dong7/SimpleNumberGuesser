#include "mainwindow.h"
#include "Generator.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btnConfirm_clicked() {
    if (ui->sbEnd->value() < ui->sbStart->value()) {
        QMessageBox::critical(this, "Error", "The End Range Must Be Larger Than Start Range");
        return;
    }
    ui->txtGuess->setValue(0);
    ui->txtAnswer->setText("Enter A Number To Guess, Good Luck!");
    ui->btnPlayAgain->setVisible(false);
    ui->btnGuess->setVisible(true);
    start = ui->sbStart->value();
    end = ui->sbEnd->value();

    Generator gen;
    randomNum = gen.generate(start, end);

    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_btnGuess_clicked() {
    if (ui->txtGuess->value() == randomNum) {
        ui->txtAnswer->setText("Good job");
        ui->btnGuess->setVisible(false);
        ui->btnPlayAgain->setVisible(true);
        return;
    }
    if (ui->txtGuess->value() < randomNum) {
        ui->txtAnswer->setText("The random number is larger");
    }
    if (ui->txtGuess->value() > randomNum) {
        ui->txtAnswer->setText("The random number is smaller");
    }
}

void MainWindow::on_btnQuit_triggered() {
    QApplication::quit();
}

void MainWindow::on_btnPlayAgain_clicked() {
    ui->sbStart->setValue(0);
    ui->sbEnd->setValue(0);
    ui->txtAnswer->clear();
    ui->txtGuess->clear();
    ui->stackedWidget->setCurrentIndex(0);
}
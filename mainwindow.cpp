#include "Aes256.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_swap_button_clicked()
{
    QString a = ui->label_text1->text();
    ui->label_text1->setText(ui->label_text2->text());
    ui->label_text2->setText(a);
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->line_key->text().trimmed().isEmpty())
    {
        ui->statusbar->showMessage("Необходимо ввести ключ.");
        return;
    }
    if (ui->label_text1->text() == "Открытый текст")
    {
        QString string1 = ui->line_text1->toPlainText();
        QString key = ui->line_key->text();
        QString string2 = QString::fromStdString(Aes256::encrypt((string1).toStdString(),
                                                                 key.toStdString()));
        ui->line_text2->setText(string2);
    }
    else
    {
        QString string1 = ui->line_text1->toPlainText();
        QString key = ui->line_key->text();
        QString string2 = QString::fromStdString(Aes256::decrypt((string1).toStdString(),
                                                                 key.toStdString()));
        ui->line_text2->setText(string2);
    }
    ui->statusbar->showMessage("Выполнено.");
}

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    QPixmap pix(":/image/OIP-C.jpg");
    pix=pix.scaled(47,37);
    ui->setupUi(this);
    ui->label_4->setPixmap(pix);
}

Dialog::~Dialog()
{
    delete ui;
}



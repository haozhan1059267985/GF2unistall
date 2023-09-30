#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    QPixmap pix(":/image/OIP-C.jpg");
    pix=pix.scaled(47,37);
    ui->setupUi(this);
    ui->label_5->setText("<a href = https://github.com/haozhan1059267985/GF2unistall>https://github.com/haozhan1059267985/<br>GF2unistall</a>");
    ui->label_6->setText("<a href = https://space.bilibili.com/74070043>https://space.bilibili.com/74070043</a>");
    ui->label_5->setOpenExternalLinks(true);
    ui->label_6->setOpenExternalLinks(true);
    ui->label_4->setPixmap(pix);
}

Dialog::~Dialog()
{
    delete ui;
}



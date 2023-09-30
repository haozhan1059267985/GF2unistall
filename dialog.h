/*
Copyright 2023 Caacobe

This file is part of GF2unistall.

GF2unistall is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

GF2unistall is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with Foobar. If not, see <https://www.gnu.org/licenses/>.*/
#ifndef DIALOG_H
#define DIALOG_H

#include <QGraphicsScene>
#include <QDialog>
#include <QPixmap>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

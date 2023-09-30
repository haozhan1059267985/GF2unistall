/*
Copyright 2023 Caacobe

This file is part of GF2unistall.

GF2unistall is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

GF2unistall is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with Foobar. If not, see <https://www.gnu.org/licenses/>.*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QUrl>
#include <QStandardItemModel>
#include <QFile>
#include <QMessageBox>
#include "dialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_action_6_triggered();

    void on_action_Qt_triggered();

    void on_action_7_triggered();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *file_list_model;
    QFileInfoList listGF2;
    QStringList filelist={"bugrpt.exe","filetxt.txt","GameAssembly.dll","GF2_Exilium.exe","GF2_Exilium_Data","NEP2.dll","NEPDaemon.exe","UnityCrashHandler64.exe","UnityPlayer.dll"};
};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/image/4.png"));
    file_list_model=new QStandardItemModel;
    ui->file_list->setModel(file_list_model);
    file_list_model->setHorizontalHeaderLabels(QStringList()={"文件名","类型","路径","状态"});
    QStandardItem *item;
    for(int i=0;i<filelist.length();i++)
    {
        item=new QStandardItem(filelist.at(i));
        file_list_model->setItem(i,0,item);
    }
    ui->file_list->setColumnWidth(0,170);
    ui->file_list->setColumnWidth(1,50);
    ui->file_list->setColumnWidth(2,300);
    ui->file_list->setColumnWidth(3,50);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    ui->dir_path->setPlainText(QFileDialog::getExistingDirectory(this,"选择安装的文件夹","C:\\"));
}


void MainWindow::on_pushButton_3_clicked()
{
    QDir opendir(ui->dir_path->toPlainText());
    QFileInfoList listall = opendir.entryInfoList(QDir::Dirs|QDir::Files|QDir::NoDotAndDotDot);

    QStandardItem *item;
    for(QFileInfo &it:listall)
    {
        for(QString &it1:filelist)
        {
            if(it.fileName()==it1)
            {
                listGF2.append(it);
                break;
            }
        }
    }
    for(QFileInfo &it:listGF2)
    {
        for(int i=0;i<filelist.length();i++)
        {
            if(it.fileName()==file_list_model->item(i,0)->text())
            {
                item = new QStandardItem();
                if(it.isDir())
                {
                    item->setText("文件夹");
                }
                else
                {
                    item->setText("文件");
                }
                file_list_model->setItem(i,1,item);
                item = new QStandardItem(it.filePath());
                file_list_model->setItem(i,2,item);
                item = new QStandardItem("存在");
                file_list_model->setItem(i,3,item);
            }
        }
    }

}


void MainWindow::on_pushButton_4_clicked()
{
    QDir dir=QDir("C:/");
    QByteArray bt;
    char *ch;
    dir.setPath("D:/Program Files/GF2Exilium/GF2/GF2Exilium/GF2 Game");
    QFileInfoList list =  dir.entryInfoList(QDir::Dirs|QDir::Files|QDir::NoDotAndDotDot);
    QFile filetxt("D:\\Program Files\\GF2Exilium\\GF2\\GF2Exilium\\GF2 Game\\filetxt.txt");
    filetxt.open(QIODevice::WriteOnly);
    for(QFileInfo &it:list)
    {
        bt=it.fileName().toLatin1();
        ch=bt.data();
        filetxt.write("\"");
        filetxt.write(ch);
        filetxt.write("\"");
        filetxt.write(",");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::StandardButton res;
    res=QMessageBox::question(this,"","确认要删除少女前线2：追放的游戏文件吗？");
    if(res==QMessageBox::Yes)
    {
    for(QFileInfo &it:listGF2)
    {


        if(it.isFile())
        {
            if(QFile::remove(it.filePath()))
            {
                for(int i=0;i<filelist.length();i++)
                {
                    if(it.fileName()==file_list_model->item(i,0)->text())
                    {
                        file_list_model->item(i,3)->setText("成功");
                    }
                }
            }
            else
            {
                for(int i=0;i<filelist.length();i++)
                {
                    if(it.fileName()==file_list_model->item(i,0)->text())
                    {
                        file_list_model->item(i,3)->setText("失败");
                    }
                }
            }
        }
        else if(it.isDir())
        {

            if(QDir(it.filePath()).removeRecursively())
            {
                for(int i=0;i<filelist.length();i++)
                {
                    if(it.fileName()==file_list_model->item(i,0)->text())
                    {
                        file_list_model->item(i,3)->setText("成功");
                    }
                }
            }
            else
            {
                for(int i=0;i<filelist.length();i++)
                {
                    if(it.fileName()==file_list_model->item(i,0)->text())
                    {
                        file_list_model->item(i,3)->setText("失败");
                    }
                }
            }

        }

    }
    }
}


void MainWindow::on_action_6_triggered()
{
    Dialog d;
    d.exec();
}


void MainWindow::on_action_Qt_triggered()
{
    QMessageBox::aboutQt(this,"关于Qt");
}


void MainWindow::on_action_7_triggered()
{
    QMessageBox::about(this,"帮助","输入路径后，点击检索少前2文件，程序会自动检索游戏文件，点击删除即可\n本程序只用于卸载游戏文件，不包括启动器");
}


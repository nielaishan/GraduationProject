#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include <QFileDialog>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QTextCodec>
#include <QMessageBox>
#include "file.h"
#include "showimage.h"
#include "adaptiveset.h"
#include "adaptivethreshold.h"
#include <exception>

using namespace std;
using namespace  cv;

void MainWindow::on_radioButton_Binary_clicked()
{
    ui->helpTextBrowser->clear();
    ui->helpTextBrowser->insertPlainText("当前点值大于阈值时，取最大值，否则设置为0 ，由src输入，dst输出\n\n"
                                         "函数原型为：\n"
                                         "double threshold(InputArray src, OutputArray dst, double thresh, double maxval, THRESH_BINARY)"
                                         "第一个参数，InputArray类型的src，输入图像，即源图像，填单通道，8或32位浮点类型的Mat对象即可。 \n\n"
                                         "第二个参数，InputArray类型的dst，函数调用后的运算结果存放在这里，即这个参数用于存放输出结果，\n\n"
                                         "且和第一个参数中的Mat变量有一样的尺寸和类型"
                                         "第三个参数，double类型的thresh,阈值的具体值\n\n"
                                         "第四个参数，double类型的maxval，阈值的最大值\n\n"
                                         "第五个参数，阈值类型\n\n");

    bool ok=true;
    int thresh=ui->binaryThreshold->text().toDouble(&ok);
    if(ok==false){
        QMessageBox::information(this,
                                          tr("输入错误"),
                                          tr("请输入正确数字!"));
        return ;
    }

    try{
        std::string fileString=file.getFileString().toLocal8Bit().toStdString();
        Mat srcImage=imread(fileString,0);//输入图像
        Mat dstImage;//输出图像
        QImage* img=new QImage;//QT界面显示图像

        threshold(srcImage,dstImage,thresh,255,THRESH_BINARY);
        imwrite("temp.jpg",dstImage);
        if(showImg.showImage(ui,img,"temp.jpg",DSTImage)==-1){
            QMessageBox::information(this,
                                              tr("打开图像失败"),
                                              tr("打开图像失败!"));
        }
        delete img;
    }catch(exception& e){
        QMessageBox::information(this,
                                          tr("打开图像失败"),
                                          tr("打开图像失败,请输入正确图像!"));
    }
}

void MainWindow::on_radioButton_BinaryInv_clicked()
{
     ui->helpTextBrowser->clear();
     ui->helpTextBrowser->insertPlainText("当前点值大于阈值时，设置为0，否则取最大值 ，由src输入，dst输出\n\n"
                                          "函数原型为： \n"
                                          "double threshold(InputArray src, OutputArray dst, double thresh, double maxval, THRESH_BINARY_INV) "
                                          "第一个参数，InputArray类型的src，输入图像，即源图像，填单通道，8或32位浮点类型的Mat对象即可。 \n\n"
                                          "第二个参数，InputArray类型的dst，函数调用后的运算结果存放在这里，即这个参数用于存放输出结果，\n\n"
                                          "且和第一个参数中的Mat变量有一样的尺寸和类型"
                                          "第三个参数，double类型的thresh,阈值的具体值\n\n"
                                          "第四个参数，double类型的maxval，阈值的最大值\n\n"
                                          "第五个参数，阈值类型\n\n");
     bool ok=true;
     int thresh=ui->binaryThreshold->text().toDouble(&ok);
     if(ok==false){
         QMessageBox::information(this,
                                           tr("输入错误"),
                                           tr("请输入正确数字!"));
         return ;
     }

     try{
         std::string fileString=file.getFileString().toLocal8Bit().toStdString();
         Mat srcImage=imread(fileString,0);//输入图像
         Mat dstImage;//输出图像
         QImage* img=new QImage;//QT界面显示图像

         threshold(srcImage,dstImage,thresh,255,THRESH_BINARY_INV);
         imwrite("temp.jpg",dstImage);
         if(showImg.showImage(ui,img,"temp.jpg",DSTImage)==-1){
             QMessageBox::information(this,
                                               tr("打开图像失败"),
                                               tr("打开图像失败!"));
         }
         delete img;
     }catch(exception& e){
         QMessageBox::information(this,
                                           tr("打开图像失败"),
                                           tr("打开图像失败,请输入正确图像!"));
     }
}

void MainWindow::on_radioButton_TRUNC_clicked()
{
    ui->helpTextBrowser->clear();
    ui->helpTextBrowser->insertPlainText("当前点值大于阈值时，设置为阈值，否则不改变，由src输入，dst输出 \n\n"
                                         "函数原型为： \n"
                                         "double threshold(InputArray src, OutputArray dst, double thresh, double maxval,THRESH_TRUNC) "
                                         "第一个参数，InputArray类型的src，输入图像，即源图像，填单通道，8或32位浮点类型的Mat对象即可。 \n\n"
                                         "第二个参数，InputArray类型的dst，函数调用后的运算结果存放在这里，即这个参数用于存放输出结果，\n\n"
                                         "且和第一个参数中的Mat变量有一样的尺寸和类型"
                                         "第三个参数，double类型的thresh,阈值的具体值\n\n"
                                         "第四个参数，double类型的maxval，阈值的最大值\n\n"
                                         "第五个参数，阈值类型\n\n");

    bool ok=true;
    int thresh=ui->binaryThreshold->text().toDouble(&ok);
    if(ok==false){
        QMessageBox::information(this,
                                          tr("输入错误"),
                                          tr("请输入正确数字!"));
        return ;
    }

    try{
        std::string fileString=file.getFileString().toLocal8Bit().toStdString();
        Mat srcImage=imread(fileString,0);//输入图像
        Mat dstImage;//输出图像
        QImage* img=new QImage;//QT界面显示图像

        threshold(srcImage,dstImage,thresh,255,THRESH_TRUNC);
        imwrite("temp.jpg",dstImage);
        if(showImg.showImage(ui,img,"temp.jpg",DSTImage)==-1){
            QMessageBox::information(this,
                                              tr("打开图像失败"),
                                              tr("打开图像失败!"));
        }
        delete img;
    }catch(exception& e){
        QMessageBox::information(this,
                                          tr("打开图像失败"),
                                          tr("打开图像失败,请输入正确图像!"));
    }
}

void MainWindow::on_radioButton_TRZERO_clicked()
{
    ui->helpTextBrowser->clear();
    ui->helpTextBrowser->insertPlainText("当前点值大于阈值时，不改变，否则设置为0 ，由src输入，dst输出\n\n"
                                         "函数原型为： \n"
                                         "double threshold(InputArray src, OutputArray dst, double thresh, double maxval,THRESH_TOZERO) "
                                         "第一个参数，InputArray类型的src，输入图像，即源图像，填单通道，8或32位浮点类型的Mat对象即可。 \n\n"
                                         "第二个参数，InputArray类型的dst，函数调用后的运算结果存放在这里，即这个参数用于存放输出结果，\n\n"
                                         "且和第一个参数中的Mat变量有一样的尺寸和类型"
                                         "第三个参数，double类型的thresh,阈值的具体值\n\n"
                                         "第四个参数，double类型的maxval，阈值的最大值\n\n"
                                         "第五个参数，阈值类型\n\n");

    bool ok=true;
    int thresh=ui->binaryThreshold->text().toDouble(&ok);
    if(ok==false){
        QMessageBox::information(this,
                                          tr("输入错误"),
                                          tr("请输入正确数字!"));
        return ;
    }
    try{
        std::string fileString=file.getFileString().toLocal8Bit().toStdString();
        Mat srcImage=imread(fileString,0);//输入图像
        Mat dstImage;//输出图像
        QImage* img=new QImage;//QT界面显示图像

        threshold(srcImage,dstImage,thresh,255,THRESH_TOZERO);
        imwrite("temp.jpg",dstImage);
        if(showImg.showImage(ui,img,"temp.jpg",DSTImage)==-1){
            QMessageBox::information(this,
                                              tr("打开图像失败"),
                                              tr("打开图像失败!"));
        }
        delete img;
    }catch(exception& e){
        QMessageBox::information(this,
                                          tr("打开图像失败"),
                                          tr("打开图像失败,请输入正确图像!"));
    }
}

void MainWindow::on_radioButton_TRZERO_INV_clicked()
{
    ui->helpTextBrowser->clear();
    ui->helpTextBrowser->insertPlainText("当前点值大于阈值时，不改变，否则设置为0，由src输入，dst输出 \n\n"
                                         "函数原型为： \n"
                                         "double threshold(InputArray src, OutputArray dst, double thresh, double maxval,THRESH_TOZERO_INV) "
                                         "第一个参数，InputArray类型的src，输入图像，即源图像，填单通道，8或32位浮点类型的Mat对象即可。 \n\n"
                                         "第二个参数，InputArray类型的dst，函数调用后的运算结果存放在这里，即这个参数用于存放输出结果，\n\n"
                                         "且和第一个参数中的Mat变量有一样的尺寸和类型"
                                         "第三个参数，double类型的thresh,阈值的具体值\n\n"
                                         "第四个参数，double类型的maxval，阈值的最大值\n\n"
                                         "第五个参数，阈值类型\n\n");

    bool ok=true;
    int thresh=ui->binaryThreshold->text().toDouble(&ok);
    if(ok==false){
        QMessageBox::information(this,
                                          tr("输入错误"),
                                          tr("请输入正确数字!"));
        return ;
    }
    try{
        std::string fileString=file.getFileString().toLocal8Bit().toStdString();
        Mat srcImage=imread(fileString,0);//输入图像
        Mat dstImage;//输出图像
        QImage* img=new QImage;//QT界面显示图像

        threshold(srcImage,dstImage,thresh,255,THRESH_TOZERO_INV);
        imwrite("temp.jpg",dstImage);
        if(showImg.showImage(ui,img,"temp.jpg",DSTImage)==-1){
            QMessageBox::information(this,
                                              tr("打开图像失败"),
                                              tr("打开图像失败!"));
        }
        delete img;
    }catch(exception& e){
        QMessageBox::information(this,
                                          tr("打开图像失败"),
                                          tr("打开图像失败,请输入正确图像!"));
    }
}

void MainWindow::on_adaptiveRadioButton_clicked()
{
    ui->helpTextBrowser->clear();
    ui->helpTextBrowser->insertPlainText("采用自适应阈值操作，，由src输入，dst输出\n\n"
                                         "函数原型为： \n"
                                         "void adaptiveThreshold(InputArray src, OutputArray dst, double maxval, "
                                         "int adaptiveMethod, int thresholdType,int blockSize,double C)\n\n"

                                         "第一个参数，InputArray类型的src，输入图像，即源图像，填单通道，8或32位浮点类型的Mat对象即可。 \n\n"
                                         "第二个参数，InputArray类型的dst，函数调用后的运算结果存放在这里，即这个参数用于存放输出结果，\n\n"
                                         "第三个参数，double类型的maxval，阈值的最大值\n\n"
                                         "第四个参数为int类型的adaptiveMethod,用于指定要使用的自适应阈值算法，可取值为"
                                         "ADAPTIVE_THRESH_MEAN_C 或 ADAPTIVE_THRESH_GUSSIAN_C\n"
                                         "前者阈值T(x,y)为blockSize*blockSize邻域内(x,y)减去第七个参数C的平均值\n"
                                         "后者阈值T(x,y)为blockSize*blockSize邻域内(x,y)减去第七个参数C与高斯窗交叉相关的加权总和\n\n"
                                         "第五个参数为thresholdType，表示阈值类型，取值为THRESH_BINARY或THRESH_BINARY_INV\n"
                                         "这两者的说明见第一个和第二个单选框\n\n"
                                         "第六个参数为blockSize，用于计算阈值大小的一个像素的邻域尺寸，取值为3,5,7等\n\n"
                                         "第七个参数为C，为减去平均或加权平均值后的常数值，通常为正数，但少数情况下也可以为负数或0\n\n"
                                         );
    try{
        std::string fileString=file.getFileString().toLocal8Bit().toStdString();
        Mat srcImage=imread(fileString,0);//输入图像
        Mat dstImage;//输出图像
        QImage* img=new QImage;//QT界面显示图像
        int method,type,size;
        double C;
        adaptive_set.getValue(method,type,size,C);
        adaptiveThreshold(srcImage,dstImage,255,method,type,size,C);
        imwrite("temp.jpg",dstImage);
        if(showImg.showImage(ui,img,"temp.jpg",DSTImage)==-1){
            QMessageBox::information(this,
                                              tr("打开图像失败"),
                                              tr("打开图像失败!"));
        }
        delete img;
    }catch(exception& e){
        QMessageBox::information(this,
                                          tr("打开图像失败"),
                                          tr("打开图像失败,请输入正确图像!"));
    }
}

void MainWindow::on_adaptiveButton_clicked()
{
    AdaptiveThreshold *adaptivethreshold=new AdaptiveThreshold;
    adaptivethreshold->show();
}

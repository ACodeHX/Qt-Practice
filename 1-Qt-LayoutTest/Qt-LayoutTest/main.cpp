﻿#include "widget.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    
    QFile qssFile(":/new/prefix1/dark_teal.qss");
    if (qssFile.open(QFile::ReadOnly))
    {
        a.setStyleSheet(qssFile.readAll());
    }
    
    return a.exec();
}

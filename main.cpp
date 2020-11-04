#include "mainwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    ShowWindow(GetConsoleWindow(), SW_HIDE); //Скроем консоль на всякий случай
    QApplication a(argc, argv);
    MainWindow w;
    system("chcp 1251");
    w.show();
    auto g = std::async(MainWindow::Change); //Запускаем функцию Change(которая в бесконечном цикле чекает какая клавиша сейчас нажата)
    //Но не просто запускаем, а запускаем асинхронно, то есть мы не будем ждать её выполнения (а она не выполнится, т.к. цикл бесконечный) и будем работать с визуальной менюшкой
    return a.exec();
}

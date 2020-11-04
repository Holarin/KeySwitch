#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <windows.h> //Используем WinAPI
#include <QMainWindow>
#include <QDebug> //Используем для того, чтобы визуально отследить что творится в программе
#include <thread>// Используем
#include <future>// Асинхронный запуск метода
#include <iostream> //Стандартная библиотека ввода вывода C++
#include <fstream> //Работа с файлами (прочитать, перезаписать)
#include <string> // Работа со строками C++
#include <QFileDialog> //Для того, чтобы вызвать диалоговое окно, где мы сможем выбрать файл, который будем потом открывать
#include <QTextCodec> //УСтанавливаем кодировку
#include <cstring> //Работа со строками C
#include <cstdlib>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static void Change();
    static void OpenFile(int i);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots: //это слоты для кнопок, то есть когда кнопка нажата - будет активирована связанная с ней функция, их прототипы находятся ниже коммента
    void on_F1_clicked();

    void on_getFile_clicked();

    void on_F2_clicked();

    void on_F3_clicked();

    void on_F4_clicked();

    void on_F5_clicked();

    void on_F6_clicked();

    void on_F7_clicked();

    void on_F8_clicked();

    void on_F9_clicked();

    void on_F10_clicked();

    void on_F11_clicked();

    void on_F12_clicked();

    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

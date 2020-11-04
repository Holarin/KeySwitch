#include "mainwindow.h"
#include "ui_mainwindow.h"

QString dirs[12]= {"-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-", "-"};
//Очень важно: это массив полных названий приложений, которые нужно будет потом открывать, итак суть:
//У нас 12 клавиш, на каждую своё приложение, поэтому мы создаём глобальный массив строк,
//dirs[0] будет отвечать за путь к приложению для F1, dirs[3] для F4 и тд.

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

void MainWindow::Change() { //GetAsyncKeyState проверяет, нажалась ли кнопка, если да, то передаём её номер в функцию OpenFile
    while(1){ //бесконечный цикл
          for(int i =8; i <= 190; i++)
           {
              if (GetAsyncKeyState(i) == -32767)
                OpenFile(i);
           }
    }
}

void MainWindow::OpenFile(int i) { //112-123 это коды клавиш F1-F12,
    switch(i) {
    case 112: { //112 - код клавиши F1, 113-F2 и тд.
        wstring z = dirs[0].toStdWString(); //wstring - тип строк, к которому мы конвертируем элемент из dirs типа QString, нужно для работы ShellExecute
        const wchar_t *w = z.c_str(); //Далее уже из wstring, преобразованием к си строке, мы получаем строку const wchar_t *w
        ShellExecute(NULL, L"open", w ,NULL, NULL, SW_SHOWDEFAULT); //вызываем открытие файла по его полному имени, в обычном режиме.
        break;
    }
    case 113: {
        wstring z = dirs[1].toStdWString();
        const wchar_t *w = z.c_str();
        ShellExecute(NULL, L"open", w ,NULL, NULL, SW_SHOWDEFAULT);
        break;
    }
    case 114: {
        wstring z = dirs[2].toStdWString();
        const wchar_t *w = z.c_str();
        ShellExecute(NULL, L"open", w ,NULL, NULL, SW_SHOWDEFAULT);
        break;
    }
    case 115: {
        wstring z = dirs[3].toStdWString();
        const wchar_t *w = z.c_str();
        ShellExecute(NULL, L"open", w ,NULL, NULL, SW_SHOWDEFAULT);
        break;
    }
    case 116: {
        wstring z = dirs[4].toStdWString();
        const wchar_t *w = z.c_str();
        ShellExecute(NULL, L"open", w ,NULL, NULL, SW_SHOWDEFAULT);
        break;
    }
    case 117: {
        wstring z = dirs[5].toStdWString();
        const wchar_t *w = z.c_str();
        ShellExecute(NULL, L"open", w ,NULL, NULL, SW_SHOWDEFAULT);
        break;
    }
    case 118: {
        wstring z = dirs[6].toStdWString();
        const wchar_t *w = z.c_str();
        ShellExecute(NULL, L"open", w ,NULL, NULL, SW_SHOWDEFAULT);
        break;
    }
    case 119: {
        wstring z = dirs[7].toStdWString();
        const wchar_t *w = z.c_str();
        ShellExecute(NULL, L"open", w ,NULL, NULL, SW_SHOWDEFAULT);
        break;
    }
    case 120: {
        wstring z = dirs[8].toStdWString();
        const wchar_t *w = z.c_str();
        ShellExecute(NULL, L"open", w ,NULL, NULL, SW_SHOWDEFAULT);
        break;
    }
    case 121: {
        wstring z = dirs[9].toStdWString();
        const wchar_t *w = z.c_str();
        ShellExecute(NULL, L"open", w ,NULL, NULL, SW_SHOWDEFAULT);
        break;
    }
    case 122: {
        wstring z = dirs[10].toStdWString();
        const wchar_t *w = z.c_str();
        ShellExecute(NULL, L"open", w ,NULL, NULL, SW_SHOWDEFAULT);
        break;
    }
    case 123: {
        wstring z = dirs[11].toStdWString();
        const wchar_t *w = z.c_str();
        ShellExecute(NULL, L"open", w ,NULL, NULL, SW_SHOWDEFAULT);
        break;
    }
    };
}



void MainWindow::on_F1_clicked() //Если кликнута визуальная кнопка в менюшке, то открываем проводник и выбираем приложение, на открытие которого переназначим соответвующую кнопку
{
    dirs[0] = QFileDialog::getOpenFileName(this, QString("Открыть файл"), QDir::currentPath(), "Text (*.txt);All files (*.*)");
    ui->F1_dir->setText(dirs[0]);
}

//при нажатии на кнопку загрузки настроек, будет предложено откуда грузить, файл должен быть текстовым содержанием:
//Путь к файлу
//Путь к файлу
//..ещё 9 путей к файлу
//Путь к файлу
//Итого - 12 путей к файлу, каждый на новой строке.
//Безопаснее всего заполнить через менюшку - нажимая на кнопки, а потом сохраняя в файл по кнопке сохранить настройки в файл.
//set ui->F1_dir->setText(dirs[0]) - заполняют тексты после соответствующих кнопок, чисто для визуала
void MainWindow::on_getFile_clicked()
{
    QString dir = QFileDialog::getOpenFileName(this, QString("Открыть файл"), QDir::currentPath(), "Text (*.txt);All files (*.*)");
    ifstream file(dir.toStdString());
    if (file.is_open()) {
    string str;
    for (int i = 0; i < 12; i++) {
      getline(file, str);
      dirs[i] = QString::fromStdString(str);
    }
    file.close();
    ui->F1_dir->setText(dirs[0]);
    ui->F2_dir->setText(dirs[1]);
    ui->F3_dir->setText(dirs[2]);
    ui->F4_dir->setText(dirs[3]);
    ui->F5_dir->setText(dirs[4]);
    ui->F6_dir->setText(dirs[5]);
    ui->F7_dir->setText(dirs[6]);
    ui->F8_dir->setText(dirs[7]);
    ui->F9_dir->setText(dirs[8]);
    ui->F10_dir->setText(dirs[9]);
    ui->F11_dir->setText(dirs[10]);
    ui->F12_dir->setText(dirs[11]);
    }
}

void MainWindow::on_F2_clicked()
{
    dirs[1] = QFileDialog::getOpenFileName(this, QString("Открыть файл"), QDir::currentPath(), "Text (*.txt);All files (*.*)");
    ui->F2_dir->setText(dirs[1]);
}

void MainWindow::on_F3_clicked()
{
    dirs[2] = QFileDialog::getOpenFileName(this, QString("Открыть файл"), QDir::currentPath(), "Text (*.txt);All files (*.*)");
    ui->F3_dir->setText(dirs[2]);
}

void MainWindow::on_F4_clicked()
{
    dirs[3] = QFileDialog::getOpenFileName(this, QString("Открыть файл"), QDir::currentPath(), "Text (*.txt);All files (*.*)");
    ui->F4_dir->setText(dirs[3]);
}

void MainWindow::on_F5_clicked()
{
    dirs[4] = QFileDialog::getOpenFileName(this, QString("Открыть файл"), QDir::currentPath(), "Text (*.txt);All files (*.*)");
    ui->F5_dir->setText(dirs[4]);
}

void MainWindow::on_F6_clicked()
{
    dirs[5] = QFileDialog::getOpenFileName(this, QString("Открыть файл"), QDir::currentPath(), "Text (*.txt);All files (*.*)");
    ui->F6_dir->setText(dirs[5]);
}

void MainWindow::on_F7_clicked()
{
    dirs[6] = QFileDialog::getOpenFileName(this, QString("Открыть файл"), QDir::currentPath(), "Text (*.txt);All files (*.*)");
    ui->F7_dir->setText(dirs[6]);
}

void MainWindow::on_F8_clicked()
{
    dirs[7] = QFileDialog::getOpenFileName(this, QString("Открыть файл"), QDir::currentPath(), "Text (*.txt);All files (*.*)");
    ui->F8_dir->setText(dirs[7]);
}

void MainWindow::on_F9_clicked()
{
    dirs[8] = QFileDialog::getOpenFileName(this, QString("Открыть файл"), QDir::currentPath(), "Text (*.txt);All files (*.*)");
    ui->F9_dir->setText(dirs[8]);
}

void MainWindow::on_F10_clicked()
{
    dirs[9] = QFileDialog::getOpenFileName(this, QString("Открыть файл"), QDir::currentPath(), "Text (*.txt);All files (*.*)");
    ui->F10_dir->setText(dirs[9]);
}

void MainWindow::on_F11_clicked()
{
    dirs[10] = QFileDialog::getOpenFileName(this, QString("Открыть файл"), QDir::currentPath(), "Text (*.txt);All files (*.*)");
    ui->F11_dir->setText(dirs[10]);
}

void MainWindow::on_F12_clicked()
{
    dirs[11] = QFileDialog::getOpenFileName(this, QString("Открыть файл"), QDir::currentPath(), "Text (*.txt);All files (*.*)");
    ui->F12_dir->setText(dirs[11]);
}


//Сохранение текущих настроек в файл - открывается менюшка с выбором файла
//Выбираем текстовый документ, в который хотим сохраниться
//Туда произойдёт сохранение текущих настроек
//QString dir - это строка, в которую запишется полный путь файла.
void MainWindow::on_saveButton_clicked()
{
    QString dir = QFileDialog::getOpenFileName(this, QString("Открыть файл"), QDir::currentPath(), "Text (*.txt);All files (*.*)");
    ofstream file(dir.toStdString());
    for (int i = 0; i < 12; i++) {
        file << dirs[i].toStdString() << '\n';
    }
}

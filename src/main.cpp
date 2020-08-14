/**
 * @file main.cpp
 * @author Linming Pan
 * @date 10.8.2020
 * @brief Example code to run simple QT
 *
 */

#include <QApplication>
#include <QMainWindow>

int main(int argc, char* argv[])
{
    // Start QT Application
    QApplication app(argc, argv);

    // Setup out example class
    QMainWindow* win = new QMainWindow();
    win->show();
    return app.exec();
}

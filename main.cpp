#include "fileanalyze.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileAnalyze w;
    w.show();

    return a.exec();
}

/********************************************************************************
** Form generated from reading UI file 'fileanalyze.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEANALYZE_H
#define UI_FILEANALYZE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileAnalyze
{
public:

    void setupUi(QWidget *FileAnalyze)
    {
        if (FileAnalyze->objectName().isEmpty())
            FileAnalyze->setObjectName(QString::fromUtf8("FileAnalyze"));
        FileAnalyze->resize(400, 300);

        retranslateUi(FileAnalyze);

        QMetaObject::connectSlotsByName(FileAnalyze);
    } // setupUi

    void retranslateUi(QWidget *FileAnalyze)
    {
        FileAnalyze->setWindowTitle(QCoreApplication::translate("FileAnalyze", "FileAnalyze", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileAnalyze: public Ui_FileAnalyze {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEANALYZE_H

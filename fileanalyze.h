#ifndef FILEANALYZE_H
#define FILEANALYZE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QPushButton>
#include <QGridLayout>
#include <QFileDialog>
#include <QTextEdit>
#include <QTableWidget>
#include <QFile>
#include <QHeaderView>

#include <fstream>

namespace Ui {
class FileAnalyze;
}

class FileAnalyze : public QWidget
{
    Q_OBJECT

public:
    explicit FileAnalyze(QWidget *parent = nullptr);
    ~FileAnalyze();

private:
    Ui::FileAnalyze *ui;

    void SetUI();
    QGridLayout* main_layout;

    QLabel* file;
    QLineEdit* file_input;
    QPushButton* file_btn;
    QString file_url;
    void GetFileUrl();

    QTableWidget* browser;

    typedef struct tagDetails
    {
        QByteArray file_detail;
        int64_t size=0;
        int page_pos=0;
        int page=0;
        const int page_size=256;
    }Details;

    Details details;
    QPushButton* next_page_btn;
    QPushButton* jump_btn;
    QLineEdit* jump_page_edit;
    QLabel* page_label;
    QPushButton* previous_page_btn;

    void ShowOnePage(QByteArray& data,const int page_pos);

public slots:
    void Analyze(const QString& file);
    void ShowPrePage()
    {
        if(details.page_pos!=1)
            --details.page_pos;
        ShowOnePage(details.file_detail,details.page_pos);
    }

    void ShowJumpPage()
    {
        QString pos=jump_page_edit->text();
        if(pos.toInt()>0&&pos.toInt()<=details.page)
        {
            details.page_pos=pos.toInt();
           ShowOnePage(details.file_detail,pos.toInt());
        }
    }
    void ShowNextPage()
    {
        if(details.page_pos!=details.page)
            ++details.page_pos;
        ShowOnePage(details.file_detail,details.page_pos);
    }
};

#endif // FILEANALYZE_H

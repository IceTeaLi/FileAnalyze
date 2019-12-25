#include "fileanalyze.h"
#include "ui_fileanalyze.h"

FileAnalyze::FileAnalyze(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileAnalyze)
{
    ui->setupUi(this);
    SetUI();
}

FileAnalyze::~FileAnalyze()
{
    delete ui;
}

void FileAnalyze::SetUI()
{
    this->main_layout=new QGridLayout(this);
    this->setLayout(main_layout);

    this->file=new QLabel(this);
    this->file->setText(QString("File"));
    this->file_input=new QLineEdit(this);
    this->file_btn=new QPushButton(this);
    this->file_btn->setText(QString("Choose"));
    main_layout->addWidget(file,0,0,1,1);
    main_layout->addWidget(file_input,0,1,1,3);
    main_layout->addWidget(file_btn,0,4,1,1);

    this->browser=new QTableWidget(this);
    main_layout->addWidget(browser,1,0,1,5);
    this->browser->setColumnCount(16);
    this->browser->setRowCount(16);
    this->browser->setHorizontalHeaderLabels(QStringList()<<"00"<<"01"<<"02"<<"03"<<"04"<<"05"<<"06"<<"07"<<"08"<<"09"<<"0A"
                         <<"0B"<<"0C"<<"0D"<<"0E"<<"0F");
    this->browser->setVerticalHeaderLabels(QStringList()<<"00"<<"10"<<"20"<<"30"<<"40"<<"50"<<"60"<<"70"<<"80"<<"90"<<"A0"
                         <<"B0"<<"C0"<<"D0"<<"E0"<<"F0");

    connect(file_btn,&QPushButton::clicked,this,&FileAnalyze::GetFileUrl);
    connect(file_input,SIGNAL(textChanged(const QString&)),this,SLOT(Analyze(const QString&)));

    next_page_btn=new QPushButton(this);
    next_page_btn->setText("next page");
    jump_btn=new QPushButton(this);
    jump_btn->setText("jump");
    jump_page_edit=new QLineEdit(this);
    jump_page_edit->setFixedSize(jump_btn->width(),jump_btn->height());
    jump_page_edit->setAlignment(Qt::AlignRight);
    previous_page_btn=new QPushButton(this);
    previous_page_btn->setText("previous page");
    page_label=new QLabel(this);
    page_label->setText(" \\ ");
    page_label->setAlignment(Qt::AlignHCenter);
    main_layout->addWidget(previous_page_btn,2,0,1,1);
    main_layout->addWidget(jump_page_edit,2,1,1,1);
    main_layout->addWidget(page_label,2,2,1,1);
    main_layout->addWidget(jump_btn,2,3,1,1);
    main_layout->addWidget(next_page_btn,2,4,1,1);


    connect(next_page_btn,&QPushButton::clicked,this,&FileAnalyze::ShowNextPage);
    connect(previous_page_btn,&QPushButton::clicked,this,&FileAnalyze::ShowPrePage);
    connect(jump_btn,&QPushButton::clicked,this,&FileAnalyze::ShowJumpPage);
}

void FileAnalyze::GetFileUrl()
{
    this->file_url=QFileDialog::getOpenFileName();
    this->file_input->setText(this->file_url);
}


void FileAnalyze::Analyze(const QString& file_url)
{

    QFile file(file_url);
    file.open(QIODevice::ReadOnly);
    details.file_detail=file.readAll();
    details.page=details.file_detail.size()/details.page_size;
    details.page_pos=1;
    ShowOnePage(details.file_detail,details.page_pos);

}



void FileAnalyze::ShowOnePage(QByteArray& data,const int page_pos)
{
    int real_pos=(page_pos-1)*256;
    for(int i=0;i<256;++i)
    {
        this->browser->setItem(i/16,i%16,new QTableWidgetItem(QString::number(static_cast<unsigned char>(data.at(real_pos+i))).sprintf("%02x",static_cast<unsigned char>(data.at(real_pos+i))).toUpper()));
    }
    this->jump_page_edit->setText(QString::number(details.page_pos));
    this->page_label->setText("\\"+QString::number(details.page));
}

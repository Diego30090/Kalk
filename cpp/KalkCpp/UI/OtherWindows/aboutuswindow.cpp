#include "aboutuswindow.h"
#include <QGridLayout>
#include "../calculatormaininterface.h"
#include "../Utils/imagelabel.h"
#include <iostream>
#include <QStyle>
#include <QDesktopWidget>
#include <QApplication>

AboutUsWindow::AboutUsWindow(QWidget *parent) : QWidget(parent)
{
    QGridLayout* layout = new QGridLayout(this);

    ImageLabel* icon = new ImageLabel("", ":/icons/program_icon", this, QSize(80, 80));

    QLabel* title = new QLabel("About us", this);
    QFont title_font = QFont(CalculatorMainInterface::PersonalFontName);
    title_font.setBold(true);
    title_font.setPointSize(12);
    title->setFont(title_font);

    QLabel* text = new QLabel("", this);
    text->setFont(QFont(CalculatorMainInterface::PersonalFontName, 10));
    text->setText("Kalk è stata creata da Francesco De Filippis e Michele Roverato per il progetto di P2 2017/2018 \n"
                  "Le immagini e le icone sono state prese da https://www.iconfinder.com/ e https://www.flaticon.com/ \n"
                  "Il font Roboto è stato preso da https://fonts.google.com/specimen/Roboto");

    std::string os = CalculatorMainInterface::osName();
    if(os=="linux" || os=="unix"){
        setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint); //block resize
        QSize size = QSize(width()+600, height()+200);
        setMinimumSize(size);
        setMaximumSize(size);
    }else{
        if(os=="windows"){
            setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint); //block resize
        }
    }

    layout->addWidget(icon, 1, 1, Qt::AlignCenter);
    layout->addWidget(title, 2, 1, Qt::AlignCenter);
    layout->addWidget(text, 3, 1, Qt::AlignCenter);

    setLayout(layout);

    //Adjust window size and position
    adjustSize();
    setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,size(),qApp->desktop()->availableGeometry()));
    setAttribute(Qt::WA_DeleteOnClose); //necessary do fully destroy the window when closed
    setWindowTitle("About us");
    setWindowIcon(QIcon(QPixmap(":/icons/about_icon")));
}

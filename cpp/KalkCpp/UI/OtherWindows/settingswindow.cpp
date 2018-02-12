#include "settingswindow.h"
#include <QGridLayout>
#include "../Utils/imagelabel.h"
#include "../calculatormaininterface.h"
#include <iostream>
#include <QStyle>
#include <QDesktopWidget>
#include <QApplication>

SettingsWindow::SettingsWindow(QWidget *parent) : QWidget(parent)
{
    QGridLayout* layout = new QGridLayout(this);

    QLabel* title = new QLabel("Impostazioni", this);
    QFont title_font = QFont(CalculatorMainInterface::PersonalFontName);
    title_font.setBold(true);
    title_font.setPointSize(10);
    title->setFont(title_font);

    QLabel* text = new QLabel("", this);
    text->setFont(QFont(CalculatorMainInterface::PersonalFontName,10));
    text->setText("Al momento sembra che non ci siano impostazioni disponibili... ¯\\_(ツ)_/¯ \nPerchè non ce ne consigli qualcuna?");

    std::string os = CalculatorMainInterface::osName();
    if(os=="linux" || os=="unix"){
        setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint); //block resize
        QSize size = QSize(width()+350, height()+100);
        setMinimumSize(size);
        setMaximumSize(size);
    }else{
        if(os=="windows"){
            setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint); //block resize
        }
    }
    layout->addWidget(title, 1, 1, Qt::AlignCenter);
    layout->addWidget(text, 2, 1, Qt::AlignCenter);
    setLayout(layout);

    //Adjust window size and position
    adjustSize();
    setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,size(),qApp->desktop()->availableGeometry()));
    setAttribute(Qt::WA_DeleteOnClose); //necessary do fully destroy the window when closed
    setWindowTitle("Impostazioni");
    setWindowIcon(QIcon(QPixmap(":/icons/settings_icon")));
}

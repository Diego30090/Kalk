#include "guidewindow.h"
#include <QGridLayout>
#include "../Utils/imagelabel.h"
#include "../calculatormaininterface.h"
#include <iostream>
#include <QStyle>
#include <QDesktopWidget>
#include <QApplication>

GuideWindow::GuideWindow(QWidget *parent) : QWidget(parent)
{
    QGridLayout* layout = new QGridLayout(this);

    QLabel* title = new QLabel("Guida", this);
    QFont title_font = QFont(CalculatorMainInterface::PersonalFontName);
    title_font.setBold(true);
    title_font.setPointSize(10);
    title->setFont(title_font);

    QLabel* text = new QLabel("", this);
    text->setFont(QFont(CalculatorMainInterface::PersonalFontName, 10));
    text->setText("Questa calcolatrice geometrica consente di fare operazioni tra forme geometriche 2D o 3D. \n"
                  "Per iniziare scegli una forma, ed inserisci i dati per impostarla come primo operando dell'operazione; \n"
                  "La seconda forma che creerai sarà utilizzata come secondo operando dell'operazione, \n a questo punto "
                  "dopo aver scelto un operatore potrai svolgere l'operazione. Per ricominciare da capo puoi utilizzare il tasto \"Cancella\"."
                  "\n Se invece creerai un'altra figura, sarà utilizzata come primo operando, sostituendo quello precedente, lo stesso vale per il secondo operando."
                  "\n Nel caso delle figure 2D, puoi anche visualizzare (e traslare) la tua figura nel piano cartesiano, ti basta andare nella scheda \"2D Draw\".");

    std::string os = CalculatorMainInterface::osName();
    if(os=="linux" || os=="unix"){
        setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint); //block resize
        QSize size = QSize(width()+800, height()+120);
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
    setWindowTitle("Guida");
    setWindowIcon(QIcon(QPixmap(":/icons/guide_icon")));
}

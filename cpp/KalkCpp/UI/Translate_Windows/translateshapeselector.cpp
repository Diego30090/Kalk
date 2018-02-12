#include "translateshapeselector.h"
#include "UI/calculatormaininterface.h"
#include <QLabel>
#include <QToolButton>
#include <QStyle>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QApplication>

TranslateShapeSelector::TranslateShapeSelector(QWidget *parent, CalculatorInterface2D* c) : QWidget(parent), interf(c)
{
    QGridLayout* mainLayout = new QGridLayout(this);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    QLabel* title = new QLabel ("Scegli la figura da traslare", this);
    QFont title_font = CalculatorMainInterface::getMainFont();
    title_font.setBold(true);
    title_font.setPointSize(10);
    title->setFont(title_font);

    QToolButton* button_operator1 = new QToolButton(this);
    button_operator1->setMinimumSize(50,30);
    button_operator1->setText("Figura 1");
    button_operator1->setFont(CalculatorMainInterface::getMainFont());
    if(!c->viewOperator1){
        button_operator1->setEnabled(false);
    }else{
        button_operator1->setText(QString::fromStdString("Figura 1 - "+c->viewOperator1->getController()->getModel()->getName()));
    }

    QToolButton* button_operator2 = new QToolButton(this);
    button_operator2->setMinimumSize(50,30);
    button_operator2->setText("Figura 2");
    button_operator2->setFont(CalculatorMainInterface::getMainFont());
    if(!c->viewOperator2){
        button_operator2->setEnabled(false);
    }else{
        button_operator2->setText(QString::fromStdString("Figura 2 - "+c->viewOperator2->getController()->getModel()->getName()));
    }

    QToolButton* button_result = new QToolButton(this);
    button_result->setMinimumSize(50,30);
    button_result->setText("Figura Risultato");
    button_result->setFont(CalculatorMainInterface::getMainFont());
    if(!c->viewResult){
        button_result->setEnabled(false);
    }else{
        button_result->setText(QString::fromStdString("Figura Risultato - "+c->viewResult->getController()->getModel()->getName()));
    }

    QToolButton* cancel = new QToolButton(this);
    cancel->setMinimumSize(50,30);
    cancel->setText("Annulla");
    cancel->setFont(CalculatorMainInterface::getMainFont());

    connect(button_operator1, SIGNAL (released()), this, SLOT (Operator1()));
    connect(button_operator2, SIGNAL (released()), this, SLOT (Operator2()));
    connect(button_result, SIGNAL (released()), this, SLOT (ShapeResult()));
    connect(cancel, SIGNAL (released()), this, SLOT (Close()));

    mainLayout->addWidget(title, 1, 1, 1,3, Qt::AlignCenter);
    mainLayout->addWidget(button_operator1, 2, 1, Qt::AlignCenter);
    mainLayout->addWidget(button_operator2, 2, 2, Qt::AlignCenter);
    mainLayout->addWidget(button_result, 2, 3, Qt::AlignCenter);
    mainLayout->addWidget(cancel, 3, 1, 1, 3, Qt::AlignCenter);

    std::string os = CalculatorMainInterface::osName();
    if(os=="linux" || os=="unix"){
        setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint); //block resize
        QSize size = QSize(width()+100, height()+80);
        setMinimumSize(size);
        setMaximumSize(size);
    }else{
        if(os=="windows"){
            setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint); //block resize
        }else{
            CalculatorMainInterface::PrintLog("TranslateShapeSelector - OS UNKNOWN");
        }
    }
    setWindowIcon(QIcon(QPixmap(":/icons/create_icon")));
    setWindowTitle("Trasla una figura");
    setLayout(mainLayout);
    setAttribute(Qt::WA_DeleteOnClose); //necessary do fully destroy the window when closed
    //Adjust window size and position
    adjustSize();
    setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,size(),qApp->desktop()->availableGeometry()));
}

void TranslateShapeSelector::ShowConversionErrorDialog(const QString& error_message)
{
    QMessageBox messageBox;
    messageBox.critical(this,"Error",error_message);
}

void TranslateShapeSelector::Operator1()
{
    if(interf->viewOperator1){ //To be sure
        interf->viewOperator1->CreateTranslateWindow();
    }else{
        CalculatorMainInterface::PrintLog("TranslateShapeSelector - Shape View has been deleted");
        ShowConversionErrorDialog("Sembra che tu abbia cancellato questa figura, per favore riapri la finestra di Traslazione");
    }
    close();
}
void TranslateShapeSelector::Operator2()
{
    if(interf->viewOperator2){ //To be sure
        interf->viewOperator2->CreateTranslateWindow();
    }else{
        CalculatorMainInterface::PrintLog("TranslateShapeSelector - Shape View has been deleted");
        ShowConversionErrorDialog("Sembra che tu abbia cancellato questa figura, per favore riapri la finestra di Traslazione");
    }
    close();
}
void TranslateShapeSelector::ShapeResult()
{
    if(interf->viewResult){ //To be sure
        interf->viewResult->CreateTranslateWindow();
    }else{
        CalculatorMainInterface::PrintLog("TranslateShapeSelector - Shape View has been deleted");
        ShowConversionErrorDialog("Sembra che tu abbia cancellato questa figura, per favore riapri la finestra di Traslazione");
    }
    close();
}
void TranslateShapeSelector::Close()
{
    close();
}

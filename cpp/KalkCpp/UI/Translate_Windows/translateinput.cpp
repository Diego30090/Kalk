#include "translateinput.h"
#include <QLabel>
#include <QToolButton>
#include <QStyle>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QApplication>
#include "UI/calculatormaininterface.h"

TranslateInput::TranslateInput(QWidget *parent, Shape2DView* w) : QWidget(parent), invoke_view(w)
{
    mainLayout = new QGridLayout(this);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    QLabel* title = new QLabel ("Trasla la figura", this);
    QFont title_font = CalculatorMainInterface::getMainFont();
    title_font.setBold(true);
    title_font.setPointSize(10);
    title->setFont(title_font);

    QLabel* info = new QLabel ("Inserisci il vettore di Traslazione", this);
    info->setFont(CalculatorMainInterface::getMainFont());

    QLabel* x_label = new QLabel ("X", this);
    x_label->setFont(CalculatorMainInterface::getMainFont());
    QLabel* y_label = new QLabel ("Y", this);
    y_label->setFont(CalculatorMainInterface::getMainFont());

    x_value = new QLineEdit(this);
    x_value->setFocus();
    x_value->setFont(CalculatorMainInterface::getMainFont());

    y_value = new QLineEdit(this);
    y_value->setFont(CalculatorMainInterface::getMainFont());

    QToolButton* cancel = new QToolButton(this);
    cancel->setMinimumSize(50,30);
    cancel->setText("Annulla");
    cancel->setFont(CalculatorMainInterface::getMainFont());

    QToolButton* confirm = new QToolButton(this);
    confirm->setMinimumSize(50,30);
    confirm->setText("Conferma");
    confirm->setFont(CalculatorMainInterface::getMainFont());

    connect(cancel, SIGNAL (released()), this, SLOT (Cancel()));
    connect(confirm, SIGNAL (released()), this, SLOT (Confirm()));

    mainLayout->addWidget(title, 1, 1, 1,2, Qt::AlignCenter);
    mainLayout->addWidget(info, 2, 1, 1,2, Qt::AlignCenter);
    mainLayout->addWidget(x_label, 3, 1, Qt::AlignCenter);
    mainLayout->addWidget(y_label, 3, 2, Qt::AlignCenter);
    mainLayout->addWidget(x_value, 4, 1, Qt::AlignCenter);
    mainLayout->addWidget(y_value, 4, 2, Qt::AlignCenter);
    mainLayout->addWidget(cancel, 5, 1, Qt::AlignCenter);
    mainLayout->addWidget(confirm, 5, 2, Qt::AlignCenter);

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
            CalculatorMainInterface::PrintLog("TranslateInput - OS UNKNOWN");
        }
    }
    setWindowIcon(QIcon(QPixmap(":/icons/create_icon")));
    setWindowTitle("Trasla una figura");
    setLayout(mainLayout);
    //This is not necessary here, this window is deleted by the Shape2DView invoke window
    //setAttribute(Qt::WA_DeleteOnClose); //REMEMBER TO UNCOMMENT THIS IF YOU DON'T MANAGE IT, OR YOU'LL CREATE GARBAGE
    //Adjust window size and position
    adjustSize();
    setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,size(),qApp->desktop()->availableGeometry()));
}

void TranslateInput::ShowConversionErrorDialog(const QString& error_message)
{
    QMessageBox messageBox;
    messageBox.critical(this,"Error",error_message);
}

void TranslateInput::Confirm()
{
    if(invoke_view){
        bool check_conversion;
        x_value->text().toDouble(&check_conversion);
        y_value->text().toDouble(&check_conversion);
        if(check_conversion){
            invoke_view->ReceiveTranslateData(Point2D(x_value->text().toDouble(), y_value->text().toDouble()));
            close();
        }else{
            ShowConversionErrorDialog("Uno dei due valori che hai inserito non è corretto, per favore controlla");
        }
    }else{
        CalculatorMainInterface::PrintLog("TranslateInput - Shape View has been deleted");
        ShowConversionErrorDialog("Sembra che la figura che stai cercando di traslare sia stata cancellata, per favore riprova");
        close();
    }
}
void TranslateInput::Cancel()
{
    close();
}

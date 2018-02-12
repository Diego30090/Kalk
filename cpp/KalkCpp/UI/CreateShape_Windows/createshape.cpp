#include "createshape.h"
#include "../Utils/imagelabel.h"
#include <iostream>
#include <QStyle>
#include <QColorDialog>
#include <QMessageBox>
#include <QStyle>
#include <QDesktopWidget>
#include <QApplication>

CreateShape::CreateShape(QWidget *parent, const QString& shape_image, const QString& title_string) : QWidget(parent)
{

    mainLayout = new QGridLayout(this);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    ImageLabel* img_shape = new ImageLabel("", shape_image,this, QSize(64,64));

    QLabel* title = new QLabel (title_string, this);
    QFont title_font = CalculatorMainInterface::getMainFont();
    title_font.setBold(true);
    title_font.setPointSize(10);
    title->setFont(title_font);

    mainLayout->addWidget(title, 1, 1, 1,2, Qt::AlignCenter);
    mainLayout->addWidget(img_shape, 2, 1, 1,2, Qt::AlignCenter);

    chooseColor = new QToolButton(this);
    chooseColor->setMinimumSize(50,30);
    chooseColor->setText("Scegli Colore");
    colorDisplay= new QLabel("\t\t\t",this);
    chooseColor->setFont(CalculatorMainInterface::getMainFont());
    connect(chooseColor, SIGNAL (released()), this, SLOT (SelectAnotherColor()));
    current_color = new QLabel(this);
    QFont color_font = CalculatorMainInterface::getMainFont();
    color_font.setBold(true);
    color = QColor(0,0,0);
    std::string colorString = "Colore Figura: ("+std::to_string(color.red())+","+std::to_string(color.green())+","+std::to_string(color.blue())+")";
    current_color->setText(QString::fromStdString(colorString));
    current_color->setFont(color_font);

    mainLayout->addWidget(current_color, 3, 1, Qt::AlignCenter);
    mainLayout->addWidget(chooseColor, 3, 2,Qt::AlignCenter);
    mainLayout->addWidget(colorDisplay, 4, 1, 1, 2, Qt::AlignCenter);

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
            CalculatorMainInterface::PrintLog("CreateShapeWIndow - OS UNKNOWN");
        }
    }

    lastRowUsed = 4;
    UpdateColorDisplay();
    setWindowIcon(QIcon(QPixmap(":/icons/create_icon")));
    setWindowTitle("Crea una nuova figura");
    setLayout(mainLayout);
    //Adjust window size and position
    adjustSize();
    setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,size(),qApp->desktop()->availableGeometry()));
}

CreateShape::~CreateShape()
{

}

void CreateShape::CreateConfirmAndCancelButton(int row, int colum)
{
    if(row==-1){
        lastRowUsed++;
        row=lastRowUsed;
    }
    confirm = new QToolButton(this);
    confirm->setMinimumSize(50,30);
    confirm->setText("Conferma");
    confirm->setFont(CalculatorMainInterface::getMainFont());
    cancel = new QToolButton(this);
    cancel->setMinimumSize(50,30);
    cancel->setText("Annulla");
    cancel->setFont(CalculatorMainInterface::getMainFont());
    mainLayout->addWidget(confirm, row, colum, Qt::AlignRight);
    mainLayout->addWidget(cancel, row, colum+1, Qt::AlignLeft);
    //Direct connect to the virtual slot
    connect(confirm, SIGNAL (released()), this, SLOT (Confirm()));
}

void CreateShape::SelectAnotherColor()
{
    color = QColorDialog::getColor(color, this);
    if(color.isValid()){
        std::string colorString = "Colore Figura: ("+std::to_string(color.red())+","+std::to_string(color.green())+","+std::to_string(color.blue())+")";
        current_color->setText(QString::fromStdString(colorString));
        UpdateColorDisplay();
    }
}

void CreateShape::UpdateColorDisplay()
{
    QPalette palette = colorDisplay->palette();
    palette.setColor(colorDisplay->backgroundRole(), color);
    colorDisplay->setPalette(palette);
    colorDisplay->setAutoFillBackground(true);
    colorDisplay->update();
}

void CreateShape::AddWidgetInThisRow(QWidget* w, int colum, int rowspan, int columspan)
{
    mainLayout->addWidget(w, lastRowUsed, colum, rowspan, columspan, Qt::AlignCenter);
}

void CreateShape::AddWidgetUnder(QWidget* w, int colum, int rowspan, int columspan)
{
    lastRowUsed++;
    AddWidgetInThisRow(w, colum, rowspan, columspan);
}

void CreateShape::SetDefaultCancelAction()
{
    if(cancel){
        connect(cancel, SIGNAL (released()), this, SLOT (Cancel()));
    }
    //This is controlled by the invoke window
    //REMEMBER TO UNCOMMENT THIS IF YOU DON'T MANAGE IT, OR YOU'LL CREATE GARBAGE
    //setAttribute(Qt::WA_DeleteOnClose); //necessary do fully destroy the window when closed
}

void CreateShape::Cancel()
{
    close();
}

QToolButton* CreateShape::get_confirm_button() const
{
    return confirm;
}
QToolButton* CreateShape::get_cancel_button() const
{
    return cancel;
}

QColor CreateShape::getColor() const
{
    return color;
}

void CreateShape::ShowConversionErrorDialog(const QString& error_message)
{
    QMessageBox messageBox;
    messageBox.critical(this,"Error",error_message);
}

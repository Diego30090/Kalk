#include "moreinfoshape.h"
#include <QStyle>
#include "../Utils/imagelabel.h"
#include <iostream>
#include <QStyle>
#include <QDesktopWidget>
#include <QApplication>

MoreInfoShape::MoreInfoShape(QWidget *parent, const QString& shape_image, const QString& title_string) : QWidget(parent)
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

    color = new QLabel("Colore Figura: (0,0,0,0)", this);
    QFont color_font = CalculatorMainInterface::getMainFont();
    color_font.setBold(true);
    color->setFont(color_font);
    color_display= new QLabel("\t\t",this);
    mainLayout->addWidget(color, 3 , 1, Qt::AlignCenter);
    mainLayout->addWidget(color_display, 3 , 2, Qt::AlignCenter);

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
            CalculatorMainInterface::PrintLog("AboutShapeWindow - OS UNKNOWN");
        }
    }

    lastRowUsed = 4;
    setWindowIcon(QIcon(QPixmap(":/icons/create_icon")));
    setWindowTitle("Informazioni sulla figura");
    setLayout(mainLayout);
    //Adjust window size and position
    adjustSize();
    setGeometry(QStyle::alignedRect(Qt::LeftToRight,Qt::AlignCenter,size(),qApp->desktop()->availableGeometry()));
}

MoreInfoShape::~MoreInfoShape()
{

}

void MoreInfoShape::AddWidgetInThisRow(QWidget* w, int colum, int rowspan, int columspan)
{
    mainLayout->addWidget(w, lastRowUsed, colum, rowspan, columspan, Qt::AlignCenter);
}

void MoreInfoShape::AddWidgetUnder(QWidget* w, int colum, int rowspan, int columspan)
{
    lastRowUsed++;
    AddWidgetInThisRow(w, colum, rowspan, columspan);
}

void MoreInfoShape::SetShapeColorInfo(const QColor& c)
{
    color->setText(QString::fromStdString("Colore Figura: (" + std::to_string(c.red()) + "," + std::to_string(c.green()) + "," + std::to_string(c.blue()) + ")"));
    QPalette palette = color_display->palette();
    palette.setColor(color_display->backgroundRole(), c);
    color_display->setPalette(palette);
    color_display->setAutoFillBackground(true);
    color_display->update();
}

void MoreInfoShape::setColor(const ColorRGB* c)
{
    SetShapeColorInfo(QColor(c->getRed(), c->getGreen(), c->getBlue()));
}

void MoreInfoShape::CreateCancelButton(int row, int colum)
{
    if(row==-1){
        lastRowUsed++;
        row=lastRowUsed;
    }
    cancel = new QToolButton(this);
    cancel->setMinimumSize(50,30);
    cancel->setText("Chiudi");
    cancel->setFont(CalculatorMainInterface::getMainFont());
    mainLayout->addWidget(cancel, row, colum, Qt::AlignLeft);
}

void MoreInfoShape::SetDefaultCancelAction()
{
    if(cancel){
        connect(cancel, SIGNAL (released()), this, SLOT (Cancel()));
    }
    setAttribute(Qt::WA_DeleteOnClose); //necessary do fully destroy the window when closed
}

void MoreInfoShape::Cancel()
{
    close();
}

QToolButton* MoreInfoShape::get_cancel_button() const
{
    return cancel;
}


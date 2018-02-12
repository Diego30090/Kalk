#include "calcbutton.h"
#include "UI/calculatormaininterface.h"

CalcButton::CalcButton(const QString &text, const QString &ImagePath,QWidget *parent, const QSize& size) : QToolButton(parent)
{
    setText(text);
    setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    pixmap_ref = new QPixmap (ImagePath);
    QIcon button_icon = QIcon(*pixmap_ref);
    setIcon(button_icon);
    if(size.width()==-1 || size.width()==-1){
        setIconSize(pixmap_ref->rect().size());
    }else{
        setIconSize(size);
    }

    setFont(CalculatorMainInterface::getMainFont());
}

CalcButton::CalcButton(const QString &ImagePath, QWidget *parent, const QSize& size) : QToolButton(parent){
    pixmap_ref = new QPixmap (ImagePath);
    QIcon button_icon = QIcon(*pixmap_ref);
    setIcon(button_icon);
    if(size.width()==-1 || size.width()==-1){
        setIconSize(pixmap_ref->rect().size());
    }else{
        setIconSize(size);
    }

    setFont(CalculatorMainInterface::getMainFont());
}

CalcButton::~CalcButton()
{
    delete pixmap_ref;
}

void CalcButton::resize_icon(const QSize& size)
{
    setIconSize(size);
}

void CalcButton::update_icon(const QString &ImagePath, const QSize& size)
{
    pixmap_ref = new QPixmap (ImagePath);
    QIcon button_icon = QIcon(*pixmap_ref);
    setIcon(button_icon);
    if(size.width()==-1 || size.width()==-1){
        setIconSize(pixmap_ref->rect().size());
    }else{
        setIconSize(size);
    }
}

QPixmap* CalcButton::getPixmapRef() const
{
    return pixmap_ref;
}

void CalcButton::update_icon(const QPixmap* PixmapRef, const QSize& size)
{
    delete pixmap_ref;
    pixmap_ref = new QPixmap (*PixmapRef);
    QIcon button_icon = QIcon(*pixmap_ref);
    setIcon(button_icon);
    if(size.width()==-1 || size.width()==-1){
        setIconSize(pixmap_ref->rect().size());
    }else{
        setIconSize(size);
    }
}

CalcButton::CalcButton(const QString &text, QWidget *parent) : QToolButton(parent)
{
    setText(text);
}



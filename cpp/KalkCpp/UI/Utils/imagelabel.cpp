#include "imagelabel.h"
#include "UI/calculatormaininterface.h"

ImageLabel::ImageLabel(const QString &text, const QString &ImagePath, QWidget *parent, const QSize& size): QLabel(text, parent)
{
    if(ImagePath!=""){
        img_path = ImagePath.toStdString();
        if(size.width()!=-1 && size.width()!=-1){ //non funziona per ora
            QPixmap image = QPixmap(ImagePath).scaled(size);
            setPixmap(image);
        }else{
            setPixmap(QPixmap(ImagePath));
        }
    }
    setFont(QFont(CalculatorMainInterface::PersonalFontName));
}

void ImageLabel::change_image(const QString &ImagePath, const QSize& size)
{
    if(ImagePath!=""){
        img_path = ImagePath.toStdString();
        if(size.width()!=-1 && size.width()!=-1){ //non funziona per ora
            QPixmap image = QPixmap(ImagePath).scaled(size);
            setPixmap(image);
        }else{
            setPixmap(QPixmap(ImagePath));
        }
    }
}

void ImageLabel::change_image(const QPixmap &Image, const QSize& size)
{
    if(size.width()!=-1 && size.width()!=-1){ //non funziona per ora
        QPixmap current_image = QPixmap(Image).scaled(size);
        setPixmap(current_image);
    }else{
        setPixmap(QPixmap(Image));
    }
}

std::string ImageLabel::GetImagePathString() const
{
    return img_path;
}

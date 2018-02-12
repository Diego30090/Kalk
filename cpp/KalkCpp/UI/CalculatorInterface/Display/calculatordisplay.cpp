#include "calculatordisplay.h"
#include "UI/calculatormaininterface.h"
#include <QGridLayout>

CalculatorDisplay::CalculatorDisplay(QWidget *parent) : QWidget(parent)
{
    QGridLayout* mainLayout = new QGridLayout(this);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    img_operator1 = new ImageLabel("Prova1", ":others/new_shape",this, QSize(64,64));
    label_operator1 = new QLabel("Nome Figura 1",this);
    label_operator1->setFont(QFont(CalculatorMainInterface::PersonalFontName));
    OpenMore_operator1 = new CalcButton("Altre info", "", this, QSize(10,10));
    OpenMore_operator1->setMaximumSize(QSize(70,30));
    mainLayout->addWidget(img_operator1, 1, 1, Qt::AlignCenter);
    mainLayout->addWidget(label_operator1, 2, 1, Qt::AlignCenter);
    mainLayout->addWidget(OpenMore_operator1, 3,1, Qt::AlignCenter);

    img_method = new ImageLabel("", ":others/unknown",this, QSize(42,42));
    mainLayout->addWidget(img_method, 1,2, Qt::AlignCenter);

    img_operator2 = new ImageLabel("", ":others/new_shape", this, QSize(64,64));
    label_operator2 = new QLabel("Nome Figura 2",this);
    label_operator2->setFont(QFont(CalculatorMainInterface::PersonalFontName));
    OpenMore_operator2 = new CalcButton("Altre info", "", this, QSize(10,10));
    OpenMore_operator2->setMaximumSize(QSize(70,30));
    mainLayout->addWidget(img_operator2, 1, 3, Qt::AlignCenter);
    mainLayout->addWidget(label_operator2, 2, 3, Qt::AlignCenter);
    mainLayout->addWidget(OpenMore_operator2, 3,3, Qt::AlignCenter);

    ImageLabel* imageLabel4 = new ImageLabel("", ":/operations/equal",this, QSize(42,42));
    mainLayout->addWidget(imageLabel4, 1, 4, Qt::AlignCenter);

    ris_image = new ImageLabel("Prova1", ":others/unknown",this, QSize(64,64));
    label_ris = new QLabel("Nome Figura Risultato",this);
    label_ris->setFont(QFont(CalculatorMainInterface::PersonalFontName));
    OpenMore_result = new CalcButton("Altre info", "", this, QSize(10,10));
    OpenMore_result->setMaximumSize(QSize(70,30));
    mainLayout->addWidget(ris_image, 1, 5, Qt::AlignCenter);
    mainLayout->addWidget(label_ris, 2, 5, Qt::AlignCenter);
    mainLayout->addWidget(OpenMore_result, 3, 5, Qt::AlignCenter);

    OpenMore_operator1->setEnabled(false); //DA TOGLIERE
    OpenMore_operator2->setEnabled(false);
    OpenMore_result->setEnabled(false);

    setLayout(mainLayout);
}

ImageLabel* CalculatorDisplay::get_img_operator1() const
{
    return img_operator1;
}
ImageLabel* CalculatorDisplay::get_img_operator2() const
{
    return img_operator2;
}
ImageLabel* CalculatorDisplay::get_img_result() const
{
    return ris_image;
}

QLabel* CalculatorDisplay::get_label_operator1() const
{
    return label_operator1;
}
QLabel* CalculatorDisplay::get_label_operator2() const
{
    return label_operator2;
}
QLabel* CalculatorDisplay::get_label_ris() const
{
    return label_ris;
}

ImageLabel* CalculatorDisplay::get_img_method() const
{
    return img_method;
}

CalcButton* CalculatorDisplay::get_Button_OpenMore_operator1() const
{
    return OpenMore_operator1;
}
CalcButton* CalculatorDisplay::get_Button_OpenMore_operator2() const
{
    return OpenMore_operator2;
}
CalcButton* CalculatorDisplay::get_Button_OpenMore_result() const
{
    return OpenMore_result;
}
void CalculatorDisplay::ClearOperator1() const
{
    img_operator1->change_image(":others/new_shape");
    label_operator1->setText("Nome Figura 1");
    OpenMore_operator1->setEnabled(false);
}

void CalculatorDisplay::ClearOperator2() const
{
    img_operator2->change_image(":others/new_shape");
    label_operator2->setText("Nome Figura 2");
    OpenMore_operator2->setEnabled(false);
}

void CalculatorDisplay::ClearResult() const
{
    ris_image->change_image(":others/unknown", QSize(64,64));
    label_ris->setText("Nome Figura Risultato");
    OpenMore_result->setEnabled(false);
}

void CalculatorDisplay::ClearMathOperator() const
{
    img_method->change_image(":others/unknown", QSize(42,42));
}


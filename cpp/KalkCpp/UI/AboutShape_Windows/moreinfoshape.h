#ifndef MOREINFOSHAPE_H
#define MOREINFOSHAPE_H

#include <QWidget>
#include <QGridLayout>
#include <QToolButton>
#include <QLabel>
#include "../calculatormaininterface.h"
#include "Color/colorrgb.h"

/**
 * @brief The MoreInfoShape class is a base Window made for showing the info about a Shape:
 * It already contains the image and the color for the shape, all the others things will be added by extensions of this base class.
 */
class MoreInfoShape : public QWidget
{
    Q_OBJECT
public:
    MoreInfoShape(QWidget *parent = nullptr, const QString& shape_image="", const QString& title_string = "Altre Informazioni");

    virtual ~MoreInfoShape()=0;

    QToolButton* get_cancel_button() const;

    void SetShapeColorInfo(const QColor&);
    void setColor(const ColorRGB* c);

protected:
    void CreateCancelButton(int row = -1, int colum = 1);
    void SetDefaultCancelAction();

    void AddWidgetInThisRow(QWidget* w, int colum, int rowspan = 1, int columspan=1);
    void AddWidgetUnder(QWidget* w, int colum, int rowspan = 1, int columspan=1);
private:
    QGridLayout* mainLayout = nullptr;

    QLabel* color;
    QLabel* color_display;

    QToolButton *cancel = nullptr;

    int lastRowUsed=0;
private slots:
    void Cancel();
};

#endif // MOREINFOSHAPE_H

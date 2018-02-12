#ifndef TRANSLATEINPUT_H
#define TRANSLATEINPUT_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include "View/Shape2DView/shape2dview.h"

class Shape2DView;

/**
 * @brief The TranslateInput class is a little window to let the user insert the X-Y coordinates to translate a shape
 * If the coordinates are valid, it call invoke_view->ReceiveTranslateData(...) to update the shape position
 */
class TranslateInput : public QWidget
{
    Q_OBJECT
public:
    TranslateInput(QWidget *parent = nullptr, Shape2DView* = nullptr);
private:
    QGridLayout* mainLayout = nullptr;

    Shape2DView* invoke_view;

    QLineEdit* x_value, *y_value;

    void ShowConversionErrorDialog(const QString& error_message);
private slots:
    void Confirm();
    void Cancel();
};

#endif // TRANSLATEINPUT_H

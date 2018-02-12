#ifndef CREATESHAPE_H
#define CREATESHAPE_H

#include <QWidget>
#include <QGridLayout>
#include <QToolButton>
#include "../calculatormaininterface.h"
#include "../Utils/imagelabel.h"

/**
 * @brief The CreateShape class is a base Window made for inserting the info to create a new Shape:
 * It already contains the image and the color chooser for the shape, all the others things will be added by extensions of this base class.
 * This base Window contains also an useful dialog to show in case of error.
 */
class CreateShape : public QWidget
{
    Q_OBJECT

public:
    CreateShape(QWidget *parent = nullptr, const QString& shape_image="", const QString& title_string = "CREATE A SHAPE");

    virtual ~CreateShape()=0;

    QToolButton* get_confirm_button() const;
    QToolButton* get_cancel_button() const;

protected:

    QColor getColor() const;

    void CreateConfirmAndCancelButton(int row = -1, int colum = 1);
    void SetDefaultCancelAction();

    void AddWidgetInThisRow(QWidget* w, int colum, int rowspan = 1, int columspan=1);
    void AddWidgetUnder(QWidget* w, int colum, int rowspan = 1, int columspan=1);

    void ShowConversionErrorDialog(const QString& error_message = "Si è verificato un errore nell'inserimento dei dati\nPer favore controlla che i dati inseriti siano validi.");
private:
    QGridLayout* mainLayout = nullptr;

    QToolButton* chooseColor;
    QLabel* current_color;
    QLabel* colorDisplay;
    void UpdateColorDisplay();

    QToolButton* confirm = nullptr, *cancel = nullptr;

    QColor color;

    int lastRowUsed=0;
private slots:
    virtual void Confirm()=0;
    void Cancel();
    void SelectAnotherColor();
};

#endif // CREATESHAPE_H

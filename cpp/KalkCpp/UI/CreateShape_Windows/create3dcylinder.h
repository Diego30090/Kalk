#ifndef CREATE3DCYLINDER_H
#define CREATE3DCYLINDER_H

#include "createshape.h"
#include "View/Shape3DView/cylinderview.h"
#include <QLineEdit>

class CylinderView;

/**
 * @brief The Create3DCylinder class is an Extension of CreateShape, it contains the QLineEdit to insert the vaules of the new 3DCylinder.
 * The values insered will be sent to CylinderView that will check them (After QT confirm that they're numbers).
 */
class Create3DCylinder : public CreateShape
{
    Q_OBJECT
public:
    Create3DCylinder(CylinderView* MainInterf, QWidget *parent = nullptr);
private:
    QLineEdit* ray, *height;
    CylinderView* MainInterfaceRef;
private slots:
    void Confirm();
};

#endif // CREATE3DCYLINDER_H

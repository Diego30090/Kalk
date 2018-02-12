#ifndef CREATE3DSPHERE_H
#define CREATE3DSPHERE_H

#include "createshape.h"
#include "View/Shape3DView/sphereview.h"
#include <QLineEdit>

class SphereView;

/**
 * @brief The Create3DSphere class is an Extension of CreateShape, it contains the QLineEdit to insert the vaules of the new 3DSphere.
 * The values insered will be sent to SphereView that will check them (After QT confirm that they're numbers).
 */
class Create3DSphere : public CreateShape
{
    Q_OBJECT
public:
    Create3DSphere(SphereView* MainInterf, QWidget *parent = nullptr);
private:
    QLineEdit* ray;
    SphereView* MainInterfaceRef;
private slots:
    void Confirm();
};

#endif // CREATE3DSPHERE_H

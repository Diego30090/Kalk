#ifndef CALCULATORDRAWINTERFACE_H
#define CALCULATORDRAWINTERFACE_H

#include <QBrush>
#include <QPen>
#include <QPixmap>
#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QPainter>
#include "Shape/point2d.h"

/**
 * @brief The CalculatorDrawInterface class is a real-time graphics window, used to draw 2D shapes.
 * It uses the paintEvent to draw, using the pen to change the color and vectors of points to create the polygons from our SHAPE2D
 */
class CalculatorDrawInterface : public QWidget
{
    Q_OBJECT

public:
    CalculatorDrawInterface(QWidget *parent = nullptr);

    void SetPointsShape1(const std::vector<Point2D>&, const QColor& c = QColor());
    void SetPointsShape2(const std::vector<Point2D>&, const QColor& c = QColor());
    void SetPointsShapeResult(const std::vector<Point2D>&, const QColor& c = QColor());
    void ClearShapeDraw();
private:
    QPen pen;
    QBrush brush;

    double current_size;
    QPoint translate_loc;
    int gridSize;

    QVector<QPoint> points_vector_op1;
    QVector<QPoint> points_vector_op2;
    QVector<QPoint> points_vector_op_res;

    QColor color_shape1;
    QColor color_shape2;
    QColor color_shape_res;

    void paintUpdate();
    void paintInitialize();
protected:
    void paintEvent(QPaintEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;

    void drawBackground(QPainter *painter);
};

#endif // CALCULATORDRAWINTERFACE_H

#include "calculatordrawinterface.h"

#include <vector>
#include <QWheelEvent>
#include "../calculatormaininterface.h"

CalculatorDrawInterface::CalculatorDrawInterface(QWidget* parent) : QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    paintInitialize();
    CalculatorMainInterface::PrintLog("Draw Interface successfully created - Paint() Ready");
}

void CalculatorDrawInterface::paintInitialize()
{
    pen = QPen();
    brush = QBrush(Qt::NoBrush);

    gridSize = 25;
    current_size = 1.0;

    translate_loc = QPoint(width()/2, height()/2); //put it in the middle at the beginning
}

void CalculatorDrawInterface::paintUpdate()
{
    update();
    updateGeometry();
    repaint();
    CalculatorMainInterface::PrintLog("Draw Interface - Paint() Updated");
}

void CalculatorDrawInterface::paintEvent(QPaintEvent* /* event */)
{
    QPainter DrawPainter(this);

    DrawPainter.setPen(pen);
    DrawPainter.setBrush(brush);
    DrawPainter.setRenderHint(QPainter::Antialiasing, true);

    DrawPainter.translate(QPoint(width()/2, height()/2));
    if(current_size<0){
        DrawPainter.scale(-current_size, -current_size);
    }else{
        DrawPainter.scale(current_size, -current_size);
    }

    pen.setWidth(1);
    pen.setColor(QColor());
    DrawPainter.setPen(pen);
    // X Axis
    DrawPainter.drawLine(-width(),0, width(),0);
    // Y Axis
    DrawPainter.drawLine(0,-height(), 0,height());

    DrawPainter.save();

    DrawPainter.drawText(QPoint(-5,-5), "O");

    //First Shape Draw
    pen.setWidth(2);
    pen.setColor(color_shape1);
    DrawPainter.setPen(pen);
    if(points_vector_op1.size()==2){ //If is a circle
        int ray = Point2D::distance(points_vector_op1.at(0).x(), points_vector_op1.at(1).x());
        QRect firstPolygon = QRect(points_vector_op1.at(0).x(), points_vector_op1.at(1).y(), ray, ray);
        DrawPainter.drawEllipse(firstPolygon);
    }else{
        QPolygon firstPolygon(points_vector_op1);
        DrawPainter.drawPolygon(firstPolygon);
    }

    //Second Shape Draw
    pen.setColor(color_shape2);
    DrawPainter.setPen(pen);
    if(points_vector_op2.size()==2){ //If is a circle
        int ray = Point2D::distance(points_vector_op2.at(0).x(), points_vector_op2.at(1).x());
        QRect secondPolygon = QRect(points_vector_op2.at(0).x(), points_vector_op2.at(1).y(), ray, ray);
        DrawPainter.drawEllipse(secondPolygon);
    }else{
        QPolygon secondPolygon(points_vector_op2);
        DrawPainter.drawPolygon(secondPolygon);
    }

    //Result Draw
    pen.setColor(color_shape_res);
    DrawPainter.setPen(pen);
    if(points_vector_op_res.size()==2){ //If is a circle
        int ray = Point2D::distance(points_vector_op_res.at(0).x(), points_vector_op_res.at(1).x());
        QRect circle = QRect(points_vector_op_res.at(0).x(), points_vector_op_res.at(1).y(), ray, ray);
        DrawPainter.drawEllipse(circle);
    }else{
        QPolygon polygon_result(points_vector_op_res);
        DrawPainter.drawPolygon(polygon_result);
    }

    DrawPainter.restore();

    //draw grid
    drawBackground(&DrawPainter);
}

void CalculatorDrawInterface::wheelEvent(QWheelEvent* event)
{
    event->accept(); //i want this event
    if(event->delta()<0){
        current_size-=0.5;
        if(current_size<=0.5){
            current_size=0.5;
        }else{
            gridSize+=2;
        }
    }else{
        gridSize-=2;
        if(gridSize<=1){
            gridSize=1;
        }else{
            current_size+=0.5;
            if(current_size>=50){
                current_size=50;
            }
        }
    }
    paintUpdate();
}

void CalculatorDrawInterface::drawBackground(QPainter *painter)
{
    const QPen actual = painter->pen();
    painter->setPen(QPen(QColor(200, 200, 255, 125)));

    qreal left = int(-width()) - (int(-width()) % gridSize);
    qreal top = int(-height()) - (int(-height()) % gridSize);

    QVarLengthArray<QLineF, 100> lines;

    for (qreal x = left; x < width(); x += gridSize)
        lines.append(QLineF(x, height(), x, -height()));
    for (qreal y = top; y < height(); y += gridSize)
        lines.append(QLineF(width(), y, -width(), y));

    painter->drawLines(lines.data(), lines.size());
    painter->setPen(actual);
}

void CalculatorDrawInterface::SetPointsShape1(const std::vector<Point2D>& v, const QColor& c)
{
    points_vector_op1.clear();
    for(std::vector<Point2D>::const_iterator it = v.begin(); it!=v.end(); ++it)
    {
        points_vector_op1.push_back(QPoint((*it).getX(), (*it).getY()));
    }
    color_shape1=c;
    paintUpdate();
}

void CalculatorDrawInterface::SetPointsShape2(const std::vector<Point2D>& v, const QColor& c)
{
    points_vector_op2.clear();
    for(std::vector<Point2D>::const_iterator it = v.begin(); it!=v.end(); ++it)
    {
        points_vector_op2.push_back(QPoint((*it).getX(), (*it).getY()));
    }
    color_shape2=c;
    paintUpdate();
}

void CalculatorDrawInterface::SetPointsShapeResult(const std::vector<Point2D>& v, const QColor& c)
{
    points_vector_op_res.clear();
    for(std::vector<Point2D>::const_iterator it = v.begin(); it!=v.end(); ++it)
    {
        points_vector_op_res.push_back(QPoint((*it).getX(), (*it).getY()));
    }
    color_shape_res=c;
    paintUpdate();
}

void CalculatorDrawInterface::ClearShapeDraw()
{
    points_vector_op1.clear();
    points_vector_op2.clear();
    points_vector_op_res.clear();
}

package Shape.Shape2D;

import Color.ColorRGB;
import Interface.ICalculable;
import Shape.Point2D;
import Shape.Shape;

import java.util.ArrayList;

public abstract class Shape2D extends Shape implements ICalculable<Shape2D> {
    protected ArrayList<Point2D> points;

    public Shape2D(ArrayList<Point2D> p, String n) {
        super(n);
        points = p;
    }

    public Shape2D(ArrayList<Point2D> p, String name, ColorRGB color) {
        super(name, color);
        points = p;
    }

    public Shape2D(Shape2D s2d) {
        super(s2d);
        points = s2d.points;
    }

    public int getNumberSide() {
        return points.size();
    }

    public abstract double sideToOperator();

    public int getNumberVertex() {
        return points.size();
    }

    public ArrayList<Point2D> getPoints() {
        return points;
    }

    public void translate(Point2D p) {
        for (Point2D point : points) {
            point.setX(p.getX() + point.getX());
            point.setY(p.getY() + point.getY());
        }
    }

    public boolean equalsPoints(ArrayList<Point2D> p) {
        if (points == null || p == null)
            return false;
        if (points.size() != p.size())
            return false;
        for (Point2D points : points) {
            if (!p.contains(points)) {
                return false;
            }
        }
        return true;
    }

    public boolean equals(Object obj) {
        if (super.equals(obj)) {
            Shape2D s2d = (Shape2D) obj;
            return equalsPoints(s2d.points);
        }
        return false;
    }
}

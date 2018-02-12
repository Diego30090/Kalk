package Shape.Shape2D.Polygon;

import Color.ColorRGB;
import Shape.Point2D;
import Shape.Shape2D.Shape2D;

import java.util.ArrayList;

public abstract class Polygon extends Shape2D {

    public Polygon(ArrayList<Point2D> p, String name) {
        super(p, name);
    }

    public Polygon(ArrayList<Point2D> p, String name, ColorRGB color) {
        super(p, name, color);
    }

    public Polygon(Polygon p) {
        super(p);
    }

    public abstract double base();

    public abstract double height();

    public abstract double area();

    public double perimeter() {
        double perimeter = 0;
        double side = 0;
        int i = 0;
        int second = 1;
        for (Point2D p : points) {
            if (i < getNumberSide() - 1) {
                side = Point2D.distance(points.get(second), p);
                perimeter += side;
                second++;
                i++;
            }
        }
        second = getNumberVertex() - 1;
        side = Point2D.distance(points.get(second), points.get(0));
        perimeter += side;

        return perimeter;
    }

    public static double gaussArea(Polygon p) {
        double area = 0;
        int i = 0;
        int second = 1;
        ArrayList<Point2D> points = p.getPoints();
        for (Point2D point : points) {
            if (i < points.size() - 1) {
                area += point.getX() * points.get(second).getY();
                second++;
                i++;
            }
        }

        second = points.size() - 1;
        area += points.get(second).getX() * points.get(0).getY();

        second = 1;
        for (Point2D point1 : points) {
            if (i < points.size() - 1) {
                area -= point1.getY() * points.get(second).getX();
                second++;
                i++;
            }
        }

        second = points.size() - 1;
        area -= points.get(second).getX() * points.get(0).getY();

        return area / 2;
    }
}

package Shape.Shape2D.Polygon.Triangle;

import Color.ColorRGB;
import Shape.Point2D;
import Shape.Shape2D.Polygon.Polygon;

import java.util.ArrayList;

public abstract class Triangle extends Polygon {

    public Triangle(ArrayList<Point2D> p, String name) {
        super(p, name);
    }

    public Triangle(ArrayList<Point2D> p, String name, ColorRGB color) {
        super(p, name, color);
    }

    public Triangle(Triangle t) {
        super(t);
    }

    public static boolean isTriangle(double a, double b, double c) {
        if (a < 0 && b < 0 && c < 0)
            return false;

        if (a < (b + c) && b < (a + c) && c < (a + b))
            return true;

        return false;
    }
}

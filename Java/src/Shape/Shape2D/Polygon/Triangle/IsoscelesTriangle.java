package Shape.Shape2D.Polygon.Triangle;

import Color.ColorRGB;
import Shape.Point2D;
import Shape.Shape2D.Shape2D;

import java.util.ArrayList;

public class IsoscelesTriangle extends Triangle {

    public IsoscelesTriangle(ArrayList<Point2D> p) {
        super(p, "IsoscelesTriangle");
        if (!canBuild(p)) {
            points = buildIsoscelesTriangle(1, 1);
        }
    }

    public IsoscelesTriangle(ArrayList<Point2D> p, ColorRGB color) {
        super(p, "IsoscelesTriangle", color);
        if (!canBuild(p)) {
            points = buildIsoscelesTriangle(1, 1);
        }
    }

    public IsoscelesTriangle(double base, double height) {
        super(null, "IsoscelesTriangle");
        points = buildIsoscelesTriangle(base, height);
    }

    public IsoscelesTriangle(double base, double height, ColorRGB color) {
        super(null, "IsoscelesTriangle", color);
        points = buildIsoscelesTriangle(base, height);
    }

    private boolean canBuild(double base, double height) {
        return base > 0 && height > 0;
    }

    private boolean canBuild(ArrayList<Point2D> p) {
        if (p.size() == 3) {
            double base = Point2D.distance(p.get(1), p.get(0));
            double height = Point2D.distance(p.get(2), new Point2D(base / 2, 0));
            return base > 0 && height > 0;
        }
        return false;
    }

    private ArrayList<Point2D> buildIsoscelesTriangle(double base, double height) {
        if (!canBuild(base, height)) {
            base = 1;
            height = 1;
        }

        ArrayList<Point2D> points = new ArrayList<>();
        points.add(new Point2D());
        points.add(new Point2D(base, 0));
        points.add(new Point2D(base / 2, height));

        return points;
    }

    public double sideToOperator() {
        return base() + height();
    }

    @Override
    public double base() {
        return Point2D.distance(points.get(1), points.get(0));
    }

    public double height() {
        return Point2D.distance(points.get(2), new Point2D(base() / 2, 0));
    }

    public double side() {
        return (2 * perimeter() - base()) / 2;
    }

    public double area() {
        return (base() * height()) / 2;
    }

    public IsoscelesTriangle sum(Shape2D other) {
        double newBase;
        double newHeight;
        IsoscelesTriangle newIsoscelesTriangle;
        if (getClass() == other.getClass()) {
            IsoscelesTriangle it = (IsoscelesTriangle) other;
            newBase = base() + it.base();
            newHeight = height() + it.height();
            newIsoscelesTriangle = new IsoscelesTriangle(buildIsoscelesTriangle(newBase, newHeight)
                    , getColor().sum(other.getColor()));
        } else {
            newBase = base() + other.sideToOperator();
            newHeight = height() + other.sideToOperator();
            newIsoscelesTriangle = new IsoscelesTriangle(buildIsoscelesTriangle(newBase, newHeight)
                    , getColor().sum(other.getColor()));
        }
        return newIsoscelesTriangle;
    }

    public IsoscelesTriangle sub(Shape2D other) {
        double newBase;
        double newHeight;
        IsoscelesTriangle newIsoscelesTriangle;
        if (getClass() == other.getClass()) {
            IsoscelesTriangle it = (IsoscelesTriangle) other;
            newBase = base() - it.base();
            newHeight = height() - it.height();
            newIsoscelesTriangle = new IsoscelesTriangle(buildIsoscelesTriangle(newBase, newHeight)
                    , getColor().sub(other.getColor()));
        } else {
            newBase = base() - other.sideToOperator();
            newHeight = height() - other.sideToOperator();
            newIsoscelesTriangle = new IsoscelesTriangle(buildIsoscelesTriangle(newBase, newHeight)
                    , getColor().sub(other.getColor()));
        }
        return newIsoscelesTriangle;
    }

    public IsoscelesTriangle mul(Shape2D other) {
        double newBase;
        double newHeight;
        IsoscelesTriangle newIsoscelesTriangle;
        if (getClass() == other.getClass()) {
            IsoscelesTriangle it = (IsoscelesTriangle) other;
            newBase = base() * it.base();
            newHeight = height() * it.height();
            newIsoscelesTriangle = new IsoscelesTriangle(buildIsoscelesTriangle(newBase, newHeight)
                    , getColor().mul(other.getColor()));
        } else {
            newBase = base() * other.sideToOperator();
            newHeight = height() * other.sideToOperator();
            newIsoscelesTriangle = new IsoscelesTriangle(buildIsoscelesTriangle(newBase, newHeight)
                    , getColor().mul(other.getColor()));
        }
        return newIsoscelesTriangle;
    }

    public IsoscelesTriangle div(Shape2D other) {
        double newBase;
        double newHeight;
        IsoscelesTriangle newIsoscelesTriangle;
        if (getClass() == other.getClass()) {
            IsoscelesTriangle it = (IsoscelesTriangle) other;
            newBase = base() / it.base();
            newHeight = height() / it.height();
            newIsoscelesTriangle = new IsoscelesTriangle(buildIsoscelesTriangle(newBase, newHeight)
                    , getColor().div(other.getColor()));
        } else {
            newBase = base() / other.sideToOperator();
            newHeight = height() / other.sideToOperator();
            newIsoscelesTriangle = new IsoscelesTriangle(buildIsoscelesTriangle(newBase, newHeight)
                    , getColor().div(other.getColor()));
        }
        return newIsoscelesTriangle;
    }

    public String toString() {
        return super.toString() + "Base: " + base() + "\nHeight: " + height() + "\nSide: " + side() +
                "\nArea: " + area() + "\nPerimeter: " + perimeter();
    }
}
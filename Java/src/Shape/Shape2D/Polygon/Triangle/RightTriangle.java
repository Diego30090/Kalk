package Shape.Shape2D.Polygon.Triangle;

import Color.ColorRGB;
import Shape.Point2D;
import Shape.Shape2D.Shape2D;

import java.util.ArrayList;

public class RightTriangle extends Triangle {

    public RightTriangle(ArrayList<Point2D> p) {
        super(p, "RightTriangle");
        if (!canBuild(p)) {
            points = buildRightTriangle(1, 1);
        }
    }

    public RightTriangle(ArrayList<Point2D> p, ColorRGB color) {
        super(p, "RightTriangle", color);
        if (!canBuild(p)) {
            points = buildRightTriangle(1, 1);
        }
    }

    public RightTriangle(double cathetusMin, double cathetusMax) {
        super(null, "RightTriangle");
        points = buildRightTriangle(cathetusMin, cathetusMax);
    }

    public RightTriangle(double cathetusMin, double cathetusMax, ColorRGB color) {
        super(null, "RightTriangle", color);
        points = buildRightTriangle(cathetusMin, cathetusMax);
    }

    private boolean canBuild(double cathetusMin, double cathetusMax) {
        return cathetusMin > 0 && cathetusMax > 0;
    }

    private boolean canBuild(ArrayList<Point2D> p) {
        if (p.size() == 3) {
            double cathetusMin = Point2D.distance(p.get(1), p.get(0));
            double cathetusMax = Point2D.distance(p.get(2), p.get(0));
            return cathetusMin > 0 && cathetusMax > 0;
        }
        return false;
    }

    private ArrayList<Point2D> buildRightTriangle(double cathetusMin, double cathetusMax) {
        if (!canBuild(cathetusMin, cathetusMax)) {
            cathetusMin = 1;
            cathetusMax = 1;
        }

        ArrayList<Point2D> points = new ArrayList<>();
        points.add(new Point2D());
        points.add(new Point2D(cathetusMin, 0));
        points.add(new Point2D(cathetusMin / 2, cathetusMax));

        return points;
    }

    public double sideToOperator() {
        return base() + height();
    }

    public double base() {
        return Point2D.distance(points.get(1), points.get(0));
    }

    public double height() {
        return Point2D.distance(points.get(2), new Point2D(base() / 2, 0));
    }

    public double hypotenuse() {
        return Math.sqrt(Math.pow(base(), 2) + Math.pow(height(), 2));
    }

    public double area() {
        return (base() * height()) / 2;
    }

    public RightTriangle sum(Shape2D other) {
        double newCathetusMin;
        double newCathetusMax;
        RightTriangle newRightTriangle;
        if (getClass() == other.getClass()) {
            RightTriangle it = (RightTriangle) other;
            newCathetusMin = base() + it.base();
            newCathetusMax = height() + it.height();
            newRightTriangle = new RightTriangle(buildRightTriangle(newCathetusMin, newCathetusMax)
                    , getColor().sum(other.getColor()));
        } else {
            newCathetusMin = base() + other.sideToOperator();
            newCathetusMax = height() + other.sideToOperator();
            newRightTriangle = new RightTriangle(buildRightTriangle(newCathetusMin, newCathetusMax)
                    , getColor().sum(other.getColor()));
        }
        return newRightTriangle;
    }

    public RightTriangle sub(Shape2D other) {
        double newCathetusMin;
        double newCathetusMax;
        RightTriangle newRightTriangle;
        if (getClass() == other.getClass()) {
            RightTriangle it = (RightTriangle) other;
            newCathetusMin = base() - it.base();
            newCathetusMax = height() - it.height();
            newRightTriangle = new RightTriangle(buildRightTriangle(newCathetusMin, newCathetusMax)
                    , getColor().sub(other.getColor()));
        } else {
            newCathetusMin = base() - other.sideToOperator();
            newCathetusMax = height() - other.sideToOperator();
            newRightTriangle = new RightTriangle(buildRightTriangle(newCathetusMin, newCathetusMax)
                    , getColor().sub(other.getColor()));
        }
        return newRightTriangle;
    }

    public RightTriangle mul(Shape2D other) {
        double newCathetusMin;
        double newCathetusMax;
        RightTriangle newRightTriangle;
        if (getClass() == other.getClass()) {
            RightTriangle it = (RightTriangle) other;
            newCathetusMin = base() * it.base();
            newCathetusMax = height() * it.height();
            newRightTriangle = new RightTriangle(buildRightTriangle(newCathetusMin, newCathetusMax)
                    , getColor().mul(other.getColor()));
        } else {
            newCathetusMin = base() * other.sideToOperator();
            newCathetusMax = height() * other.sideToOperator();
            newRightTriangle = new RightTriangle(buildRightTriangle(newCathetusMin, newCathetusMax)
                    , getColor().mul(other.getColor()));
        }
        return newRightTriangle;
    }

    public RightTriangle div(Shape2D other) {
        double newCathetusMin;
        double newCathetusMax;
        RightTriangle newRightTriangle;
        if (getClass() == other.getClass()) {
            RightTriangle it = (RightTriangle) other;
            newCathetusMin = base() / it.base();
            newCathetusMax = height() / it.height();
            newRightTriangle = new RightTriangle(buildRightTriangle(newCathetusMin, newCathetusMax)
                    , getColor().div(other.getColor()));
        } else {
            newCathetusMin = base() / other.sideToOperator();
            newCathetusMax = height() / other.sideToOperator();
            newRightTriangle = new RightTriangle(buildRightTriangle(newCathetusMin, newCathetusMax)
                    , getColor().div(other.getColor()));
        }
        return newRightTriangle;
    }

    public String toString() {
        return super.toString() + "CathetusMin: " + base() + "\nCathetusMax: " + height() + "\nHypotenuse: " +
                hypotenuse() + "\nArea: " + area() + "\nPerimeter: " + perimeter();
    }
}


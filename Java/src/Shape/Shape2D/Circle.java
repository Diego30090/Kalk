package Shape.Shape2D;

import Color.ColorRGB;
import Shape.Point2D;

import java.util.ArrayList;


public class Circle extends Shape2D {

    public Circle(ArrayList<Point2D> p) {
        super(p, "Circle");
        if (p.size() != 2) {
            points = buildCircle(1);
        } else {
            double ray = Point2D.distance(p.get(1), p.get(0));
            points = buildCircle(ray);
        }
    }

    public Circle(ArrayList<Point2D> p, ColorRGB color) {
        super(p, "Circle", color);
        if (p.size() != 2) {
            points = buildCircle(1);
        } else {
            double ray = Point2D.distance(p.get(1), p.get(0));
            points = buildCircle(ray);
        }
    }

    public Circle(double ray) {
        super(null, "Circle");
        points = buildCircle(ray);
    }

    public Circle(double ray, ColorRGB color) {
        super(null, "Circle", color);
        points = buildCircle(ray);
    }

    public Circle(Circle c) {
        super(c);
    }

    private boolean canBuild(double ray) {
        return ray > 0;
    }

    private ArrayList<Point2D> buildCircle(double ray) {
        if (!canBuild(ray))
            ray = 1;
        ArrayList<Point2D> points = new ArrayList<>();

        points.add(new Point2D());
        points.add(new Point2D(ray, 0));

        return points;
    }

    @Override
    public double sideToOperator() {
        return ray();
    }

    public double ray() {
        return Point2D.distance(points.get(1), points.get(0));
    }

    public double diameter() {
        return ray() * 2;
    }

    public double circumference() {
        return 2 * Math.PI * ray();
    }

    public double area() {
        return Math.PI * Math.pow(ray(), 2);
    }

    public Circle sum(Shape2D other) {
        double newRay;
        Circle newCircle;
        if (getClass() == other.getClass()) //identical types vs instance of tests whether the object reference
        // on the left-hand side (LHS) is an instance of the type on the right-hand side (RHS) or some subtype.
        {
            Circle c = (Circle) other;
            newRay = ray() + c.ray();
            newCircle = new Circle(buildCircle(newRay), getColor().sum(other.getColor()));
        } else {
            newRay = ray() + other.sideToOperator();
            newCircle = new Circle(buildCircle(newRay), getColor().sum(other.getColor()));
        }
        return newCircle;
    }

    public Circle sub(Shape2D other) {
        double newRay;
        Circle newCircle;
        if (getClass() == other.getClass()) {
            Circle c = (Circle) other;
            newRay = ray() - c.ray();
            newCircle = new Circle(buildCircle(newRay), getColor().sub(other.getColor()));
        } else {
            newRay = ray() - other.sideToOperator();
            newCircle = new Circle(buildCircle(newRay), getColor().sub(other.getColor()));
        }
        return newCircle;
    }

    public Circle mul(Shape2D other) {
        double newRay;
        Circle newCircle;
        if (getClass() == other.getClass()) {
            Circle c = (Circle) other;
            newRay = ray() * c.ray();
            newCircle = new Circle(buildCircle(newRay), getColor().mul(other.getColor()));
        } else {
            newRay = ray() * other.sideToOperator();
            newCircle = new Circle(buildCircle(newRay), getColor().mul(other.getColor()));
        }
        return newCircle;
    }

    public Circle div(Shape2D other) {
        double newRay = 0;
        Circle newCircle;
        if (getClass() == other.getClass()) {
            Circle c = (Circle) other;
            newRay = ray() / c.ray();
            newCircle = new Circle(buildCircle(newRay), getColor().div(other.getColor()));
        } else {
            newRay = ray() / other.sideToOperator();
            newCircle = new Circle(buildCircle(newRay), getColor().div(other.getColor()));
        }
        return newCircle;
    }

    public String toString() {
        return super.toString() + "Ray: " + ray() + "\nDiameter: " + diameter() +
                "\nCircumferece: " + circumference() + "\nArea: " + area();
    }
}

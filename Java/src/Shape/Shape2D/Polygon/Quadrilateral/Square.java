package Shape.Shape2D.Polygon.Quadrilateral;

import Color.ColorRGB;
import Shape.Point2D;
import Shape.Shape2D.Shape2D;

import java.util.ArrayList;

public class Square extends Quadrilateral {

    public Square(ArrayList<Point2D> p) {
        super(p, "Square");
        if (!canBuild(p)) {
            points = buildSquare(1);
        }
    }

    public Square(ArrayList<Point2D> p, ColorRGB color) {
        super(p, "Square", color);
        if (!canBuild(p)) {
            points = buildSquare(1);
        }
    }

    public Square(double sideLength) {
        super(null, "Square");
        points = buildSquare(sideLength);
    }

    public Square(double sideLength, ColorRGB color) {
        super(null, "Square", color);
        points = buildSquare(sideLength);

    }

    public Square(Square s) {
        super(s);
    }

    private boolean canBuild(double sideLength) {
        return sideLength > 0;
    }

    private boolean canBuild(ArrayList<Point2D> vp2d) {
        if (vp2d.size() == 4) {
            return Point2D.distance(vp2d.get(1), vp2d.get(0)) > 0;
        }
        return false;
    }

    private ArrayList<Point2D> buildSquare(double sideLength) {
        if (!canBuild(sideLength))
            sideLength = 1;

        ArrayList<Point2D> points = new ArrayList<>();

        points.add(new Point2D());
        points.add(new Point2D(sideLength));
        points.add(new Point2D(sideLength, sideLength));
        points.add(new Point2D(0, sideLength));

        return points;
    }

    public double sideToOperator() {
        return base();
    }

    public double base() {
        return Point2D.distance(points.get(1), points.get(0));
    }

    public double height() {
        return base();
    }

    public double diagonal() {
        return base() * Math.sqrt(2);
    }

    public double area() {
        return Math.pow(base(), 2);
    }

    public Square sum(Shape2D other) {
        double newSide;
        Square newSquare;
        if (getClass() == other.getClass()) {
            Square s = (Square) other;
            newSide = base() + s.base();
            newSquare = new Square(buildSquare(newSide), getColor().sum(other.getColor()));
        } else {
            newSide = base() + other.sideToOperator();
            newSquare = new Square(buildSquare(newSide), getColor().sum(other.getColor()));
        }
        return newSquare;
    }

    public Square sub(Shape2D other) {
        double newSide;
        Square newSquare;
        if (getClass() == other.getClass()) {
            Square s = (Square) other;
            newSide = base() - s.base();
            newSquare = new Square(buildSquare(newSide), getColor().sub(other.getColor()));
        } else {
            newSide = base() - other.sideToOperator();
            newSquare = new Square(buildSquare(newSide), getColor().sub(other.getColor()));
        }
        return newSquare;
    }

    public Square mul(Shape2D other) {
        double newSide;
        Square newSquare;
        if (getClass() == other.getClass()) {
            Square s = (Square) other;
            newSide = base() * s.base();
            newSquare = new Square(buildSquare(newSide), getColor().mul(other.getColor()));
        } else {
            newSide = base() * other.sideToOperator();
            newSquare = new Square(buildSquare(newSide), getColor().mul(other.getColor()));
        }
        return newSquare;
    }

    public Square div(Shape2D other) {
        double newSide;
        Square newSquare;
        if (getClass() == other.getClass()) {
            Square s = (Square) other;
            newSide = base() / s.base();
            newSquare = new Square(buildSquare(newSide), getColor().div(other.getColor()));
        } else {
            newSide = base() / other.sideToOperator();
            newSquare = new Square(buildSquare(newSide), getColor().div(other.getColor()));
        }
        return newSquare;
    }


    public String toString() {
        return super.toString() + "Side: " + base() + "\nDiagonal: " + diagonal() +
                "\nArea: " + area() + "\nArea: " + area() + "\nPerimeter: " + perimeter();
    }

}

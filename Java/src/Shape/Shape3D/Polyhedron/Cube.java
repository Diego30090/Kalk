package Shape.Shape3D.Polyhedron;

import Color.ColorRGB;
import Shape.Point2D;
import Shape.Point3D;
import Shape.Shape2D.Polygon.Quadrilateral.Square;
import Shape.Shape3D.Shape3D;

import java.util.ArrayList;

public class Cube extends Polyhedron {

    public Cube(ArrayList<Point3D> p, Square bShape) {
        super(p, bShape, "Cube");
        points = buildCube(bShape);
    }

    public Cube(ArrayList<Point3D> p, Square bShape, ColorRGB color) {
        super(p, bShape, "Cube", color);
        points = buildCube(bShape);
    }

    public Cube(Square s) {
        super(null, s, "Cube");
        points = buildCube(s);
    }

    public Cube(Square s, ColorRGB color) {
        super(null, s, "Cube", color);
        points = buildCube(s);
    }

    public Cube(Cube c) {
        super(c);
    }

    private ArrayList<Point3D> buildCube(Square s) {
        ArrayList<Point3D> points = new ArrayList<>();

        for (Point2D point2d : s.getPoints()) {
            points.add(Point3D.p2dTop3d(point2d));
        }

        for (Point2D point2d : s.getPoints()) {
            points.add(new Point3D(point2d.getX(), point2d.getY(), s.base()));
        }
        return points;
    }

    public Cube sum(Shape3D other) {
        Square newbaseShape = (Square) baseShape.sum(other.getBaseShape());
        return new Cube(
                buildCube(newbaseShape), newbaseShape, getColor().sum(other.getColor()));
    }


    public Cube sub(Shape3D other) {
        Square newbaseShape = (Square) baseShape.sub(other.getBaseShape());
        return new Cube(
                buildCube(newbaseShape), newbaseShape, getColor().sub(other.getColor()));
    }

    public Cube mul(Shape3D other) {
        Square newbaseShape = (Square) baseShape.mul(other.getBaseShape());
        return new Cube(
                buildCube(newbaseShape), newbaseShape, getColor().mul(other.getColor()));
    }

    public Cube div(Shape3D other) {
        Square newbaseShape = (Square) baseShape.div(other.getBaseShape());
        return new Cube(
                buildCube(newbaseShape), newbaseShape, getColor().div(other.getColor()));
    }

    public int getNumberCorner() {
        return 12;
    }

    public int getNumberFaces() {
        return getNumberCorner() / 2;
    }


    public double volume() {
        Square s = (Square) baseShape;
        return Math.pow(s.base(), 3);
    }


    public double lateralSurface() {
        Square s = (Square) baseShape;
        return 4 * Math.pow(s.base(), 2);
    }

    public double totalSurface() {
        Square s = (Square) baseShape;
        return 6 * Math.pow(s.base(), 2);
    }

    public double diagonal() {
        return side() * Math.sqrt(3);
    }

    double side() {
        Square s = (Square) baseShape;
        return s.base();
    }

    public String toString() {
        return super.toString() + "Side " + side() + "\nVolume " + volume() +
                "\nLateralSurface " + lateralSurface() + "\nTotalSurface " + totalSurface();
    }

}

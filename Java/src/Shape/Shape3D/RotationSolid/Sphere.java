package Shape.Shape3D.RotationSolid;

import Color.ColorRGB;
import Shape.Point2D;
import Shape.Point3D;
import Shape.Shape2D.Circle;
import Shape.Shape3D.Shape3D;

import java.util.ArrayList;

public class Sphere extends RotationSolid {

    public Sphere(ArrayList<Point3D> p, Circle bShape) {
        super(p, bShape, "Sphere");
    }

    public Sphere(ArrayList<Point3D> p, Circle bShape, ColorRGB color) {
        super(p, bShape, "Sphere", color);
    }

    public Sphere(Circle c) {
        super(null, c, "Sphere");
        points = buildSphere(c);
    }

    public Sphere(Circle c, ColorRGB color) {
        super(null, c, "Sphere", color);
        points = buildSphere(c);
    }

    public Sphere(Sphere s) {
        super(s);
    }

    private ArrayList<Point3D> buildSphere(Circle c) {
        ArrayList<Point3D> points = new ArrayList<>();
        for (Point2D p2d : c.getPoints()) {
            points.add(Point3D.p2dTop3d(p2d));
        }

        return points;
    }

    public Sphere sum(Shape3D other) {
        Circle newbaseShape = (Circle) baseShape.sum(other.getBaseShape());
        return new Sphere(
                buildSphere(newbaseShape), newbaseShape, getColor().sum(other.getColor()));
    }

    public Sphere sub(Shape3D other) {
        Circle newbaseShape = (Circle) baseShape.sub(other.getBaseShape());
        return new Sphere(
                buildSphere(newbaseShape), newbaseShape, getColor().sub(other.getColor()));
    }

    public Sphere mul(Shape3D other) {
        Circle newbaseShape = (Circle) baseShape.mul(other.getBaseShape());
        return new Sphere(
                buildSphere(newbaseShape), newbaseShape, getColor().mul(other.getColor()));
    }

    public Sphere div(Shape3D other) {
        Circle newbaseShape = (Circle) baseShape.div(other.getBaseShape());
        return new Sphere(
                buildSphere(newbaseShape), newbaseShape, getColor().sum(other.getColor()));
    }

    public double diameter() {
        Circle c = (Circle) baseShape;
        return c.diameter();
    }

    public double ray() {
        Circle c = (Circle) baseShape;
        return c.ray();
    }

    public double circumference() {
        Circle c = (Circle) baseShape;
        return c.circumference();
    }

    public double volume() {
        return (4 * Math.PI * Math.pow(ray(), 2)) / 3;
    }

    public double totalSurface() {
        return 4 * Math.PI * Math.pow(ray(), 2);
    }

    public String toString() {
        return super.toString() + "Ray " + ray() + "\nVolume " + volume() +
                "\nDiameter " + diameter() + "\nTotalSurface " + totalSurface();
    }
}

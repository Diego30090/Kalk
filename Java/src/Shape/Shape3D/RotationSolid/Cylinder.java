package Shape.Shape3D.RotationSolid;

import Color.ColorRGB;
import Shape.Point2D;
import Shape.Point3D;
import Shape.Shape2D.Polygon.Quadrilateral.Rectangle;
import Shape.Shape3D.Shape3D;

import java.util.ArrayList;

public class Cylinder extends RotationSolid {

    public Cylinder(ArrayList<Point3D> p, Rectangle bShape) {
        super(p, bShape, "Cylinder");
    }

    public Cylinder(ArrayList<Point3D> p, Rectangle bShape, ColorRGB color) {
        super(p, bShape, "Cylinder", color);
    }

    public Cylinder(Rectangle r) {
        super(null, r, "Cylinder");
        points = buildCylinder(r);
    }

    public Cylinder(Rectangle r, ColorRGB color) {
        super(null, r, "Cylinder", color);
        points = buildCylinder(r);
    }

    public Cylinder(Cylinder c) {
        super(c);
    }

    private ArrayList<Point3D> buildCylinder(Rectangle r) {
        ArrayList<Point3D> points = new ArrayList<>();
        for (Point2D p2d : r.getPoints()) {
            points.add(Point3D.p2dTop3d(p2d));
        }
        return points;
    }

    public Cylinder sum(Shape3D other) {
        Rectangle newbaseShape = (Rectangle) baseShape.sum(other.getBaseShape());
        return new Cylinder(
                buildCylinder(newbaseShape), newbaseShape, getColor().sum(other.getColor()));
    }

    public Cylinder sub(Shape3D other) {
        Rectangle newbaseShape = (Rectangle) baseShape.sub(other.getBaseShape());
        return new Cylinder(
                buildCylinder(newbaseShape), newbaseShape, getColor().sub(other.getColor()));
    }

    public Cylinder mul(Shape3D other) {
        Rectangle newbaseShape = (Rectangle) baseShape.mul(other.getBaseShape());
        return new Cylinder(
                buildCylinder(newbaseShape), newbaseShape, getColor().mul(other.getColor()));
    }

    public Cylinder div(Shape3D other) {
        Rectangle newbaseShape = (Rectangle) baseShape.div(other.getBaseShape());
        return new Cylinder(
                buildCylinder(newbaseShape), newbaseShape, getColor().div(other.getColor()));
    }

    public double height() {
        return ((Rectangle) baseShape).height();
    }

    public double ray() {
        return ((Rectangle) baseShape).base();
    }

    public double lateralSurface() {
        Rectangle r = (Rectangle) baseShape;
        return 2 * Math.PI * r.base() * r.height();
    }

    public double baseSurface() {
        Rectangle r = (Rectangle) baseShape;
        return 2 * Math.PI * r.base() * r.height();
    }

    public double volume() {
        return Math.PI * Math.pow(ray(), 2) * height();
    }

    public double totalSurface() {
        return lateralSurface() + 2 * Math.PI * Math.pow(ray(), 2);
    }

    public String toString() {
        return super.toString() + "BaseRay " + ray() + "\nHeight " + height() + "\nVolume " + volume() +
                "\nLateralSurface " + lateralSurface() + "\nTotalSurface " + totalSurface();
    }
}

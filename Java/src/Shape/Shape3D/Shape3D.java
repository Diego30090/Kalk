package Shape.Shape3D;

import Color.ColorRGB;
import Interface.ICalculable;
import Shape.Point2D;
import Shape.Point3D;
import Shape.Shape;
import Shape.Shape2D.Shape2D;

import java.util.ArrayList;

public abstract class Shape3D extends Shape implements ICalculable<Shape3D> {

    protected ArrayList<Point3D> points;
    protected Shape2D baseShape;

    public Shape3D(ArrayList<Point3D> p, Shape2D bShape, String name) {
        super(name);
        baseShape = bShape;
        points = p;
        adjustPoints(baseShape.getPoints());
    }

    public Shape3D(ArrayList<Point3D> p, Shape2D bShape, String name, ColorRGB color) {
        super(name, color);
        baseShape = bShape;
        points = p;
        adjustPoints(baseShape.getPoints());
    }

    public Shape3D(Shape3D s3d) {
        super(s3d);
        points = s3d.points;
        baseShape = s3d.baseShape;
    }

    public abstract double volume();

    public abstract double totalSurface();

    public int getNumberVertex() {
        return points.size();
    }

    public ArrayList<Point3D> getPoints() {
        return points;
    }

    public Shape2D getBaseShape() {
        return baseShape;
    }

    private void adjustPoints(ArrayList<Point2D> bs_points) {
        if (points == null)
            return;
        for (Point2D point : bs_points) {
            Point3D tmp = Point3D.p2dTop3d(point);
            boolean found = false;
            for (Point3D p3d : points) {
                if (tmp == p3d) {
                    found = true;
                }
            }
            if (!found) {
                points.add(tmp);
            }
        }
    }

    public boolean equalsPoints(ArrayList<Point3D> p) {
        if (points == null || p == null)
            return false;
        if (points.size() != p.size())
            return false;
        for (Point3D points : points) {
            if (!p.contains(points)) {
                return false;
            }
        }
        return true;
    }

    public boolean equals(Object obj) {
        if (super.equals(obj)) {
            Shape3D s3d = (Shape3D) obj;
            return equalsPoints(s3d.points);
        }
        return false;
    }
}

package Shape;

public class Point3D extends Point2D {
    private double z;

    public Point3D() {
        super();
        z = 0;
    }

    public Point3D(double _z) {
        super();
        z = _z;
    }

    public Point3D(double x, double _z) {
        super(x);
        z = _z;
    }

    public Point3D(double x, double y, double _z) {
        super(x, y);
        z = _z;
    }

    public Point3D(Point3D p3d) {
        super(p3d);
        z = p3d.z;
    }

    public static double distance(Point3D p1, Point3D p2) {
        return Math.sqrt(Math.pow(p2.getX() - p1.getX(), 2) + Math.pow(p2.getY() - p1.getY(), 2) + Math.pow(p2.z - p1.z, 2));
    }

    public boolean equals(Object obj) {
        if (super.equals(obj)) {
            Point3D p3d = (Point3D) obj;
            return z == p3d.z;
        }
        return false;
    }

    public static Point3D p2dTop3d(Point2D p) {
        return new Point3D(p.getX(), p.getY());
    }

    public String toString() {
        return "(" + getX() + "," + getY() + "," + z + ")";
    }
}

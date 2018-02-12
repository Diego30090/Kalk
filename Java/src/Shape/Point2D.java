package Shape;

public class Point2D {
    private double x;
    private double y;

    public Point2D() {
        x = 0;
        y = 0;
    }

    public Point2D(double _x) {
        x = _x;
        y = 0;
    }

    public Point2D(double _x, double _y) {
        this(_x);
        y = _y;
    }

    public Point2D(Point2D p2d) {
        x = p2d.x;
        y = p2d.y;
    }

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public void setX(double nx) {
        x = nx;
    }

    public void setY(double ny) {
        y = ny;
    }

    public static double distance(Point2D p1, Point2D p2) {
        return Math.sqrt(Math.pow(p2.x - p1.x, 2) + Math.pow(p2.y - p1.y, 2));
    }

    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj != null && obj.getClass() == getClass()) {
            return x == ((Point2D) obj).x && y == ((Point2D) obj).y;
        }
        return false;
    }

    public String toString() {
        return "(" + x + "," + y + ")";
    }

}

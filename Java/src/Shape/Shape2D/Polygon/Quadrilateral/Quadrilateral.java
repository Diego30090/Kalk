package Shape.Shape2D.Polygon.Quadrilateral;

import Color.ColorRGB;
import Shape.Point2D;
import Shape.Shape2D.Polygon.Polygon;

import java.util.ArrayList;

public abstract class Quadrilateral extends Polygon {

    public Quadrilateral(ArrayList<Point2D> p, String name) {
        super(p, name);
    }

    public Quadrilateral(ArrayList<Point2D> p, String name, ColorRGB color) {
        super(p, name, color);
    }

    public Quadrilateral(Quadrilateral q) {
        super(q);
    }

}

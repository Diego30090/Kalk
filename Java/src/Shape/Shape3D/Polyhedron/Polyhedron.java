package Shape.Shape3D.Polyhedron;

import Color.ColorRGB;
import Shape.Point3D;
import Shape.Shape2D.Shape2D;
import Shape.Shape3D.Shape3D;

import java.util.ArrayList;

public abstract class Polyhedron extends Shape3D {

    public Polyhedron(ArrayList<Point3D> p, Shape2D bShape, String name) {
        super(p, bShape, name);
    }

    public Polyhedron(ArrayList<Point3D> p, Shape2D bShape, String name, ColorRGB color) {
        super(p, bShape, name, color);
    }

    public Polyhedron(Polyhedron p) {
        super(p);
    }

    public abstract int getNumberCorner();

    public abstract int getNumberFaces();

    public abstract double lateralSurface();

}

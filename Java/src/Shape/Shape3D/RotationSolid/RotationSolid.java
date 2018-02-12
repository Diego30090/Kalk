package Shape.Shape3D.RotationSolid;

import Color.ColorRGB;
import Shape.Point3D;
import Shape.Shape2D.Shape2D;
import Shape.Shape3D.Shape3D;

import java.util.ArrayList;

public abstract class RotationSolid extends Shape3D {

    public RotationSolid(ArrayList<Point3D> p, Shape2D bShape, String name) {
        super(p, bShape, name);
    }

    public RotationSolid(ArrayList<Point3D> p, Shape2D bShape, String name, ColorRGB color) {
        super(p, bShape, name, color);
    }

    public RotationSolid(RotationSolid rs) {
        super(rs);
    }
}

import Color.ColorRGB;
import Color.ColorRGBA;
import Shape.Point2D;
import Shape.Shape2D.Circle;
import Shape.Shape2D.Polygon.Quadrilateral.Rectangle;
import Shape.Shape2D.Polygon.Quadrilateral.Square;
import Shape.Shape2D.Polygon.Triangle.IsoscelesTriangle;
import Shape.Shape2D.Polygon.Triangle.RightTriangle;
import Shape.Shape3D.Polyhedron.Cube;
import Shape.Shape3D.RotationSolid.Cylinder;
import Shape.Shape3D.RotationSolid.Sphere;

public class Use {
    public static void main(String[] args) {
        System.out.println(
                "#####################################\n" +
                        "Collaudo dell'implementazione di\nalcune classi concrete\ne di alcuni metodi\n" +
                        "#####################################\n"
        );

        //COLORS TEST BEGIN
        System.out.println("COLORS TEST BEGIN\n");
        ColorRGB crgb = new ColorRGB((short) 42, (short) 5, (short) 32);
        ColorRGB crgb1 = new ColorRGB((short) 84, (short) 20, (short) 346);
        ColorRGBA crgba = new ColorRGBA((short) 42, (short) 5, (short) 32);
        ColorRGBA crgba2 = new ColorRGBA((short) 234, (short) 456, (short) 5645, (short) 345);
        ColorRGB crgba1 = new ColorRGBA(crgba2);
        System.out.println("crgba1 equals to crgba 2? " + crgba1.equals(crgba2));
        System.out.println("---------------------");
        System.out.println("crgba1 equals to crgba ? " + crgb.equals(crgba));
        System.out.println("---------------------");
        System.out.println("Print crgb: " + crgb);
        System.out.println("---------------------");
        System.out.println("Print : " + crgba1);
        System.out.println("---------------------");
        crgba = crgba.sum(crgba1);
        System.out.println(crgba);
        System.out.println("crgb + crgba = " + crgb);
        System.out.println("---------------------");
        crgb1 = crgb1.div(crgb);
        System.out.println("crgba / crgba1 = " + crgb1);
        System.out.println("---------------------");
        System.out.println("\nCOLORS TEST END\n\n");
        //END COLORS TEST

        //SHAPE2D TEST BEGIN
        System.out.println("SHAPE2D TEST BEGIN\n");
        Circle c = new Circle(5, crgb);
        Circle c1 = new Circle(5, crgba);
        c = c.div(c1);
        System.out.println(c);
        System.out.println("---------------------");
        Square s = new Square(10, crgb);
        Square s1 = new Square(5, crgba1);
        s = s.sum(c);
        c = c.sub(s1);
        System.out.println(c);
        System.out.println("---------------------");
        Rectangle rect = new Rectangle(4, 6, crgb);
        System.out.println(s);
        System.out.println("---------------------");
        RightTriangle rt = new RightTriangle(4, 5, new ColorRGBA((short) 100, (short) 30, (short) 40, (short) 89));
        IsoscelesTriangle it = new IsoscelesTriangle(5, 7, new ColorRGB((short) 50));
        it = it.mul(rt);
        System.out.println(it);
        System.out.println("Before translate ");
        for (int i = 0; i < rt.getPoints().size(); i++) {
            System.out.println(rt.getPoints().get(i));
        }
        rt.translate(new Point2D(2, 4));
        System.out.println("After translate ");
        for (int i = 0; i < rt.getPoints().size(); i++) {
            System.out.println(rt.getPoints().get(i));
        }
        System.out.println("---------------------");
        System.out.println("\nSHAPE2D TEST END\n\n");
        //SHAPE2D TEST END

        //SHAPE3D TEST BEGIN
        System.out.println("SHAPE3D TEST BEGIN\n");

        Cube cube = new Cube(s, crgba);
        System.out.println(cube);
        System.out.println("---------------------");
        Sphere sphere = new Sphere(new Circle(5), crgb);
        cube = cube.sum(sphere);
        System.out.println(sphere);
        System.out.println("---------------------");
        System.out.println(cube);
        System.out.println("---------------------");
        Cylinder cylinder = new Cylinder(rect, crgb1);
        Cylinder cylinder1 = new Cylinder(cylinder);
        System.out.println("Cylinder1 is equal to Cylinder? " + cylinder1.equals(cylinder));
        System.out.println("---------------------");
        cylinder = cylinder.mul(sphere);
        System.out.println(cylinder);
        System.out.println("---------------------");
        System.out.println(sphere.div(cylinder));
        System.out.println("---------------------");
        System.out.println("Circle c is equals to Cylinder cylinder? " + c.equals(cylinder));

        System.out.println("\nSHAPE3D TEST END\n\n");
        //SHAPE3D TEST END
    }
}

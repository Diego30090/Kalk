package Shape;

import Color.ColorRGB;

public abstract class Shape {
    private String name;
    private ColorRGB color;

    public Shape(String n) {
        name = n;
        color = new ColorRGB();
    }

    public Shape(String n, ColorRGB c) {
        this(n);
        color = c;
    }

    public Shape(Shape s) {
        name = s.name;
        color = s.color;
    }

    public abstract int getNumberVertex();

    public ColorRGB getColor() {
        return color;
    }

    public void setColor(ColorRGB c) {
        color = c;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj != null && obj.getClass() == getClass()) {
            return name.equals(((Shape) obj).name) && color.equals(((Shape) obj).color);
        }
        return false;
    }

    public String toString() {
        return "Name: " + name + "\n" + "Color: " + color + "\n";
    }
}

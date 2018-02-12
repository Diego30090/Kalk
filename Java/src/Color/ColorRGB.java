package Color;

import Interface.ICalculable;

public class ColorRGB implements ICalculable<ColorRGB> {
    private short red;
    private short green;
    private short blue;

    public ColorRGB() {
        red = 0;
        green = 0;
        blue = 0;
    }

    public ColorRGB(short r) {
        red = (short) (Math.abs(r) % 256);
        green = 0;
        blue = 0;
    }

    public ColorRGB(short r, short g) {
        this(r);
        green = (short) (Math.abs(g) % 256);
        blue = 0;
    }

    public ColorRGB(short r, short g, short b) {
        this(r, g);
        blue = (short) (Math.abs(b) % 256);
    }

    public ColorRGB(ColorRGB crgb) {
        red = crgb.red;
        green = crgb.green;
        blue = crgb.blue;
    }

    public short getRed() {
        return red;
    }

    public short getGreen() {
        return green;
    }

    public short getBlue() {
        return blue;
    }

    public ColorRGB sum(ColorRGB crgb) {
        return new ColorRGB((short) (red + crgb.red), (short) (green + crgb.green), (short) (blue + crgb.blue));
    }

    public ColorRGB sub(ColorRGB crgb) {
        return new ColorRGB((short) (red - crgb.red), (short) (green - crgb.green), (short) (blue - crgb.blue));
    }

    public ColorRGB mul(ColorRGB crgb) {
        return new ColorRGB((short) (red * crgb.red), (short) (green * crgb.green), (short) (blue * crgb.blue));
    }

    public ColorRGB div(ColorRGB crgb) {
        if (crgb.red == 0 || crgb.green == 0 || crgb.blue == 0) {
            return new ColorRGB(this);
        }

        return new ColorRGB((short) (red / crgb.red), (short) (green / crgb.green), (short) (blue / crgb.blue));
    }

    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj != null && obj.getClass() == getClass()) {
            return red == ((ColorRGB) obj).red && green == ((ColorRGB) obj).green
                    && blue == ((ColorRGB) obj).blue;
        }
        return false;
    }

    public String toString() {
        return "ColorRGB(" + red + "," + green + "," + blue + ")";
    }
}

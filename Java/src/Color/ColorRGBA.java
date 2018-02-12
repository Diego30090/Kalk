package Color;

public class ColorRGBA extends ColorRGB {
    private short alpha;

    public ColorRGBA() {
        super();
        alpha = 0;
    }

    public ColorRGBA(short a) {
        super();
        alpha = (short) (Math.abs(a) % 256);
    }

    public ColorRGBA(short r, short a) {
        super(r);
        alpha = (short) (Math.abs(a) % 256);
    }

    public ColorRGBA(short r, short g, short a) {
        super(r, g);
        alpha = (short) (Math.abs(a) % 256);
    }

    public ColorRGBA(short r, short g, short b, short a) {
        super(r, g, b);
        alpha = (short) (Math.abs(a) % 256);
    }

    public ColorRGBA(ColorRGBA crgba) {
        super(crgba);
        alpha = crgba.alpha;
    }

    public short getAlpha() {
        return alpha;
    }

    public ColorRGBA sum(ColorRGB crgba) {
        ColorRGB tmp = super.sum(crgba);
        if (getClass() == crgba.getClass()) {
            ColorRGBA c = (ColorRGBA) crgba;
            return new ColorRGBA(tmp.getRed(), tmp.getGreen(), tmp.getBlue(), (short) (alpha + c.alpha));
        } else {
            return new ColorRGBA(tmp.getRed(), tmp.getGreen(), tmp.getBlue(), alpha);
        }
    }

    public ColorRGBA sub(ColorRGB crgba) {
        ColorRGB tmp = super.sub(crgba);
        if (getClass() == crgba.getClass()) {
            ColorRGBA c = (ColorRGBA) crgba;
            return new ColorRGBA(tmp.getRed(), tmp.getGreen(), tmp.getBlue(), (short) (alpha - c.alpha));
        } else {
            return new ColorRGBA(tmp.getRed(), tmp.getGreen(), tmp.getBlue(), alpha);
        }
    }

    public ColorRGBA mul(ColorRGB crgba) {
        ColorRGB tmp = super.mul(crgba);
        if (getClass() == crgba.getClass()) {
            ColorRGBA c = (ColorRGBA) crgba;
            return new ColorRGBA(tmp.getRed(), tmp.getGreen(), tmp.getBlue(), (short) (alpha * c.alpha));
        } else {
            return new ColorRGBA(tmp.getRed(), tmp.getGreen(), tmp.getBlue(), alpha);
        }
    }


    public ColorRGBA div(ColorRGB crgba) {
        ColorRGB tmp = super.div(crgba);
        if (getClass() == crgba.getClass()) {
            ColorRGBA c = (ColorRGBA) crgba;
            if (alpha == 0)
                return new ColorRGBA(this);
            return new ColorRGBA(tmp.getRed(), tmp.getGreen(), tmp.getBlue(), (short) (alpha / c.alpha));
        } else {
            return new ColorRGBA(tmp.getRed(), tmp.getGreen(), tmp.getBlue(), alpha);
        }
    }

    public boolean equals(Object obj) {
        if (super.equals(obj)) {
            ColorRGBA crgba = (ColorRGBA) obj;
            return alpha == crgba.alpha;
        }
        return false;
    }

    public String toString() {
        return "ColorRGBA(" + getRed() + "," + getGreen() + "," + getBlue() + "," + alpha + ")";
    }
}

//（2）矩形Rectangle设计（20分）
//  1）继承Shape（2分）
//        2）新增属性：长、宽（5分）
//        3）构造器：Rectangle(String shapeName, String shapeID, String color, double borderWidth, double length, double width)（5分）
//        4）get方法、set方法（4分）
//        5）重写toString方法：打印矩形的所有属性信息（4分）

public class Rectangle extends Shape {
    private double length;
    private double width;

    public Rectangle(String shapeName, String shapeID, String color, double borderWidth, double length, double width) {
        super(shapeName, shapeID, color, borderWidth);
        this.length = length;
        this.width = width;
    }

    public double getLength() {
        return length;
    }

    public void setLength(double length) {
        this.length = length;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }
    public String toString() {
        return "正方形{" + "长=" + length + ", 宽=" + width + ", 图形名='" + getShapeName() + '\'' + ",ID='" + getShapeID() + '\'' + ", 颜色='" + getColor() + '\'' + ", 边框宽度=" + getBorderWidth() + '}';
    }
}

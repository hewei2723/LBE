//（3）圆Circle设计（20分）
//        1）继承Shape（2分）
//        2）新增属性：半径（5分）
//        3）构造器：Circle(String shapeName, String shapeID, String color, double borderWidth, double radius)（5分）
//        4）get方法、set方法（4分）
//        5）重写toString方法：打印圆的所有属性信息（4分）
public class Circle extends Shape
{
    private double radius;
    public Circle(String shapeName, String shapeID, String color, double borderWidth, double radius)
    {
        super(shapeName, shapeID, color, borderWidth);
        this.radius = radius;}
    public double getRadius()
    {return radius;}
    public void setRadius(double radius)
    {this.radius = radius;}
    public String toString() {
        return "图形 半径 图形名 ID 颜色 边框宽度\n" +
                "圆形 " + radius + " " + getShapeName() + " " + getShapeID() + " " + getColor() + " " + getBorderWidth();
    }}
//1）图形父类Shape设计（30分）
//        1）属性：图形名称、图形编号、颜色、边框宽度（6分） 完成🐕
//        2）构造器：Shape(String shapeName, String shapeID, String color, double borderWidth)（6分）
//        3）get方法、set方法（6分）
//        4）重写toString方法：打印图形的所有属性信息（6分）
//        5）重写equals函数：实现比较两种图形的图形编号是否相同，如果相同则返回true，否则返回false（6分）
public class Shape {
    private String shapeName;
    private String shapeID;
    private String color;
    private double borderWidth;
    public Shape(String shapeName, String shapeID, String color, double borderWidth) {
        this.shapeName = shapeName;
        this.shapeID = shapeID;
        this.color = color;
        this.borderWidth = borderWidth;
    }

    public String getShapeName() {
        return shapeName;
    }

    public void setShapeName(String shapeName) {
        this.shapeName = shapeName;
    }

    public String getShapeID() {
        return shapeID;
    }

    public void setShapeID(String shapeID) {
        this.shapeID = shapeID;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public double getBorderWidth() {
        return borderWidth;
    }

    public void setBorderWidth(double borderWidth) {
        this.borderWidth = borderWidth;
    }

    public String toString() {
        return "图形{" +
                "图名='" + shapeName + '\'' +
                ", 图编号='" + shapeID + '\'' +
                ", 颜色='" + color + '\'' +
                ", 图边框宽度=" + borderWidth +
                '}';
    }
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass())
            return false;//如果两个对象相等，则返回true，否则返回false
        Shape shape = (Shape) obj;
        return shapeID.equals(shape.shapeID);
    }
}

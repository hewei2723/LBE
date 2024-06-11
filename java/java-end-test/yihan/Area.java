public class Area extends Rectangle implements AreaCalculable
{
    public Area(String shapeName, String shapeID, String color, double borderWidth, double length, double width) {
        super(shapeName, shapeID, color, borderWidth, length, width);}
    public double calculateArea()
    {
        return getLength() * getWidth();}

    public String toString()
    {
        return super.toString() + ", 面积=" + calculateArea();}}

class CircleArea extends Circle implements AreaCalculable
{
    public CircleArea(String shapeName, String shapeID, String color, double borderWidth, double radius) {
        super(shapeName, shapeID, color, borderWidth, radius);}

    public double calculateArea()
    {
        return Math.PI * getRadius() * getRadius();}

    public String toString()
    {
        return super.toString() + ", 面积=" + calculateArea();}
}

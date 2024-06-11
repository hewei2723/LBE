package shapeAbstract;

public class Circle extends Shape{
    private double r;

    public Circle(String name,double r){
        super(name);
       // this.setName(name);
        this.r=r;

    }
    @Override
    public double getArea() {
        return Math.PI*r*r;
    }
}

//
//（3）三轮电动车ThreeWheeler设计（20分）

public class ThreeWheeler extends ElectricVehicle
{
    //        1）继承ElectricVehicle（2分）
    private int cargoCapacity;//车厢容量
    private boolean Top;//顶棚
    public ThreeWheeler(String vehicleName, String vehicleID, int batteryCapacity, int range, int maxSpeed,String batType,int price, int cargoCapacity,boolean Top)
    {
        super(vehicleName, vehicleID, batteryCapacity, range, maxSpeed,batType,price);
        this.cargoCapacity = cargoCapacity;
        this.Top=Top;
    }
    //        4）get方法、set方法（4分）
    public int getCargoCapacity()
    {
        return cargoCapacity;
    }

    public void setCargoCapacity(int cargoCapacity)
    {
        this.cargoCapacity = cargoCapacity;
    }

    public boolean isTop() {
        return Top;
    }

    public void setTop(boolean top) {
        this.Top = Top;
    }

    //        5）重写toString方法：打印三轮电动车的所有属性信息（4分）
    public String getName()
    {
        return "交通工具名字: " + getVehicleName();
//                + ", ID: " + getVehicleID() +
//                ", 电池容量: " + getBatteryCapacity() + ", 最大行程数: " + getRange() +
//                ", 最大速度: " + getMaxSpeed() +"电池类型"+ getBatType()+"价格"+getPrice() + "车厢容量"+cargoCapacity+"是否有顶棚"+Top;
    }

}

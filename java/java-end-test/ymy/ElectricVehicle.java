//（1）电动车父类ElectricVehicle设计（30分）
public class ElectricVehicle
{
    private String vehicleName;
    private String vehicleID;
    private int batteryCapacity;
    private int range;
    private String  batType;
    private int price;
    private int maxSpeed;
    //        1）属性：电动车名称、电动车编号、电池容量、续航里程、最大速度（6分）
    //        2）构造器：ElectricVehicle(String vehicleName, String vehicleID, int batteryCapacity, int range, int maxSpeed)（6分）
    public ElectricVehicle(String vehicleName, String vehicleID, int batteryCapacity, int range, int maxSpeed,String  batType,int price) {
        this.vehicleName = vehicleName;
        this.vehicleID = vehicleID;
        this.batteryCapacity = batteryCapacity;
        this.range = range;
        this.maxSpeed = maxSpeed;
        this.batType=batType;
        this.price=price;
    }
    //        3）get方法、set方法（6分）
    public String getVehicleName()
    {
        return vehicleName;
    }

    public void setVehicleName(String vehicleName)
    {
        this.vehicleName = vehicleName;
    }

    public String getVehicleID()
    {
        return vehicleID;
    }

    public void setVehicleID(String vehicleID)
    {
        this.vehicleID = vehicleID;
    }

    public int getBatteryCapacity()
    {
        return batteryCapacity;
    }

    public void setBatteryCapacity(int batteryCapacity)
    {
        this.batteryCapacity = batteryCapacity;
    }

    public int getRange()
    {
        return range;
    }

    public void setRange(int range)
    {
        this.range = range;
    }

    public int getMaxSpeed()
    {
        return maxSpeed;
    }

    public void setMaxSpeed(int maxSpeed) {
        this.maxSpeed = maxSpeed;
    }

    public String  getBatType() {
        return batType;
    }

    public void setBatType(String batType) {
        this.batType = batType;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }
    //        4）重写toString方法：打印电动车的所有属性信息（6分）
    public String toString()
    {
        return "交通工具名字: " + getVehicleName() + ", ID: " + getVehicleID() + ", 电池容量: " + getBatteryCapacity() +
                ", 最大行程数: " + getRange() + ", 最大速度: " + getMaxSpeed() + "，电池类型:"+getBatType() + "，价格"+getPrice();
    }
    //        5）重写equals函数：实现比较两种电动车的电动车编号是否相同，如果相同则返回true，否则返回false（6分）
    public boolean equals(Object hhh)
    {
        if (this == hhh) return true;
        if (hhh == null || getClass() != hhh.getClass()) return false;
        ElectricVehicle that = (ElectricVehicle) hhh;
        return vehicleID.equals(that.vehicleID);
    }
}

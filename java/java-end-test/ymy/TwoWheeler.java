//
//（2）两轮电动车TwoWheeler设计（20分）
public class TwoWheeler extends ElectricVehicle
{
    //        1）继承ElectricVehicle（2分）
    private int Tire;//轮胎尺寸
    private int Load;//载重

    //        2）新增属性：是否折叠（5分）
    //        3）构造器：TwoWheeler(String vehicleName, String vehicleID, int batteryCapacity, int range, int maxSpeed, boolean isFoldable)（5分）
    public TwoWheeler(String vehicleName, String vehicleID, int batteryCapacity, int range, int maxSpeed,String batType,int price,int Tire,int Load)
    {
        super(vehicleName, vehicleID, batteryCapacity, range, maxSpeed,batType,price);
        this.Load=Load;
        this.Tire=Tire;
    }

    public int getTire() {
        return Tire;
    }

    public void setTire(int tire) {
        this.Tire = Tire;
    }

    public int getLoad() {
        return Load;
    }

    public void setLoad(int load) {
        this.Load = Load;
    }

    //get方法、set方法（4分）
    //重写toString方法：打印两轮电动车的所有属性信息（4分）
    public String toString()
    {
        return "两轮:" + "名字='" + getVehicleName() + ", ID='" + getVehicleID() + ", " +
                "电池容量=" + getBatteryCapacity() + ", 公里数=" + getRange() + ", " +
                "最大速度=" + getMaxSpeed() +" ,电池类型"+","+ getBatType()+ " ,价格" +getPrice() + ", "+"轮胎尺寸=" + Tire + " 载重"+Load;
    }
}

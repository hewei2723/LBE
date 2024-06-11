//（5）接口实现类设计（10分）
//两轮电动车实现充电接口：每次充电时，输出“两轮电动车已充电”（5分）
//三轮电动车实现充电接口：每次充电时，输出“三轮电动车已充电”（5分）
public class ChargeTwoWheeler extends TwoWheeler implements ChargeVehicle
{
    public ChargeTwoWheeler(String vehicleName, String vehicleID, int batteryCapacity, int range, int maxSpeed,String batType,int price,int Tire,int Load) {
        super(vehicleName, vehicleID, batteryCapacity, range, maxSpeed,batType,price,Tire,Load);
    }

    public void charge()
    {
        System.out.println("两轮电动车已充电 充电功率：200W 充电状态：正在充电");
    }
}

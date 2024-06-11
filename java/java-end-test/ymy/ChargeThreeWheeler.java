//（5）接口实现类设计（10分）
//两轮电动车实现充电接口：每次充电时，输出“两轮电动车已充电”（5分）
//三轮电动车实现充电接口：每次充电时，输出“三轮电动车已充电”（5分）
public class ChargeThreeWheeler extends ThreeWheeler implements ChargeVehicle
{
    public ChargeThreeWheeler(String vehicleName, String vehicleID, int batteryCapacity, int range, int maxSpeed,String  batType,int price,int cargoCapacity,boolean Top) {
        super(vehicleName, vehicleID, batteryCapacity, range, maxSpeed,batType,price,cargoCapacity,Top);
    }

    public void charge()
    {
        System.out.println("三轮电动车已充电 输入功率：100w 充电状态：正在充电中");
    }
}

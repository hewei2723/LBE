import java.util.Random;

public class ElectricVehicleTest {
    private static ChargeTwoWheeler[] twoWheelers = new ChargeTwoWheeler[28];
    private static ChargeThreeWheeler[] threeWheelers = new ChargeThreeWheeler[28];
    public static void main(String[] args) {
        // 创建电动车
        createVehicles();
        // 查找电动车
        String vehicleID = "两轮1";
        ElectricVehicle vehicle = findVehicle(vehicleID);

        // 修改电动车信息并打印前后对比
        if (vehicle != null) {
            System.out.println("修改前: " + vehicle);
            SearchAndChange(vehicle);
            System.out.println("修改后: " + vehicle);
        }
        // 调用接口方法
        chargeVehicle(vehicleID);
        // 删除电动车并插入新的电动车
        deleteVehicle(vehicleID);
        addVehicle(new ChargeTwoWheeler("三轮车", "两轮1", 2600, 110, 70, "锂电池", 2600, 50, 2400));
        // 打印所有电动车信息
        printVehicles();
    }
    private static void createVehicles() {
        Random random = new Random();
        // 初始化一些两轮电动车
        for (int i = 0; i < 4; i++) {
            twoWheelers[i] = new ChargeTwoWheeler("自行车" + (i + 1), "两轮" + (i + 1),
                    2000 + random.nextInt(2000), 100 + random.nextInt(50),
                    50 + random.nextInt(50), "锂电池", 2000 + random.nextInt(1000),
                    40 + random.nextInt(20), 2000 + random.nextInt(1000));
        }
        // 初始化一些三轮电动车
        for (int i = 0; i < 4; i++) {
            threeWheelers[i] = new ChargeThreeWheeler("三轮车" + (i + 1), "三轮" + (i + 1),
                    3000 + random.nextInt(2000), 150 + random.nextInt(50),
                    30 + random.nextInt(30), "铅蓄电池", 2500 + random.nextInt(1500),
                    40 + random.nextInt(20), random.nextBoolean());
        }
    }
    private static ElectricVehicle findVehicle(String vehicleID) {
        for (ChargeTwoWheeler twoWheeler : twoWheelers) {
            if (twoWheeler != null && twoWheeler.getVehicleID().equals(vehicleID)) {
                System.out.println("找到两轮电动车: " + twoWheeler);
                return twoWheeler;
            }
        }
        for (ChargeThreeWheeler threeWheeler : threeWheelers) {
            if (threeWheeler != null && threeWheeler.getVehicleID().equals(vehicleID)) {
                System.out.println("找到三轮电动车: " + threeWheeler);
                return threeWheeler;
            }
        }
        System.out.println("未找到电动车: " + vehicleID);
        return null;
    }
    private static void SearchAndChange(ElectricVehicle vehicle) {
        if (vehicle instanceof ChargeTwoWheeler) {
            ChargeTwoWheeler twoWheeler = (ChargeTwoWheeler) vehicle;
            twoWheeler.setPrice(twoWheeler.getPrice() + 500);
            twoWheeler.setLoad(twoWheeler.getLoad() + 5);
            twoWheeler.setMaxSpeed(twoWheeler.getMaxSpeed() + 10);
        } else if (vehicle instanceof ChargeThreeWheeler) {
            ChargeThreeWheeler threeWheeler = (ChargeThreeWheeler) vehicle;
            threeWheeler.setPrice(threeWheeler.getPrice() + 700);

        }
    }
    private static void addVehicle(ElectricVehicle vehicle) {
        if (vehicle instanceof ChargeTwoWheeler) {
            for (int i = 0; i < twoWheelers.length; i++) {
                if (twoWheelers[i] == null) {
                    twoWheelers[i] = (ChargeTwoWheeler) vehicle;
                    System.out.println("两轮电动车已添加: " + vehicle);
                    return;
                }
            }
        } else if (vehicle instanceof ChargeThreeWheeler) {
            for (int i = 0; i < threeWheelers.length; i++) {
                if (threeWheelers[i] == null) {
                    threeWheelers[i] = (ChargeThreeWheeler) vehicle;
                    System.out.println("三轮电动车已添加: " + vehicle);
                    return;
                }
            }
        }
        System.out.println("车位不够了");
    }
    private static void deleteVehicle(String vehicleID) {
        for (int i = 0; i < twoWheelers.length; i++) {
            if (twoWheelers[i] != null && twoWheelers[i].getVehicleID().equals(vehicleID)) {
                System.out.println("删除两轮电动车: " + twoWheelers[i]);
                twoWheelers[i] = null;
                return;
            }
        }
        for (int i = 0; i < threeWheelers.length; i++) {
            if (threeWheelers[i] != null && threeWheelers[i].getVehicleID().equals(vehicleID)) {
                System.out.println("删除三轮电动车: " + threeWheelers[i]);
                threeWheelers[i] = null;
                return;
            }
        }
        System.out.println("未找到电动车: " + vehicleID);
    }

    private static void chargeVehicle(String vehicleID) {
        for (ChargeTwoWheeler twoWheeler : twoWheelers) {
            if (twoWheeler != null && twoWheeler.getVehicleID().equals(vehicleID)) {
                twoWheeler.charge();
                return;
            }
        }
        for (ChargeThreeWheeler threeWheeler : threeWheelers) {
            if (threeWheeler != null && threeWheeler.getVehicleID().equals(vehicleID)) {
                threeWheeler.charge();
                return;
            }
        }
        System.out.println("未找到电动车: " + vehicleID);
    }

    private static void printVehicles() {
        System.out.println("所有两轮电动车信息：");
        for (ChargeTwoWheeler twoWheeler : twoWheelers) {
            if (twoWheeler != null) {
                System.out.println(twoWheeler);
            }
        }
        System.out.println("所有三轮电动车信息：");
        for (ChargeThreeWheeler threeWheeler : threeWheelers) {
            if (threeWheeler != null) {
                System.out.println(threeWheeler);
            }
        }
    }
}

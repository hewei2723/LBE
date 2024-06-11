public class six {
    public static void main(String[] args) {
        int[] array = {74, 84, 142, 20, 25};  // 定义数组
        // 外层循环控制排序轮数
        // 最后一个元素，不用再比较
        for (int i = 0; i < array.length - 1; i++) {
            // 内层循环控制元素两两比较的次数
            // 每轮循环沉底一个元素，沉底元素不用再参加比较
            for (int j = 0; j < array.length - 1 - i; j++) {
                // 比较相邻元素
                if (array[j] > array[j + 1]) {
                    // 交换元素
                    int tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                }
            }
            // 打印每轮排序结果
            System.out.print("第" + (i + 1) + "轮排序：");
            for (int j = 0; j < array.length; j++) {
                System.out.print(array[j] + "\t");
            }
            System.out.println();
        }
        System.out.print("最终排序 ：");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + "\t");
        }
        System.out.println();
    }
}
public class Main{
    public static void main(String[] args){
        int[] arr = {1, 2, 3, 4, 5};
        int[] result = reverseArray(arr);
        for (int j : result) {
            System.out.print(j + " ");
        }
    }
    public static int[] reverseArray(int[] arr){
        int[] result = new int[arr.length];
        for(int i = 0; i < arr.length; i++){
            result[i] = arr[arr.length - 1 - i];
        }
        return result;
    }
}
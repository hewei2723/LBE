public class for1 {
    public  static  void main(String[]args){
        System.out.println(sum(5));
    }
    public static int sum(int n){
        int sn=0;
        for (int i = 1; i <=n ; i++) {
            sn += (int) ((2 * (Math.pow(10, i) - 1)) / 9);
        }
        return sn;
    }
}

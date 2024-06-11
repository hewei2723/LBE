
package 习题;
public class Num {
    public static void main(String[] args){
        @SuppressWarnings("unused")
        int n=3;
        int i=1;
        for (int j = 1; j<=i; j++){
            for (int k=1;k<=j;k++){
                for (int l=1;l<=k;l++){
                    i++;
                    System.out.print(i);
                }
            }
        }

    }
}

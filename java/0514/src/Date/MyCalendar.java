package src.Date;
import java.text.SimpleDateFormat;
import java.util.Calendar;
/**
 * @author lvna
 * @create 2024-05-10 11:20
 * @description
 */
public class MyCalendar {
    public static void main(String[] args) {
        Calendar c=Calendar.getInstance();
        System.out.println(c.get(Calendar.YEAR));
        System.out.println(c.get(Calendar.MONTH));//1月是0
        System.out.println(c.get(Calendar.DAY_OF_MONTH));
        c.set(Calendar.YEAR,2023);
        c.set(Calendar.MONTH,6);
        c.set(Calendar.DAY_OF_MONTH,1);
        System.out.println(c);
        System.out.println(c.getTime());
        SimpleDateFormat sdf=new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        String s=sdf.format(c.getTime());
        System.out.println(s);
        c.set(Calendar.MONTH,7);
        s=sdf.format(c.getTime());
        System.out.println(s);
        //输出2024年5月日历
        c.set(Calendar.YEAR,2024);
        c.set(Calendar.MONTH,4);
        c.set(Calendar.DAY_OF_MONTH,1);
        int year=c.get(Calendar.YEAR);
        int month=c.get(Calendar.MONTH)+1;
        int maxDay=c.getActualMaximum(Calendar.DAY_OF_MONTH);
        int day_of_week=c.get(Calendar.DAY_OF_WEEK)-1;
        if(day_of_week==0){
            day_of_week=7;
        }
        System.out.println("************"+year+"年"+month+"月日历*************");
        System.out.println("一\t二\t三\t四\t五\t六\t日");
        for (int t=1;t<day_of_week;t++){
            System.out.print("\t");
        }
        for (int day=1;day<=maxDay;day++){
            System.out.print(day+"\t");
            if((day+day_of_week-1)%7==0){
                System.out.println();
            }
        }
    }
}

package map;
import java.util.Objects;

public class Student {
    String sno;
    String name;

    public Student(String sno, String name) {
        this.sno = sno;
        this.name = name;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Student student = (Student) o;
        return sno.equals(student.sno) &&  name.equals(student.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(sno,name);
    }
}

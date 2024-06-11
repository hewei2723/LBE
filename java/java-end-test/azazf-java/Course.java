
public class Course {
    private String courseName;
    private String courseID;
    private String instructor;
    private int credits;
    private String schedule;

    public Course(String courseName, String courseID, String instructor, int credits, String schedule) {
        this.courseName = courseName;
        this.courseID = courseID;
        this.instructor = instructor;
        this.credits = credits;
        this.schedule = schedule;
    }

    public String getCourseName() {
        return courseName;
    }

    public void setCourseName(String courseName) {
        this.courseName = courseName;
    }

    public String getCourseID() {
        return courseID;
    }

    public void setCourseID(String courseID) {
        this.courseID = courseID;
    }

    public String getInstructor() {
        return instructor;
    }

    public void setInstructor(String instructor) {
        this.instructor = instructor;
    }

    public int getCredits() {
        return credits;
    }

    public void setCredits(int credits) {
        this.credits = credits;
    }

    public String getSchedule() {
        return schedule;
    }

    public void setSchedule(String schedule) {
        this.schedule = schedule;
    }

    @Override
    public String toString() {
        return "Course{" +
                "courseName='" + courseName + '\'' +
                ", courseID='" + courseID + '\'' +
                ", instructor='" + instructor + '\'' +
                ", credits=" + credits +
                ", schedule='" + schedule + '\'' +
                '}';
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Course course = (Course) obj;
        return courseID.equals(course.courseID);
    }

    @Override
    public int hashCode() {
        return courseID.hashCode();
    }
}
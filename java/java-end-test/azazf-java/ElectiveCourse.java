class ElectiveCourse extends Course {
    private String prerequisite;

    public ElectiveCourse(String courseName, String courseID, String instructor, int credits, String schedule, String prerequisite) {
        super(courseName, courseID, instructor, credits, schedule);
        this.prerequisite = prerequisite;
    }

    public String getPrerequisite() {
        return prerequisite;
    }

    public void setPrerequisite(String prerequisite) {
        this.prerequisite = prerequisite;
    }

    @Override
    public String toString() {
        return super.toString() + ", prerequisite='" + prerequisite + '\'' + '}';
    }
}

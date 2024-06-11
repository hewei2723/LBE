class RequiredCourse extends Course {
    private String examType;

    public RequiredCourse(String courseName, String courseID, String instructor, int credits, String schedule, String examType) {
        super(courseName, courseID, instructor, credits, schedule);
        this.examType = examType;
    }

    public String getExamType() {
        return examType;
    }

    public void setExamType(String examType) {
        this.examType = examType;
    }

    @Override
    public String toString() {
        return super.toString() + ", examType='" + examType + '\'' + '}';
    }
}


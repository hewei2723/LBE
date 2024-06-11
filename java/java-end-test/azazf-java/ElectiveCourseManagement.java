class ElectiveCourseManagement implements CourseManagement {
    private boolean prerequisiteCompleted;

    public ElectiveCourseManagement(ElectiveCourse course, boolean prerequisiteCompleted) {
        this.prerequisiteCompleted = prerequisiteCompleted;
    }

    @Override
    public void enroll() {
        if (prerequisiteCompleted) {
            System.out.println("选修课已选");
        } else {
            System.out.println("先修课程未完成，无法选修此课程");
        }
    }
}

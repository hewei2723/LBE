#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义学生结构体
struct Student {
    int id;
    char name[50];
    int math;
    int english;
    int politics;
    int major1;
    int major2;
    int total;
};

// 比较函数用于qsort排序
int compare(const void *a, const void *b) {
    const struct Student *s1 = (const struct Student *)a;
    const struct Student *s2 = (const struct Student *)b;
    return s1->total - s2->total;
}

// 输入学生信息函数
void inputStudents(struct Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("输入学生的学号、姓名、数学、英语、政治、专业课1和专业课2成绩：\n");
        scanf("%d %s %d %d %d %d %d", &students[i].id, students[i].name, &students[i].math, &students[i].english,
              &students[i].politics, &students[i].major1, &students[i].major2);
        students[i].total = students[i].math + students[i].english + students[i].politics + students[i].major1 + students[i].major2;
    }
}

// 查询学生信息函数
void queryStudent(struct Student *students, int numStudents, int queryId) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == queryId) {
            printf("查询结果：\n");
            printf("%d %s %d %d %d %d %d %d\n", students[i].id, students[i].name, students[i].math, students[i].english,
                   students[i].politics, students[i].major1, students[i].major2, students[i].total);
            return; // 查询到结果后立即返回，无需继续遍历
        }
    }
    printf("未找到该学生信息。\n");
}

// 主函数
int main() {
    int numStudents;
    printf("输入学生人数：");
    scanf("%d", &numStudents);

    // 检查学生人数是否合法
    if (numStudents <= 0) {
        printf("学生人数不合法。\n");
        return 1; // 返回错误码
    }

    // 动态分配存储学生信息的数组
    struct Student *students = (struct Student *)malloc(numStudents * sizeof(struct Student));
    if (students == NULL) {
        printf("内存分配失败。\n");
        return 1; // 返回错误码
    }

    // 输入学生信息
    inputStudents(students, numStudents);

    // 查询学生信息
    int queryId;
    printf("输入要查询学生的学号：");
    scanf("%d", &queryId);
    queryStudent(students, numStudents, queryId);

    // 按照指定科目成绩排序
    int subjectIndex;
    printf("输入排序的科目序号：");
    scanf("%d", &subjectIndex);

    // 使用qsort函数进行排序
    qsort(students, numStudents, sizeof(struct Student), compare);

    // 输出排序后的结果
    printf("按照score[%d]进行排序，排序后的成绩表如下：\n", subjectIndex);
    for (int i = 0; i < numStudents; i++) {
        printf("%d %s %d %d %d %d %d %d\n", students[i].id, students[i].name, students[i].math, students[i].english,
               students[i].politics, students[i].major1, students[i].major2, students[i].total);
    }

    // 释放动态分配的内存
    free(students);

    return 0;
}

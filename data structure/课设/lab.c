#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Book
{
    int id;
    char title[50];
    struct Book *left;
    struct Book *right;
} Book;

typedef struct BorrowedBook
{
    int bookId;
    char title[50];
    struct BorrowedBook *next;
} BorrowedBook;

typedef struct Student
{
    int id;
    char name[50];
    BorrowedBook *borrowedBooks;
    struct Student *next;
} Student;

typedef struct StackNode
{
    char operation[50];
    struct StackNode *next;
} StackNode;

typedef struct
{
    Student *students;
    Book *books;
    StackNode *stack;
} Library;
void push(StackNode **stack, const char *operation)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    strcpy(newNode->operation, operation);
    newNode->next = *stack;
    *stack = newNode;
}

char *pop(StackNode **stack)
{
    if (*stack == NULL)
    {
        return NULL;
    }
    StackNode *temp = *stack;
    *stack = (*stack)->next;
    char *operation = temp->operation;
    free(temp);
    return operation;
}
void addStudent(Library *lib, int id, const char *name)
{
    Student *newStudent = (Student *)malloc(sizeof(Student));
    newStudent->id = id;
    strcpy(newStudent->name, name);
    newStudent->borrowedBooks = NULL;
    newStudent->next = lib->students;
    lib->students = newStudent;
    push(&lib->stack, "Added student");
}

Student *findStudent(Library *lib, int id)
{
    Student *current = lib->students;
    while (current != NULL)
    {
        if (current->id == id)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// void deleteStudent(Library *lib, int id) {
void deleteStudent(Library *lib, int id)
{
    Student *current = lib->students;
    Student *prev = NULL;
    while (current != NULL && current->id != id)
    {
        prev = current;
        current = current->next;
    }
    if (current == NULL)
    {
        return;
    }
    if (prev == NULL)
    {
        lib->students = current->next;
    }
    else
    {
        prev->next = current->next;
    }
    BorrowedBook *borrowed = current->borrowedBooks;
    while (borrowed != NULL)
    {
        BorrowedBook *temp = borrowed;
        borrowed = borrowed->next;
        free(temp);
    }
    free(current);
    push(&lib->stack, "Deleted student");
}
Book *addBook(Book *root, int id, const char *title)
{
    if (root == NULL)
    {
        Book *newBook = (Book *)malloc(sizeof(Book));
        newBook->id = id;
        strcpy(newBook->title, title);
        newBook->left = newBook->right = NULL;
        return newBook;
    }
    if (id < root->id)
    {
        root->left = addBook(root->left, id, title);
    }
    else if (id > root->id)
    {
        root->right = addBook(root->right, id, title);
    }
    return root;
}

Book *findBook(Book *root, int id)
{
    if (root == NULL || root->id == id)
    {
        return root;
    }
    if (id < root->id)
    {
        return findBook(root->left, id);
    }
    else
    {
        return findBook(root->right, id);
    }
}

Book *findMin(Book *root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Book *deleteBook(Book *root, int id)
{
    if (root == NULL)
    {
        return root;
    }
    if (id < root->id)
    {
        root->left = deleteBook(root->left, id);
    }
    else if (id > root->id)
    {
        root->right = deleteBook(root->right, id);
    }
    else
    {
        if (root->left == NULL)
        {
            Book *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Book *temp = root->left;
            free(root);
            return temp;
        }
        Book *temp = findMin(root->right);
        root->id = temp->id;
        strcpy(root->title, temp->title);
        root->right = deleteBook(root->right, temp->id);
    }
    return root;
}
void borrowBook(Library *lib, int studentId, int bookId)
{
    Student *student = findStudent(lib, studentId);
    Book *book = findBook(lib->books, bookId);
    if (student && book)
    {
        BorrowedBook *newBorrowedBook = (BorrowedBook *)malloc(sizeof(BorrowedBook));
        newBorrowedBook->bookId = book->id;
        strcpy(newBorrowedBook->title, book->title);
        newBorrowedBook->next = student->borrowedBooks;
        student->borrowedBooks = newBorrowedBook;
        push(&lib->stack, "Borrowed book");
    }
}

void returnBook(Library *lib, int studentId, int bookId)
{
    Student *student = findStudent(lib, studentId);
    if (student)
    {
        BorrowedBook *current = student->borrowedBooks;
        BorrowedBook *prev = NULL;
        while (current != NULL && current->bookId != bookId)
        {
            prev = current;
            current = current->next;
        }
        if (current == NULL)
        {
            return;
        }
        if (prev == NULL)
        {
            student->borrowedBooks = current->next;
        }
        else
        {
            prev->next = current->next;
        }
        free(current);
        push(&lib->stack, "Returned book");
    }
}
void saveStudents(Library *lib, const char *filename)
{
    FILE *file = fopen(filename, "w");
    Student *current = lib->students;
    while (current != NULL)
    {
        fprintf(file, "%d %s\n", current->id, current->name);
        BorrowedBook *borrowed = current->borrowedBooks;
        while (borrowed != NULL)
        {
            fprintf(file, "  %d %s\n", borrowed->bookId, borrowed->title);
            borrowed = borrowed->next;
        }
        current = current->next;
    }
    fclose(file);
}

void loadStudents(Library *lib, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return;
    }
    int id;
    char name[50];
    while (fscanf(file, "%d %s", &id, name) != EOF)
    {
        addStudent(lib, id, name);
        while (fscanf(file, " %d %s", &id, name) == 2)
        {
            borrowBook(lib, id, id); // Borrow book for student
        }
    }
    fclose(file);
}

void saveBooks(Book *root, FILE *file)
{
    if (root != NULL)
    {
        fprintf(file, "%d %s\n", root->id, root->title);
        saveBooks(root->left, file);
        saveBooks(root->right, file);
    }
}

void loadBooks(Library *lib, const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return;
    }
    int id;
    char title[50];
    while (fscanf(file, "%d %s", &id, title) != EOF)
    {
        lib->books = addBook(lib->books, id, title);
    }
    fclose(file);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generateRandomName(char *name) {
    const char *names[] = {"Alice", "Bob", "Charlie", "David", "Eva", "Frank", "Grace", "Hannah", "Ivy", "Jack"};
    strcpy(name, names[rand() % 10]);
}

void generateRandomTitle(char *title) {
    const char *titles[] = {"BookA", "BookB", "BookC", "BookD", "BookE", "BookF", "BookG", "BookH", "BookI", "BookJ"};
    strcpy(title, titles[rand() % 10]);
}

int main() {
    srand(time(NULL));

    Library lib = {NULL, NULL, NULL};

    // 加载学生和图书信息
    loadStudents(&lib, "students.txt");
    loadBooks(&lib, "books.txt");

    char input[100];
    printf("1. 添加学生\n");
        printf("2. 查找学生\n");
        printf("3. 删除学生\n");
        printf("4. 书籍入库\n");
        printf("5. 搜索书籍\n");
        printf("6. 删除书籍\n");
        printf("7. 借出书籍\n");
        printf("8. 归还书籍\n");
        printf("9. 保存退出\n");
        printf("请输入操作序列（如1234表示添加学生、查找学生、删除学生、添加书籍）: ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {
        int choice = input[i] - '0';  // 将字符转换为数字
        int id, studentId, bookId;
        char name[50], title[50];

        switch (choice) {
            case 1:
                id = rand() % 1000;  // 随机生成学生学号
                generateRandomName(name);  // 随机生成学生姓名
                printf("添加学生: 学号=%d, 姓名=%s\n", id, name);
                addStudent(&lib, id, name);
                break;
            case 2:
                id = rand() % 1000;  // 随机生成要查找的学生学号
                printf("查找学生: 学号=%d\n", id);
                Student *student = findStudent(&lib, id);
                if (student) {
                    printf("找到学生: %s\n", student->name);
                    BorrowedBook *borrowed = student->borrowedBooks;
                    while (borrowed != NULL) {
                        printf("  借出书籍: %s\n", borrowed->title);
                        borrowed = borrowed->next;
                    }
                } else {
                    printf("找不到这个学生\n");
                }
                break;
            case 3:
                id = rand() % 1000;  // 随机生成要删除的学生学号
                printf("删除学生: 学号=%d\n", id);
                deleteStudent(&lib, id);
                break;
            case 4:
                id = rand() % 1000;  // 随机生成书号
                generateRandomTitle(title);  // 随机生成书名
                printf("添加书籍: 书号=%d, 书名=%s\n", id, title);
                lib.books = addBook(lib.books, id, title);
                break;
            case 5:
                id = rand() % 1000;  // 随机生成要查找的书号
                printf("搜索书籍: 书号=%d\n", id);
                Book *book = findBook(lib.books, id);
                if (book) {
                    printf("找到此书: %s\n", book->title);
                } else {
                    printf("找不到此书\n");
                }
                break;
            case 6:
                id = rand() % 1000;  // 随机生成要删除的书号
                printf("删除书籍: 书号=%d\n", id);
                lib.books = deleteBook(lib.books, id);
                break;
            case 7:
                studentId = rand() % 1000;  // 随机生成学生学号
                bookId = rand() % 1000;  // 随机生成书号
                printf("学生 %d 借出书籍 %d\n", studentId, bookId);
                borrowBook(&lib, studentId, bookId);
                break;
            case 8:
                studentId = rand() % 1000;  // 随机生成学生学号
                bookId = rand() % 1000;  // 随机生成书号
                printf("学生 %d 归还书籍 %d\n", studentId, bookId);
                returnBook(&lib, studentId, bookId);
                break;
            case 9:
                saveStudents(&lib, "students.txt");
                FILE *file = fopen("books.txt", "w");
                saveBooks(lib.books, file);
                fclose(file);
                printf("保存并退出\n");
                return 0;
            default:
                printf("无效选择: %d\n", choice);
                break;
        }
    }

    return 0;
}
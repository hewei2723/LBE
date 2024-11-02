#include <iostream>
using namespace std;
// 定义枚举类型
enum Color {
    RED,    // 默认值为 0
    GREEN,  // 默认值为 1
    BLUE    // 默认值为 2
};

int main() {
    Color myColor = GREEN; // 使用枚举类型

    if (myColor == GREEN) {
        cout << "The color is green." << endl;
    }

    return 0;
}

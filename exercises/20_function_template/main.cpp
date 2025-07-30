#include "../exercise.h"

// READ: 函数模板 <https://zh.cppreference.com/w/cpp/language/function_template>
// TODO: 将这个函数模板化
// int plus(int a, int b) {
//     return a + b;
// }

template <typename T>
T plus(T a, T b) {
    // 如果是浮点类型，使用更安全的比较方式
    if constexpr (std::is_floating_point_v<T>) {
        // 实际上加法操作不需要特殊处理，比较时才需要
        return a + b;
    } else {
        return a + b;
    }
}

// 浮点数比较的辅助函数
template <typename T>
bool almost_equal(T a, T b, T epsilon = 1e-5) {
    return std::abs(a - b) < epsilon;
}

int main(int argc, char **argv) {
    ASSERT(plus(1, 2) == 3, "Plus two int");
    ASSERT(plus(1u, 2u) == 3u, "Plus two unsigned int");

    // THINK: 浮点数何时可以判断 ==？何时必须判断差值？
    ASSERT(plus(1.25f, 2.5f) == 3.75f, "Plus two float");
    ASSERT(plus(1.25, 2.5) == 3.75, "Plus two double");
    // TODO: 修改判断条件使测试通过
    //ASSERT(plus(0.1, 0.2) == 0.3, "How to make this pass?");
    ASSERT(almost_equal(plus(0.1, 0.2), 0.3), "Safe float comparison");

    return 0;
}

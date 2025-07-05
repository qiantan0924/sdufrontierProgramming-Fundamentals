#include <iostream>

int main() {
    std::cout << "换行符:\\n 输出结果:\n" << "这是一行新文本。\n";
    std::cout << "水平制表符:\\t 输出结果:\t这是制表符后的文本。\n";
    std::cout << "垂直制表符:\\v 输出结果:\v这是垂直制表符后的文本。\n";
    std::cout << "退格符:\\b 输出结果:Hello\bWorld!（注意：效果可能不明显，取决于终端）\n";
    std::cout << "回车符:\\r 输出结果:\r这是回车符后的文本。（注意：光标回到行首）This will overwrite the start.\n";
    std::cout << "换页符:\\f 输出结果:\f（注意：效果可能不明显，取决于终端）\n";
    std::cout << "反斜杠:\\\\ 输出结果:\\\n";
    std::cout << "单引号:\\' 输出结果:' 这是单引号。\n";
    std::cout << "双引号:\\\" 输出结果:\" 这是双引号。\n";
    std::cout << "问号:\\? 输出结果:? 这是问号。\n";
    std::cout << "警报:\\a 输出结果:（注意：会发出蜂鸣声，效果取决于系统）\a\n";
    std::cout << "十六进制字符:\\x41 输出结果:\x41 这是字符 'A'。\n";
    std::cout << "空字符:\\0 输出结果:（注意：空字符不会显示，但会结束字符串）\0This will not be displayed.（实际代码中不会这样写，仅用于说明）\n";}

    // 注意：空字符在字符串中通常不会这样使用，因为它会结束字符串。
    // 下面的例子展示了如何在字符串中嵌入空字符（但实际效果不会显示）：
    // char str[] = "
    #include <iostream>
#include <iomanip> // 包含流操纵符的定义

/// @brief 
/// @return 
int main() {
    double num = 1234567.89;

    // 默认格式
    std::cout << "默认格式: " << num << std::endl;

    // 保留固定的小数位数
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "固定小数位数: " << num << std::endl;

    // 科学计数法
    std::cout << std::scientific << std::setprecision(3);
    std::cout << "科学计数法: " << num << std::endl;

    // 恢复默认格式
    std::cout << std::defaultfloat << std::setprecision(6);
    std::cout << "恢复默认格式: " << num << std::endl;

    return 0;
}
#include "ShrubberyCreationForm.hpp"
#include <fstream> // 用于文件流操作

/**
 * 构造函数
 * @param target 文件生成的目录/目标名称
 * 固定参数：名称为 "shrubbery Creation"，签署等级 145，执行等级 137
 */
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : 
    AForm("shrubbery Creation", 145, 137),
    _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/**
 * 执行表单的具体功能
 * 1. 调用基类的 checkExecute 验证签署状态和官僚等级
 * 2. 创建名为 <target>_shrubbery 的文件
 * 3. 向文件内写入 ASCII 树
 */
void ShrubberyCreationForm::execute(const Bureaucrat &bureaucrat) const
{
    // 首先检查执行条件（是否已签、执行者等级是否足够）
    // 如果不满足，checkExecute 会抛出异常并中断当前函数
    checkExecute(bureaucrat);

    // 创建文件流。使用 .c_str() 是为了兼容 C++98 的 ofstream 构造函数
    std::ofstream file((_target + "_shrubbery").c_str());
    
    // 检查文件是否成功打开
    if (!file.is_open())
    {
        // 实际开发中这里也可以抛出一个自定义异常，例如 FileOpenException
        return;
    }

    // 写入 ASCII 艺术树
    file << "       _-_        \n";
    file << "    /~~   ~~\\    \n";
    file << " /~~         ~~\\ \n";
    file << "{               }\n";
    file << " \\  _-     -_  / \n";
    file << "   ~  \\\\ //  ~  \n";
    file << "_- -   | | _- _  \n";
    file << "  _ -  | |   -_  \n";
    file << "      // \\\\      \n";

    // 关闭文件
    file.close();
}
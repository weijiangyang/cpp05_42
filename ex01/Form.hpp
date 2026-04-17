#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <ostream>

// 前置声明 (Forward Declaration)
// 因为 beSigned 提到了 Bureaucrat，但我们不需要在这里知道它的完整定义
// 这样可以避免头文件循环包含 (Circular Include)
class Bureaucrat;

class Form
{
    private:
        const std::string   _name;              // 表单名称
        bool                _is_signed;         // 签署状态（true 为已签，false 为未签）
        const int           _grade_for_sign;    // 签署所需等级
        const int           _grade_for_execute; // 执行所需等级

    public:
        // --- 异常类 ---
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        // --- 构造与析构 ---
        // 构造函数：需要初始化所有 const 成员
        Form(const std::string& name, int grade_for_sign, int grade_for_execute);
        virtual ~Form(); // 使用虚析构函数，方便后续子类继承
        Form(const Form& other);
        Form& operator=(const Form& other);

        // --- 核心业务逻辑 ---
        /**
         * 接受一个 Bureaucrat 尝试签署此表单
         * 如果官僚等级足够，改变 _is_signed 状态
         * 如果等级不够，抛出 GradeTooLowException
         */
        void beSigned(const Bureaucrat& bureaucrat);

        // --- Getters ---
        const std::string& getName() const;
        bool getIsSigned() const;
        int  getGradeForSign() const;
        int  getGradeForExecute() const;

};

/**
 * 插入运算符重载
 * 用于打印表单的所有状态信息（名称、是否已签、所需等级等）
 */
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
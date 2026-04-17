#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

/**
 * Bureaucrat 类
 * 等级范围：1 (最高) 到 150 (最低)
 */
class Bureaucrat
{
    private:
        const std::string _name; // 官僚的名字，设为 const 表示初始化后不可更改
        int _grade;              // 官僚的等级

    public:
        // --- 异常类定义 ---
        // 继承自 std::exception，用于处理等级越界的情况
        class GradeTooHighException : public std::exception
        {
            // throw() 是异常规格说明，表示该函数承诺不抛出异常
            virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw();
        };

        // --- 构造函数与析构函数 ---
        Bureaucrat(const std::string& name, int grade); // 参数化构造函数
        ~Bureaucrat();                                  // 析构函数
        Bureaucrat(const Bureaucrat& other);            // 拷贝构造函数
        Bureaucrat& operator=(const Bureaucrat& other); // 赋值运算符重载

        // --- Getter 成员函数 ---
        std::string getName() const; // 获取名字
        int getGrade() const;        // 获取等级

        // --- 等级操作函数 ---
        // 注意：增加等级意味着数值减小 (例如从 2 变 1)
        void incrementGrade(); 
        // 注意：降低等级意味着数值增大 (例如从 149 变 150)
        void decrementGrade();
};

/**
 * 插入运算符重载 (Ostream overload)
 * 用于直接使用 std::cout << bureaucrat; 打印官僚信息
 * 格式通常为: <name>, bureaucrat grade <grade>.
 */
std::ostream& operator<<(std::ostream &os, const Bureaucrat& b);

#endif
#include "Form.hpp"
#include "Bureaucrat.hpp"

// --- 构造函数 ---
// 使用初始化列表处理所有成员，尤其是 const 成员
Form::Form(const std::string &name, int grade_for_sign, int grade_for_execute)
    : _name(name),
      _is_signed(false),
      _grade_for_sign(grade_for_sign),
      _grade_for_execute(grade_for_execute)
{
    // 检查签署等级和执行等级是否都在 1-150 范围内
    if (grade_for_sign < 1 || grade_for_execute < 1)
        throw GradeTooHighException();
    if (grade_for_sign > 150 || grade_for_execute > 150)
        throw GradeTooLowException();
}

// 拷贝构造函数
Form::Form(const Form &other)
    : _name(other._name),
      _is_signed(other._is_signed),
      _grade_for_sign(other._grade_for_sign),
      _grade_for_execute(other._grade_for_execute)
{
}

// 赋值运算符重载
Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        // 因为除了 _is_signed 之外都是 const，所以只能拷贝这个状态
        _is_signed = other._is_signed;
    }
    return (*this);
}

Form::~Form() {}

// --- 异常信息实现 ---
const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low!";
}

// --- 核心逻辑：签署表单 ---
void Form::beSigned(const Bureaucrat &bureaucrat)
{
    // 如果已经签过了，可以直接返回（或者根据需求再次检查等级）
    if (_is_signed)
        return;

    // 关键：如果官僚的等级数值大于（即等级低于）要求的等级，抛出异常
    if (bureaucrat.getGrade() > _grade_for_sign)
        throw GradeTooLowException();

    _is_signed = true;
}

// --- Getters ---
const std::string &Form::getName() const
{
    return (_name);
}

bool Form::getIsSigned() const
{
    return (_is_signed);
}

int Form::getGradeForSign() const
{
    return (_grade_for_sign);
}

int Form::getGradeForExecute() const
{
    return (_grade_for_execute);
}

// --- 插入运算符重载 ---
// 输出格式：[名字], signed: [yes/no], sign grade: [n], exec grade: [n]
std::ostream &operator<<(std::ostream &os, const Form &f)
{
    os << f.getName()
       << ", signed: " << (f.getIsSigned() ? "yes" : "no")
       << ", sign grade: " << f.getGradeForSign()
       << ", exec grade: " << f.getGradeForExecute();
    return os;
}

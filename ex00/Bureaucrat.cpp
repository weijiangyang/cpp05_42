#include "Bureaucrat.hpp"

// --- 异常类成员函数实现 ---
// what() 函数返回一个字符串，用于描述捕获到的异常原因
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high!"); // 等级太高（数值过小）
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!"); // 等级太低（数值过大）
}

// --- 构造函数 ---
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    // 在构造时就进行等级检查，确保对象在创建时就是合法的
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();

    _grade = grade;
}

// 拷贝构造函数：使用成员初始化列表来初始化 const 成员 _name
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade){}

// 析构函数
Bureaucrat::~Bureaucrat(){}

// 赋值运算符重载
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other) // 防止自赋值
    {
        // 注意：因为 _name 是 const，所以只能通过这种方式拷贝 _grade
        this->_grade = other._grade;
    }
    return (*this);
}

// --- Getters ---
std::string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

// --- 等级操作 ---
void Bureaucrat::incrementGrade()
{
    // 提升等级意味着数值减小 (例如从 2 提升到 1)
    // 如果当前已经是 1，再提升就会越界
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    // 降低等级意味着数值增大 (例如从 149 降低到 150)
    // 如果当前已经是 150，再降低就会越界
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

// --- 插入运算符重载 ---
// 允许使用 std::cout << bureaucrat_instance; 直接输出
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}




#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>

class Bureaucrat;

/**
 * AForm 抽象类
 * 带有 'A' 前缀表示这是一个抽象基类 (Abstract Class)
 */
class AForm
{
private:
    const std::string _name;
    bool _is_signed;
    const int _grade_for_sign;
    const int _grade_for_execute;

public:
    // --- 构造与析构 ---
    AForm(const std::string &name, int grade_for_sign, int grade_for_execute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
    // 抽象类必须有虚析构函数，确保子类对象能被正确销毁
    virtual ~AForm();

    // --- 异常类 ---
    class NotSignedException : public std::exception
    {
        public:
            const char *what() const throw();
    };

	class GradeTooHighException : public std::exception
    {
        public:
            const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    
    // 注意：通常这里还应该保留 Form 阶段的 GradeTooHighException
    // 以及继承自 std::exception 的其他必要异常

    // --- 核心成员函数 ---
    
    /**
     * 纯虚函数 (Pure Virtual Function)
     * = 0 使得 AForm 成为抽象类。
     * 具体的执行逻辑将由派生类（子类）来实现。
     */
    virtual void execute(const Bureaucrat &bureaucrat) const = 0;

    /**
     * 签署逻辑：检查官僚等级是否满足 _grade_for_sign
     */
    void beSigned(const Bureaucrat &bureaucrat);

    /**
     * 辅助函数：用于在执行前检查是否已签署以及执行者等级是否足够。
     * 这样可以减少子类中的重复代码。
     */
    void checkExecute(const Bureaucrat &bureaucrat) const;

    // --- Getters ---
    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeForSign() const;
    int getGradeForExecute() const;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
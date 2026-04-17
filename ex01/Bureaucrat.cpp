#include "Bureaucrat.hpp"
#include "Form.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();

	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

const std::string &Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

/**
 * 官僚签名表单函数
 * @param form 需要被签名的表单引用
 * * 逻辑：
 * 1. 尝试调用表单的 beSigned 方法。
 * 2. 如果成功，打印签名成功的消息。
 * 3. 如果失败（表单抛出异常），捕获异常并打印失败原因。
 */
void Bureaucrat::signForm(Form &form)
{
	try
	{
		// 尝试让表单签署当前官僚（this 指针指向当前 Bureaucrat 实例）
		// beSigned 内部会检查官僚等级，如果等级不够会抛出异常
		form.beSigned(*this);

		// 如果上面一行没有抛出异常，说明签名成功
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		// 如果 beSigned 抛出了异常（如 GradeTooLowException）
		// 则会进入这里，打印题目要求的错误格式
		std::cout << _name << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}

// 深度解析与注意事项：

//     设计模式：这是一个典型的 “双向交互”。Bureaucrat 调用 form.beSigned(*this)，而 beSigned 内部通常会反过来调用 bureaucrat.getGrade()。这种设计确保了表单拥有决定权，即由表单来定义“多高等级才能签我”。

//     异常捕获 (Catch by Reference)：注意 catch (const std::exception& e) 使用了引用。这是一个最佳实践，可以防止对象切割 (Object Slicing)，确保你能捕获到 GradeTooLowException 实际覆盖的 what() 信息，而不是基类 std::exception 的默认信息。
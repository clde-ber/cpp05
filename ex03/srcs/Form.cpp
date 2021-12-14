#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Form::Form() : _name("random form"), _signed(0), _gradeReqSign(150), _gradeReqExe(150), _target("random target")
{
    std::cout << "constructor called" << std::endl;
    checkValue(_gradeReqSign);
    checkValue(_gradeReqExe);
    _formTypes[0] = "shrubbery creation";
    _formTypes[1] = "robotomy request";
    _formTypes[2] = "presidential pardon";
    _f[0] = &ShrubberyCreationForm::Form::executeSpecialForm;
    _f[1] = &RobotomyRequestForm::Form::executeSpecialForm;
    _f[2] = &PresidentialPardonForm::Form::executeSpecialForm;
}

Form::Form(std::string const name, int isSigned, int const gradeReqSign, int const gradeReqExe, std::string const target) : _name(name), _signed(isSigned), _gradeReqSign(gradeReqSign), _gradeReqExe(gradeReqExe), _target(target)
{
    std::cout << "constructor called" << std::endl;
    checkValue(_gradeReqSign);
    checkValue(_gradeReqExe);
    _formTypes[0] = "shrubbery creation";
    _formTypes[1] = "robotomy request";
    _formTypes[2] = "presidential pardon";
    _f[0] = &ShrubberyCreationForm::Form::executeSpecialForm;
    _f[1] = &RobotomyRequestForm::Form::executeSpecialForm;
    _f[2] = &PresidentialPardonForm::Form::executeSpecialForm;
}

Form::Form( Form const & rhs) : _signed(rhs._signed), _gradeReqSign(rhs._gradeReqSign), _gradeReqExe(rhs._gradeReqExe), _target(rhs._target)
{
    std::cout << "constructor called" << std::endl;
    checkValue(_gradeReqSign);
    checkValue(_gradeReqExe);
}

Form & Form::operator=(Form const & rhs)
{
    checkValue(rhs.getGradeReqSign());
    checkValue(rhs.getGradeReqExe());
    _formTypes[0] = "shrubbery creation";
    _formTypes[1] = "robotomy request";
    _formTypes[2] = "presidential pardon";
    _f[0] = &ShrubberyCreationForm::Form::executeSpecialForm;
    _f[1] = &RobotomyRequestForm::Form::executeSpecialForm;
    _f[2] = &PresidentialPardonForm::Form::executeSpecialForm;
    return *this;
}

Form::~Form()
{

}

bool const & Form::getIfSigned() const
{
    return _signed;
}

int const & Form::getGradeReqSign() const
{
    return _gradeReqSign;
}

int const & Form::getGradeReqExe() const
{
    return _gradeReqExe;
}

void Form::checkValue(int const & grade)
{
    if (grade < 1)
        throw Form::GradeTooHighException();
    if (grade > 150)
        throw Form::GradeTooLowException();
}

void Form::beSigned(Bureaucrat & bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeReqSign)
        _signed = 1;
    else
        throw Form::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, Form const & rhs)
{
    o << "Form signature status : [" << rhs.getIfSigned() << "] | grade required for signing : [" << rhs.getGradeReqSign() \
    << "] | grade required for executing : " << rhs.getGradeReqExe();
    return o;
}

std::string const & Form::getName() const
{
    return _name;
}

int Form::checkIfSigned(bool isSigned)
{
    if (!isSigned)
    {
        throw Form::UnsignedException();
        return 0;
    }
    return 1;
}

void Form::execute(Bureaucrat const & executor) const
{
    if (!_signed)
        throw UnsignedException();
    else if (executor.getGrade() > _gradeReqSign)
        throw GradeTooLowException();
    for (int i = 0; i < 3; i++)
        if (_name.compare(_formTypes[i]) == 0)
            (this->*_f[i])(executor);
}
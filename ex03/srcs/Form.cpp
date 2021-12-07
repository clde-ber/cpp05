#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Form::Form() : _name(""), _signed(0), _gradeReqSign(0), _gradeReqExe(0), _target("")
{
    _formTypes[0] = "shrubbery creation";
    _formTypes[1] = "robotomy request";
    _formTypes[2] = "presidential pardon";
    _f[0] = &ShrubberyCreationForm::Form::execute;
    _f[1] = &RobotomyRequestForm::Form::execute;
    _f[2] = &PresidentialPardonForm::Form::execute;
}

Form::Form(std::string const name, int isSigned, int const gradeReqSign, int const gradeReqExe, std::string const target) : _name(name), _signed(isSigned), _gradeReqSign(gradeReqSign), _gradeReqExe(gradeReqExe), _target(target)
{
    _formTypes[0] = "shrubbery creation";
    _formTypes[1] = "robotomy request";
    _formTypes[2] = "presidential pardon";
    _f[0] = &ShrubberyCreationForm::Form::execute;
    _f[1] = &RobotomyRequestForm::Form::execute;
    _f[2] = &PresidentialPardonForm::Form::execute;
}

Form::Form( Form const & rhs) : _name(rhs._name), _signed(rhs._signed), _gradeReqSign(rhs._gradeReqSign), _gradeReqExe(rhs._gradeReqExe), _target(rhs._target)
{
    _formTypes[0] = rhs._formTypes[0];
    _formTypes[1] = rhs._formTypes[1];
    _formTypes[2] = rhs._formTypes[2];
    _f[0] = rhs._f[0];
    _f[1] = rhs._f[1];
    _f[2] = rhs._f[2];
}

Form const & Form::operator=(Form const & rhs)
{
    std::cout << "Assignation operator called";
    new (this) Forms(rhs);
    return *this;
}

Form::~Form()
{

}

int Form::getIfSigned() const
{
    return _signed;
}

int Form::getGradeReqSign() const
{
    return _gradeReqSign;
}

int Form::getGradeReqExe() const
{
    return _gradeReqExe;
}

int Form::checkValue(int grade)
{
    if (grade < 1)
    {
        throw Form::GradeTooHighException();
        return 0;
    }
    if (grade > 150)
    {
        throw Form::GradeTooLowException();
        return 0;
    }
    return 1; 
}

void Form::beSigned(Bureaucrat * bureaucrat)
{
    if (bureaucrat->getGrade() <= _gradeReqSign)
        _signed = 1;
    else
        _signed = 0;
}

void Form::signForm(Bureaucrat * bureaucrat)
{
    if (checkValue(_gradeReqSign))
    {
        if (_gradeReqSign < bureaucrat->getGrade())
        {
            throw Form::GradeTooLowException();
            std::cout << "Bureaucrat [" << bureaucrat->getName() << "] cannot sign Form [" << _name << "] because of a too low grade" << std::endl;
            return ;
        }
        std::cout << "Bureaucrat [" << bureaucrat->getName() << "] signs Form [" << _name << "]" << std::endl;
    }
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
    for (int i = 0; i < 3; i++)
    {
        if (_name.compare(_formTypes[i]) == 0)
            (this->*_f[i])(executor);
    }
}
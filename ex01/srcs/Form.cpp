#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Random form"), _signed(0), _gradeReqSign(150), _gradeReqExe(150)
{
    std::cout << "constructor by default called" << std::endl;
    checkValue(_gradeReqSign);
    checkValue(_gradeReqExe);
    std::cout << "New form created" << std::endl; 
    std::cout << "- name [" << _name << "]" << std::endl;
    if (_signed)
        std::cout << "- [signed]" << std::endl;
    else
        std::cout << "- [unsigned]" << std::endl;
    std::cout << "- grade required to sign [" << _gradeReqSign << "]" << std::endl;
    std::cout << "- grade requires to execute [" << _gradeReqExe << "]" << std::endl; 
}

Form::Form(std::string const name, int is_signed, int const gradeReqSign, int const gradeReqExe) : _name(name), _signed(is_signed), _gradeReqSign(gradeReqSign), _gradeReqExe(gradeReqExe)
{
    std::cout << "constructor called" << std::endl;
    checkValue(_gradeReqSign);
    checkValue(_gradeReqExe);
    std::cout << "New form created" << std::endl; 
    std::cout << "- name [" << _name << "]" << std::endl;
    if (_signed)
        std::cout << "- [signed]" << std::endl;
    else
        std::cout << "- [unsigned]" << std::endl;
    std::cout << "- grade required to sign [" << _gradeReqSign << "]" << std::endl;
    std::cout << "- grade requires to execute [" << _gradeReqExe << "]" << std::endl; 
}

Form::Form( Form const & rhs) : _name(rhs._name), _signed(rhs._signed), _gradeReqSign(rhs._gradeReqSign), _gradeReqExe(rhs._gradeReqExe)
{
    std::cout << "copy constructor called" << std::endl;
    checkValue(_gradeReqSign);
    checkValue(_gradeReqExe);
    std::cout << "New form created" << std::endl; 
    std::cout << "- name [" << _name << "]" << std::endl;
    if (_signed)
        std::cout << "- [signed]" << std::endl;
    else
        std::cout << "- [unsigned]" << std::endl;
    std::cout << "- grade required to sign [" << _gradeReqSign << "]" << std::endl;
    std::cout << "- grade requires to execute [" << _gradeReqExe << "]" << std::endl; 
}

Form & Form::operator=(Form const & rhs)
{
    std::cout << "Assignation operator called";
    new (this) Form(rhs);
    return *this;
}

Form::~Form()
{

}

std::string const & Form::getName() const
{
    return (_name);
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
    o << "Form signature name [" << rhs.getName() << "] | status : [" << rhs.getIfSigned() << "] | grade required for signing : [" << rhs.getGradeReqSign() \
    << "] | grade required for executing : [" << rhs.getGradeReqExe() << "]";
    return o;
}
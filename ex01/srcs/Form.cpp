#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name(""), _signed(0), _gradeReqSign(0), _gradeReqExe(0)
{
    std::cout << "constructor by default called" << std::endl;
    try
    {
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
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

Form::Form(std::string const name, int is_signed, int const gradeReqSign, int const gradeReqExe) : _name(name), _signed(is_signed), _gradeReqSign(gradeReqSign), _gradeReqExe(gradeReqExe)
{
    std::cout << "constructor called" << std::endl;
    try
    {
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
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

Form::Form( Form const & rhs) : _signed(rhs._signed), _gradeReqSign(rhs._gradeReqSign), _gradeReqExe(rhs._gradeReqExe)
{
    std::cout << "copy constructor called" << std::endl;
    try
    {
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
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

Form & Form::operator=(Form const & rhs)
{
    std::cout << "Assignation operator called";
    _signed = rhs._signed;
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

int Form::checkValue(int const & grade)
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

std::ostream & operator<<(std::ostream & o, Form* const & rhs)
{
    o << "Form signature status : [" << rhs->getIfSigned() << "] | grade required for signing : [" << rhs->getGradeReqSign() \
    << "] | grade required for executing : " << rhs->getGradeReqExe();
    return o;
}
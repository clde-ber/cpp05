#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name(""), _signed(0), _gradeReqSign(0), _gradeReqExe(0)
{
    std::cout << "Constructor by default called : form created -> [unsigned] | name [" << this->_name << "] | grade required to sign [" << this->_gradeReqSign << "] | grade requires to execute [" << this->_gradeReqExe << "]" << std::endl << std::endl; 
}

Form::Form(std::string const name, int is_signed, int const gradeReqSign, int const gradeReqExe) : _name(name), _signed(is_signed), _gradeReqSign(gradeReqSign), _gradeReqExe(gradeReqExe)
{
    std::cout << "Constructor called : new form created -> name [" << this->_name << "] | ";
    if (this->_signed)
        std::cout << "[signed] | ";
    else
        std::cout << "[unsigned] | ";
    std::cout << "grade required to sign [" << this->_gradeReqSign << "] | grade requires to execute [" << this->_gradeReqExe << "]" << std::endl << std::endl; 
}

Form::Form( Form const & rhs) : _name(rhs._name), _signed(rhs._signed), _gradeReqSign(rhs._gradeReqSign), _gradeReqExe(rhs._gradeReqExe)
{
    std::cout << "Constructor by copy called : new form created -> name [" << this->_name << "] | ";
    if (this->_signed)
        std::cout << "[signed] | ";
    else
        std::cout << "[unsigned] | ";
    std::cout << "grade required to sign [" << this->_gradeReqSign << "] | grade requires to execute [" << this->_gradeReqExe << "]" << std::endl << std::endl; 
}

Form const & Form::operator=(Form const & rhs) const
{
    std::cout << "Assignation operator called";
    std::cout << "-> Object substitution : Form is now ";
    if (this->_signed)
        std::cout << "[signed] | ";
    else
        std::cout << "[unsigned] | ";
    std::cout << "name [" << this->_name << "] | grade required to sign [" << this->_gradeReqSign << "] | grade requires to execute [" << this->_gradeReqExe << "]" << std::endl << std::endl; 
    return rhs;
}

Form::~Form()
{
    std::cout << "Destructor called." << std::endl << std::endl;
}

int Form::getIfSigned() const
{
    return this->_signed;
}

int Form::getGradeReqSign() const
{
    return this->_gradeReqSign;
}

int Form::getGradeReqExe() const
{
    return this->_gradeReqExe;
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

int Form::beSigned(Bureaucrat & bureaucrat) const
{
    if (bureaucrat.getGrade() <= this->_gradeReqSign)
        return 1;
    else
        return 0;
}

void Form::signForm(Bureaucrat & bureaucrat)
{
    if (checkValue(this->_gradeReqSign))
    {
        if (this->_gradeReqSign < bureaucrat.getGrade())
        {
            throw Form::GradeTooLowException();
            std::cout << "Bureaucrat [" << bureaucrat.getName() << "] cannot sign Form [" << this->_name << "] because of a too low grade" << std::endl;
            return ;
        }
        std::cout << "Bureaucrat [" << bureaucrat.getName() << "] signs Form [" << this->_name << "]" << std::endl;
    }
}

std::ostream & operator<<(std::ostream & o, Form* const & rhs)
{
    o << "Form signature status : [" << rhs->getIfSigned() << "] | grade required for signing : [" << rhs->getGradeReqSign() \
    << "] | grade required for executing : " << rhs->getGradeReqExe();
    return o;
}
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm::AForm() : _name(""), _signed(0), _gradeReqSign(0), _gradeReqExe(0), _target("")
{
    std::cout << "Constructor by default called : form created -> [unsigned] | name [" << this->_name << "] | grade required to sign [" << this->_gradeReqSign << "] | grade requires to execute [" << this->_gradeReqExe << "] | target [" << this->_target << "]" << std::endl;
    this->_formTypes[0] = "shrubbery creation";
    this->_formTypes[1] = "robotomy request";
    this->_formTypes[2] = "presidential pardon";
    this->_f[0] = &ShrubberyCreationForm::AForm::execute;
    this->_f[1] = &RobotomyRequestForm::AForm::execute;
    this->_f[2] = &PresidentialPardonForm::AForm::execute;
}

AForm::AForm(std::string const name, int isSigned, int const gradeReqSign, int const gradeReqExe, std::string const target) : _name(name), _signed(isSigned), _gradeReqSign(gradeReqSign), _gradeReqExe(gradeReqExe), _target(target)
{
    std::cout << "Constructor called : new form created -> name [" << this->_name << "] | ";
    if (this->_signed)
        std::cout << "[signed] | ";
    else
        std::cout << "[unsigned] | ";
    std::cout << "grade required to sign [" << this->_gradeReqSign << "] | grade requires to execute [" << this->_gradeReqExe << "] | target [" << this->_target << "]" << std::endl; 
    this->_formTypes[0] = "shrubbery creation";
    this->_formTypes[1] = "robotomy request";
    this->_formTypes[2] = "presidential pardon";
    this->_f[0] = &ShrubberyCreationForm::AForm::execute;
    this->_f[1] = &RobotomyRequestForm::AForm::execute;
    this->_f[2] = &PresidentialPardonForm::AForm::execute;
}

AForm::AForm( AForm const & rhs) : _name(rhs._name), _signed(rhs._signed), _gradeReqSign(rhs._gradeReqSign), _gradeReqExe(rhs._gradeReqExe), _target(rhs._target)
{
    std::cout << "Constructor by copy called : new form created -> name [" << this->_name << "] | ";
    if (this->_signed)
        std::cout << "[signed] | ";
    else
        std::cout << "[unsigned] | ";
    std::cout << "grade required to sign [" << this->_gradeReqSign << "] | grade requires to execute [" << this->_gradeReqExe << "] | target [" << this->_target << "]" << std::endl; 
    this->_formTypes[0] = rhs._formTypes[0];
    this->_formTypes[1] = rhs._formTypes[1];
    this->_formTypes[2] = rhs._formTypes[2];
}

AForm const & AForm::operator=(AForm const & rhs) const
{
    std::cout << "Assignation operator called";
    std::cout << "-> Object substitution : Form is now ";
    if (this->_signed)
        std::cout << "[signed] | ";
    else
        std::cout << "[unsigned] | ";
    std::cout << "name [" << this->_name << "] | grade required to sign [" << this->_gradeReqSign << "] | grade requires to execute [" << this->_gradeReqExe << "] | target [" << this->_target << "]" << std::endl;
    return rhs;
}

AForm::~AForm()
{
    std::cout << "Destructor called." << std::endl;
}

int AForm::getIfSigned() const
{
    return this->_signed;
}

int AForm::getGradeReqSign() const
{
    return this->_gradeReqSign;
}

int AForm::getGradeReqExe() const
{
    return this->_gradeReqExe;
}

int AForm::checkValue(int grade)
{
    if (grade < 1)
    {
        throw AForm::GradeTooHighException();
        return 0;
    }
    if (grade > 150)
    {
        throw AForm::GradeTooLowException();
        return 0;
    }
    return 1; 
}

void AForm::beSigned(Bureaucrat* bureaucrat)
{
    if (bureaucrat->getGrade() <= this->_gradeReqSign)
        this->_signed = 1;
    else
        this->_signed = 0;
}

void AForm::signForm(Bureaucrat* bureaucrat)
{
    if (checkValue(this->_gradeReqSign))
    {
        if (this->_gradeReqSign < bureaucrat->getGrade())
        {
            throw AForm::GradeTooLowException();
            std::cout << "Bureaucrat [" << bureaucrat->getName() << "] cannot sign Form [" << this->_name << "] because of a too low grade" << std::endl;
            return ;
        }
        std::cout << "Bureaucrat [" << bureaucrat->getName() << "] signs Form [" << this->_name << "]" << std::endl;
    }
}

std::ostream & operator<<(std::ostream & o, AForm const & rhs)
{
    o << "Form signature status : [" << rhs.getIfSigned() << "] | grade required for signing : [" << rhs.getGradeReqSign() \
    << "] | grade required for executing : " << rhs.getGradeReqExe();
    return o;
}

std::string const AForm::getName() const
{
    return this->_name;
}

int AForm::checkIfSigned(bool isSigned)
{
    if (!isSigned)
    {
        throw AForm::UnsignedException();
        return 0;
    }
    return 1;
}

void AForm::execute (Bureaucrat const & executor) const
{
    for (int i = 0; i < 3; i++)
    {
        if (this->_name.compare(this->_formTypes[i]) == 0)
            (this->*_f[i])(executor);
    }
}
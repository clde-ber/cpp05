#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
    protected:
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Too high grade!";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Too low grade!";
                }
        };
        class UnsignedException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Bureaucrat cannot execute form because it is not signed!";
                }
        };
    public:
        Bureaucrat();
        Bureaucrat( std::string const name, int grade);
        Bureaucrat( Bureaucrat const & rhs);
        Bureaucrat const & operator=(Bureaucrat const & rhs) const;
        ~Bureaucrat();
        std::string const getName() const;
        int getGrade() const;
        void    incrementGrade();
        void    decrementGrade();
        void executeForm (AForm const & form);
        friend class Intern;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat* const & rhs);

#endif
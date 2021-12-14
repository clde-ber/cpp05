#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include "Form.hpp"

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
                    return "Bureaucrat exception : Too high grade!";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Bureaucrat exception : Too low grade!";
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
        Bureaucrat( std::string const name);
        Bureaucrat( std::string const name, int grade);
        Bureaucrat( Bureaucrat const & rhs);
        Bureaucrat & operator=(Bureaucrat const & rhs);
        ~Bureaucrat();
        std::string const & getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void checkValue(int grade) const;
        void signForm(Form & form);
        void executeForm (Form const & form);
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
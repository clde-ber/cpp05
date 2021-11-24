#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>

class Bureaucrat
{
    protected:
        std::string const _name;
        int _grade;
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
    public:
        Bureaucrat();
        Bureaucrat( std::string const name, int grade);
        Bureaucrat( Bureaucrat const & rhs);
        Bureaucrat const & operator=(Bureaucrat const & rhs) const;
        ~Bureaucrat();
        std::string const getName() const;
        int getGrade() const;
        void checkValue(int const grade);
        void    incrementGrade();
        void    decrementGrade();
};

std::ostream & operator<<(std::ostream & o, Bureaucrat* const & rhs);

#endif
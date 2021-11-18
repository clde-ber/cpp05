#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>

class Bureaucrat
{
    protected:
        std::string const _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat( std::string const name, int grade);
        Bureaucrat( Bureaucrat const & rhs);
        Bureaucrat const & operator=(Bureaucrat const & rhs) const;
        ~Bureaucrat();
        void GradeTooHighException();
        void GradeTooLowException();
        std::string const getName() const;
        int getGrade() const;
        void    incrementGrade();
        void    decrementGrade();
};

std::ostream & operator<<(std::ostream & o, Bureaucrat* const & rhs);

#endif
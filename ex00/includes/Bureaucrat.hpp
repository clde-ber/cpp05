#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
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
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif
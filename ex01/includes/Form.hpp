#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        int _signed;
        int const _gradeReqSign;
        int const _gradeReqExe;
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Form exception : Too high grade!";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Form exception : Too low grade!";
                }
        };
    public:
        Form();
        Form(std::string const name, int is_signed, int const gradeReqSign, int const gradeReqExe);
        Form( Form const & rhs);
        Form & operator=(Form const & rhs);
        ~Form();
        int const & getIfSigned() const;
        int const & getGradeReqSign() const;
        int const & getGradeReqExe() const;
        void beSigned(Bureaucrat* bureaucrat);
        void signForm(Bureaucrat* bureaucrat);
        int checkValue(int grade);
};

std::ostream & operator<<(std::ostream & o, Form* const & rhs);

#endif
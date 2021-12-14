#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        bool _signed;
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
        bool const & getIfSigned() const;
        int const & getGradeReqSign() const;
        int const & getGradeReqExe() const;
        std::string const & getName() const;
        void checkValue(int const & grade);
        void beSigned(Bureaucrat & bureaucrat);
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif
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
        std::string const _target;
        std::string _formTypes[3];
        void (Form::*_f[3])(const Bureaucrat &) const;
    protected:
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
        class UnsignedException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Form exception : Form not signed!";
                }
        };
    public:
        Form();
        Form(std::string const name, int is_signed, int const gradeReqSign, int const gradeReqExe, std::string const target);
        Form( Form const & rhs);
        Form & operator=(Form const & rhs);
        virtual ~Form();
        bool const & getIfSigned() const;
        int const & getGradeReqSign() const;
        int const & getGradeReqExe() const;
        std::string const & getName() const;
        void checkValue(int const & grade);
        void beSigned(Bureaucrat & bureaucrat);
        void execute (Bureaucrat const & executor) const;
        virtual void executeSpecialForm(Bureaucrat const & executor) const = 0;
};

std::ostream & operator<<(std::ostream & o, Form const & rhs);

#endif
#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
    private:
        std::string const _name;
        bool _signed;
        int const _gradeReqSign;
        int const _gradeReqExe;
        std::string const _target;
        std::string _formTypes[3];
        void (AForm::*_f[3])(const Bureaucrat &) const;
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
                    return "Form exception : This form cannot be executed because it is not signed!";
                }
        };
    public:
        AForm();
        AForm(std::string const name, int is_signed, int const gradeReqSign, int const gradeReqExe, std::string const target);
        AForm( AForm const & rhs);
        AForm const & operator=(AForm const & rhs);
        virtual ~AForm();
        int getIfSigned() const;
        int getGradeReqSign() const;
        int getGradeReqExe() const;
        void beSigned(Bureaucrat * bureaucrat);
        void signForm(Bureaucrat * bureaucrat);
        int checkValue(int grade);
        int checkIfSigned(bool isSigned);
        std::string const & getName() const;
        virtual void execute (Bureaucrat const & executor) const = 0;
};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif
#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        std::string const _name;
        bool _signed;
        int _gradeReqSign;
        int _gradeReqExe;
    protected:
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Too high grade required to sign/execute!";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Too low grade required to sign/execute!";
                }
        };
        class GradeReqSignException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Bureaucrat cannot sign/execute because his grade is too low!";
                }
        };
        class UnsignedException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "This form cannot be executed because it is not signed!";
                }
        };
    public:
        AForm(void);
        AForm(int is_signed, int gradeReqSign, int gradeReqExe);
        AForm( AForm const & rhs);
        AForm const & operator=(AForm const & rhs) const;
        virtual ~AForm();
        std::string const getName() const;
        void setIfSigned(int boolean);
        void setGradeReqSign(int grade);
        void setGradeReqExe(int grade);
        int getIfSigned() const;
        int getGradeReqSign() const;
        int getGradeReqExe() const;
        int beSigned(Bureaucrat* bureaucrat) const;
        void signForm(Bureaucrat* bureaucrat);
        virtual void execute (Bureaucrat const & executor) const = 0;
};

std::ostream & operator<<(std::ostream & o, AForm* const & rhs);

#endif
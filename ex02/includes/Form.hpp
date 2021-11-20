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
        int _gradeReqSign;
        int _gradeReqExe;
    protected:
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Too high grade required to sign!";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Too low grade required to sign!";
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
        AForm();
        AForm(int is_signed, int gradeReqSign, int gradeReqExe);
        AForm( AForm const & rhs);
        AForm const & operator=(AForm const & rhs) const;
        virtual ~AForm();
        std::string const getName() const;
        int getIfSigned() const;
        int getGradeReqSign() const;
        int getGradeReqExe() const;
        int beSigned(Bureaucrat* bureaucrat) const;
        void signForm(Bureaucrat* bureaucrat);
        virtual void execute (Bureaucrat const & executor) const = 0;
    /*    class ShrubberyCreationForm; // (Grades requis : signature 145, execution 137)
        class RobotomyRequestForm; //(Grades requis : signature 72, execution 45)
        class PresidentialPardonForm; //(Grades requis : signature 25, execution 5)*/
};

std::ostream & operator<<(std::ostream & o, AForm* const & rhs);

#endif
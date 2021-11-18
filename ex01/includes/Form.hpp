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
        int _gradeReqSign;
        int _gradeReqExe;
    public:
        Form();
        Form(int is_signed, int gradeReqSign, int gradeReqExe);
        Form( Form const & rhs);
        Form const & operator=(Form const & rhs) const;
        ~Form();
        int getIfSigned() const;
        int getGradeReqSign() const;
        int getGradeReqExe() const;
        int beSigned(Bureaucrat* & bureaucrat) const;
        void signForm(Bureaucrat* & bureaucrat);
        void GradeTooHighException();
        void GradeTooLowException();
};

std::ostream & operator<<(std::ostream & o, Form* const & rhs);

#endif
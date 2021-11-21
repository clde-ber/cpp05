#ifndef INTERN_H
#define INTERN_H

#include <iostream>
#include <string>
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <cstring>

class Intern
{
    public:
        Intern( void );
        Intern( Intern const & rhs);
        Intern const & operator=(Intern const & rhs) const;
        virtual ~Intern();
        AForm* makeForm(const char* type, std::string name);
        private:
            class UnknownTypeException : public std::exception
            {
                public:
                    virtual const char* what() const throw()
                    {
                        return "Unknown type of form!";
                    }
            };
};

#endif
#ifndef INTERN_H
#define INTERN_H

#include <iostream>
#include <string>
#include <cstring>

class Form;

class Intern
{
    public:
        Intern( void );
        Intern( Intern const & rhs);
        Intern & operator=(Intern const & rhs);
        virtual ~Intern();
        Form* makeForm(const char* type, std::string name);
        private:
            class UnknownTypeException : public std::exception
            {
                public:
                    virtual const char* what() const throw()
                    {
                        return "Intern exception : Unknown type of form!";
                    }
            };
};

#endif
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 0, 145, 137, "no target")
{
    _trees = "                                   _\\ |/ /   _\\ |/ /   _\\ |/ /      \\/\\|//_   \\/\\|//_   \\/\\|//_      _\\/|//_   _\\/|//_   _\\/|//_        \\|/       \\|/       \\|/           |         |         |            |         |         |                                        ";
    std::cout << "[shrubbery creation form] default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("shrubbery creation", 0, 145, 137, target)
{
    _trees = "                                   _\\ |/ /   _\\ |/ /   _\\ |/ /      \\/\\|//_   \\/\\|//_   \\/\\|//_      _\\/|//_   _\\/|//_   _\\/|//_        \\|/       \\|/       \\|/           |         |         |            |         |         |                                        ";
    std::cout << "[shrubbery creation form] constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & rhs) : AForm("shrubbery creation", 0, 145, 137, rhs._target)
{
    std::cout << "[shrubbery creation form] copy constructor called" << std::endl;
    _trees = rhs._trees;
}

ShrubberyCreationForm const & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) const
{
    std::cout << "[shrubbery creation form] assignation operator called" << std::endl;
    return rhs;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "[shrubbery creation form] destrcutor called" << std::endl;
}

void ShrubberyCreationForm::execute (Bureaucrat const & executor) const
{
    (void)executor;
    std::ofstream ofs("Trees.txt", std::ofstream::out);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 33; j++)
        {
            ofs.put(this->_trees[(int)(j + i * 33)]);
        }
        ofs.put('\n');
    }
}
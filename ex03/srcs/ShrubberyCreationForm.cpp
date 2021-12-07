#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("shrubbery creation", 0, 145, 137, "no target")
{
    _trees = "                                   _\\ |/ /   _\\ |/ /   _\\ |/ /      \\/\\|//_   \\/\\|//_   \\/\\|//_      _\\/|//_   _\\/|//_   _\\/|//_        \\|/       \\|/       \\|/           |         |         |            |         |         |                                        ";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : Form("shrubbery creation", 0, 145, 137, target)
{
    _trees = "                                   _\\ |/ /   _\\ |/ /   _\\ |/ /      \\/\\|//_   \\/\\|//_   \\/\\|//_      _\\/|//_   _\\/|//_   _\\/|//_        \\|/       \\|/       \\|/           |         |         |            |         |         |                                        ";
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & rhs) : Form("shrubbery creation", 0, 145, 137, rhs._target)
{
    _trees = rhs._trees;
}

ShrubberyCreationForm const & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
    new (this) ShrubberyCreationForm(rhs);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute (Bureaucrat const & executor) const
{
    (void)executor;
    std::ofstream ofs("Trees.txt", std::ofstream::out);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 33; j++)
        {
            ofs.put(_trees[(int)(j + i * 33)]);
        }
        ofs.put('\n');
    }
}
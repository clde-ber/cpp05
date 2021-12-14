#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("shrubbery creation", 0, 145, 137, "random target"), _target("random target")
{
    _trees = "                                   _\\ |/ /   _\\ |/ /   _\\ |/ /      \\/\\|//_   \\/\\|//_   \\/\\|//_      _\\/|//_   _\\/|//_   _\\/|//_        \\|/       \\|/       \\|/           |         |         |            |         |         |                                        ";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : Form("shrubbery creation", 0, 145, 137, target), _target(target)
{
    _trees = "                                   _\\ |/ /   _\\ |/ /   _\\ |/ /      \\/\\|//_   \\/\\|//_   \\/\\|//_      _\\/|//_   _\\/|//_   _\\/|//_        \\|/       \\|/       \\|/           |         |         |            |         |         |                                        ";
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & rhs) : Form("shrubbery creation", 0, 145, 137, rhs._target), _target(rhs._target)
{
    _trees = rhs._trees;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
    new (this) ShrubberyCreationForm(rhs);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::executeSpecialForm(Bureaucrat const & executor) const
{
    std::string file;
    file += executor.getName();
    file += "_shrubbery";
    std::ofstream ofs(file.c_str(), std::ofstream::out);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 33; j++)
        {
            ofs.put(_trees[(int)(j + i * 33)]);
        }
        ofs.put('\n');
    }
}
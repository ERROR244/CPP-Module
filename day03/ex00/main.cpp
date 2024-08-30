#include "ClapTrap.hpp"


int main()
{
	ClapTrap c("Trap");
	ClapTrap d("Cody");

	ClapTrap a;
    a = c;
	ClapTrap b(d);

    a.attack("\033[34m\"some robot\"\033[0m");
	a.takeDamage(5);
	a.beRepaired(5);
	a.takeDamage(60);
	a.beRepaired(0);
	a.attack("\033[34m\"some other robot\"\033[0m");
	b.beRepaired(3);
	for (int i = 0; i < 9; i++)
		b.attack("\033[34m\"Cody-clone\"\033[0m");
	b.takeDamage(3);
	b.beRepaired(3);
	return (0);
}

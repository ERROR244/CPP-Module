#include "ClapTrap.hpp"


int main()
{
		ClapTrap c("Trap");
		ClapTrap d("Cody");

		ClapTrap a;
    a = c;
		ClapTrap b(d);

    a.attack("\033[34m\"some robot\"\033[0m");
		a.takeDamage(10);
		a.takeDamage(10);
		a.beRepaired(5);
		a.attack("\033[34m\"some other robot\"\033[0m");
		b.beRepaired(3);
		for (int i = 0; i < 12; i++)
			b.attack("\033[34m\"Cody-clone\"\033[0m");
		b.beRepaired(3);
		return (0);
}

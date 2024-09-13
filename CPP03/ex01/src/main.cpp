#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap d("ydoC");
	ScavTrap c(d);
	ScavTrap a;
	ScavTrap b("Cody");

	a = c;

    a.attack("\033[34m\"some robot\"\033[0m");
	a.takeDamage(10);
	a.takeDamage(10);
	a.takeDamage(10);
	a.takeDamage(10);
	a.takeDamage(10);
	a.takeDamage(10);
	a.takeDamage(10);
	a.takeDamage(10);
	a.takeDamage(10);
	a.takeDamage(5);
	a.beRepaired(5);
	a.takeDamage(9);
	// a.takeDamage(1);
	a.attack("\033[34m\"some other robot\"\033[0m");
	for (int i = 0; i < 49; i++)
		b.attack("\033[34m\"Cody-clone\"\033[0m");
	// b.attack("\033[34m\"Cody-clone\"\033[0m");
	b.takeDamage(99);
	// b.takeDamage(1);
	b.guardGate();
	return (0);
}

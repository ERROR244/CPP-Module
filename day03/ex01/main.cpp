#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
		ScavTrap d("ydoC");
		ScavTrap a(d);
		ScavTrap b("Cody");

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
		a.attack("\033[34m\"some other robot\"\033[0m");
		for (int i = 0; i < 5; i++)
			b.attack("\033[34m\"Cody-clone\"\033[0m");
		b.guardGate();
		return (0);
}

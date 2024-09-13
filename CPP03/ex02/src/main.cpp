#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	FragTrap d("ydoC");
	FragTrap c(d);
	FragTrap a;
	FragTrap b("Cody");

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
	a.highFivesGuys();
	for (int i = 0; i < 99; i++)
		b.attack("\033[34m\"Cody-clone\"\033[0m");
	// b.attack("\033[34m\"Cody-clone\"\033[0m");
	b.takeDamage(99);
	// b.takeDamage(1);
	b.highFivesGuys();
	return (0);
}

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
    std::cout << "=== FRAGTRAP VS SCAVTRAP BATTLE ===" << std::endl;
    std::cout << "\n--- Creating FragTraps ---" << std::endl;
    FragTrap optimus("Optimus Prime");
    FragTrap bumblebee("Bumblebee");
    
    std::cout << "\n--- Creating ScavTraps ---" << std::endl;
    ScavTrap megatron("Megatron");
    ScavTrap starscream("Starscream");
    
    std::cout << "\n=== BATTLE BEGINS ===" << std::endl;
    
    // Round 1: FragTrap vs ScavTrap
    std::cout << "\n--- Round 1: Optimus (FragTrap) vs Megatron (ScavTrap) ---" << std::endl;
    optimus.attack("Megatron");
    megatron.takeDamage(30); // FragTrap does 30 damage
    megatron.attack("Optimus Prime");
    optimus.takeDamage(20); // ScavTrap does 20 damage
    
    // Round 2: FragTrap vs ScavTrap
    std::cout << "\n--- Round 2: Bumblebee (FragTrap) vs Starscream (ScavTrap) ---" << std::endl;
    bumblebee.attack("Starscream");
    starscream.takeDamage(30); // FragTrap does 30 damage
    starscream.attack("Bumblebee");
    bumblebee.takeDamage(20); // ScavTrap does 20 damage
    
    // Healing attempts
    std::cout << "\n--- Healing Phase ---" << std::endl;
    optimus.beRepaired(15);
    bumblebee.beRepaired(15);
    megatron.beRepaired(10);
    starscream.beRepaired(10);
    
    // Special abilities
    std::cout << "\n--- Special Abilities ---" << std::endl;
    optimus.highFivesGuys();
    bumblebee.highFivesGuys();
    megatron.guardGate();
    starscream.guardGate();
    
    // Energy comparison test
    std::cout << "\n--- Energy Comparison Test ---" << std::endl;
    std::cout << "FragTrap has more energy (100) than ScavTrap (50)" << std::endl;
    for (int i = 0; i < 10; i++) {
        optimus.attack("Training dummy");
        megatron.attack("Training dummy");
    }
    
    // FragTrap should still have energy, ScavTrap should be depleted
    std::cout << "\n--- After 10 attacks each ---" << std::endl;
    optimus.attack("Still has energy");
    megatron.attack("Should be depleted");
    
    // Test copy constructor and assignment operator
    std::cout << "\n=== SUBJECT REQUIREMENTS TEST ===" << std::endl;
    
    std::cout << "\n--- FragTrap Copy Constructor Test ---" << std::endl;
    FragTrap optimus_clone(optimus);
    optimus_clone.attack("Decepticon");
    optimus_clone.highFivesGuys();
    
    std::cout << "\n--- ScavTrap Copy Constructor Test ---" << std::endl;
    ScavTrap megatron_clone(megatron);
    megatron_clone.attack("Autobot");
    megatron_clone.guardGate();
    
    std::cout << "\n--- Assignment Operator Test ---" << std::endl;
    FragTrap jazz("Jazz");
    jazz = bumblebee;
    jazz.attack("Autobot");
    jazz.highFivesGuys();
    
    std::cout << "\n--- Inheritance Test ---" << std::endl;
    std::cout << "FragTrap vs ScavTrap comparison:" << std::endl;
    std::cout << "FragTrap - HP: 100, Energy: 100, Attack: 30" << std::endl;
    std::cout << "ScavTrap - HP: 100, Energy: 50, Attack: 20" << std::endl;
    std::cout << "Both inherit from ClapTrap but have different stats" << std::endl;
    
    std::cout << "\n=== BATTLE END ===" << std::endl;
    return (0);
}

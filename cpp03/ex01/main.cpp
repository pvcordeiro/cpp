#include "ScavTrap.hpp"

int	main(void)
{
    std::cout << "=== TRANSFORMERS BATTLE ===" << std::endl;
    std::cout << "\n--- Creating Autobots ---" << std::endl;
    ClapTrap optimus("Optimus Prime");
    ClapTrap bumblebee("Bumblebee");
    
    std::cout << "\n--- Creating Decepticons ---" << std::endl;
    ScavTrap megatron("Megatron");
    ScavTrap starscream("Starscream");
    
    std::cout << "\n=== BATTLE BEGINS ===" << std::endl;
    
    // Round 1: Optimus vs Megatron
    std::cout << "\n--- Round 1: Optimus vs Megatron ---" << std::endl;
    optimus.attack("Megatron");
    megatron.takeDamage(0); // ClapTrap does 0 damage
    megatron.attack("Optimus Prime");
    optimus.takeDamage(20); // ScavTrap does 20 damage
    
    // Round 2: Bumblebee vs Starscream
    std::cout << "\n--- Round 2: Bumblebee vs Starscream ---" << std::endl;
    bumblebee.attack("Starscream");
    starscream.takeDamage(0); // ClapTrap does 0 damage
    starscream.attack("Bumblebee");
    bumblebee.takeDamage(20); // ScavTrap does 20 damage
    
    // Healing attempts
    std::cout << "\n--- Healing Phase ---" << std::endl;
    optimus.beRepaired(5);
    bumblebee.beRepaired(5);
    megatron.beRepaired(10);
    starscream.beRepaired(10);
    
    // Special abilities
    std::cout << "\n--- Special Abilities ---" << std::endl;
    megatron.guardGate();
    starscream.guardGate();
    
    // Energy depletion test
    std::cout << "\n--- Energy Depletion Test ---" << std::endl;
    for (int i = 0; i < 8; i++) // Use remaining energy
        optimus.attack("Training dummy");
    
    optimus.attack("Should fail"); // Should show no energy
    optimus.beRepaired(1); // Should show no energy
    
    // Test copy constructor and assignment operator
    std::cout << "\n=== SUBJECT REQUIREMENTS TEST ===" << std::endl;
    
    std::cout << "\n--- Copy Constructor Test ---" << std::endl;
    ScavTrap megatron_clone(megatron);
    megatron_clone.attack("Autobot");
    megatron_clone.guardGate();
    
    std::cout << "\n--- Assignment Operator Test ---" << std::endl;
    ScavTrap soundwave("Soundwave");
    soundwave = starscream;
    soundwave.attack("Autobot");
    soundwave.guardGate();
    
    std::cout << "\n--- Inheritance Test ---" << std::endl;
    std::cout << "ScavTrap inherits from ClapTrap:" << std::endl;
    std::cout << "- HP: 100 (vs ClapTrap's 10)" << std::endl;
    std::cout << "- Energy: 50 (vs ClapTrap's 10)" << std::endl;
    std::cout << "- Attack Damage: 20 (vs ClapTrap's 0)" << std::endl;
    std::cout << "- Has special guardGate() ability" << std::endl;
    
    std::cout << "\n=== BATTLE END ===" << std::endl;
    return (0);
}

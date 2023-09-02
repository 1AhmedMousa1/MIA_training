# Define a class for a villain
class Villain:
    # Initialize the villain with a name, health, and energy
    def __init__(self, name, health=100, energy=500):
        self.name = name
        self.health = health
        self.energy = energy
        # Initialize empty lists to store the villain's weapons and shields
        self.weapons = []
        self.shields = []

    # Method to add a weapon to the villain's list of weapons
    def add_weapon(self, weapon):
        self.weapons.append(weapon)

    # Method to add a shield to the villain's list of shields
    def add_shield(self, shield):
        self.shields.append(shield)

    # Method for the villain to attack an opponent with a weapon
    def attack(self, opponent, weapon_index):
        # Get the weapon from the list of weapons using the specified index
        weapon = self.weapons[weapon_index]
        # Check if the weapon has resources left
        if weapon.resources > 0:
            # Use the weapon on the opponent
            weapon.use(self, opponent)
            print(f"{self.name} used {weapon.name} on {opponent.name}")
        else:
            print(f"{self.name} tried to use {weapon.name} on {opponent.name} but it has no resources left")

    # Method for the villain to defend with a shield
    def defend(self, shield_index):
        # Get the shield from the list of shields using the specified index
        shield = self.shields[shield_index]
        # Check if the shield has resources left
        if shield.resources > 0:
            # Use the shield
            shield.use(self)
            print(f"{self.name} used {shield.name}")
        else:
            print(f"{self.name} tried to use {shield.name} but it has no resources left")

    # Method to check if the villain is still alive (has health greater than 0)
    def is_alive(self):
        return self.health > 0

# Define a base class for a weapon
class Weapon:
    # Initialize the weapon with a name, energy cost, damage, and resources
    def __init__(self, name, energy, damage, resources=float('inf')):
        self.name = name
        self.energy = energy
        self.damage = damage
        self.resources = resources

    # Method to use the weapon on an opponent
    def use(self, user, opponent):
        # Reduce the user's energy by the energy cost of the weapon
        user.energy -= self.energy
        # Reduce the opponent's health by the damage of the weapon
        opponent.health -= self.damage
        # Reduce the resources of the weapon by 1
        self.resources -= 1

# Define a base class for a shield
class Shield:
    # Initialize the shield with a name, energy cost, save percentage, and resources
    def __init__(self, name, energy, save, resources=float('inf')):
        self.name = name
        self.energy = energy
        self.save = save
        self.resources = resources

    # Method to use the shield
    def use(self, user):
        # Reduce the user's energy by the energy cost of the shield
        user.energy -= self.energy
        # Reduce the resources of the shield by 1
        self.resources -= 1

# Define subclasses for each specific weapon and shield mentioned in the prompt

# Freeze Gun subclass that inherits from Weapon class and defines its own behavior 
class FreezeGun(Weapon):
    def __init__(self):
      super().__init__('Freeze Gun', 50, 11)

# Electric Prod subclass that inherits from Weapon class and defines its own behavior 
class ElectricProd(Weapon):
    def __init__(self):
      super().__init__('Electric Prod', 88, 18, 5)

# Mega Magnet subclass that inherits from Weapon class and defines its own behavior 
class MegaMagnet(Weapon):
    def __init__(self):
      super().__init__('Mega Magnet', 92, 10, 3)

    def use(self, user, opponent):
      super().use(user, opponent)
      opponent.next_attack_reduction = 0.2

# Kalman Missile subclass that inherits from Weapon class and defines its own behavior 
class KalmanMissile(Weapon):
    def __init__(self):
      super().__init__('Kalman Missile', 120, 20, 1)

# Energy Projected Barrier Gun subclass that inherits from Shield class and defines its own behavior 
class EnergyProjectedBarrierGun(Shield):
    def __init__(self):
      super().__init__('Energy Projected Barrier Gun', 20, 0.4)

# Selective Permeability subclass that inherits from Shield class and defines its own behavior 
class SelectivePermeability(Shield):
    def __init__(self):
      super().__init__('Selective Permeability', 50, 0.9, 2)

# Laser Blasters subclass that inherits from Weapon class and defines its own behavior 
class LaserBlasters(Weapon):
    def __init__(self):
      super().__init__('Laser Blasters', 40, 8)

# Plasma Grenades subclass that inherits from Weapon class and defines its own behavior 
class PlasmaGrenades(Weapon):
    def __init__(self):
      super().__init__('Plasma Grenades', 56, 13, 8)

# Sonic Resonance Cannon subclass that inherits from Weapon class and defines its own behavior 
class SonicResonanceCannon(Weapon):
    def __init__(self):
      super().__init__('Sonic Resonance Cannon', 100, 22, 3)

# Energy Net Trap subclass that inherits from Shield class and defines its own behavior 
class EnergyNetTrap(Shield):
    def __init__(self):
      super().__init__('Energy Net Trap', 15, 0.32)

# Quantum Deflector subclass that inherits from Shield class and defines its own behavior 
class QuantumDeflector(Shield):
    def __init__(self):
      super().__init__('Quantum Deflector', 40, 0.8)

# Function to play the game
def play_game(gru_strategy=None,vector_strategy=None):

    # Create the villains Gru and Vector
    gru = Villain('Gru')
    vector = Villain('Vector')

    # Add weapons and shields to Gru
    gru.add_weapon(FreezeGun())
    gru.add_weapon(ElectricProd())
    gru.add_weapon(MegaMagnet())
    gru.add_weapon(KalmanMissile())
    gru.add_shield(EnergyProjectedBarrierGun())
    gru.add_shield(SelectivePermeability())

    # Add weapons and shields to Vector
    vector.add_weapon(LaserBlasters())
    vector.add_weapon(PlasmaGrenades())
    vector.add_weapon(SonicResonanceCannon())
    vector.add_shield(EnergyNetTrap())
    vector.add_shield(QuantumDeflector())

    # Initialize the round number
    round_number = 1

    # Continue playing rounds until one of the villains is defeated
    while gru.is_alive() and vector.is_alive():
        
        print(f"Round {round_number}")
        round_number +=1
        
        # If a strategy function is provided for Gru, use it to determine Gru's action
        if gru_strategy is None:
            gru_action = input(f"Choose Gru's action (a for attack with weapon index or d for defend with shield index): ")
        else:
            gru_action=gru_strategy(gru,vector)
            
        # If Gru's action is to attack, use the specified weapon to attack Vector
        if gru_action[0] == 'a':
            gru.attack(vector, int(gru_action[1]))
        # If Gru's action is to defend, use the specified shield to defend
        elif gru_action[0] == 'd':
            gru.defend(int(gru_action[1]))

        # If a strategy function is provided for Vector, use it to determine Vector's action
        if vector_strategy is None:
            vector_action = input(f"Choose Vector's action (a for attack with weapon index or d for defend with shield index): ")
        else:
            vector_action=vector_strategy(vector,gru)
            
        # If Vector's action is to attack, use the specified weapon to attack Gru
        if vector_action[0] == 'a':
            vector.attack(gru, int(vector_action[1]))
        # If Vector's action is to defend, use the specified shield to defend
        elif vector_action[0] == 'd':
            vector.defend(int(vector_action[1]))

        # Print the current health and energy of both villains
        print(f"Gru's health: {gru.health}, energy: {gru.energy}")
        print(f"Vector's health: {vector.health}, energy: {vector.energy}")

    # Print the winner of the game
    if gru.is_alive():
        print("Gru wins!")
    else:
        print("Vector wins!")

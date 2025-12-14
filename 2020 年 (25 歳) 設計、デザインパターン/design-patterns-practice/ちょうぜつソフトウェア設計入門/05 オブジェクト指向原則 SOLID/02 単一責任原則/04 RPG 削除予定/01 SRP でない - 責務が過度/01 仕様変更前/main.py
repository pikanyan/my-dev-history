# SRP でない
# 責務過多

# 仕様変更前



class Character:
    def __init__(self, name, hp, attack_power):
        self.name = name
        self.hp = hp
        self.attack_power = attack_power
        self.experience = 0

    def attack(self, target):
        damage = self.attack_power
        target.hp -= damage
        self.experience += 10

        print(f"{self.name} attacks {target.name} for {damage} damage.")
        print(f"{target.name} has {target.hp} HP left.")

    def save_to_file(self):
        with open(f"{self.name}.txt", "w", encoding="utf-8") as f:
            f.write(f"Name: {self.name}\n")
            f.write(f"HP: {self.hp}\n")
            f.write(f"Attack Power: {self.attack_power}\n")
            f.write(f"Experience: {self.experience}\n")
            # 保存対象データが増えるほどメソッドが肥大化



def main():
    hero = Character("Hero", 100, 10)
    goblin = Character("Goblin", 50, 5)



    # Hero attacks Goblin for 10 damage.
    # Goblin has 40 HP left.
    hero.attack(goblin)



    # Name: Hero
    # HP: 100
    # Attack Power: 10
    # Experience: 10
    hero.save_to_file()



if __name__ == "__main__":
    main()

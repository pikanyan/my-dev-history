# SRP である
# 責務適度

# 仕様変更後



class CharacterData:
    """ キャラクターのステータスなど純粋なデータのみ管理 """
    def __init__(self, name, hp, attack_power):
        self.name = name
        self.hp = hp
        self.attack_power = attack_power
        self.experience = 0


class CombatSystem:
    """ 戦闘に関連するロジックを管理 """
    def attack(self, attacker: CharacterData, defender: CharacterData):
        damage = attacker.attack_power
        defender.hp -= damage
        attacker.experience += 10

        print(f"{attacker.name} attacks {defender.name} for {damage} damage.")
        print(f"{defender.name} has {defender.hp} HP left.")

class RestSystem:
    """ 新仕様: 休む(HP 回復)責務を担当 """
    def rest(self, character: CharacterData):
        rest_amount = 5
        character.hp += rest_amount

        print(f"{character.name} rests and recovers {rest_amount} HP.")

class FilePersistence:
    """ ファイルへの保存に責務を限定 """
    def save_character(self, character: CharacterData):
        with open(f"{character.name}.txt", "w", encoding="utf-8") as f:
            f.write(f"Name: {character.name}\n")
            f.write(f"HP: {character.hp}\n")
            f.write(f"Attack Power: {character.attack_power}\n")
            f.write(f"Experience: {character.experience}\n")
            # 保存対象データが増えるほどメソッドが肥大化



def main():
    hero = CharacterData("Hero", 100, 10)
    goblin = CharacterData("Goblin", 50, 5)

    combat = CombatSystem()
    rest_system = RestSystem()
    persistence = FilePersistence()



    # Hero attacks Goblin for 10 damage.
    # Goblin has 40 HP left.
    combat.attack(hero, goblin)



    # Hero rests and recovers 5 HP.
    rest_system.rest(hero)



    # Name: Hero
    # HP: 105
    # Attack Power: 10
    # Experience: 10
    persistence.save_character(hero)



if __name__ == "__main__":
    main()

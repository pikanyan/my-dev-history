# SRP でない
# 修正前



# ユーザー管理
class UserManager:
    def __init__(self):
        self.users = []

    # ユーザー管理のメソッド
    def add_user(self, username: str):
        # ユーザー管理の処理
        self.users.append(username)

        # ログ管理の処理を委託しない
        with open("app.txt", "a") as f:
            f.write(f"[ADD] Added user: {username}\n")

    # ユーザー管理のメソッド
    def remove_user(self, username: str):
        # ユーザー管理の処理
        if username in self.users:
            self.users.remove(username)

        # ログ管理の処理を委託しない
        with open("app.txt", "a") as f:
            f.write(f"[REMOVE] Removed user: {username}\n")

    # ユーザー管理のメソッド
    def list_users(self):
        # ユーザー管理の処理
        return self.users



def main():
    manager = UserManager()

    # [ADD] Added user: Alice
    # [ADD] Added user: Bob
    manager.add_user("Alice")
    manager.add_user("Bob")

    # Current users: ['Alice', 'Bob']
    print("Current users:", manager.list_users())
    


    # [REMOVE] Removed user: Alice
    manager.remove_user("Alice")

    # After removal: ['Bob']
    print("After removal:", manager.list_users())



if __name__ == "__main__":
    main()

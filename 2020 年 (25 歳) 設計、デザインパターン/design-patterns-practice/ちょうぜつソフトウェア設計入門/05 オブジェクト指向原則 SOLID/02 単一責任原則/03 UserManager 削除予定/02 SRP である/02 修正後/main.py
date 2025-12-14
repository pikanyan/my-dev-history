# SRP である
# 修正後



# ログ管理
class Logger:
    def __init__(self, log_filename="app.csv"):
            self.log_filename = log_filename

    # ログ管理のメソッド
    def write_log(self, action_type: str, details: str, username: str):
        # ログ管理の処理
        with open(self.log_filename, "a") as f:
            f.write(f"{action_type},{details},{username}\n")



# ユーザー管理
class UserManager:
    def __init__(self, logger: Logger):
        self.users = []
        self.logger = logger

    # ユーザー管理のメソッド
    def add_user(self, username: str):
        # ユーザー管理の処理
        self.users.append(username)

        # ログ管理の処理を委託する
        self.logger.write_log("ADD", "Added user", username)

    # ユーザー管理のメソッド
    def remove_user(self, username: str):
        # ユーザー管理の処理
        if username in self.users:
            self.users.remove(username)

        # ログ管理の処理を委託する
        self.logger.write_log("REMOVE", "Removed user", username)

    # ユーザー管理のメソッド
    def list_users(self):
        # ユーザー管理の処理
        return self.users



def main():
    logger = Logger()
    manager = UserManager(logger)

    # ADD,Added user,Alice
    # ADD,Added user,Bob
    manager.add_user("Alice")
    manager.add_user("Bob")

    # Current users: ['Alice', 'Bob']
    print("Current users:", manager.list_users())
    


    # REMOVE,Removed user,Alice
    manager.remove_user("Alice")

    # After removal: ['Bob']
    print("After removal:", manager.list_users())



if __name__ == "__main__":
    main()

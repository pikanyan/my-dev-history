# DIP でない
# 変更前



class MySQLUserRepository:
    """
    低水準モジュール:
    実際に MySQL へ接続してユーザ情報を CRUD する想定のクラス
    """
    def save_user(self, username: str):
        # 実際には MySQL に INSERT するなどの処理
        print(f"[MySQL] User '{username}' saved to MySQL database.")

    def get_user(self, username: str):
        # 実際には SELECT などを行う
        print(f"[MySQL] Getting user '{username}' from MySQL database.")

        return {"username": username}

class UserService:
    """
    高水準モジュール:
    アプリのビジネスロジックを担う (ユーザ管理など)
    """
    def __init__(self):
        # ここで低水準の具体クラスを直接生成している
        self.repository = MySQLUserRepository()

    def register_user(self, username: str):
        # 何かビジネスロジックがあったとして
        print(f"[Service] Registering user '{username}'...")

        self.repository.save_user(username)

    def get_user_info(self, username: str):
        return self.repository.get_user(username)



def main():
    service = UserService()

    # [Service] Registering user 'alice'..
    # [MySQL] User 'alice' saved to MySQL database.
    service.register_user("alice")

    # [MySQL] Getting user 'alice' from MySQL database.
    info = service.get_user_info("alice")

    # {'username': 'alice'}
    print(info)



if __name__ == "__main__":
    main()

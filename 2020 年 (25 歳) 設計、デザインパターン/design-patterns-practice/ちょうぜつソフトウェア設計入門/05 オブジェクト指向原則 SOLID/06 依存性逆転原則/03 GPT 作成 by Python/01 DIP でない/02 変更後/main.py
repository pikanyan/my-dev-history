# DIP でない
# 変更後



"""
class MySQLUserRepository:
    def save_user(self, username: str):
        # 実際には MySQL に INSERT するなどの処理
        print(f"[MySQL] User '{username}' saved to MySQL database.")

    def get_user(self, username: str):
        # 実際には SELECT などを行う
        print(f"[MySQL] Getting user '{username}' from MySQL database.")

        return {"username": username}
"""

class MongoUserRepository:
    """
    低水準モジュール:
    MongoDBでユーザ情報をCRUDする
    """
    def save_user(self, username: str):
        print(f"[Mongo] User '{username}' saved to MongoDB.")

    def get_user(self, username: str):
        print(f"[Mongo] Getting user '{username}' from MongoDB.")

        return {"username": username}

class UserService:
    """
    低水準の具体クラス(MongoUserRepository)を直接使うように変更された
    """
    def __init__(self):
        # ここで低水準の具体クラスを直接生成している
        # self.repository = MySQLUserRepository()

        # 以前は MySQLUserRepository を使っていたが、仕様変更で Mongo へ
        self.repository = MongoUserRepository()

    def register_user(self, username: str):
        # 何かビジネスロジックがあったとして
        print(f"[Service] Registering user '{username}' (Mongo version)...")

        self.repository.save_user(username)

    def get_user_info(self, username: str):
        return self.repository.get_user(username)



def main():
    service = UserService()

    # [Service] Registering user 'alice' (Mongo version)...
    # [Mongo] User 'alice' saved to MongoDB.
    service.register_user("alice")

    # [Mongo] Getting user 'alice' from MongoDB.
    info = service.get_user_info("alice")

    # {'username': 'alice'}
    print(info)



if __name__ == "__main__":
    main()

# DIP である
# 変更前

from abc import ABC, abstractmethod



class UserRepository(ABC):
    """
    Userに関するデータアクセスの抽象インターフェイス
    """
    @abstractmethod
    def save_user(self, username: str):
        pass

    @abstractmethod
    def get_user(self, username: str):
        pass

class MySQLUserRepository(UserRepository):
    """
    低水準モジュールの具体実装: MySQL
    """
    def save_user(self, username: str):
        print(f"[MySQL] User '{username}' saved to MySQL.")

    def get_user(self, username: str):
        print(f"[MySQL] Getting user '{username}' from MySQL.")
        return {"username": username}

class MongoUserRepository(UserRepository):
    """
    新たに追加された Mongo 実装
    """
    def save_user(self, username: str):
        print(f"[Mongo] User '{username}' saved to MongoDB.")

    def get_user(self, username: str):
        print(f"[Mongo] Getting user '{username}' from MongoDB.")

        return {"username": username}

class UserService:
    """
    高水準モジュール:
    抽象 (UserRepository) に対する依存を持つ (具体クラスには依存しない)
    """
    def __init__(self, repository: UserRepository):
        self.repository = repository

    def register_user(self, username: str):
        print("[Service] Registering user...")

        self.repository.save_user(username)

    def get_user_info(self, username: str):
        return self.repository.get_user(username)



def main():
    # 仕様変更後: Mongo版を使いたいだけ
    mongo_repo = MongoUserRepository()

    # 依存性注入: DI
    # コンストラクタで「どの実装を使うか」注入してもらう
    service = UserService(mongo_repo)



    # [Service] Registering user...
    # [Mongo] User 'carol' saved to MongoDB.
    service.register_user("carol")

    # [Mongo] Getting user 'carol' from MongoDB.
    info = service.get_user_info("carol")

    # {'username': 'carol'}
    print(info)



if __name__ == "__main__":
    main()

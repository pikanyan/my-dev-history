# SRP である
# 修正前

from abc import ABC, abstractmethod
from typing import Any



class DatabaseDriverInterface(ABC):
    @abstractmethod
    def write(self, key: str, data: Any) -> None:
        pass

    @abstractmethod
    def read(self, key: str) -> Any:
        pass



class DatabaseDriverVer1(DatabaseDriverInterface):
    def write(self, key: str, data: Any) -> None:
        pass

    def read(self, key: str) -> Any:
        pass

class DatabaseDriverVer2(DatabaseDriverInterface):
    def write(self, key: str, data: Any) -> None:
        pass

    def read(self, key: str) -> Any:
        pass



def main():
    pass



if __name__ == "__main__":
    main()

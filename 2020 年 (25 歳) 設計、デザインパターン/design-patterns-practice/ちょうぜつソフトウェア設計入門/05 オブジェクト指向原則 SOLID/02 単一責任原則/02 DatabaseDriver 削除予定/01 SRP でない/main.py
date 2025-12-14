# SRP でない
# 修正前

from abc import ABC, abstractmethod
from typing import Any



class WritingDatabaseDriverInterface(ABC):
    @abstractmethod
    def write(self, key: str, data: Any) -> None:
        pass

class ReadingDatabaseDriverInterface(ABC):
    @abstractmethod
    def read(self, key: str) -> Any:
        pass



class WritingDatabaseDriverVer1(WritingDatabaseDriverInterface):
    def write(self, key: str, data: Any) -> None:
        pass

class ReadingDatabaseDriverVer1(ReadingDatabaseDriverInterface):
    def read(self, key: str) -> Any:
        pass



class WritingDatabaseDriverVer2(WritingDatabaseDriverInterface):
    def write(self, key: str, data: Any) -> None:
        pass

class ReadingDatabaseDriverVer2(ReadingDatabaseDriverInterface):
    def read(self, key: str) -> Any:
        pass



def main():
    pass



if __name__ == "__main__":
    main()

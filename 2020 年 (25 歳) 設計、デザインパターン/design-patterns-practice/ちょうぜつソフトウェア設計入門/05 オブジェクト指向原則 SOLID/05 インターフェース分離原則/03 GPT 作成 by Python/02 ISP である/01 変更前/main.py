# ISP である
# 変更前

from abc import ABC, abstractmethod



class IPrinter(ABC):
    @abstractmethod
    def print(self, content: str) -> None:
        pass

class IScanner(ABC):
    @abstractmethod
    def scan(self) -> str:
        pass

class IFax(ABC):
    @abstractmethod
    def fax(self, number: str, content: str) -> None:
        pass



class AllInOneMachine(IPrinter, IScanner, IFax):
    def print(self, content: str) -> None:
        print(f"Printing: {content}")

    def scan(self) -> str:
        return "Scanned image data"

    def fax(self, number: str, content: str) -> None:
        print(f"Faxing to {number}, content: {content}")



def main():
    machine = AllInOneMachine()

    # Printing: Hello World
    machine.print("Hello World")

    # Scanned image data
    print(machine.scan())

    # Faxing to 0120-XXXX-XXX, content: Fax content
    machine.fax("0120-XXXX-XXX", "Fax content")



if __name__ == "__main__":
    main()

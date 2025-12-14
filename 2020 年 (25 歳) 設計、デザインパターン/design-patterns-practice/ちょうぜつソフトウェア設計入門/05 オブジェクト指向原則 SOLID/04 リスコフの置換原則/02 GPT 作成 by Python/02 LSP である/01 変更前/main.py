# LSP である
# 変更前

from abc import ABC, abstractmethod



class Shape(ABC):
    @abstractmethod
    def get_area(self) -> float:
        pass



class Rectangle(Shape):
    def __init__(self, width: float, height: float):
        self._width = width
        self._height = height

    def get_area(self) -> float:
        return self._width * self._height

    def set_width(self, width: float):
        self._width = width

    def set_height(self, height: float):
        self._height = height

    def get_width(self) -> float:
        return self._width

    def get_height(self) -> float:
        return self._height



class Square(Shape):
    def __init__(self, side: float):
        self._side = side

    def get_area(self) -> float:
        return self._side * self._side

    def set_side(self, side: float):
        self._side = side

    def get_side(self) -> float:
        return self._side



def main():
    rectangle = Rectangle(2, 3)
    sqare = Square(5)

    # 期待 6
    # 実際 6
    print(rectangle.get_area())



    # 期待 25
    # 実際 25
    print(sqare.get_area())



if __name__ == "__main__":
    main()

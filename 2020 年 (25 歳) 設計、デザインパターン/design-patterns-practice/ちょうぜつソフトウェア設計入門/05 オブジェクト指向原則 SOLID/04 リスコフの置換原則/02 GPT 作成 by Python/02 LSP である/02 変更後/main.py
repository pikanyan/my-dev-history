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

    # Rectangle の仕様
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

    # Square の仕様
    def set_side(self, side: float):
        self._side = side

    def get_side(self) -> float:
        return self._side



def resize_rectangle_to_10x20(rect: Rectangle):
    rect.set_width(10)
    rect.set_height(20)



def main():
    rectangle = Rectangle(2, 3)
    sqare = Square(5)

    # 期待 6
    # 実際 6
    print(rectangle.get_area())

    resize_rectangle_to_10x20(rectangle)

    # 期待 200
    # 実際 200
    print(rectangle.get_area())



    # 期待 25
    # 実際 25
    print(sqare.get_area())

    # resize_rectangle_to_10x20(sqare)

    # 期待 25
    # 実際 25
    print(sqare.get_area())



if __name__ == "__main__":
    main()

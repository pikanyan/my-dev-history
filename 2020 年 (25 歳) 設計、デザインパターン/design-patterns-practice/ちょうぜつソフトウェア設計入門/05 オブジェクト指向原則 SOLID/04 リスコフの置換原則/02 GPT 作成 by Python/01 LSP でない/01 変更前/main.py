# LSP でない
# 変更前



class Rectangle:
    def __init__(self, width: float, height: float):
        self._width = width
        self._height = height

    def set_width(self, width: float):
        self._width = width

    def set_height(self, height: float):
        self._height = height

    def get_width(self) -> float:
        return self._width

    def get_height(self) -> float:
        return self._height

    def get_area(self) -> float:
        return self._width * self._height



class Square(Rectangle):
    def __init__(self, side: float):
        super().__init__(side, side)

    # override
    def set_width(self, width: float):
        self._width = width
        self._height = width

    # override
    def set_height(self, height: float):
        self._width = height
        self._height = height



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

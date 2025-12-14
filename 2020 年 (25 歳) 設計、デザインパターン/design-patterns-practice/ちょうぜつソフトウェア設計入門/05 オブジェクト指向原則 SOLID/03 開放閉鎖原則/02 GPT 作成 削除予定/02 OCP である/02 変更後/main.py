# OCP である
# 変更前

from abc import ABC, abstractmethod



class Order:
    def __init__(self, user_type, amount):
        self.user_type = user_type
        self.amount = amount



# --- 割引ポリシーの抽象クラス ---
class DiscountPolicy(ABC):
    @abstractmethod
    def apply_discount(self, amount: float) -> float:
        pass

# --- 具体的な割引ポリシー ---
class NormalDiscountPolicy(DiscountPolicy):
    def apply_discount(self, amount: float) -> float:
        return amount

class VipDiscountPolicy(DiscountPolicy):
    def apply_discount(self, amount: float) -> float:
        return amount * 0.9

class GoldDiscountPolicy(DiscountPolicy):
    def apply_discount(self, amount: float) -> float:
        return amount * 0.8



class DiscountCalculator:
    def __init__(self):
        self._policies =\
        {
            'normal': NormalDiscountPolicy(),
            'vip':    VipDiscountPolicy(),
            'gold':   GoldDiscountPolicy(),
        }

    def calculate(self, order: Order) -> float:
        policy = self._policies.get(order.user_type, NormalDiscountPolicy())

        return policy.apply_discount(order.amount)



def main():
    calc = DiscountCalculator()

    normal_order = Order('normal', 1000)
    vip_order = Order('vip', 1000)
    gold_order = Order('gold', 1000)



    # 1000
    print(calc.calculate(normal_order))

    # 900.0
    print(calc.calculate(vip_order))

    # 800.0
    print(calc.calculate(gold_order))



if __name__ == "__main__":
    main()

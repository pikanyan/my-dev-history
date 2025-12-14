# OCP でない
# 変更後



class Order:
    def __init__(self, user_type, amount):
        self.user_type = user_type
        self.amount = amount

class DiscountCalculator:
    def calculate(self, order: Order) -> float:
        if order.user_type == 'normal':
            return order.amount
        
        elif order.user_type == 'vip':
            return order.amount * 0.9
        
        elif order.user_type == 'gold':
            return order.amount * 0.8
            
        else:
            return order.amount



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

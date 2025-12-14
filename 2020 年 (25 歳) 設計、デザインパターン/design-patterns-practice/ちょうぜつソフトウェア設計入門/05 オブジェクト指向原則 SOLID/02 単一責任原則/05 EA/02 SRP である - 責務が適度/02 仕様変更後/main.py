# SRP である
# 責務が適度

# 仕様変更後



# ---------- Data Retrieval ----------
class DataRetriever:
    def retrieve_data(self):
        """
        2 秒に 1 回データを取得（仕様変更）
        """
        print("Retrieving market data every 2 seconds... (Changed Spec: 2sec)")

        return ["tick_data", "order_book_data"]

# ---------- Data Storage ----------
class DataSaver:
    def save_data(self, data):
        """
        保存先をPostgreSQLに変更（仕様変更）
        """
        print("Saving data to PostgreSQL database...")

# ---------- Data Display ----------
class DataDisplayer:
    # ここは変更なし
    def display_data(self, data):
        print(f"Displaying data in console: {data}")

# ---------- Data Analysis ----------
class DataAnalyzer:
    # ここも変更なし
    def analyze_data(self, data):
        print("Analyzing data with basic logic...")
        return "BUY"

# ---------- Trade Execution ----------
class Trader:
    # ここも変更なし
    def execute_trade(self, signal):
        print(f"Executing {signal} order by market order.")



# Facade 的役割を担うメインクラス
class TradingSystem:
    def __init__(self):
        self.retriever = DataRetriever()
        self.saver = DataSaver()
        self.displayer = DataDisplayer()
        self.analyzer = DataAnalyzer()
        self.trader = Trader()

    def run(self):
        # Retrieving market data every 2 seconds... (Changed Spec: 2sec)
        # data = ["tick_data", "order_book_data"]
        data = self.retriever.retrieve_data()

        # Saving data to PostgreSQL database...
        self.saver.save_data(data)

        # Displaying data in console: ['tick_data', 'order_book_data']
        self.displayer.display_data(data)

        # Analyzing data with basic logic...
        # signal = "BUY"
        signal = self.analyzer.analyze_data(data)

        # Executing BUY order by market order.
        self.trader.execute_trade(signal)



def main():
    system = TradingSystem()

    system.run()



if __name__ == "__main__":
    main()

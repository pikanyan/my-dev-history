# SRP である
# 責務が適度

# 仕様変更前



# ---------- Data Retrieval ----------
class DataRetriever:
    def retrieve_data(self):
        print("Retrieving market data every second... (Specification: 1sec)")

        return ["tick_data", "order_book_data"]

# ---------- Data Storage ----------
class DataSaver:
    def save_data(self, data):
        print("Saving data to CSV...")

# ---------- Data Display ----------
class DataDisplayer:
    def display_data(self, data):
        print(f"Displaying data in console: {data}")

# ---------- Data Analysis ----------
class DataAnalyzer:
    def analyze_data(self, data):
        print("Analyzing data with basic logic...")
        
        return "BUY"

# ---------- Trade Execution ----------
class Trader:
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
        # Retrieving market data every second... (Specification: 1sec)
        # data = ["tick_data", "order_book_data"]
        data = self.retriever.retrieve_data()

        # Saving data to CSV...
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

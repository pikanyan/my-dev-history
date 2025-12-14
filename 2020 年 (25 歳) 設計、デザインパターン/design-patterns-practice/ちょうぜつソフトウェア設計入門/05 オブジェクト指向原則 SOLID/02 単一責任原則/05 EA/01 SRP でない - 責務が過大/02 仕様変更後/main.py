# SRP でない
# 責務が過大

# 仕様変更後



class MonolithicEA:
    def __init__(self):
        # 必要な属性をまとめてここに
        self.data_buffer = []
        self.analysis_result = None

    def run(self):
        # 全ての機能を一括で呼び出す

        # Retrieving market data every 2 seconds... (Changed Spec: 2sec)
        # self.data_buffer = ["tick_data", "order_book_data"]
        self.retrieve_data()

        # Saving data to PostgreSQL database..
        self.save_data()

        # Displaying data in console: ['tick_data', 'order_book_data']
        self.display_data()

        # Analyzing data with basic logic...
        # self.analysis_result = "BUY"
        self.analyze_data()

        # Executing BUY order by market order.
        self.trade()

    def retrieve_data(self):
        """取得頻度を 2 秒に変更"""

        print("Retrieving market data every 2 seconds... (Changed Spec: 2sec)")

        # 仮のデータを生成
        self.data_buffer = ["tick_data", "order_book_data"]

    def save_data(self):
        """保存先を CSV から PostgreSQL に変更"""

        print("Saving data to PostgreSQL database...")

    def display_data(self):
        """テキスト出力でリアルタイム表示"""

        print(f"Displaying data in console: {self.data_buffer}")

    def analyze_data(self):
        """簡易的な分析(例: 板の厚みの差を計算して保持)"""

        print("Analyzing data with basic logic...")

        # 仮の分析結果を格納
        self.analysis_result = "BUY"  # or "SELL"

    def trade(self):
        """成行注文のみサポート"""

        print(f"Executing {self.analysis_result} order by market order.")



def main():
    ea = MonolithicEA()

    ea.run()



if __name__ == "__main__":
    main()

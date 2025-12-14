# Factory Method でない
# 仕様変更前



import sqlite3



class EAWithoutFactoryV2:
    def __init__(self):
        # DB 接続のための初期化
        self.conn = sqlite3.connect("tick_data.db")

        self.create_table_if_not_exists()

    def create_table_if_not_exists(self):
        cursor = self.conn.cursor()

        cursor.execute("""
            CREATE TABLE IF NOT EXISTS tick_data (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                data TEXT
            )
        """)

        self.conn.commit()

    def retrieve_data(self):
        print("[V2] データ取得：銘柄増やす or 頻度調整など追加仕様かも")

    def save_data(self, data):
        # CSV 固定
        with open("tick_data.csv", "a", encoding="utf-8") as f:
            f.write(data + "\n")

        print("[V2] CSV へ保存完了")



        # SQLite への保存
        cursor = self.conn.cursor()

        cursor.execute("INSERT INTO tick_data(data) VALUES (?)", (data,))

        self.conn.commit()

        print("[V2] SQLite へ保存完了")

    def display_data(self, data):
        print(f"[V2] 画面表示：{data}（表示内容が増える可能性あり）")

    def analyze_data(self, data):
        # ここも分析ロジック追加される可能性
        print("[V2] 分析：より詳細なアルゴリズムへの変更など")

        return "分析結果"

    def trade(self, analysis_result):
        print(f"[V2] トレード実行：注文タイプ増加（指値・逆指値など）")

    def run(self):
        # [V2] データ取得：銘柄増やす or 頻度調整など追加仕様かも

        # tick_data.db

        # sqlite_sequence
        # CREATE TABLE sqlite_sequence(name, seq)

        # tick_data
        # CREATE TABLE tick_data (id INTEGER PRIMARY KEY AUTOINCREMENT, data TEXT)
        self.retrieve_data()



        dummy_data = "dummy_tick"
        
        # tick_data.csv
        # dummy_tick

        # tick_data.db

        # sqlite_sequence
        # tick_data 1

        # tick_data
        # 1 dummy_tick

        # [V2] CSV へ保存完了
        # [V2] SQLite へ保存完了
        self.save_data(dummy_data)



        # [V2] 画面表示：dummy_tick（表示内容が増える可能性あり）
        self.display_data(dummy_data)

        # [V2] 分析：より詳細なアルゴリズムへの変更など
        # analysis_result = "分析結果"
        analysis_result = self.analyze_data(dummy_data)

        # [V2] トレード実行：注文タイプ増加（指値・逆指値など）
        self.trade(analysis_result)



def main():
    ea = EAWithoutFactoryV2()
    
    ea.run()



if __name__ == "__main__":
    main()

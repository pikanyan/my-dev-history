# Factory Method でない
# 仕様変更前



class EAWithoutFactoryV1:
    def __init__(self):
        # 必要なら初期化処理
        pass

    def retrieve_data(self):
        print("[V1] データ取得: MarketSpeed.exe メモリから 1 銘柄だけ読み取り（例）")

    def save_data(self, data):
        # CSV 固定
        with open("tick_data.csv", "a", encoding="utf-8") as f:
            f.write(data + "\n")

        print("[V1] CSV へ保存完了")

    def display_data(self, data):
        print(f"[V1] 画面表示：{data}")

    def analyze_data(self, data):
        print("[V1] 分析：テクニカル指標や OFI を簡易計算（例）")

        return "分析結果"

    def trade(self, analysis_result):
        print(f"[V1] トレード実行：利確・損切りなど（例）")

    def run(self):
        # print("[V1] データ取得: MarketSpeed.exe メモリから 1 銘柄だけ読み取り（例）")
        self.retrieve_data()



        dummy_data = "dummy_tick"
        
        # tick_data.csv
        # dummy_tick

        # [V1] CSV へ保存完了
        self.save_data(dummy_data)

        # [V1] 画面表示：dummy_tick
        self.display_data(dummy_data)

        # [V1] 分析：テクニカル指標や OFI を簡易計算（例）
        # analysis_result = "分析結果"
        analysis_result = self.analyze_data(dummy_data)

        # [V1] トレード実行：利確・損切りなど（例）
        self.trade(analysis_result)



def main():
    ea = EAWithoutFactoryV1()
    ea.run()



if __name__ == "__main__":
    main()

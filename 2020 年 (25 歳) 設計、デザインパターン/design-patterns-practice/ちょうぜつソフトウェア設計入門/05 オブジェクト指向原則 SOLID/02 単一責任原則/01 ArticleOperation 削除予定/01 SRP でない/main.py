# SRP でない
# 責務が過多

# 仕様変更前



class Article:
    def __init__(self, title: str, content: str):
        self.title = title
        self.content = content

        # draft / published
        self.status = "draft"

        self.writer = None
        self.subscribers = []

class Writer:
    def __init__(self, name: str):
        self.name = name

class Subscriber:
    def __init__(self, name: str):
        self.name = name



class ArticleOperation:
    def __init__(self, article: Article):
        self.article = article

    def draft(self, writer: Writer):
        self.article.writer = writer
        self.article.status = "draft"

        print(f"[ArticleOperation] {writer.name} が記事 '{self.article.title}' のドラフトを作成しました。")

    def subscribe(self, subscriber: Subscriber):
        self.article.subscribers.append(subscriber.name)

        print(f"[ArticleOperation] {subscriber.name} が記事 '{self.article.title}' を購読しました。")



def main():
    writer = Writer("山田太郎")
    subscriber = Subscriber("佐藤花子")

    article = Article("ニュース記事 A", "ニュース内容 A")
    article_op = ArticleOperation(article)



    # [ArticleOperation] 山田太郎 が記事 'ニュース記事 A' のドラフトを作成しました。
    article_op.draft(writer)

    # [ArticleOperation] 佐藤花子 が記事 'ニュース記事 A' を購読しました。
    article_op.subscribe(subscriber)



if __name__ == "__main__":
    main()
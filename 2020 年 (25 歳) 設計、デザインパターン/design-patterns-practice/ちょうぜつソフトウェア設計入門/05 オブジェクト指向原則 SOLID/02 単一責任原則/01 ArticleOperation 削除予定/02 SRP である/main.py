# SRP である
# 責務が適度

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



class ArticleDraftOperation:
    def __init__(self, article: Article):
        self.article = article

    def draft(self, writer: Writer):
        self.article.writer = writer
        self.article.status = "draft"

        print(f"[ArticleDraftOperation] {writer.name} が記事 '{self.article.title}' のドラフトを作成しました。")

class ArticleSubscribeOperation:
    def __init__(self, article: Article):
        self.article = article

    def subscribe(self, subscriber: Subscriber):
        self.article.subscribers.append(subscriber.name)

        print(f"[ArticleSubscribeOperation] {subscriber.name} が記事 '{self.article.title}' を購読しました。")


def main():
    writer = Writer("山田太郎")
    subscriber = Subscriber("佐藤花子")

    article = Article("ニュース記事 A", "ニュース内容 A")
    draft_op = ArticleDraftOperation(article)
    subscribe_op = ArticleSubscribeOperation(article)



    # [ArticleDraftOperation] 山田太郎 が記事 'ニュース記事 A' のドラフトを作成しました。
    draft_op.draft(writer)

    # [ArticleSubscribeOperation] 佐藤花子 が記事 'ニュース記事 A' を購読しました。
    subscribe_op.subscribe(subscriber)



if __name__ == "__main__":
    main()
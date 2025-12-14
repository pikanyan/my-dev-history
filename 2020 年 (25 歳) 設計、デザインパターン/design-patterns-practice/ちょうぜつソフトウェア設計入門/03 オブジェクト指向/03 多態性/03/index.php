<?php

interface ArticleRepositoryInterface
{
    public function fetch($id): Article;
}

interface ArticlePresenterInterface
{
    public function format(Article $article);
}

class ArticleOperation
{
    public function __construct
    (
        protected ArticleRepositoryInterface $repository,
        protected ArticlePresenterInterface $presenter
    )
    {
        
    }

    public function show($id)
    {
        $article = $this->repository->fetch($id);

        return $this->presenter->format($article);
    }
}



class ArticleRepository implements ArticleRepositoryInterface
{
    public function fetch($id): Article
    {
        // TODO データベースに問い合わせする (SQL)

        return null;
    }
}

class ArticlePresenter implements ArticlePresenterInterface
{
    public function format(Article $article)
    {
        // TODO 表示用に整形する (HTML)
    }
}

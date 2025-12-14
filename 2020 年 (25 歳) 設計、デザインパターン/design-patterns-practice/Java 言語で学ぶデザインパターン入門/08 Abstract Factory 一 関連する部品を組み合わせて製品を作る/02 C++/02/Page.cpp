#include "Page.h"


Page::Page(const std::string& title, const std::string& author) :
    title(title), author(author)
{
}

Page::~Page()
{
    for (auto item : content)
    {
        // 管理しているリソース解放
        // delete item;
    }
}

void Page::add(Item* item)
{
    content.push_back(item);
}

void Page::output()
{
    std::string filename = title + ".html";



    try
    {
        std::ofstream writer(filename);

        // ファイルオープン失敗時
        if (!writer)
        {
            throw std::runtime_error("Failed to open file: " + filename);
        }



        writer << makeHTML();

        // 書き込みエラー時
        if (!writer)
        {
            throw std::runtime_error("Failed to write to file: " + filename);
        }

        writer.close();



        std::cout << filename << " を作成しました\n";
    }
    catch (const std::exception& e)
    {
        // C++では例外捕捉はcatchブロックで行います。
        // 具体的なエラーメッセージ表示等は実装次第です。
        // ここでは単純にメッセージ出力します。
        std::cerr << e.what() << '\n';
    }
}


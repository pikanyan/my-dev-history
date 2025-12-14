#include "main.h"

#include <iostream>
#include <memory>



class Handler
{
protected:
    std::shared_ptr<Handler> nextHandler_;

public:
    virtual ~Handler() = default;

    void set_next(std::shared_ptr<Handler> handler)
    {
        nextHandler_ = handler;
    }

    virtual void handle_request(int request) = 0;
};

class HandlerA :
    public Handler,
    public std::enable_shared_from_this<HandlerA>
{
public:
    void handle_request(int request) override
    {
        if (10 < request)
        {
            std::cout << "HandlerA handled the request : " << request << "\n";
        }
        else if (nextHandler_)
        {
            nextHandler_->handle_request(request);
        }
    }
};



int main()
{
    std::shared_ptr<Handler> handler1 = std::make_shared<HandlerA>();
    std::shared_ptr<Handler> handler2 = std::make_shared<HandlerA>();



    handler1->set_next(handler2);

    for (int i = 5; i <= 15; i += 5)
        handler1->handle_request(i);



    return 0;
}



/*
i = 5
handle_request(5)
handler2 ‚ªˆ—‚·‚é

i = 10
handle_request(10)
handler2 ‚ªˆ—‚·‚é

i = 15
handle_request(15)
handler1 ‚ªˆ—‚·‚é
*/

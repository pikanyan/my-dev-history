<?php

class Response
{
    public function __construct
    (
        public string $content = "OK"
    )
    {

    }
}

class ErrorResponse extends Response
{
    public function __construct()
    {
        parent::__construct("Error");
    }
}



interface RequestHandlerInterface
{
    public function handle(Request $request): Response;
}



// namespace Security;

abstract class AbstractCheckedHandler implements RequestHandlerInterface
{
    public function handle(Request $request): Response
    {
        if
        (
            $this->checkCommonly($request) &&
            $this->checkExternally($request)
        )
        {
            $request = $this->preProcessRequest($request);

            $response = $this->requestToResponse($request);

            return $this->postProcessResponse($response);
        }
        else
        {
            return new ErrorResponse();
        }
    }



    private function checkCommonly(Request $request): bool
    {
        return true;
    }

    abstract protected function checkExternally(Request $request): bool;

    private function preProcessRequest(Request $request): Request
    {
        return $request;
    }

    abstract protected function requestToResponse(Request $request): Response;

    private function postProcessResponse(Response $response): Response
    {
        return $response;
    }
}

class UserAccessCheckedHandler extends AbstractCheckedHandler
{
    public function __construct
    (
        private UserAccessCheckerInterface $userAccessChecker
    )
    {
        
    }

    protected function checkExternally(Request $request): bool
    {
        return $this->userAccessChecker->isAllowed($request->user);
    }

    protected function requestToResponse(Request $request): Response
    {
        return new Response("User Access Granted");
    }
}

class ResourceCheckedHandler extends AbstractCheckedHandler
{
    public function __construct
    (
        private ResourceCheckerInterface $resourceChecker
    )
    {
        
    }

    protected function checkExternally(Request $request): bool
    {
        return $this->resourceChecker->isAllowed($request->resource);
    }

    protected function requestToResponse(Request $request): Response
    {
        return new Response("Resource Access Granted");
    }
}



class Request
{
    public $user;
    public $resource;

    public function __construct($user, $resource = null)
    {
        $this->user = $user;
        $this->resource = $resource;
    }
}



interface UserAccessCheckerInterface
{
    public function isAllowed($user): bool;
}

interface ResourceCheckerInterface
{
    public function isAllowed($resource): bool;
}



class UserAccessChecker implements UserAccessCheckerInterface
{
    public function isAllowed($user): bool
    {
        return $user === "User1";
    }
}

class ResourceChecker implements ResourceCheckerInterface
{
    public function isAllowed($resource): bool
    {
        return $resource === "Resource1";
    }
}



class App
{
    public static function main(): void
    {
        $userAccessChecker = new UserAccessChecker();

        $resourceChecker = new ResourceChecker();



        $userHandler = new UserAccessCheckedHandler($userAccessChecker);

        $resourceHandler = new ResourceCheckedHandler($resourceChecker);



        $request = new Request("User1", "Resource1");

        echo $userHandler->handle($request)->content . PHP_EOL;     // User Access Granted

        echo $resourceHandler->handle($request)->content . PHP_EOL; // Resource Access Granted
    }
}



require __DIR__ . '/../vendor/autoload.php';



App::main();

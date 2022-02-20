#include <iostream>
#include <RendererEngine.h>

int main(void)
{
    Engine = new RendererEngine(1024, 768);
    Engine->Run();
    
    return 0;
}
#include <ribbon.hxx>

class Sandbox : public Ribbon::App
{
public:
    Sandbox()
    {

    }
    ~Sandbox()
    {

    }
};

int main()
{
    Sandbox *sandbox = new Sandbox();

    sandbox->Run();
    
    delete sandbox;
}

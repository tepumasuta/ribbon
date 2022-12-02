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

Ribbon::App* Ribbon::CreateApp()
{
    return new Sandbox();
}

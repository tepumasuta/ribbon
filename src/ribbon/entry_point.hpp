#pragma once

#ifdef RIB_PLATFORM_LINUX

extern Ribbon::App* Ribbon::CreateApp();

int main(int argc, char** argv)
{
    auto app = Ribbon::CreateApp();
    app->Run();
    delete app;
}

#endif

#include "enable_core.h"
#include "BoApp.h"

int main(int argc, char** argv)
{
    EnableCoreFile();
    BoApp app;
    return app.main(argc, argv);
}


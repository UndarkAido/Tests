#include <iostream>
#include <string>

#include "hub.hh"
#include "plugin-hello.hh"
#include "plugin-goodbye.hh"

int main() {
    Hub hub;
    hub.installPlugin(new pluginHello());
    hub.installPlugin(new pluginGoodbye());
    ((pluginHello*)hub.getPlugin("hello"))->sayHello();
    ((pluginGoodbye*)hub.getPlugin("goodbye"))->sayGoodbye();
    return 0;
}
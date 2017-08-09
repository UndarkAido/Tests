#include <iostream>
#include <string>

#include "hub.hh"
#include "plugin-hello.hh"
#include "plugin-goodbye.hh"

int main() {
    Hub hub;
    hub.installPlugin(new pluginHello());
    hub.installPlugin(new pluginGoodbye());
    hub.getPlugin<pluginHello>("hello")->sayHello();
    hub.getPlugin<pluginGoodbye>("goodbye")->sayGoodbye();
    return 0;
}
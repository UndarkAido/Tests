#ifndef PLUGINS_PLUGIN_HELLO_HH
#define PLUGINS_PLUGIN_HELLO_HH

#include <iostream>

#include "plugin.hh"

class pluginHello : public Plugin{
public:
    std::string getName() const {return "hello";};
    void sayHello(){
        std::cout << "Hello!" << std::endl;
    }
};

#endif //PLUGINS_PLUGIN_HELLO_HH

#ifndef PLUGINS_PLUGIN_GOODBYE_HH
#define PLUGINS_PLUGIN_GOODBYE_HH

#include <iostream>

#include "plugin.hh"

class pluginGoodbye : public Plugin{
public:
    std::string getName() const {return "goodbye";}
    void sayGoodbye(){
        std::cout << "Goodbye!" << std::endl;
    }
};

#endif //PLUGINS_PLUGIN_GOODBYE_HH

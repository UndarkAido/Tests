#ifndef PLUGINS_PLUGIN_HH
#define PLUGINS_PLUGIN_HH

#include <string>

class Plugin{
public:
    virtual std::string getName() const = 0;
};

#endif //PLUGINS_PLUGIN_HH

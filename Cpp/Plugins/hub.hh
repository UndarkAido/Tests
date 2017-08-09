#ifndef PLUGINS_HUB_HH
#define PLUGINS_HUB_HH

#include <map>
#include <string>
#include <memory>

#include "plugin.hh"

class Hub{
public:
    void installPlugin(Plugin* plugin){
        plugins.insert(std::pair<std::string, std::unique_ptr<Plugin>>(plugin->getName(), plugin));
    }

    template <typename T>
    T* getPlugin(std::string name){
        return (T*)plugins[name].get();
    }

    Plugin* getPlugin(std::string name){
        return getPlugin<Plugin>(name);
    }
private:
    std::map<std::string, std::unique_ptr<Plugin>> plugins;
};

#endif //PLUGINS_HUB_HH

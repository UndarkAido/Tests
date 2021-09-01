//&>/dev/null;x="${0%.*}";[ ! "$x" -ot "$0" ]||(rm -f "$x";clang++ -o "$x" "$0")&&"$x" $@;rm -f "$x";exit

#include <iostream>
#include <sstream>

#define JSON_USE_IMPLICIT_CONVERSIONS 0

#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace discordpp {
    using snowflake = uint64_t;

    inline snowflake get_snowflake(std::string src) {
        snowflake out;
        std::istringstream(src) >> out;
        return out;
    }

    inline snowflake get_snowflake(json src) {
        return get_snowflake(src.get<std::string>());
    }

    template<typename T>
    inline std::string to_string(const T &t) {
        return std::move(std::to_string(t));
    }

    template<>
    inline std::string to_string<std::string>(const std::string &s) {
        return s;
    }

    struct Snowflake {
        Snowflake(uint64_t value) : _value(value) {}

        Snowflake(std::string value) : _value(get_snowflake(value)) {}

        operator uint64_t &() {
            return _value;
        }

        operator std::string() const {
            return to_string(_value);
        }

        Snowflake &operator=(const std::string &str) {
            _value = get_snowflake(str);
            return *this;
        }

    protected:
        uint64_t _value;
    };
} // namespace discordpp

namespace nlohmann {
    template <>
    struct adl_serializer<discordpp::Snowflake> {
        static void to_json(json &j, const discordpp::Snowflake &sf) {
            j = static_cast<std::string>(sf);
        }
        static discordpp::Snowflake from_json(const json& j) {
            return {j.get<std::string>()};
        }
    };
} // namespace nlohmann

namespace dpp = discordpp;

int main() {
    dpp::Snowflake sf = 56;
    std::string sfs = sf;
    std::cout << sf << std::endl;
    std::cout << sfs << std::endl;
    json j({{"id", sf}});
    std::cout << j.dump(4) << std::endl;
    dpp::Snowflake sffj = j["id"].get<dpp::Snowflake>();
    std::cout << sf << std::endl;
}

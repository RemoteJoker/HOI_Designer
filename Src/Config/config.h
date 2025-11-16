#ifndef CONFIG_H
#define CONFIG_H

class Config {
public:
    static Config& getInstance() {
        static Config instance;
        return instance;
    }


public:
    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;
private:
    Config() = default;
    ~Config() = default;
};

#endif
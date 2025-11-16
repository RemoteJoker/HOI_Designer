#ifndef UTILS_H
#define UTILS_H

class Utils {
public:
    static Utils& getInstance() {
        static Utils instance;
        return instance;
    }


public:
    Utils(const Utils&) = delete;
    Utils& operator=(const Utils&) = delete;
private:
    Utils() = default;
    ~Utils() = default;
};

#endif
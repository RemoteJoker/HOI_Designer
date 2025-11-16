#ifndef GLOBALDATA_H
#define GLOBALDATA_H

class GlobalData {
public:
    static GlobalData& getInstance() {
        static GlobalData instance;
        return instance;
    }


public:
    GlobalData(const GlobalData&) = delete;
    GlobalData& operator=(const GlobalData&) = delete;
private:
    GlobalData() = default;
    ~GlobalData() = default;
};

#endif
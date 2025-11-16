#ifndef T_SERVICEIMPL_H
#define T_SERVICEIMPL_H

#include <QThread>

class T_ServiceImpl :public QThread {
public:
    T_ServiceImpl() = default;
    ~T_ServiceImpl() = default;
    
};

#endif
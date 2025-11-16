#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Service/t_control.h"
#include "Service/t_data.h"
#include "Service/t_network.h"
#include "Service/t_safety.h"

int main(){
    QApplication g_app(argc, argv);
    g_app.setApplicationName("DashBoard");
    g_app.setApplicationVersion("0.1.0");

    T_Control g_control = new T_Control;
    T_Data g_data = new T_Data;
    T_Network g_network = new T_Network;
    T_Safety g_safety = new T_Safety;

    g_control->start();
    g_data->start();
    g_network->start();
    g_safety->start();

    QQmlApplicationEngine g_engine;
    g_engine.rootContext()->setContextProperty("gControl", g_t_control);
    QObject::connect(
        &g_engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &g_app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    g_engine.load(QUrl("qrc:/Main.qml"));

    return g_app.exec();
}
#ifndef SPECTACLEDBUSADAPTOR_H
#define SPECTACLEDBUSADAPTOR_H

#include <QObject>

#include "Spectacle.h"


class SpectacleDbusAdaptor : public QObject
{
    Q_OBJECT
public:
    SpectacleDbusAdaptor(QObject *parent = 0);
    ~SpectacleDbusAdaptor();

public Q_SLOTS:
    void captureScreen(bool include_pointer);
    void captureWindow(bool include_pointer);
    void captureArea(bool include_pointer);
    
    void eraseCapture(const QString &fileName);
    void copyCaptureToClipboard(const QString &fileName);
    
Q_SIGNALS:
  void screenshotTaken(const QString &fileName);
  void screenshotFailed();
private:
    org::kde::Spectacle *iface;
};

#endif // SPECTACLEDBUSADAPTOR_H

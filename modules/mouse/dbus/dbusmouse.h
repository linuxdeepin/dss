/**
 * Copyright (C) 2015 Deepin Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 **/

/*
 * This file was generated by qdbusxml2cpp version 0.8
 * Command line was: qdbusxml2cpp touchpad.xml -p MouseInterface
 *
 * qdbusxml2cpp is Copyright (C) 2015 Digia Plc and/or its subsidiary(-ies).
 *
 * This is an auto-generated file.
 * Do not edit! All changes made to it will be lost.
 */

#ifndef DBUSMOUSE_H
#define DBUSMOUSE_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>


class MouseDeviceList
{
public:
    MouseDeviceList();
    ~MouseDeviceList();
    void registerMetaType();
    friend QDBusArgument & operator<< (QDBusArgument & argument, const MouseDeviceList & deviceList);
    friend const QDBusArgument & operator>> (const QDBusArgument & argument, MouseDeviceList & deviceList);
    void printValue();  // for test

private:
    QString m_name;
    int m_deviceId;
    bool m_active;
};

Q_DECLARE_METATYPE(MouseDeviceList)

/*
 * Proxy class for interface com.deepin.daemon.InputDevice.Mouse
 */
class ComDeepinDaemonInputDeviceMouseInterface: public QDBusAbstractInterface
{
    Q_OBJECT

    Q_SLOT void __propertyChanged__(const QDBusMessage& msg)
    {
        QList<QVariant> arguments = msg.arguments();
        if (3 != arguments.count())
            return;
        QString interfaceName = msg.arguments().at(0).toString();
        if (interfaceName != "com.deepin.daemon.InputDevice.Mouse")
            return;
        QVariantMap changedProps = qdbus_cast<QVariantMap>(arguments.at(1).value<QDBusArgument>());
        QStringList keys = changedProps.keys();
        foreach(const QString &prop, keys) {
        const QMetaObject* self = metaObject();
            for (int i=self->propertyOffset(); i < self->propertyCount(); ++i) {
                QMetaProperty p = self->property(i);
                if (p.name() == prop) {
                    QVariant v = p.read(this);
                    Q_EMIT p.notifySignal().invoke(this, QGenericArgument(v.typeName(), v.data()));
                }
            }
        }
    }
public:
    static inline const char *staticInterfaceName()
    { return "com.deepin.daemon.InputDevice.Mouse"; }

public:
    ComDeepinDaemonInputDeviceMouseInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~ComDeepinDaemonInputDeviceMouseInterface();

    Q_PROPERTY(MouseDeviceList DeviceList READ deviceList NOTIFY deviceListChanged)
    inline MouseDeviceList deviceList() const
    { return qvariant_cast< MouseDeviceList >(property("DeviceList")); }

    Q_PROPERTY(bool DisableTpad READ disableTpad WRITE setDisableTpad NOTIFY disableTpadChanged)
    inline bool disableTpad() const
    { return qvariant_cast< bool >(property("DisableTpad")); }
    inline void setDisableTpad(bool value)
    { setProperty("DisableTpad", QVariant::fromValue(value)); }

    Q_PROPERTY(int DoubleClick READ doubleClick WRITE setDoubleClick NOTIFY doubleClickChanged)
    inline int doubleClick() const
    { return qvariant_cast< int >(property("DoubleClick")); }
    inline void setDoubleClick(int value)
    { setProperty("DoubleClick", QVariant::fromValue(value)); }

    Q_PROPERTY(int DragThreshold READ dragThreshold WRITE setDragThreshold NOTIFY dragThresholdChanged)
    inline int dragThreshold() const
    { return qvariant_cast< int >(property("DragThreshold")); }
    inline void setDragThreshold(int value)
    { setProperty("DragThreshold", QVariant::fromValue(value)); }

    Q_PROPERTY(bool Exist READ exist NOTIFY existChanged)
    inline bool exist() const
    { return qvariant_cast< bool >(property("Exist")); }

    Q_PROPERTY(bool LeftHanded READ leftHanded WRITE setLeftHanded  NOTIFY leftHandedChanged)
    inline bool leftHanded() const
    { return qvariant_cast< bool >(property("LeftHanded")); }
    inline void setLeftHanded(bool value)
    { setProperty("LeftHanded", QVariant::fromValue(value)); }

    Q_PROPERTY(bool MiddleButtonEmulation READ middleButtonEmulation WRITE setMiddleButtonEmulation  NOTIFY middleButtonEmulationChanged)
    inline bool middleButtonEmulation() const
    { return qvariant_cast< bool >(property("MiddleButtonEmulation")); }
    inline void setMiddleButtonEmulation(bool value)
    { setProperty("MiddleButtonEmulation", QVariant::fromValue(value)); }

    Q_PROPERTY(double MotionAcceleration READ motionAcceleration WRITE setMotionAcceleration NOTIFY motionAccelerationChanged)
    inline double motionAcceleration() const
    { return qvariant_cast< double >(property("MotionAcceleration")); }
    inline void setMotionAcceleration(double value)
    { setProperty("MotionAcceleration", QVariant::fromValue(value)); }

    Q_PROPERTY(double MotionThreshold READ motionThreshold WRITE setMotionThreshold NOTIFY motionThresholdChanged)
    inline double motionThreshold() const
    { return qvariant_cast< double >(property("MotionThreshold")); }
    inline void setMotionThreshold(double value)
    { setProperty("MotionThreshold", QVariant::fromValue(value)); }

    Q_PROPERTY(bool NaturalScroll READ naturalScroll WRITE setNaturalScroll NOTIFY naturalScrollChanged)
    inline bool naturalScroll() const
    { return qvariant_cast< bool >(property("NaturalScroll")); }
    inline void setNaturalScroll(bool value)
    { setProperty("NaturalScroll", QVariant::fromValue(value)); }

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> Reset()
    {
        QList<QVariant> argumentList;
        return asyncCallWithArgumentList(QStringLiteral("Reset"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void naturalScrollChanged(bool NaturalScroll);
    void motionThresholdChanged(double MotionThreshold);
    void motionAccelerationChanged(double MotionAcceleration);
    void middleButtonEmulationChanged(bool MiddleButtonEmulation);
    void leftHandedChanged(bool LeftHanded);
    void existChanged(bool Exist);
    void dragThresholdChanged(int DragThreshold);
    void doubleClickChanged(int DoubleClick);
    void disableTpadChanged(bool DisableTpad);
    void deviceListChanged(MouseDeviceList DeviceList);
};

namespace com {
  namespace deepin {
    namespace daemon {
      namespace InputDevice {
        typedef ::ComDeepinDaemonInputDeviceMouseInterface Mouse;
      }
    }
  }
}
#endif

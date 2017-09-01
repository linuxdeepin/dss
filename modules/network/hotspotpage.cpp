#include "hotspotpage.h"
#include "nextpagewidget.h"
#include "switchwidget.h"
#include "settingsgroup.h"
#include "wirelessdevice.h"
#include "networkmodel.h"
#include "connectionsessionmodel.h"
#include "connectionsessionworker.h"

#include <QVBoxLayout>
#include <QDebug>

#include <unistd.h>

namespace dcc {

using namespace widgets;

namespace network {

const QString defaultHotspotName()
{
    return getlogin();
}

HotspotPage::HotspotPage(WirelessDevice *wdev, QWidget *parent)
    : ContentWidget(parent),
      m_wdev(wdev)
{
    Q_ASSERT(m_wdev->supportHotspot());

    m_hotspotSwitch = new SwitchWidget;
    m_hotspotSwitch->setTitle("aaa");

    m_configureWidget = new NextPageWidget;
    m_configureWidget->setTitle(tr("Hotspot Settings"));

    SettingsGroup *sgrp = new SettingsGroup;
    sgrp->appendItem(m_hotspotSwitch);
    sgrp->appendItem(m_configureWidget);

    QVBoxLayout *centralLayout = new QVBoxLayout;
    centralLayout->addWidget(sgrp);
    centralLayout->setSpacing(0);
    centralLayout->setContentsMargins(0, 10, 0, 0);

    QWidget *centralWidget = new TranslucentFrame;
    centralWidget->setLayout(centralLayout);

    setContent(centralWidget);
    setTitle(tr("Hotspot"));

    connect(m_hotspotSwitch, &SwitchWidget::checkedChanged, this, &HotspotPage::onSwitchToggled);
    connect(m_configureWidget, &NextPageWidget::clicked, this, &HotspotPage::onConfigWidgetClicked);
    connect(m_wdev, &WirelessDevice::sessionCreated, this, &HotspotPage::onConnectionSessionCreated);
}

void HotspotPage::setModel(NetworkModel *model)
{
    m_model = model;

    connect(model, &NetworkModel::connectionListChanged, this, &HotspotPage::onConnectionsChanged);

    QTimer::singleShot(1, this, &HotspotPage::onConnectionsChanged);
}

void HotspotPage::onSwitchToggled(const bool checked)
{
    if (checked)
        openHotspot();
    else
        closeHotspot();
}

void HotspotPage::onConfigWidgetClicked()
{
    const QString uuid = hotspotUuid();
    Q_ASSERT(!uuid.isEmpty());

    emit requestEditConnection(m_wdev->path(), uuid);
}

void HotspotPage::onConnectionsChanged()
{
    m_hotspotInfo = QJsonObject();
    for (const auto &hotspot : m_model->hotspots())
    {
        if (hotspot.value("HwAddress").toString() == m_wdev->hwAddr())
        {
            m_hotspotInfo = hotspot;
            break;
        }
    }

    const QString ssid = m_hotspotInfo.value("Ssid").toString();
    m_hotspotSwitch->setTitle(ssid.isEmpty() ? defaultHotspotName() : ssid);
    m_configureWidget->setVisible(!m_hotspotInfo.isEmpty());

    QTimer::singleShot(1, this, &HotspotPage::onActiveConnsChanged);
}

void HotspotPage::onActiveConnsChanged()
{
    if (m_hotspotInfo.isEmpty())
        return m_hotspotSwitch->setChecked(false);

    m_hotspotSwitch->setChecked(m_model->activeConnections().contains(hotspotUuid()));
}

void HotspotPage::onConnectionSessionCreated(const QString &sessionPath)
{
    // ensure edit page is empty
    Q_ASSERT(m_editPage.isNull());

    m_editPage = new ConnectionEditPage;

    ConnectionSessionModel *sessionModel = new ConnectionSessionModel(m_editPage);
    ConnectionSessionWorker *sessionWorker = new ConnectionSessionWorker(sessionPath, sessionModel, m_editPage);

    m_editPage->setModel(m_model, sessionModel);
    connect(m_editPage, &ConnectionEditPage::requestCancelSession, sessionWorker, &ConnectionSessionWorker::closeSession);
    connect(m_editPage, &ConnectionEditPage::requestChangeSettings, sessionWorker, &ConnectionSessionWorker::changeSettings);
    connect(m_editPage, &ConnectionEditPage::accept, sessionWorker, &ConnectionSessionWorker::saveSettings);
    connect(m_editPage, &ConnectionEditPage::requestNextPage, this, &HotspotPage::requestNextPage);
    connect(m_editPage, &ConnectionEditPage::requestFrameKeepAutoHide, this, &HotspotPage::requestFrameKeepAutoHide);
    connect(m_editPage, &ConnectionEditPage::requestRemove, [this] { emit requestDeleteConnection(hotspotUuid()); });
    connect(m_editPage, &ConnectionEditPage::requestDisconnect, [this] { emit requestDisconnectConnection(hotspotUuid()); });

    emit requestNextPage(m_editPage);
}

void HotspotPage::closeHotspot()
{
    const QString uuid = hotspotUuid();
    Q_ASSERT(!uuid.isEmpty());

    emit requestDisconnectConnection(uuid);
}

void HotspotPage::openHotspot()
{
    const QString uuid = hotspotUuid();

    if (uuid.isEmpty())
        emit requestNewHotspot(m_wdev->path());
    else
        requestActivateConnection(m_wdev->path(), uuid);
}

}

}

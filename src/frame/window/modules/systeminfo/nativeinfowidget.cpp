/*
 * Copyright (C) 2011 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     liuhong <liuhong_cm@deepin.com>
 *
 * Maintainer: liuhong <liuhong_cm@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "nativeinfowidget.h"
#include "widgets/settingsgroup.h"
#include "widgets/titlevalueitem.h"
#include "modules/systeminfo/logoitem.h"

#include <QVBoxLayout>
#include <QApplication>
#include <QSettings>
#include <QIcon>

using namespace dcc::widgets;
using namespace dcc::systeminfo;
using namespace DCC_NAMESPACE::systeminfo;

namespace DCC_NAMESPACE {
namespace systeminfo {

NativeInfoWidget::NativeInfoWidget(SystemInfoModel *model, QWidget *parent)
    : QWidget(parent)
    , m_model(model)
    , m_mainLayout(new QVBoxLayout)
{
    initWidget();
}

void NativeInfoWidget::initWidget()
{
    SettingsGroup *infoGroup = new SettingsGroup();

    LogoItem *logo = new LogoItem;
    logo->setDescription(systemCopyright());//LogoItem构造函数: set the discription visible=false
//    logo->setLogo(QIcon::fromTheme("dcc_deepin_logo"), 164, 42);
//    logo->setLogo(QIcon::fromTheme("dcc_deepin_uos_logo"), 156, 46); //不生效
    logo->setLogo(QIcon(":/icons/deepin/builtin/icons/dcc_deepin_uos_logo.svg"), 156, 46);

    m_version = new TitleValueItem();
    //~ contents_path /systeminfo/Edition
    m_version->setTitle(tr("Edition:"));
    m_version->setValue(m_model->version());
    //~ contents_path /systeminfo/Type
    m_type = new TitleValueItem();
    m_type->setTitle(tr("Type:"));

    m_kernel = new TitleValueItem();
    //~ contents_path /systeminfo/Kernel
    m_kernel->setTitle(tr("Kernel:"));
    m_kernel->setValue(m_model->kernel());

    m_processor = new TitleValueItem();
    //~ contents_path /systeminfo/Processor
    m_processor->setTitle(tr("Processor:"));
    m_processor->setValue(m_model->processor());

    m_memory = new TitleValueItem();
    //~ contents_path /systeminfo/Memory
    m_memory->setTitle(tr("Memory:"));
    m_memory->setValue(m_model->memory());

    m_disk = new TitleValueItem();
    //~ contents_path /systeminfo/Disk
    m_disk->setTitle(tr("Disk:"));
    m_disk->setValue(m_model->disk());

    infoGroup->appendItem(logo);
    infoGroup->appendItem(m_version);
    infoGroup->appendItem(m_type);
    infoGroup->appendItem(m_kernel);
    infoGroup->appendItem(m_processor);
    infoGroup->appendItem(m_memory);
    infoGroup->appendItem(m_disk);
    infoGroup->setSpacing(3);
    m_mainLayout->setMargin(0);
    m_mainLayout->addWidget(infoGroup);
    m_mainLayout->addStretch();
    setLayout(m_mainLayout);

    connect(m_model, &SystemInfoModel::versionChanged, this, &NativeInfoWidget::setEdition);
    connect(m_model, &SystemInfoModel::typeChanged, this, &NativeInfoWidget::setType);
    connect(m_model, &SystemInfoModel::processorChanged, this, &NativeInfoWidget::setProcessor);
    connect(m_model, &SystemInfoModel::memoryChanged, this, &NativeInfoWidget::setMemory);
    connect(m_model, &SystemInfoModel::diskChanged, this, &NativeInfoWidget::setDisk);

    setType(m_model->type());
}

void NativeInfoWidget::setEdition(const QString &edition)
{
    m_version->setValue(edition);
}

void NativeInfoWidget::setType(const QString &type)
{
    m_type->setValue(tr("%1-bit").arg(type));
}

void NativeInfoWidget::setProcessor(const QString &processor)
{
    m_processor->setValue(processor);
}

void NativeInfoWidget::setMemory(const QString &memory)
{
    m_memory->setValue(memory);
}

void NativeInfoWidget::setDisk(const QString &disk)
{
    m_disk->setValue(disk);
}

const QString NativeInfoWidget::systemCopyright() const
{
    const QSettings settings("/etc/deepin-installer.conf", QSettings::IniFormat);
    const QString oem_copyright = settings.value("system_info_vendor_name").toString().toLatin1();

    if (oem_copyright.isEmpty()) {
        return QString(QApplication::translate("dcc::systeminfo::SystemInfoWidget", "Copyright © 2011-%1 Wuhan Deepin Technology Co., Ltd.")).arg(2019);
    } else {
        return oem_copyright;
    }
}

const QString NativeInfoWidget::systemLogo() const
{
    const QSettings settings("/etc/deepin-installer.conf", QSettings::IniFormat);
    const QString logo_path = settings.value("system_info_vendor_logo").toString();
    const QPixmap oem_logo(logo_path);

    if (oem_logo.isNull()) {
        return ":/systeminfo/themes/dark/icons/logo.png";
    } else {
        return logo_path;
    }
}

}
}

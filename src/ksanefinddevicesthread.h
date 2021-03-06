/* ============================================================
 *
 * This file is part of the KDE project
 *
 * Date        : 2007-09-13
 * Description : Sane interface for KDE
 *
 * Copyright (C) 2007-2008 by Kare Sars <kare dot sars at iki dot fi>
 * Copyright (C) 2014 by Gregor Mitsch: port to KDE5 frameworks
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) version 3, or any
 * later version accepted by the membership of KDE e.V. (or its
 * successor approved by the membership of KDE e.V.), which shall
 * act as a proxy defined in Section 6 of version 3 of the license.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * ============================================================ */

#ifndef KSANE_FIND_DEVICES_THREAD_H
#define KSANE_FIND_DEVICES_THREAD_H

#include "ksanewidget.h"

#include <QThread>
#include <QList>

namespace KSaneIface
{

class FindSaneDevicesThread : public QThread
{
    Q_OBJECT

public:
    static FindSaneDevicesThread *getInstance();
    ~FindSaneDevicesThread();
    void run();

    const QList<KSaneWidget::DeviceInfo> devicesList() const;

private:
    FindSaneDevicesThread();

    QList<KSaneWidget::DeviceInfo> m_deviceList;
};

}

#endif

/*
 * Copyright (C) 2014-2015 Symeon Huang <hzwhuang@gmail.com>
 *
 * shadowsocks-qt5 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * shadowsocks-qt5 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libQtShadowsocks; see the file LICENSE. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef SQPROFILE_H
#define SQPROFILE_H

#include <QDataStream>
#include <QDate>
#include <QDateTime>

struct SQProfile
{
    SQProfile();

    bool autoStart;
    bool debug;
    quint16 serverPort;
    quint16 localPort;
    QString name;
    QString serverAddress;
    QString localAddress;
    QString method;
    QString password;
    int timeout;
    int latency;
    quint64 currentUsage;
    quint64 totalUsage;
    QDateTime lastTime;//last time this connection is used
    QDate clearedDate;//the last date when currentUsage was automatically reset
    quint8 resetDate;//on which day of the month (1~31) should the usage gets reset
};
Q_DECLARE_METATYPE(SQProfile)

QDataStream& operator << (QDataStream &out, const SQProfile &p);
QDataStream& operator >> (QDataStream &in, SQProfile &p);

#endif // SQPROFILE_H

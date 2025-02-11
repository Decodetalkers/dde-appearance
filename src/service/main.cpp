// SPDX-FileCopyrightText: 2021 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#include <QGuiApplication>
#include "dbus/appearance1adaptor.h"
#include "dbus/appearance1.h"
#include "modules/common/commondefine.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setOrganizationName("deepin");
    app.setApplicationName("org.deepin.dde.appearance");
    QTranslator translator;
    translator.load("/usr/share/dde-appearance/translations/dde-appearance_" + QLocale::system().name());
    app.installTranslator(&translator);
    Appearance1 *appearance = new Appearance1();
    new Appearance1Adaptor(appearance);

    APPEARANCEDBUS.registerService(AppearanceService);
    APPEARANCEDBUS.registerObject(AppearancePath, AppearanceInterface, appearance);

    return app.exec();
}

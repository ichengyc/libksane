/* ============================================================
 *
 * This file is part of the KDE project
 *
 * Copyright (C) 2009-2013 by Kare Sars <kare.sars@iki.fi>
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

#ifndef KSaneOption_h
#define KSaneOption_h

#include "libksane_export.h"

#include <KLocalizedString>

#include <QVariant>
#include <QObject>

class KSaneOptInternal;

class LIBKSANE_EXPORT KSaneOption : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)

public:

    enum Type {
        Type_None,
        Type_CheckBox,
        Type_Slider,
        Type_SliderF,
        Type_Combo,
        Type_Entry,
        Type_Gamma,
        Type_Button
    };

    enum Visibility {
        Hidden,
        Disabled,
        Shown
    };

    enum Unit {
        Unit_None,         /* the value is unit-less (e.g., # of scans) */
        Unit_Pixel,        /* value is number of pixels */
        Unit_Bit,          /* value is number of bits */
        Unit_mm,           /* value is millimeters */
        Unit_DPI,          /* value is resolution in dots/inch */
        Unit_Percent,      /* value is a percentage */
        Unit_Microsecond   /* value is micro seconds */
    };

    explicit KSaneOption(KSaneOptInternal *option);
    ~KSaneOption();

    Type type() const;

    Visibility visibility() const;

    /** Returns the technical name of the option */
    const QString saneName() const;

    /** Returns a translated title of the option for the user */
    const QString title() const;

    /** Returns a translated description of the option for the user */
    const QString description() const;


    QVariant value() const;
    Q_INVOKABLE QVariant minValue() const;
    Q_INVOKABLE QVariant maxValue() const;
    Q_INVOKABLE const QStringList valueList() const;
    Unit unit() const;
    const KLocalizedString unitString() const;
    Q_INVOKABLE const QString unitSpinBoxDoubleString() const;

    Q_INVOKABLE bool editable() const;
    bool setValue(const QVariant &val);

Q_SIGNALS:
    void valueChanged();
    void visibilityChanged();

private:
    KSaneOptInternal * const d;
};

#endif // KSANE_OPTION_H

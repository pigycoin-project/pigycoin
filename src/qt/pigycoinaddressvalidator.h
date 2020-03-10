// Copyright (c) 2011-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef PIGYCOIN_QT_PIGYCOINADDRESSVALIDATOR_H
#define PIGYCOIN_QT_PIGYCOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class PigycoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit PigycoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** Pigycoin address widget validator, checks for a valid pigycoin address.
 */
class PigycoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit PigycoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // PIGYCOIN_QT_PIGYCOINADDRESSVALIDATOR_H

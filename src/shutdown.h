// Copyright (c) 2020 Wayan Saka
// Copyright (c) 2020 The Pigycoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef PIGYCOIN_SHUTDOWN_H
#define PIGYCOIN_SHUTDOWN_H

void StartShutdown();
void AbortShutdown();
bool ShutdownRequested();

#endif

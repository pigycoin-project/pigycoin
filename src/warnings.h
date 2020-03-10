// Copyright (c) 2020 Wayan Saka
// Copyright (c) 2020 The Pigycoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef PIGYCOIN_WARNINGS_H
#define PIGYCOIN_WARNINGS_H

#include <stdlib.h>
#include <string>

void SetMiscWarning(const std::string& strWarning);
void SetfLargeWorkForkFound(bool flag);
bool GetfLargeWorkForkFound();
void SetfLargeWorkInvalidChainFound(bool flag);
/** Format a string that describes several potential problems detected by the core.
 * @param[in] strFor can have the following values:
 * - "statusbar": get the most important warning
 * - "gui": get all warnings, translated (where possible) for GUI, separated by <hr />
 * @returns the warning string selected by strFor
 */
std::string GetWarnings(const std::string& strFor);

#endif //  PIGYCOIN_WARNINGS_H

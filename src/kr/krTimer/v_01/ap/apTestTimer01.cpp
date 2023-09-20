//  *******************************************************************************
//  
//  mpfw / fw2 - Multi Platform FirmWare FrameWork 
//      library that contains the application code
//  Copyright (C) (2023) Marco Dau
//  
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Affero General Public License as published
//  by the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Affero General Public License for more details.
//  
//  You should have received a copy of the GNU Affero General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
//  
//  You can contact me by the following email address
//  marco <d o t> ing <d o t> dau <a t> gmail <d o t> com
//  
//  *******************************************************************************
/*
 * apTestTimer01.cpp
 *
 *  Created on: Sep, 16 2022
 *      Author: Marco Dau
 */

#include "apTestTimer01.h"

#include <rsSerial.h>
using namespace fw2::wrapper::resources;

namespace mpfw { namespace apps {

// ------------ End Service: Init by Timer -------------
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// -------------------------------------------------------------- SERVICE: TIMER --------------------------
// -------------------------------------------------- #include <common/krTimer.h>

// ............ Methods
void apTestTimer01::krTmrHndl_empty1 (void) {
    rsSerial::Tx("apTestTimer 01 ... "); rsSerial::Tx(rsSerial::endl);
}

void apTestTimer01::krTmrHndl_empty2 (void) {
    rsSerial::Tx("apTestTimer 02 ... "); rsSerial::Tx(rsSerial::endl);
}

// ............ Attributes
std::array<krTimer,apTestTimer01::kTimerNum> apTestTimer01::TmrArray {
/* kTimer_empty1	*/	krTimer(krTmrHndl_empty1,	krThread_One, krTimer::krTimer_STATUS_RUN),
/* kTimer_empty2	*/	krTimer(krTmrHndl_empty2,	krThread_Two, krTimer::krTimer_STATUS_RUN)
};

} }	// mpfw::apps

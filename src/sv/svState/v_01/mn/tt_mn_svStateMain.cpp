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
 * tt_mn_svStateMain.cpp
 *
 *  Created on: Sep, 27 2022
 *      Author: Marco Dau
 */

// module include
#include "tt_mn_svStateMain.h"
#include "../ap/tt_ap_svState.h"
#include "../mg/tt_mg_StateTbl.h"
#include "../mg/tt_mg_StateManager.h"

// lib include
#include <rsSerial.h>
using namespace fw2::wrapper::resources;

namespace mpfw { namespace apps {

void tt_mn_svStateMain::ShowTestResult	(void)	{
    rsSerial::Tx("************************************************************"); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx("From \"tt_mn_svStateMain.cpp\""); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx("************************************************************"); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx(rsSerial::endl);

    rsSerial::Tx("Thread Status:"); rsSerial::Tx(rsSerial::endl);
    for(uint16_t i=0; i<krThread_Num; i++)  {
        rsSerial::Tx(" >>> ");
        rsSerial::Tx("g_cnt[");                 rsSerial::Tx(i); rsSerial::Tx("]: "); rsSerial::Tx(tt_mg_StateManager::g_cnt[i]);           rsSerial::Tx(" -- ");
        rsSerial::Tx("g_cnt_no_match[");        rsSerial::Tx(i); rsSerial::Tx("]: "); rsSerial::Tx(tt_mg_StateManager::g_cnt_no_match[i]);  rsSerial::Tx(" -- ");
        rsSerial::Tx("gTest_CounterHandler[");  rsSerial::Tx(i); rsSerial::Tx("]: "); rsSerial::Tx(tt_ap_svState::gTest_CounterHandler[i]); rsSerial::Tx(" -- ");
    }
    rsSerial::Tx(rsSerial::endl);

    rsSerial::Tx("svState Status:"); rsSerial::Tx(rsSerial::endl);
    for(uint16_t i=0; i<tt_ap_svState::STATE_NUM; i++)  {
        rsSerial::Tx(" >>> ");
        if(tt_ap_svState:: gTest_CheckStateFail[i]) {
            rsSerial::Tx("State["); rsSerial::Tx(i); rsSerial::Tx("]: "); rsSerial::Tx("NO PASS!!! ERROR!!!");
        } else {
            rsSerial::Tx("State["); rsSerial::Tx(i); rsSerial::Tx("]: "); rsSerial::Tx("OK");
        }
    }

    rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx("............................................................"); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx(rsSerial::endl);
}

} }	// mpfw::apps

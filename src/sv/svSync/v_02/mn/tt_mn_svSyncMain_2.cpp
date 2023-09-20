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
 * tt_mn_svSyncMain_2.cpp
 *
 *  Created on: Sep, 27 2022
 *      Author: Marco Dau
 */

// module
#include "tt_mn_svSyncMain_2.h"
#include "../ap/tt_ap_svSync_2.h"
#include "../mg/tt_mg_SyncManager_2.h"

// lib include
#include <rsSerial.h>
using namespace fw2::wrapper::resources;

// tst
namespace mpfw { namespace apps {

uint32_t tt_mn_svSyncMain_2::Get_Test_CntrCheck	(uint8_t p_Param)   {
    if(1 == p_Param) return tt_ap_svSync_2::gTest_CntrCheck1;
    if(2 == p_Param) return tt_ap_svSync_2::gTest_CntrCheck2;
    return 0xffffffff;
}

bool tt_mn_svSyncMain_2::CheckRaceConditionCounter	(uint8_t p_Param)   {
    return (
        (tt_ap_svSync_2::gTest_CntrCheck1 < p_Param) ||
        (tt_ap_svSync_2::gTest_CntrCheck2 < p_Param)
    );
}

void tt_mn_svSyncMain_2::ShowTestResult	(void)	{
    rsSerial::Tx("************************************************************"); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx("From \"tt_mn_svSyncMain_2.cpp\""); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx("************************************************************"); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx(rsSerial::endl);

    rsSerial::Tx("gTest_CntrCheck1: "); rsSerial::Tx(tt_ap_svSync_2::gTest_CntrCheck1); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx("gTest_CntrCheck2: "); rsSerial::Tx(tt_ap_svSync_2::gTest_CntrCheck2); rsSerial::Tx(rsSerial::endl);

    if(tt_ap_svSync_2::gTest_CntrCheck1_Sync)   {
        rsSerial::Tx("FAILURE !!!! - gTest_CntrCheck1_Sync: "); rsSerial::Tx(tt_ap_svSync_2::gTest_CntrCheck1_Sync); rsSerial::Tx(rsSerial::endl);
    } else {
        rsSerial::Tx("gTest_Resource1_Sync: OK"); rsSerial::Tx(rsSerial::endl);
    }
    if(tt_ap_svSync_2::gTest_CntrCheck2_Sync)   {
        rsSerial::Tx("FAILURE !!!! - gTest_CntrCheck2_Sync: "); rsSerial::Tx(tt_ap_svSync_2::gTest_CntrCheck2_Sync); rsSerial::Tx(rsSerial::endl);
    } else {
        rsSerial::Tx("gTest_Resource2_Sync: OK"); rsSerial::Tx(rsSerial::endl);
    }
    rsSerial::Tx(rsSerial::endl);

    rsSerial::Tx("gTest_Counter_ABC: "      ); rsSerial::Tx(tt_ap_svSync_2::gTest_Counter_ABC       ); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx("gTest_Counter_ABC_Check: "); rsSerial::Tx(tt_ap_svSync_2::gTest_Counter_ABC_Check ); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx("gTest_Counter_CMD_Sync:  "); rsSerial::Tx(tt_ap_svSync_2::gTest_Counter_CMD_Sync  ); rsSerial::Tx(rsSerial::endl);

    rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx("............................................................"); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx(rsSerial::endl);

}

} }	// mpfw::apps

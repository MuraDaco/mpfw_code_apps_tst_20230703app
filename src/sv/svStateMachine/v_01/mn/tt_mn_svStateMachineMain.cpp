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
 * tt_mn_svStateMachineMain.cpp
 *
 *  Created on: Oct,  5 2022
 *      Author: Marco Dau
 */


// module include
#include "tt_mn_svStateMachineMain.h"
#include "../ap/tt_ap_svStateMachine.h"

// lib include
#include <rsSerial.h>
using namespace fw2::wrapper::resources;

// using namespace fw2::wrapper::core;

namespace mpfw { namespace apps {

void tt_mn_svStateMachineMain::ShowTestResult	(void)	{
    rsSerial::Tx("************************************************************"); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx("From \"tt_mn_svStateMachineMain.cpp\""); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx("************************************************************"); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx(rsSerial::endl);

    rsSerial::Tx("gTest_Counter:           "); rsSerial::Tx(tt_ap_svStateMachine::gTest_Counter      ); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx("gTest_Counter_Check:     "); rsSerial::Tx(tt_ap_svStateMachine::gTest_Counter_Check); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx("gTest_Counter_SM1:           "); rsSerial::Tx(tt_ap_svStateMachine::gTest_Counter_SM1      ); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx("gTest_Counter_Check_SM1:     "); rsSerial::Tx(tt_ap_svStateMachine::gTest_Counter_Check_SM1); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx("gTest_Counter_SM2:           "); rsSerial::Tx(tt_ap_svStateMachine::gTest_Counter_SM2      ); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx("gTest_Counter_Check_SM2:     "); rsSerial::Tx(tt_ap_svStateMachine::gTest_Counter_Check_SM2); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx(rsSerial::endl);


    rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx("SM1 State Status:"); rsSerial::Tx(rsSerial::endl);
    for(uint16_t i=0; i<tt_ap_svStateMachine::k_tt_State_Num; i++)  {
        rsSerial::Tx(" >>> ");
        rsSerial::Tx("gTest_CounterState_SM1[");       rsSerial::Tx(i); rsSerial::Tx("]: "); rsSerial::Tx(tt_ap_svStateMachine::gTest_CounterState_SM1[i]);       rsSerial::Tx(" -- ");
        rsSerial::Tx("gTest_CounterStateSwitch_SM1["); rsSerial::Tx(i); rsSerial::Tx("]: "); rsSerial::Tx(tt_ap_svStateMachine::gTest_CounterStateSwitch_SM1[i]); rsSerial::Tx(" -- ");
    }
    rsSerial::Tx(rsSerial::endl);

    rsSerial::Tx("SM2 State Status:"); rsSerial::Tx(rsSerial::endl);
    for(uint16_t i=0; i<tt_ap_svStateMachine::k_tt_State_Num; i++)  {
        rsSerial::Tx(" >>> ");
        rsSerial::Tx("gTest_CounterState_SM2[");       rsSerial::Tx(i); rsSerial::Tx("]: "); rsSerial::Tx(tt_ap_svStateMachine::gTest_CounterState_SM2[i]);       rsSerial::Tx(" -- ");
        rsSerial::Tx("gTest_CounterStateSwitch_SM2["); rsSerial::Tx(i); rsSerial::Tx("]: "); rsSerial::Tx(tt_ap_svStateMachine::gTest_CounterStateSwitch_SM2[i]); rsSerial::Tx(" -- ");
    }
    rsSerial::Tx(rsSerial::endl);

    rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx("............................................................"); rsSerial::Tx(rsSerial::endl);
    rsSerial::Tx(rsSerial::endl);

}

} }	// mpfw::apps

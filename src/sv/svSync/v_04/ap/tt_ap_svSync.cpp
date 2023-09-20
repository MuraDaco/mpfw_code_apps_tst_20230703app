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
 * tt_ap_svSync.cpp
 *
 *  Created on: Sep, 27 2022
 *      Author: Marco Dau
 */

#include "tt_ap_svSync.h"

#include <wp_sys_thread.h>

namespace mpfw { namespace apps {

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// ---------------------------------------------------------------  SERVICE: STATE ------------------------
// -------------------------------------------------- #include "../sv/svState.h"

//
// State definition
//

svState::state_t tt_ap_svSync::svState_Send1_Handler (__attribute__((unused)) krThreadId p_Thread, svState::state_t p_State)  {
    //for(auto i=0; i<10; i++) gTest_Resource1++;
    gTest_Resource1++;
    g_SyncCmd.Send(p_Thread, k_svSync_CMD_INC_RESOURCES_1, 1);
    return p_State;
}

svState::state_t tt_ap_svSync::svState_Send2_Handler (__attribute__((unused)) krThreadId p_Thread, svState::state_t p_State)  {
    //for(auto i=0; i<10; i++) gTest_Resource2++;
    gTest_Resource2++;
    g_SyncCmd.Send(p_Thread, k_svSync_CMD_INC_RESOURCES_2, 1);
    return p_State;
}

svState::state_t tt_ap_svSync::svState_Check_Handler (__attribute__((unused)) krThreadId p_Thread, svState::state_t p_State)  {
    uint32_t lTest_Resource1 = gTest_Resource1;
    uint32_t lTest_Resource2 = gTest_Resource2;

    uint32_t lTest_Resource1_Sync = gTest_Resource1_Sync;
    uint32_t lTest_Resource2_Sync = gTest_Resource2_Sync;

    //sleep_for(5ms);
    for (auto i=0; i<1000000; i++);

    if(lTest_Resource1 != gTest_Resource1)  gTest_CntrCheck1++;
    if(lTest_Resource2 != gTest_Resource2)  gTest_CntrCheck2++;

    if(lTest_Resource1_Sync != gTest_Resource1_Sync)  gTest_CntrCheck1_Sync++;
    if(lTest_Resource2_Sync != gTest_Resource2_Sync)  gTest_CntrCheck2_Sync++;

    return p_State;
}


svState tt_ap_svSync::svStateUnitArray [] = {
/* k_tt_StateUnitId_SEND1   */   {svState_Send1_Handler, krThread_One      ,k_tt_State_SEND1   }
/* k_tt_StateUnitId_SEND2   */  ,{svState_Send2_Handler, krThread_Two      ,k_tt_State_SEND2   }
/* k_tt_StateUnitId_CHECK   */  ,{svState_Check_Handler, krThread_Three    ,k_tt_State_CHECK   }
                                ,svState::svStateNull
};

volatile uint32_t   tt_ap_svSync::gTest_Resource1       = 0;
volatile uint32_t   tt_ap_svSync::gTest_Resource2       = 0;
volatile uint32_t   tt_ap_svSync::gTest_Resource1_Sync  = 0;
volatile uint32_t   tt_ap_svSync::gTest_Resource2_Sync  = 0;
uint32_t            tt_ap_svSync::gTest_Resource_Sync   = 0;
volatile uint32_t   tt_ap_svSync::gTest_CntrCheck1      = 0;
volatile uint32_t   tt_ap_svSync::gTest_CntrCheck2      = 0;
volatile uint32_t   tt_ap_svSync::gTest_CntrCheck1_Sync = 0;
volatile uint32_t   tt_ap_svSync::gTest_CntrCheck2_Sync = 0;


// ------------- END SERVICE: STATE -------------------
// ::::::::::::::::::::::::::::::::::::::::::::::::::::
// ++++++++++++++++++++++++++++++++++++++++++++++++++++



// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// ---------------------------------------------------------------  SERVICE: SYNCHRONIZATION --------------
// -------------------------------------------------- #include "../sv/svSync.h"

// ************************************************************** METHODS
void tt_ap_svSync::svSync_UpdateResource_Handler	(__attribute__((unused)) krThreadId p_ThreadId, svSync::sync_sgn_t p_sync_cmd, __attribute__((unused)) svSync::sync_val_t p_param)      {

    gTest_Resource_Sync += 1;

    if(k_svSync_CMD_INC_RESOURCES_1 == p_sync_cmd) {
        gTest_Resource1_Sync += 1;
    }
    if(k_svSync_CMD_INC_RESOURCES_2 == p_sync_cmd) {
        gTest_Resource2_Sync += 1;
    }


}

// ************************************************************ ATTRIBUTE
svSync  tt_ap_svSync::g_SyncCmd(svSync_UpdateResource_Handler, krThread_Three);


// ------------- END SERVICE: SYNCHRONIZATION ---------
// ::::::::::::::::::::::::::::::::::::::::::::::::::::
// ++++++++++++++++++++++++++++++++++++++++++++++++++++



} }	// mpfw::apps


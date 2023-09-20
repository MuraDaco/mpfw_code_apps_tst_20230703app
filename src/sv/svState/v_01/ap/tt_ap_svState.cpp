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
 * tt_ap_svState.cpp
 *
 *  Created on: Sep, 20 2022
 *      Author: Marco Dau
 */

#include "tt_ap_svState.h"

namespace mpfw { namespace apps {

bool     tt_ap_svState::gTest_CheckStateFail[STATE_NUM];
uint32_t tt_ap_svState::gTest_CounterHandler[krThread_Num];

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// ---------------------------------------------------------------  SERVICE: INIT  ------------------------
// -------------------------------------------------- #include "../kr/krInit.h"

// ************************************************************** METHODS
void tt_ap_svState::kr_InitHandler (void)   {

    for(auto i=0; i<STATE_NUM; i++) {
        gTest_CheckStateFail[i] = false;
    }

    for(auto i=0; i<krThread_Num; i++) {
        gTest_CounterHandler[i] = 0;
    }
}

// ********************************************************* UNIT SERVICE
krInit tt_ap_svState::g_Init(kr_InitHandler);

// ------------- END SERVICE: INIT --------------------
// ::::::::::::::::::::::::::::::::::::::::::::::::::::
// ++++++++++++++++++++++++++++++++++++++++++++++++++++


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// ---------------------------------------------------------------  SERVICE: STATE ------------------------
// -------------------------------------------------- #include "../sv/svState.h"

//
// State definition
//

svState::state_t tt_ap_svState::svState_00_Handler (krThreadId p_Thread, svState::state_t p_State)  {
    // -----------------------------------------------------------------
    // check status
    if (p_State != k_tt_State_00) gTest_CheckStateFail[p_State-k_tt_State_00] = true;
    gTest_CounterHandler[p_Thread]++;
    // -----------------------------------------------------------------
    return p_State;
}

svState::state_t tt_ap_svState::svState_01_Handler (krThreadId p_Thread, svState::state_t p_State)  {
    // -----------------------------------------------------------------
    // check status
    if (p_State != k_tt_State_01) gTest_CheckStateFail[p_State-k_tt_State_00] = true;
    gTest_CounterHandler[p_Thread]++;
    // -----------------------------------------------------------------
    return p_State;
}

svState::state_t tt_ap_svState::svState_02_Handler (krThreadId p_Thread, svState::state_t p_State)  {
    // -----------------------------------------------------------------
    // check status
    if (p_State != k_tt_State_02) gTest_CheckStateFail[p_State-k_tt_State_00] = true;
    gTest_CounterHandler[p_Thread]++;
    // -----------------------------------------------------------------
    return p_State;
}

svState::state_t tt_ap_svState::svState_03_Handler (krThreadId p_Thread, svState::state_t p_State)  {
    // -----------------------------------------------------------------
    // check status
    if (p_State != k_tt_State_03) gTest_CheckStateFail[p_State-k_tt_State_00] = true;
    gTest_CounterHandler[p_Thread]++;
    // -----------------------------------------------------------------
    return p_State;
}

svState::state_t tt_ap_svState::svState_04_Handler (krThreadId p_Thread, svState::state_t p_State)  {
    // -----------------------------------------------------------------
    // check status
    if (p_State != k_tt_State_04) gTest_CheckStateFail[p_State-k_tt_State_00] = true;
    gTest_CounterHandler[p_Thread]++;
    // -----------------------------------------------------------------
    return p_State;
}

svState::state_t tt_ap_svState::svState_05_Handler (krThreadId p_Thread, svState::state_t p_State)  {
    // -----------------------------------------------------------------
    // check status
    if (p_State != k_tt_State_05) gTest_CheckStateFail[p_State-k_tt_State_00] = true;
    gTest_CounterHandler[p_Thread]++;
    // -----------------------------------------------------------------
    return p_State;
}


svState tt_ap_svState::svStateUnitArray [] = {
/* k_tt_StateUnitId_00  */   {svState_00_Handler, krThread_Zero     ,k_tt_State_00   ,k_tt_State_01 }
/* k_tt_StateUnitId_01  */  ,{svState_01_Handler, krThread_One      ,k_tt_State_01   ,k_tt_State_02 }
/* k_tt_StateUnitId_02  */  ,{svState_02_Handler, krThread_Two      ,k_tt_State_02   ,k_tt_State_03 }
/* k_tt_StateUnitId_03  */  ,{svState_03_Handler, krThread_Three    ,k_tt_State_03   ,k_tt_State_04 }
/* k_tt_StateUnitId_04  */  ,{svState_04_Handler, krThread_Three    ,k_tt_State_04   ,k_tt_State_05 }
/* k_tt_StateUnitId_05  */  ,{svState_05_Handler, krThread_Two      ,k_tt_State_05   ,k_tt_State_00 }
                            ,svState::svStateNull
};




// ------------- END SERVICE: STATE -------------------
// ::::::::::::::::::::::::::::::::::::::::::::::::::::
// ++++++++++++++++++++++++++++++++++++++++++++++++++++



} }	// mpfw::apps

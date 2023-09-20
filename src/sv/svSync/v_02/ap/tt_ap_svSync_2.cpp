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
 * tt_ap_svSync_2.cpp
 *
 *  Created on: Sep, 27 2022
 *      Author: Marco Dau
 */

#include "tt_ap_svSync_2.h"

namespace mpfw { namespace apps {

volatile svState::state_t   tt_ap_svSync_2::g_ActiveState			    = tt_ap_svSync_2::k_tt_State_2_A;
volatile uint32_t		    tt_ap_svSync_2::gTest_Counter_ABC			= 0;
volatile uint32_t 		    tt_ap_svSync_2::gTest_Counter_ABC_Check		= 0;
volatile uint32_t 		    tt_ap_svSync_2::gTest_Counter_CMD_Sync		= 0;
volatile uint32_t           tt_ap_svSync_2::gTest_CounterState[k_tt_State_2_Num];

volatile uint32_t   tt_ap_svSync_2::gTest_Resource1         = 0;
volatile uint32_t   tt_ap_svSync_2::gTest_Resource2         = 0;
volatile uint32_t   tt_ap_svSync_2::gTest_Resource1_Sync    = 0;
volatile uint32_t   tt_ap_svSync_2::gTest_Resource2_Sync    = 0;
uint32_t            tt_ap_svSync_2::gTest_Resource_Sync     = 0;
volatile uint32_t   tt_ap_svSync_2::gTest_CntrCheck1        = 0;
volatile uint32_t   tt_ap_svSync_2::gTest_CntrCheck2        = 0;
volatile uint32_t   tt_ap_svSync_2::gTest_CntrCheck1_Sync   = 0;
volatile uint32_t   tt_ap_svSync_2::gTest_CntrCheck2_Sync   = 0;
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// ---------------------------------------------------------------  SERVICE: INIT  ------------------------
// -------------------------------------------------- #include "../kr/krInit.h"

// ************************************************************** METHODS
void tt_ap_svSync_2::kr_InitHandler (void)  {

    for(auto i=0; i<k_tt_State_2_Num; i++) {
        gTest_CounterState[i] = 0;
    }

}

// ********************************************************* UNIT SERVICE
krInit tt_ap_svSync_2::g_Init(kr_InitHandler);

// ------------- END SERVICE: INIT --------------------
// ::::::::::::::::::::::::::::::::::::::::::::::::::::
// ++++++++++++++++++++++++++++++++++++++++++++++++++++


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// ---------------------------------------------------------------  SERVICE: STATE ------------------------
// -------------------------------------------------- #include "../sv/svState.h"

// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// // ******************************
// // svStateUnitArray
// // ******************************
//	// ************************************************************** METHODS
//	static svState::state_t svState_Send1_Handler	(krThreadId, svState::state_t);
//	static svState::state_t svState_Send2_Handler	(krThreadId, svState::state_t);
//	static svState::state_t svState_Check_Handler	(krThreadId, svState::state_t);
//

// ___________________________________________________________________________
svState::state_t tt_ap_svSync_2::svState_Send1_Handler (__attribute__((unused)) krThreadId p_Thread, svState::state_t p_State)  {
    //for(auto i=0; i<10; i++) gTest_Resource1++;
    gTest_Resource1++;
    g_SyncCmd.Send(p_Thread, k_svSync_CMD_INC_RESOURCES_1, 1);
    return p_State;
}

// ___________________________________________________________________________
svState::state_t tt_ap_svSync_2::svState_Send2_Handler (__attribute__((unused)) krThreadId p_Thread, svState::state_t p_State)  {
    //for(auto i=0; i<10; i++) gTest_Resource2++;
    gTest_Resource2++;
    g_SyncCmd.Send(p_Thread, k_svSync_CMD_INC_RESOURCES_2, 1);
    return p_State;
}

// ___________________________________________________________________________
svState::state_t tt_ap_svSync_2::svState_Check_Handler (__attribute__((unused)) krThreadId p_Thread, svState::state_t p_State)  {
    uint32_t lTest_Resource1 = gTest_Resource1;
    uint32_t lTest_Resource2 = gTest_Resource2;

    uint32_t lTest_Resource1_Sync = gTest_Resource1_Sync;
    uint32_t lTest_Resource2_Sync = gTest_Resource2_Sync;

    for (auto i=0; i<1000000; i++);

    if(lTest_Resource1 != gTest_Resource1)  gTest_CntrCheck1++;
    if(lTest_Resource2 != gTest_Resource2)  gTest_CntrCheck2++;

    if(lTest_Resource1_Sync != gTest_Resource1_Sync)  gTest_CntrCheck1_Sync++;
    if(lTest_Resource2_Sync != gTest_Resource2_Sync)  gTest_CntrCheck2_Sync++;

    return p_State;
}


//  // ************************************************************ ATTRIBUTE
svState tt_ap_svSync_2::svStateUnitArray [] = {
/* k_tt_StateUnitId_SEND1   */   {svState_Send1_Handler, krThread_One      ,k_tt_State_SEND1   }
/* k_tt_StateUnitId_SEND2   */  ,{svState_Send2_Handler, krThread_Two      ,k_tt_State_SEND2   }
/* k_tt_StateUnitId_CHECK   */  ,{svState_Check_Handler, krThread_Three    ,k_tt_State_CHECK   }
                                ,svState::svStateNull
};
// .........................................................................

// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// // ******************************
// // svStateUnitArray_2
// // ******************************
// // ************************************************************** METHODS
// static svState::state_t svState_A_Handler	(krThreadId, svState::state_t);
// static svState::state_t svState_B_Handler	(krThreadId, svState::state_t);
// static svState::state_t svState_C_Handler	(krThreadId, svState::state_t);
//

// ___________________________________________________________________________
svState::state_t tt_ap_svSync_2::svState_Handler	(__attribute__((unused)) krThreadId p_Thread, svState::state_t p_State)  {
    gTest_Counter_ABC++;

    uint32_t lTest_Counter_ABC = gTest_Counter_ABC;

    switch (p_State) {
        case k_tt_State_2_A:
            gTest_CounterState[0]++;
        break;
        case k_tt_State_2_B:
            gTest_CounterState[1]++;
        break;
        case k_tt_State_2_C:
            gTest_CounterState[2]++;
        break;
    }

    for (auto i=0; i<1000000; i++);

    if(lTest_Counter_ABC != gTest_Counter_ABC)  gTest_Counter_ABC_Check++;

    if(!(gTest_Counter_ABC%100))    {
        switch (p_State) {
            case k_tt_State_2_A:
                gTest_CounterState[0]++;
            break;
            case k_tt_State_2_B:
                gTest_CounterState[1]++;
            break;
            case k_tt_State_2_C:
                gTest_CounterState[2]++;
            break;
        }
        return svState::k_SvState_DEFAULT_NEXT;
    }   


    return p_State;
}


// // ************************************************************ ATTRIBUTE
// static svState svStateUnitArray_2[];
//
svState tt_ap_svSync_2::svStateUnitArray_2 [] = {
/* k_tt_StateUnitId_2_A   */   {svState_Handler, krThread_Four    ,k_tt_State_2_A   ,k_tt_State_2_C   }
/* k_tt_StateUnitId_2_B   */  ,{svState_Handler, krThread_Five    ,k_tt_State_2_B   ,k_tt_State_2_A   }
/* k_tt_StateUnitId_2_C   */  ,{svState_Handler, krThread_Six     ,k_tt_State_2_C   ,k_tt_State_2_B   }
                              ,svState::svStateNull
};

// .........................................................................


// ------------- END SERVICE: STATE -------------------
// ::::::::::::::::::::::::::::::::::::::::::::::::::::
// ++++++++++++++++++++++++++++++++++++++++++++++++++++



// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// ---------------------------------------------------------------  SERVICE: SYNCHRONIZATION --------------
// -------------------------------------------------- #include "../sv/svSync.h"

// ************************************************************** METHODS
void tt_ap_svSync_2::svSync_UpdateResource_Handler	(__attribute__((unused)) krThreadId p_ThreadId, svSync::sync_sgn_t p_sync_cmd, __attribute__((unused)) svSync::sync_val_t p_param)      {

    gTest_Resource_Sync += 1;

    if(k_svSync_CMD_INC_RESOURCES_1 == p_sync_cmd) {
        gTest_Resource1_Sync += 1;
    }
    if(k_svSync_CMD_INC_RESOURCES_2 == p_sync_cmd) {
        gTest_Resource2_Sync += 1;
    }

}

void tt_ap_svSync_2::svSync_UpdateState_Handler	(__attribute__((unused)) krThreadId p_ThreadId, svSync::sync_sgn_t p_sync_cmd, svSync::sync_val_t p_param)      {
// N.B.: when there is no command (svSync::k_svSyncSgn_NULL) does not mean that the state had not to be modified
//       because the state handler could have modified it
//       when there is a command it means that someone in some part of the code use the svSync function/method "Send" (svSync::Send(...))
    gTest_Counter_CMD_Sync++;
    switch (p_sync_cmd) {
        case svSync::k_svSyncSgn_NULL:
        case k_svSync_CMD_2_UPDATE_STATE:
            g_ActiveState = p_param;
        break;
        default:
        break;
    }

}

// ************************************************************ ATTRIBUTE
svSync  tt_ap_svSync_2::g_SyncCmd         (svSync_UpdateResource_Handler, krThread_Three  );
svSync  tt_ap_svSync_2::g_SyncUpdateState (svSync_UpdateState_Handler                     );


// ------------- END SERVICE: SYNCHRONIZATION ---------
// ::::::::::::::::::::::::::::::::::::::::::::::::::::
// ++++++++++++++++++++++++++++++++++++++++++++++++++++



} }	// mpfw::apps


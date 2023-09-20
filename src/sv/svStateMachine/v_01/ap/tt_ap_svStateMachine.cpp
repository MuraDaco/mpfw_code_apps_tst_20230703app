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
 * tt_ap_svStateMachine.cpp
 *
 *  Created on: Oct,  5 2022
 *      Author: Marco Dau
 */

// module include
#include "tt_ap_svStateMachine.h"

// lib include
#include <krThread.h>
using namespace fw2::wrapper::core;

#include <rsSerial.h>
using namespace fw2::wrapper::resources;

namespace mpfw { namespace apps {


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// ---------------------------------------------------------------  GENERAL  ------------------------------
// -------------------------------------------------- #include "..."

// USE BY --> svState
uint32_t            volatile tt_ap_svStateMachine::gTest_Counter    				= 0 ;
uint32_t            volatile tt_ap_svStateMachine::gTest_Counter_Check 				= 0 ;
uint32_t            volatile tt_ap_svStateMachine::gTest_Counter_SM1				= 0 ;
uint32_t            volatile tt_ap_svStateMachine::gTest_Counter_Check_SM1			= 0 ;
uint32_t            volatile tt_ap_svStateMachine::gTest_Counter_SM2				= 0 ;
uint32_t            volatile tt_ap_svStateMachine::gTest_Counter_Check_SM2			= 0 ;
std::atomic_flag    tt_ap_svStateMachine::gLock                                     = ATOMIC_FLAG_INIT;

// USE BY --> krInit, svState
uint32_t volatile tt_ap_svStateMachine::gTest_CounterState_SM1			[k_tt_State_Num]	;
uint32_t volatile tt_ap_svStateMachine::gTest_CounterStateSwitch_SM1	[k_tt_State_Num]	;
uint32_t volatile tt_ap_svStateMachine::gTest_CounterState_SM2			[k_tt_State_Num]	;
uint32_t volatile tt_ap_svStateMachine::gTest_CounterStateSwitch_SM2	[k_tt_State_Num]	;


// ------------- END GENERAL  -------------------------
// ::::::::::::::::::::::::::::::::::::::::::::::::::::
// ++++++++++++++++++++++++++++++++++++++++++++++++++++

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// ---------------------------------------------------------------  SERVICE: INIT  ------------------------
// -------------------------------------------------- #include "../kr/krInit.h"

// ************************************************************** METHODS
void tt_ap_svStateMachine::kr_InitHandler (void)   {

    for(auto i=0; i<k_tt_State_Num; i++) {
        gTest_CounterState_SM1			[i] = 0;
        gTest_CounterStateSwitch_SM1	[i] = 0;
        gTest_CounterState_SM2			[i] = 0;
        gTest_CounterStateSwitch_SM2	[i] = 0;
    }
}

// ********************************************************* UNIT SERVICE
krInit tt_ap_svStateMachine::g_Init(kr_InitHandler);

// ------------- END SERVICE: INIT --------------------
// ::::::::::::::::::::::::::::::::::::::::::::::::::::
// ++++++++++++++++++++++++++++++++++++++++++++++++++++

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// ---------------------------------------------------------------  SERVICE: STATE ------------------------
// -------------------------------------------------- #include "../sv/svState.h"
// -------------------------------------------------- #include "../cg/cg_svState.h"

// ************************************************************** METHODS
svState::state_t tt_ap_svStateMachine::svState_SM1_Handler (__attribute__((unused)) krThreadId p_Thread, svState::state_t p_State)   {
    svState::state_t result = p_State;

    gTest_Counter_SM1++;
    uint32_t lTest_Counter_SM1 = gTest_Counter_SM1;

    gTest_CounterState_SM1[p_State - k_tt_State_FIRST]++;
    for (auto i=0; i<1000000; i++);

    // ................................................

    if (!gLock.test_and_set(std::memory_order_acquire)) {
        // .............
        gTest_Counter++;
        uint32_t lTest_Counter = gTest_Counter;
        for (auto i=0; i<1000000; i++);
        if(lTest_Counter != gTest_Counter)  gTest_Counter_Check++;
        // .............

        char ch;
        do {
            gTest_Counter++;
            lTest_Counter = gTest_Counter;

            rsSerial::Tx(rsSerial::endl);
            rsSerial::Tx("---------------------------------------------"); rsSerial::Tx(rsSerial::endl);
            rsSerial::Tx("State Machine 1 - Thread is: "); rsSerial::Tx(static_cast<uint8_t>(p_Thread)); rsSerial::Tx(" - State is: "); rsSerial::Tx(static_cast<uint8_t>(p_State - k_tt_State_FIRST)); rsSerial::Tx(rsSerial::endl);
            rsSerial::Tx("Counter State of State Machine 2: "); rsSerial::Tx(gTest_Counter_SM2); rsSerial::Tx(rsSerial::endl);
            rsSerial::Tx("Counter : "); rsSerial::Tx(gTest_Counter); rsSerial::Tx(" - Counter Check: "); rsSerial::Tx(gTest_Counter_Check); rsSerial::Tx(rsSerial::endl);
            rsSerial::Tx("Waiting you press a key: ");  rsSerial::Tx(rsSerial::endl);
            ch = rsSerial::Rx();
            rsSerial::Tx("---------------"); rsSerial::Tx(rsSerial::endl);
            rsSerial::Tx("State Machine 1 - Thread is: "); rsSerial::Tx(static_cast<uint8_t>(p_Thread)); rsSerial::Tx(" - State is: "); rsSerial::Tx(static_cast<uint8_t>(p_State - k_tt_State_FIRST)); rsSerial::Tx(rsSerial::endl);
            rsSerial::Tx("The character pressed is: "); rsSerial::Tx(ch); rsSerial::Tx(rsSerial::endl);

            if(lTest_Counter != gTest_Counter)  gTest_Counter_Check++;

            if(ch == 'n')    {
                gTest_CounterStateSwitch_SM1[p_State - k_tt_State_FIRST]++;
                rsSerial::Tx("Let's go to the next state!!"); rsSerial::Tx(rsSerial::endl);
                result = svState::k_SvState_DEFAULT_NEXT;
            }   

        } while ((ch != 'n') && (ch != 'X'));

        if(lTest_Counter_SM1 != gTest_Counter_SM1)  gTest_Counter_Check_SM1++;
        rsSerial::Tx("+++++++++++++++++++++++++++++++++++++++++++++"); rsSerial::Tx(rsSerial::endl);

        if(ch == 'X')    {
            krThread::g_Status = krThread::krThread_STATUS_END;
        }

        // .............

        gLock.clear(std::memory_order_release);

    }

    // ................................................

    if(lTest_Counter_SM1 != gTest_Counter_SM1)  gTest_Counter_Check_SM1++;

    if( !(gTest_Counter_SM1%100) )    {
        gTest_CounterStateSwitch_SM1[p_State - k_tt_State_FIRST]++;
        result = svState::k_SvState_DEFAULT_NEXT;
    }   


    return result;
}

svState::state_t tt_ap_svStateMachine::svState_SM2_Handler (__attribute__((unused)) krThreadId p_Thread, svState::state_t p_State)   {
    svState::state_t result = p_State;

    gTest_Counter_SM2++;
    uint32_t lTest_Counter_SM2 = gTest_Counter_SM2;

    gTest_CounterState_SM2[p_State - k_tt_State_FIRST]++;

    for (auto i=0; i<1000000; i++);

    // ................................................

    if (!gLock.test_and_set(std::memory_order_acquire)) {
        // .............
        gTest_Counter++;
        uint32_t lTest_Counter = gTest_Counter;
        for (auto i=0; i<1000000; i++);
        if(lTest_Counter != gTest_Counter)  gTest_Counter_Check++;

        // .............

        char ch;
        do {
            gTest_Counter++;
            lTest_Counter = gTest_Counter;

            rsSerial::Tx(rsSerial::endl);
            rsSerial::Tx("---------------------------------------------"); rsSerial::Tx(rsSerial::endl);
            rsSerial::Tx("State Machine 2 - Thread is: "); rsSerial::Tx(static_cast<uint8_t>(p_Thread)); rsSerial::Tx(" - State is: "); rsSerial::Tx(static_cast<uint8_t>(p_State - k_tt_State_FIRST)); rsSerial::Tx(rsSerial::endl);
            rsSerial::Tx("Counter State of State Machine 1: "); rsSerial::Tx(gTest_Counter_SM1); rsSerial::Tx(rsSerial::endl);
            rsSerial::Tx("Counter : "); rsSerial::Tx(gTest_Counter); rsSerial::Tx(" - Counter Check: "); rsSerial::Tx(gTest_Counter_Check); rsSerial::Tx(rsSerial::endl);
            rsSerial::Tx("Waiting you press a key: ");  rsSerial::Tx(rsSerial::endl);
            ch = rsSerial::Rx();
            rsSerial::Tx("---------------"); rsSerial::Tx(rsSerial::endl);
            rsSerial::Tx("State Machine 2 - Thread is: "); rsSerial::Tx(static_cast<uint8_t>(p_Thread)); rsSerial::Tx(" - State is: "); rsSerial::Tx(static_cast<uint8_t>(p_State - k_tt_State_FIRST)); rsSerial::Tx(rsSerial::endl);
            rsSerial::Tx("The character pressed is: "); rsSerial::Tx(ch); rsSerial::Tx(rsSerial::endl);

            if(lTest_Counter != gTest_Counter)  gTest_Counter_Check++;

            if(ch == 'n')    {
                gTest_CounterStateSwitch_SM2[p_State - k_tt_State_FIRST]++;
                rsSerial::Tx("Let's go to the next state!!"); rsSerial::Tx(rsSerial::endl);
                result = svState::k_SvState_DEFAULT_NEXT;
            }   

        } while ((ch != 'n') && (ch != 'X'));

        if(lTest_Counter_SM2 != gTest_Counter_SM2)  gTest_Counter_Check_SM1++;
        rsSerial::Tx("+++++++++++++++++++++++++++++++++++++++++++++"); rsSerial::Tx(rsSerial::endl);

        if(ch == 'X')    {
            krThread::g_Status = krThread::krThread_STATUS_END;
        }

        // .............

        gLock.clear(std::memory_order_release);

    }

    // ................................................

    if(lTest_Counter_SM2 != gTest_Counter_SM2)  gTest_Counter_Check_SM2++;
    
    if( !(gTest_Counter_SM2%100) )    {
        gTest_CounterStateSwitch_SM2[p_State - k_tt_State_FIRST]++;
        result = svState::k_SvState_DEFAULT_NEXT;
    }   

    return result;
}


// ************************************************************ UNIT SERVICE
svState tt_ap_svStateMachine::svState_SM1_UnitArray [] = {
/* k_tt_StateUnitId_A  */   {svState_SM1_Handler, krThread_Three       ,k_tt_State_A   ,k_tt_State_B }  ,
/* k_tt_StateUnitId_B  */   {svState_SM1_Handler, krThread_Four        ,k_tt_State_B   ,k_tt_State_C }  ,
/* k_tt_StateUnitId_C  */   {svState_SM1_Handler, krThread_Five        ,k_tt_State_C   ,k_tt_State_D }  ,
/* k_tt_StateUnitId_D  */   {svState_SM1_Handler, krThread_Six         ,k_tt_State_D   ,k_tt_State_E }  ,
/* k_tt_StateUnitId_E  */   {svState_SM1_Handler, krThread_Seven       ,k_tt_State_E   ,k_tt_State_F }  ,
/* k_tt_StateUnitId_F  */   {svState_SM1_Handler, krThread_Eight       ,k_tt_State_F   ,k_tt_State_A }  ,
                            svState::svStateNull
};


svState tt_ap_svStateMachine::svState_SM2_UnitArray [] = {
/* k_tt_StateUnitId_A  */   {svState_SM2_Handler, krThread_Nine        ,k_tt_State_A   ,k_tt_State_F }  ,
/* k_tt_StateUnitId_B  */   {svState_SM2_Handler, krThread_Ten         ,k_tt_State_B   ,k_tt_State_A }  ,
/* k_tt_StateUnitId_C  */   {svState_SM2_Handler, krThread_Eleven      ,k_tt_State_C   ,k_tt_State_B }  ,
/* k_tt_StateUnitId_D  */   {svState_SM2_Handler, krThread_Twelve      ,k_tt_State_D   ,k_tt_State_C }  ,
/* k_tt_StateUnitId_E  */   {svState_SM2_Handler, krThread_Thirteen    ,k_tt_State_E   ,k_tt_State_D }  ,
/* k_tt_StateUnitId_F  */   {svState_SM2_Handler, krThread_Fourteen    ,k_tt_State_F   ,k_tt_State_E }  ,
                            svState::svStateNull
};



// ------------- END SERVICE: STATE -------------------
// ::::::::::::::::::::::::::::::::::::::::::::::::::::
// ++++++++++++++++++++++++++++++++++++++++++++++++++++



// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// ---------------------------------------------------------------  SERVICE: STATE MACHINE ----------------
// -------------------------------------------------- #include "../sv/svStateMachine.h"

// ********************************************************* UNIT SERVICE
svStateMachine tt_ap_svStateMachine::g_StMach_1(svState_SM1_UnitArray, k_tt_State_A, svStateMachine::k_StateMachine_STATUS_RUN);
svStateMachine tt_ap_svStateMachine::g_StMach_2(svState_SM2_UnitArray, k_tt_State_A, svStateMachine::k_StateMachine_STATUS_RUN);

// ------------- END SERVICE: STATE MACHINE -----------
// ::::::::::::::::::::::::::::::::::::::::::::::::::::
// ++++++++++++++++++++++++++++++++++++++++++++++++++++

} }	// mpfw::apps

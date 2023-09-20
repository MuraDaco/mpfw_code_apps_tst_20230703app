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
 * tt_ap_svStateMachine.h
 *
 *  Created on: Oct,  5 2022
 *      Author: Marco Dau
 */


#ifndef AP_TT_SV_STATE_MACHINE_H_
#define AP_TT_SV_STATE_MACHINE_H_

// system include
#include <atomic>
#include <array>
#include <cstdint>

// lib include 
#include <krInit.h>
#include <svState.h>
#include <svStateMachine.h>
using namespace fw2::core::core;


// tst include
#include <cg_krThread.h>
#include <app/cg_app_svState.h>

// using namespace fw2::wrapper::core;

namespace mpfw { namespace apps {



class tt_ap_svStateMachine {
public:

	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	// ---------------------------------------------------------------  GENERAL  ------------------------------
	// -------------------------------------------------- #include "..."

	// USE BY --> svState
    static volatile uint32_t gTest_Counter						;
    static volatile uint32_t gTest_Counter_Check				;
    static volatile uint32_t gTest_Counter_SM1					;
    static volatile uint32_t gTest_Counter_Check_SM1			;
    static volatile uint32_t gTest_Counter_SM2					;
    static volatile uint32_t gTest_Counter_Check_SM2			;

	static std::atomic_flag gLock;


	// USE BY --> krInit, svState
    static volatile uint32_t gTest_CounterState_SM1			[]	;
    static volatile uint32_t gTest_CounterStateSwitch_SM1	[]	;
    static volatile uint32_t gTest_CounterState_SM2			[]	;
    static volatile uint32_t gTest_CounterStateSwitch_SM2	[]	;



	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	// ---------------------------------------------------------------  SERVICE: INIT  ------------------------
	// -------------------------------------------------- #include "../kr/krInit.h"

	// ************************************************************** METHODS
	static void kr_InitHandler (void);

	// ********************************************************* UNIT SERVICE
	static krInit g_Init;

	// ------------- END SERVICE: INIT --------------------
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++

	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	// ---------------------------------------------------------------  SERVICE: STATE ------------------------
	// -------------------------------------------------- #include "../sv/svState.h"
	// -------------------------------------------------- #include "../cg/cg_svState.h"

	// ************************************************************ CONSTANTS
	enum k_tt_State	{
		 k_tt_State_FIRST		= MAKE_svStateId(k_cg_svState_Group_tt_ap_svStateMachine,0)
		,k_tt_State_A			= k_tt_State_FIRST
		,k_tt_State_B
		,k_tt_State_C
		,k_tt_State_D
		,k_tt_State_E
		,k_tt_State_F
		,k_tt_State_LAST		= k_tt_State_F
	};
	enum {k_tt_State_Num = k_tt_State_LAST - k_tt_State_FIRST + 1};

	enum k_tt_StateUnitId	{
		 k_tt_StateUnitId_A	= k_tt_State_A - k_tt_State_FIRST
		,k_tt_StateUnitId_B	= k_tt_State_B - k_tt_State_FIRST
		,k_tt_StateUnitId_C	= k_tt_State_C - k_tt_State_FIRST
		,k_tt_StateUnitId_D	= k_tt_State_D - k_tt_State_FIRST
		,k_tt_StateUnitId_E	= k_tt_State_E - k_tt_State_FIRST
		,k_tt_StateUnitId_F	= k_tt_State_F - k_tt_State_FIRST
	};
	

	// ************************************************************ ATTRIBUTE
	static svState svState_SM1_UnitArray[];
	static svState svState_SM2_UnitArray[];

	// ************************************************************** METHODS
	static svState::state_t svState_SM1_Handler (krThreadId, svState::state_t);
	static svState::state_t svState_SM2_Handler (krThreadId, svState::state_t);


	// ------------- END SERVICE: STATE -------------------
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++


	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	// ---------------------------------------------------------------  SERVICE: STATE MACHINE ----------------
	// -------------------------------------------------- #include "../sv/svStateMachine.h"

	// ************************************************************** METHODS

	// ********************************************************* UNIT SERVICE
	static svStateMachine g_StMach_1;
	static svStateMachine g_StMach_2;

	// ------------- END SERVICE: STATE MACHINE -----------
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++


};

} }	// mpfw::apps

#endif /* AP_TT_SV_STATE_MACHINE_H_ */

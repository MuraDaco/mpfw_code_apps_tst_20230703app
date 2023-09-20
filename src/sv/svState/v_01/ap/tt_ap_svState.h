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
 * tt_ap_svState.h
 *
 *  Created on: Sep, 20 2022
 *      Author: Marco Dau
 */

#ifndef AP_TT_SV_STATE_H_
#define AP_TT_SV_STATE_H_

// system include
#include <array>
#include <cstdint>

// lib include 
#include <krInit.h>
#include <svState.h>

// tst include
#include <cg_krThread.h>
#include <app/cg_app_svState.h>


namespace mpfw { namespace apps {

class tt_ap_svState {
public:
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
		 k_tt_State_00		= MAKE_svStateId(k_cg_svState_Group_tt_ap_svState,7)
		,k_tt_State_01
		,k_tt_State_02
		,k_tt_State_03
		,k_tt_State_04
		,k_tt_State_05
	};
	enum { STATE_NUM   = k_tt_State_05 - k_tt_State_00 + 1};

	enum k_tt_StateUnitId	{
		 k_tt_StateUnitId_00
		,k_tt_StateUnitId_01
		,k_tt_StateUnitId_02
		,k_tt_StateUnitId_03
		,k_tt_StateUnitId_04
		,k_tt_StateUnitId_05
	};

	// ************************************************************ ATTRIBUTE
	static svState svStateUnitArray[];

	static uint32_t gTest_CounterHandler[];
	//	static char 	check_krThread_Num[];

	static bool		gTest_CheckStateFail[];
	//	static char 	check_State_Num[];

	// ************************************************************** METHODS
	static svState::state_t svState_00_Handler (krThreadId, svState::state_t);
	static svState::state_t svState_01_Handler (krThreadId, svState::state_t);
	static svState::state_t svState_02_Handler (krThreadId, svState::state_t);
	static svState::state_t svState_03_Handler (krThreadId, svState::state_t);
	static svState::state_t svState_04_Handler (krThreadId, svState::state_t);
	static svState::state_t svState_05_Handler (krThreadId, svState::state_t);


	// ------------- END SERVICE: STATE -------------------
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++

};

} }	// mpfw::apps

#endif /* AP_TT_SV_STATE_H_ */

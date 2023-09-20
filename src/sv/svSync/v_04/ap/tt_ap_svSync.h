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
 * tt_ap_svSync.h
 *
 *  Created on: Sep, 27 2022
 *      Author: Marco Dau
 */

#ifndef AP_TT_SV_STATE_H_
#define AP_TT_SV_STATE_H_

#include <array>
#include <cstdint>

// lib include 
#include <svState.h>
#include <svSync.h>
using namespace fw2::core::core;

// tst include
#include <cg_krThread.h>
#include <app/cg_app_svState.h>
#include <app/cg_app_svSync.h>

namespace mpfw { namespace apps {

class tt_ap_svSync {
public:

	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	// ---------------------------------------------------------------  SERVICE: STATE ------------------------
	// -------------------------------------------------- #include "../sv/svState.h"
	// -------------------------------------------------- #include "../cg/cg_svState.h"

	// ************************************************************ CONSTANTS
	enum k_tt_State	{
		 k_tt_State_SEND1		= MAKE_svStateId(k_cg_svState_Group_tt_ap_svSync,0)
		,k_tt_State_SEND2
		,k_tt_State_CHECK
	};

	enum k_tt_StateUnitId	{
		 k_tt_StateUnitId_SEND1
		,k_tt_StateUnitId_SEND2
		,k_tt_StateUnitId_CHECK
	};
	
	// ************************************************************ ATTRIBUTE
	static svState svStateUnitArray[];

	static volatile uint32_t gTest_Resource1;
	static volatile uint32_t gTest_Resource2;
	static volatile uint32_t gTest_Resource1_Sync;
	static volatile uint32_t gTest_Resource2_Sync;
	static 			uint32_t gTest_Resource_Sync;
	static volatile uint32_t gTest_CntrCheck1;
	static volatile uint32_t gTest_CntrCheck2;
	static volatile uint32_t gTest_CntrCheck1_Sync;
	static volatile uint32_t gTest_CntrCheck2_Sync;

	// ************************************************************** METHODS
	static svState::state_t svState_Send1_Handler	(krThreadId, svState::state_t);
	static svState::state_t svState_Send2_Handler	(krThreadId, svState::state_t);
	static svState::state_t svState_Check_Handler	(krThreadId, svState::state_t);


	// ------------- END SERVICE: STATE -------------------
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++


	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	// ---------------------------------------------------------------  SERVICE: SYNCHRONIZATION --------------
	// -------------------------------------------------- #include "../sv/svSync.h"

	// ************************************************************ CONSTANTS

	enum k_svSync_CMD {
		 k_svSync_CMD_INC_RESOURCES_1       = MAKE_svSyncSgn(k_cg_app_svSyncSgn_Group_tt_ap_svSync, 0)
		,k_svSync_CMD_INC_RESOURCES_2
	};
	


	// ************************************************************ ATTRIBUTE
    static svSync  g_SyncCmd;

	// ************************************************************** METHODS
	static void svSync_UpdateResource_Handler	(krThreadId, svSync::sync_sgn_t, svSync::sync_val_t);

	// ------------- END SERVICE: SYNCHRONIZATION ---------
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++


};


} }	// mpfw::apps

#endif /* AP_TT_SV_STATE_H_ */

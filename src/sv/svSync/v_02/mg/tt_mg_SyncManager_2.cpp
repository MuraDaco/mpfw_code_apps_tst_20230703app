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
 * tt_mg_SyncManager_2.cpp
 *
 *  Created on: Sep, 30 2022
 *      Author: Marco Dau
 */

// module include
#include "tt_mg_SyncTbl_2.h"
#include "tt_mg_SyncManager_2.h"
#include "../ap/tt_ap_svSync_2.h"

namespace mpfw { namespace apps {

uint16_t tt_mg_SyncManager_2::g_cnt				[krThread_Num];
uint16_t tt_mg_SyncManager_2::g_cnt_no_match	[krThread_Num];
uint16_t tt_mg_SyncManager_2::g_SyncCnt			[krThread_Num];


void tt_mg_SyncManager_2::ThreadUnitLoop (krThreadId p_thread) {
	// init static arrays
	static bool l_init = false;
	if(!l_init) {
		l_init = true;
		for (auto i=0; i<krThread_Num; i++)	{
			g_cnt			[i] = 0;
			g_cnt_no_match	[i] = 0;
			g_SyncCnt		[i] = 0;			
		}
	}

	// SECTION - svState
	for (auto i=0; i<200; i++)
	{
		svState::state_t result;
		if (nullptr == tt_mg_SyncTbl_2::svStatePtrUnitArray[i]) break;

		if(tt_ap_svSync_2::g_ActiveState == tt_mg_SyncTbl_2::svStatePtrUnitArray[i]->g_State) {
			result = tt_mg_SyncTbl_2::svStatePtrUnitArray[i]->StateRun(p_thread);
			if (svState::k_SvState_THREAD_NOT_MATCH == result)	{
				g_cnt_no_match[p_thread]++;
			} else {
				g_SyncCnt[p_thread]++;
				tt_ap_svSync_2::g_SyncUpdateState.UpdateSyncResorces	(p_thread	,result	);
			}
		}
	}
	g_cnt[p_thread]++;

	// SECTION - svSync
	tt_ap_svSync_2::g_SyncUpdateState.ResetSyncSignals	(p_thread	);

}


} }	// mpfw::apps

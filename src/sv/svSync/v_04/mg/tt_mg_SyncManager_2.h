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
 * tt_mg_SyncManager_2.h
 *
 *  Created on: Sep, 30 2022
 *      Author: Marco Dau
 */

#ifndef TT_MG_SYNC_MANAGER_2_H_
#define TT_MG_SYNC_MANAGER_2_H_

#include <cstdint>

// tst include
#include <cg_krThread.h>

namespace mpfw { namespace apps {

class tt_mg_SyncManager_2 {
public:

	static tt_mg_SyncManager_2& getInstance()
	{
		static tt_mg_SyncManager_2 instance;

		return instance;
	}

	static void ThreadUnitLoop 			(krThreadId	p_u32Thread	);
	static uint16_t g_cnt			[];
	static uint16_t g_cnt_no_match	[];
	static uint16_t g_SyncCnt		[];

private:
	tt_mg_SyncManager_2() {}

};


} }	// mpfw::apps

#endif /* TT_MG_SYNC_MANAGER_2_H_ */

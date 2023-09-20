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
 * tt_mn_svSyncMain_3.h
 *
 *  Created on: Oct,  4 2022
 *      Author: Marco Dau
 */

#ifndef TT_MN_SV_SYNC_MAIN_3_H_
#define TT_MN_SV_SYNC_MAIN_3_H_


#include <cstdint>

#include <cg_krThread.h>

namespace mpfw { namespace apps {

class tt_mn_svSyncMain_3 {
public:


	static tt_mn_svSyncMain_3& getInstance()
	{
		static tt_mn_svSyncMain_3 instance;

		return instance;
	}

	static uint32_t Get_Test_CntrCheck			(uint8_t);
	static bool 	CheckRaceConditionCounter	(uint8_t);
	static void 	ShowTestResult				(void);

private:
	tt_mn_svSyncMain_3() {}

};


} }	// mpfw::apps

#endif /* TT_AP_SV_SYNC_MAIN_3_H_ */

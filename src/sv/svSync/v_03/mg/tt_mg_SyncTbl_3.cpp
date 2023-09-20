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
 * tt_mg_SyncTbl_3.cpp
 *
 *  Created on: Oct,  4 2022
 *      Author: Marco Dau
 */

// module
#include "tt_mg_SyncTbl_3.h"
#include "../ap/tt_ap_svSync_3.h"

namespace mpfw { namespace apps {

// ************************************************************************************************
// ************************************************************************************************
svState*	tt_mg_SyncTbl_3::svStatePtrUnitArray[] = {
	&tt_ap_svSync_3	::svStateUnitArray		[tt_ap_svSync_3	::k_tt_StateUnitId_SEND1	]	,
	&tt_ap_svSync_3	::svStateUnitArray		[tt_ap_svSync_3	::k_tt_StateUnitId_SEND2	]	,
	&tt_ap_svSync_3	::svStateUnitArray		[tt_ap_svSync_3	::k_tt_StateUnitId_CHECK	]	,
	&tt_ap_svSync_3	::svStateUnitArray_2	[tt_ap_svSync_3	::k_tt_StateUnitId_2_A		]	,
	&tt_ap_svSync_3	::svStateUnitArray_2	[tt_ap_svSync_3	::k_tt_StateUnitId_2_B		]	,
	&tt_ap_svSync_3	::svStateUnitArray_2	[tt_ap_svSync_3	::k_tt_StateUnitId_2_C		]	,
	nullptr
};

} }	// mpfw::apps

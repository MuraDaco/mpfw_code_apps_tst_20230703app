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
 * tt_mg_StateTbl.cpp
 *
 *  Created on: Sep, 25 2022
 *      Author: Marco Dau
 */

// module include
#include "tt_mg_StateTbl.h"
#include "../ap/tt_ap_svState.h"

namespace mpfw { namespace apps {

// ************************************************************************************************
// ************************************************************************************************
svState*  tt_mg_StateTbl::svStatePtrUnitArray[] = {
	&tt_ap_svState	::svStateUnitArray	[tt_ap_svState	::k_tt_StateUnitId_00	]	,
	&tt_ap_svState	::svStateUnitArray	[tt_ap_svState	::k_tt_StateUnitId_01	]	,
	&tt_ap_svState	::svStateUnitArray	[tt_ap_svState	::k_tt_StateUnitId_02	]	,
	&tt_ap_svState	::svStateUnitArray	[tt_ap_svState	::k_tt_StateUnitId_03	]	,
	&tt_ap_svState	::svStateUnitArray	[tt_ap_svState	::k_tt_StateUnitId_04	]	,
	&tt_ap_svState	::svStateUnitArray	[tt_ap_svState	::k_tt_StateUnitId_05	]	,
	nullptr
};

} }	// mpfw::apps


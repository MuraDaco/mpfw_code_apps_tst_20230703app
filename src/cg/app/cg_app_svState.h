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
 * cg_app_svState.h
 *
 *  Created on: Sep 20, 2022
 *      Author: Marco Dau
 */

#ifndef CG_APP_SV_STATE_H_
#define CG_APP_SV_STATE_H_

#include <cg_lib_svState.h>

using namespace fw2::core::core;

namespace mpfw { namespace apps {

enum k_cg_svState_Group {
	 k_cg_svState_Group_apTestStateMachine01_Funct1		=	MAKE_svState_Group(0)
	,k_cg_svState_Group_apTestStateMachine01_Funct2
	,k_cg_svState_Group_tt_ap_svState
	,k_cg_svState_Group_tt_ap_svSync
	,k_cg_svState_Group_tt_ap_svSync_2
	,k_cg_svState_Group_tt_ap_svStateMachine
};



} }	// mpfw::apps

#endif /* CG_APP_SV_STATE_H_ */

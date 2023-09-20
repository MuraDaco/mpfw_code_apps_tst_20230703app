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
 * tt_mg_SyncTbl_2.h
 *
 *  Created on: Sep, 30 2022
 *      Author: Marco Dau
 */

#ifndef TT_MG_SYNC_TBL_2_H_
#define TT_MG_SYNC_TBL_2_H_

// lib include 
#include <svState.h>
#include <svSync.h>
using namespace fw2::core::core;

namespace mpfw { namespace apps {

class tt_mg_SyncTbl_2 {
public:

	static svState*	svStatePtrUnitArray	[];
	static svSync*	svSyncPtrUnitArray	[];

};

} }	// mpfw::apps

#endif /* TT_MG_SYNC_TBL_2_H_ */

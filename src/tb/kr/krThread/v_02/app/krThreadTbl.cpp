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
 * ap_krThreadTbl.cpp
 *
 *  Created on: Nov, 24 2022
 *      Author: Marco Dau
 */

// class include
#include "krThreadTbl.h"

// tst includes
#include "kr/krThread/v_02/ap/ap_krThread02.h"
// #include <sv/svSync/v_01/mg/tt_mg_SyncManager.h>
// #include <sv/svSync/v_02/mg/tt_mg_SyncManager_2.h>
// #include <sv/svSync/v_03/mg/tt_mg_SyncManager_3.h>
// #include <sv/svState/v_01/mg/tt_mg_StateManager.h>

namespace mpfw { namespace apps {

fw2::wrapper::core::krThreadTbl::ThreadLoopFunction_t krThreadTbl::LoopFunctionArray[] = {
&ap_krThread02                ::TaskTest0 ,
&ap_krThread02                ::TaskTest1 ,
//    &tt_mg_SyncManager                 ::ThreadUnitLoop ,
//    &tt_mg_SyncManager_2               ::ThreadUnitLoop ,
//    &tt_mg_SyncManager_3               ::ThreadUnitLoop ,
//    &tt_mg_StateManager                ::ThreadUnitLoop ,
    nullptr
};

} }	// mpfw::apps

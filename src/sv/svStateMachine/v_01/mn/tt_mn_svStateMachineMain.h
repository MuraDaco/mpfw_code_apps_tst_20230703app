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
 * tt_mn_svStateMachineMain.h
 *
 *  Created on: Oct,  5 2022
 *      Author: Marco Dau
 */


#ifndef TT_MN_SV_STATE_MACHINE_MAIN_H_
#define TT_MN_SV_STATE_MACHINE_MAIN_H_

// tst include
#include <cg_krThread.h>

namespace mpfw { namespace apps {


class tt_mn_svStateMachineMain {
public:


	static tt_mn_svStateMachineMain& getInstance()
	{
		static tt_mn_svStateMachineMain instance;

		return instance;
	}

	static void ShowTestResult	(void);

private:
	tt_mn_svStateMachineMain() {}

};


} }	// mpfw::apps

#endif /* TT_MN_SV_STATE_MACHINE_MAIN_H_ */

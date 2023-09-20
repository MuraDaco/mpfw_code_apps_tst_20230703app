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
 * apTestTimer01.h
 *
 *  Created on: Sep, 16 2022
 *      Author: Marco Dau
 */

#ifndef APTESTTIMER01_H_
#define APTESTTIMER01_H_

#include <array>
#include <cstdint>

// lib include
#include <krTimer.h>
using namespace fw2::core::core;

#include <cg_krThread.h>

namespace mpfw { namespace apps {

class apTestTimer01 {
public:
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
	// ---------------------------------------------------------------  SERVICE: TIMER ------------------------
	// -------------------------------------------------- #include <../kr/krTimer.h>

	// ************************************************************ CONSTANTS
		enum kTimerDefaultTimeout {
			kTimerDefaultTimeout_empty 	= 3000,
		};

		enum kTimer {
			kTimer_empty1,
			kTimer_empty2,
			kTimerNum
		};


	// ************************************************************ ATTRIBUTE
		static std::array<krTimer,kTimerNum> TmrArray;

	// ************************************************************** METHODS
		static void krTmrHndl_empty1 (void);
		static void krTmrHndl_empty2 (void);

	// ------------- END SERVICE: TIMER -------------------
};

} }	// mpfw::apps

#endif /* APTESTTIMER01_H_ */

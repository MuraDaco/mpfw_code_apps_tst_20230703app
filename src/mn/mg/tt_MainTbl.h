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
 * tt_MainTbl.h
 *
 *  Created on: Sep, 29 2022
 *      Author: Marco Dau
 */

#ifndef TT_MAIN_TBL_H_
#define TT_MAIN_TBL_H_

namespace mpfw { namespace apps {

class tt_MainTbl {
public:

	typedef void (*TestUnitShow_t)(void);

	static TestUnitShow_t tt_MainArray[];

};

} }	// mpfw::apps

#endif /* TT_MAIN_TBL_H_ */

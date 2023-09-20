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
 * ap_krThread02.h
 *
 *  Created on: Jan,  5 2023
 *      Author: Marco Dau
 */

#ifndef AP_KR_THREAD_02_H_
#define AP_KR_THREAD_02_H_

#include <array>
#include <cstdint>

// lib include
#include <cg_krThread.h>

namespace mpfw { namespace apps {


class ap_krThread02 {

public:
	static void TaskTest0	(krThreadId p_ThreadId);
	static void TaskTest1	(krThreadId p_ThreadId);

	static          char    recv_buffer[4];
	static volatile uint8_t g_status;

};

} }	// mpfw::apps

#endif /* AP_KR_THREAD_02_H_ */

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
 * ap_krThread02.cpp
 *
 *  Created on: Jan,  5 2023
 *      Author: Marco Dau
 */

#include "ap_krThread02.h"

// system
#include <cstring>

#include <krThread.h>
using namespace fw2::wrapper::core;
#include <rsSerial.h>
using namespace fw2::wrapper::resources;


namespace mpfw { namespace apps {

/*******************************************************************************
 * Definitions
 ******************************************************************************/

#define THREAD_1_ID  0
#define THREAD_2_ID  1

volatile uint8_t ap_krThread02::thread_sync = THREAD_1_ID;
uint8_t ap_krThread02::rx_buffer[100];

void ap_krThread02::TaskTest0	(krThreadId p_ThreadId) {
    if(krThread_Zero == p_ThreadId) {
    	// lock rsSerial resources
    	while(THREAD_1_ID != thread_sync){wp_sleep_for(100);}
    	rsSerial::Tx("Start thread 01 ..."); rsSerial::Tx(rsSerial::endl);
    	// release rsSerial resources
    	thread_sync = THREAD_2_ID;

    	bool g_ask_for_an_input = true;

    	for (;;) {
    		wp_sleep_for(100);

    		// lock rsSerial resources
    		if(THREAD_1_ID == thread_sync) {

    			if(g_ask_for_an_input)	{
    				g_ask_for_an_input = false;
    				rsSerial::Tx("Press some keys five times ..."); rsSerial::Tx(rsSerial::endl);
    			}

    			if(rsSerial::RxCheck())	{
    				g_ask_for_an_input = true;
    				rsSerial::Tx("Thread 1 - The following characters have been received:"); rsSerial::Tx(rsSerial::endl);
    				rsSerial::Tx("01uxQuesta è un altra provax"); rsSerial::Tx(rsSerial::endl);
    				rsSerial::Tx(rx_buffer, sizeof(rx_buffer), 5); rsSerial::Tx(rsSerial::endl);
    				// release rsSerial resources
    				thread_sync = THREAD_2_ID;
    			} else rsSerial::RxStart(rx_buffer, sizeof(rx_buffer), 5);
    		}

    		if(rsSerial::CheckService()) {
    			break;
    		}
    	}


        // for( ;; )
        // {
        //     // Task code goes here.
        // }
    }
}

void ap_krThread02::TaskTest1	(krThreadId p_ThreadId) {
    if(krThread_One == p_ThreadId) {
    	// lock rsSerial resources
    	while(THREAD_2_ID != thread_sync){wp_sleep_for(100);}
    	rsSerial::Tx("Start thread 02 ..."); rsSerial::Tx(rsSerial::endl);
    	// release rsSerial resources
    	thread_sync = THREAD_1_ID;

    	bool g_ask_for_an_input = true;

    	for (;;) {
    		wp_sleep_for(100);

    		// lock rsSerial resources
    		if(THREAD_2_ID == thread_sync) {
    			if(g_ask_for_an_input)	{
    				g_ask_for_an_input = false;
    				//           01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
    				//           0    -    1    -    2    -    3    -    4    -    5    -    6    -    7    -    8    -    9    -    0
    				rsSerial::Tx("th2-Input the sequence \"01<xxx>\" or \"01u<terminating character>\" then the body of packet..."); rsSerial::Tx(rsSerial::endl);
    			}

    			if(rsSerial::RxCheck())	{
    				g_ask_for_an_input = true;
    				//           01234567890123456789012345678901234567890123456789012345678901234567890
    				//           0    -    1    -    2    -    3    -    4    -    5    -    6    -    7
    				rsSerial::Tx("Thread 2 - The following characters have been received:"); rsSerial::Tx(rsSerial::endl);
    				rsSerial::Tx("01041Questa_e_un altra prova.nVediamo se funziona!n----....."); rsSerial::Tx(rsSerial::endl);
    				rsSerial::Tx(rx_buffer); rsSerial::Tx(rsSerial::endl);
    
    				// release rsSerial resources
    				thread_sync = THREAD_1_ID;
    			} else rsSerial::RxStart((char *) rx_buffer, sizeof(rx_buffer));
    		}

    		if(rsSerial::CheckService()) {
    			break;
    		}
    	}


        // for( ;; )
        // {
        //     // Task code goes here.
        // }

    }
}

} }	// mpfw::apps

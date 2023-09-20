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

#include <rsSerial.h>
using namespace fw2::wrapper::resources;


namespace mpfw { namespace apps {

/*******************************************************************************
 * Definitions
 ******************************************************************************/
char ap_krThread02::recv_buffer[4];

volatile uint8_t ap_krThread02::g_status = 0;
void ap_krThread02::TaskTest0	(krThreadId p_ThreadId) {
    // .............0.........1.........2.........3.........4.........5.........6
    // ..............123456789012345678901234567890123456789012345678901234567890
    char txbuff[] = "------ -> the received character on Thread 0 ...\r\nOOO";
    char array_ch[5];
    if(krThread_Zero == p_ThreadId) {

        while(0 != g_status) {}
        rsSerial::Tx("Thread 0 started!\r\n");
        g_status = 1;

        /* Receive user input and send it back to terminal. */
        while(1)
        {

            if(g_status == 0)    {
                rsSerial::Tx("Thread 0 - Press four times any key\r\n");
                rsSerial::Rx(array_ch, sizeof(array_ch) - 1);

                txbuff[0] = array_ch[0];
                txbuff[1] = array_ch[1];
                txbuff[2] = array_ch[2];
                txbuff[3] = '.';

                txbuff[4] = ' ';
                txbuff[5] = '-';
                txbuff[6] = ' ';

                rsSerial::Tx(txbuff);
                rsSerial::Tx("\r\n");
                rsSerial::Rx();

                g_status = 1;
            }
        }

        for( ;; )
        {
            // Task code goes here.
        }
    }
}

void ap_krThread02::TaskTest1	(krThreadId p_ThreadId) {
    // .............0.........1.........2.........3.........4.........5.........6
    // ..............123456789012345678901234567890123456789012345678901234567890
    char txbuff[] = "------ -> the received character on Thread 1 ...\r\nOOO";
    char array_ch[5];
    if(krThread_One == p_ThreadId) {

        while(1 != g_status) {}
        rsSerial::Tx("Thread 1 started!\r\n");
        g_status = 0;


        while (1)
        {

            // ******************************************************************************************
            // from serial/rs485 MARCO_TEST
            // N.B.:
            //       - marrone sul led2 (port3 - pin3) accoppiato a sw2 -> DE
            //       - bianco  sul led3 (port2 - pin2) accoppiato a sw3 -> RE
            // ******************************************************************************************

            if(g_status == 1)    {
                rsSerial::Tx("Thread 1 - Press four times any key\r\n");
                rsSerial::Rx(array_ch, sizeof(array_ch) - 1);

                txbuff[0] = array_ch[0];
                txbuff[1] = array_ch[1];
                txbuff[2] = array_ch[2];
                txbuff[3] = '.';

                txbuff[4] = ' ';
                txbuff[5] = '-';
                txbuff[6] = ' ';

                rsSerial::Tx(txbuff);
                rsSerial::Tx("\r\n");
                rsSerial::Rx();

                g_status = 0;
            }

        }


        for( ;; )
        {
            // Task code goes here.
        }

    }
}

} }	// mpfw::apps

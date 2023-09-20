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

    //BOARD_InitDebugConsole();
    //rsSerial::Init2();

    if(krThread_Zero == p_ThreadId) {
        // .......................0.........1.........2.........3.........4.........5.........6.........7.........8.........9.........0.........1
        // .......................12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
        const char *to_send    = "\r\nIf this AGEmess will be show then TaskTest0 is started! \r\n";
        int  l_status;
        uint8_t n = 0;

        rsSerial::InitFreeRTOS();

        /* send back the received data */
        l_status = rsSerial::TxFreeRTOS(to_send, strlen(to_send));

        /* Receive user input and send it back to terminal. */
        do
        {
            if(g_status == 0)    {
                l_status = rsSerial::RxFreeRTOS(recv_buffer, sizeof(recv_buffer), &n);
                if (n > 0)
                {
                    /* send back the received data */
                    rsSerial::TxFreeRTOS(recv_buffer, n);
                    g_status = 1;
                }
            }
        } while (rsSerial::CheckStatus(l_status));

        rsSerial::DeinitFreeRTOS();
    }
}

void ap_krThread02::TaskTest1	(krThreadId p_ThreadId) {
    if(krThread_One == p_ThreadId) {
        // ....................0.........1.........2.........3.........4.........5.........6.........7.........8.........9.........0.........1
        // ....................12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
        char txbuff_marco[] = "(120702) - TaskTest1 is started! \r\nNow, press any key to test rs485 Rx ...\r\nOOO";

        char array_ch[5];

        while (1)
        {

            // ******************************************************************************************
            // from serial/rs485 MARCO_TEST
            // N.B.:
            //       - marrone sul led2 (port3 - pin3) accoppiato a sw2 -> DE
            //       - bianco  sul led3 (port2 - pin2) accoppiato a sw3 -> RE
            // ******************************************************************************************

            if(g_status == 1)    {
                // first message
                //USART_WriteBlocking(DEMO_USART_MARCO_TEST, txbuff_marco, sizeof(txbuff_marco) - 1);
                rsSerial::Tx(txbuff_marco);
                // vTaskDelay(100);
                // rsSerial::Tx(txbuff_marco);
                // vTaskDelay(100);

                // waiting start RS485 RX test: press any key on minicom (by minicom.rs485_dsdtech) terminal
                // USART_ReadBlocking(DEMO_USART_MARCO_TEST, array_ch, size_of(array_ch));
                rsSerial::Rx(array_ch, sizeof(array_ch) - 1);

                txbuff_marco[0] = array_ch[0];
                txbuff_marco[1] = array_ch[1];
                txbuff_marco[2] = array_ch[2];
                txbuff_marco[3] = array_ch[3];

                txbuff_marco[4] = ' ';
                txbuff_marco[5] = '-';
                txbuff_marco[6] = ' ';

                g_status = 0;
            }

            //PRINTF("Rx data from rs485 : %02d - %02d - %02d - %02d\r\n",	array_ch[0],
            //		array_ch[1],
    		//		array_ch[2],
    		//		array_ch[3]
        	//		);

        }


        for( ;; )
        {
            // Task code goes here.
        }

    }
}

} }	// mpfw::apps

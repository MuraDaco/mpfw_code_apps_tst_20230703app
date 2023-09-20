#   *******************************************************************************
#   
#   mpfw / fw2 - Multi Platform FirmWare FrameWork 
#       library that contains the application code
#   Copyright (C) (2023) Marco Dau
#   
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU Affero General Public License as published
#   by the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#   
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU Affero General Public License for more details.
#   
#   You should have received a copy of the GNU Affero General Public License
#   along with this program.  If not, see <https://www.gnu.org/licenses/>.
#   
#   You can contact me by the following email address
#   marco <d o t> ing <d o t> dau <a t> gmail <d o t> com
#   
#   *******************************************************************************
## ******************************************************************
## __________________________________________________________________
## TST/APP CPP FILES Definitions


set(CODE_FILES_TST_KR_THREAD_AP
    ${AP_KR_THREAD_CPP_DIR}/ap/ap_krThread02.cpp
)

set(CODE_FILES_TST_KR_TIMER_AP
    ${AP_KR_TIMER_CPP_DIR}/ap/apTestTimer01.cpp
)

set(CODE_FILES_TST_SV_SYNC
    ${AP_SV_SYNC_CPP_DIR}/ap/tt_ap_svSync.cpp
    ${AP_SV_SYNC_CPP_DIR}/mn/tt_mn_svSyncMain.cpp
    ${AP_SV_SYNC_CPP_DIR}/mg/tt_mg_SyncManager.cpp
    ${AP_SV_SYNC_CPP_DIR}/mg/tt_mg_SyncTbl.cpp

    ${AP_SV_SYNC_CPP_DIR}/ap/tt_ap_svSync_2.cpp
    ${AP_SV_SYNC_CPP_DIR}/mn/tt_mn_svSyncMain_2.cpp
    ${AP_SV_SYNC_CPP_DIR}/mg/tt_mg_SyncManager_2.cpp
    ${AP_SV_SYNC_CPP_DIR}/mg/tt_mg_SyncTbl_2.cpp

    ${AP_SV_SYNC_CPP_DIR}/ap/tt_ap_svSync_3.cpp
    ${AP_SV_SYNC_CPP_DIR}/mn/tt_mn_svSyncMain_3.cpp
    ${AP_SV_SYNC_CPP_DIR}/mg/tt_mg_SyncManager_3.cpp
    ${AP_SV_SYNC_CPP_DIR}/mg/tt_mg_SyncTbl_3.cpp
)

set(CODE_FILES_TST_SV_STATE
    ${AP_SV_STATE_CPP_DIR}/ap/tt_ap_svState.cpp
    ${AP_SV_STATE_CPP_DIR}/mn/tt_mn_svStateMain.cpp
    ${AP_SV_STATE_CPP_DIR}/mg/tt_mg_StateManager.cpp
    ${AP_SV_STATE_CPP_DIR}/mg/tt_mg_StateTbl.cpp
)

set(CODE_FILES_TST_SV_STATE_MACHINE
    ${AP_SV_STATE_MACHINE_CPP_DIR}/ap/tt_ap_svStateMachine.cpp
    ${AP_SV_STATE_MACHINE_CPP_DIR}/mn/tt_mn_svStateMachineMain.cpp
)

set(CODE_FILES_TST_TB
    ${TB_KR_THREAD_CPP_DIR}/app/krThreadTbl.cpp
    ${TB_KR_INIT_CPP_DIR}/app/krInitStaticTbl.cpp
    ${TB_KR_TIMER_CPP_DIR}/app/krTimerTbl.cpp
    ${TB_SV_STATE_MACHINE_CPP_DIR}/app/svStateMachineTbl.cpp
    ${TB_MN_MAIN_CPP_DIR}/tt_MainTbl.cpp
)

set(CODE_FILES_TST_MN
    ${MN_MG_MAIN_MANAGER_CPP_DIR}/tt_MainManager.cpp
)



set(CODE_CPP_FILES_TST_LIB

    ${CODE_FILES_TST_KR_THREAD_AP}

    ${CODE_FILES_TST_KR_TIMER_AP}

    ${CODE_FILES_TST_SV_SYNC}
    ${CODE_FILES_TST_SV_STATE}
    ${CODE_FILES_TST_SV_STATE_MACHINE}

    ${CODE_FILES_TST_TB}

    ${CODE_FILES_TST_MN}
)




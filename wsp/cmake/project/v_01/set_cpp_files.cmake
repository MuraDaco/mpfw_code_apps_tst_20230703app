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


set(APPS_XXX_SRC_DIR_KR     ${APPS_XXX_SRC_DIR}/kr          )
set(APPS_XXX_SRC_DIR_SV     ${APPS_XXX_SRC_DIR}/sv          )
set(APPS_XXX_SRC_DIR_DG     ${APPS_XXX_SRC_DIR}/dg          )
set(APPS_XXX_SRC_DIR_RS     ${APPS_XXX_SRC_DIR}/rs          )
set(APPS_XXX_SRC_DIR_MN     ${APPS_XXX_SRC_DIR}/mn          )
set(APPS_XXX_SRC_DIR_TB     ${APPS_XXX_SRC_DIR}/tb          )
set(APPS_XXX_SRC_DIR_WP     ${APPS_XXX_SRC_DIR}/wp          )


set(CODE_FILES_TST_KR_THREAD_AP
    ${APPS_XXX_SRC_DIR_KR}/krThread/v_02/ap/ap_krThread02.cpp
)

set(CODE_FILES_TST_KR_TIMER_AP
    ${APPS_XXX_SRC_DIR_KR}/krTimer/v_01/ap/apTestTimer01.cpp
)

set(CODE_FILES_TST_SV_SYNC_V_01
    ${APPS_XXX_SRC_DIR_SV}/svSync/v_01/ap/tt_ap_svSync.cpp
    ${APPS_XXX_SRC_DIR_SV}/svSync/v_01/mn/tt_mn_svSyncMain.cpp
    ${APPS_XXX_SRC_DIR_SV}/svSync/v_01/mg/tt_mg_SyncManager.cpp
    ${APPS_XXX_SRC_DIR_SV}/svSync/v_01/mg/tt_mg_SyncTbl.cpp
)

set(CODE_FILES_TST_SV_SYNC_V_02
    ${APPS_XXX_SRC_DIR_SV}/svSync/v_02/ap/tt_ap_svSync_2.cpp
    ${APPS_XXX_SRC_DIR_SV}/svSync/v_02/mn/tt_mn_svSyncMain_2.cpp
    ${APPS_XXX_SRC_DIR_SV}/svSync/v_02/mg/tt_mg_SyncManager_2.cpp
    ${APPS_XXX_SRC_DIR_SV}/svSync/v_02/mg/tt_mg_SyncTbl_2.cpp
)

set(CODE_FILES_TST_SV_SYNC_V_03
    ${APPS_XXX_SRC_DIR_SV}/svSync/v_03/ap/tt_ap_svSync_3.cpp
    ${APPS_XXX_SRC_DIR_SV}/svSync/v_03/mn/tt_mn_svSyncMain_3.cpp
    ${APPS_XXX_SRC_DIR_SV}/svSync/v_03/mg/tt_mg_SyncManager_3.cpp
    ${APPS_XXX_SRC_DIR_SV}/svSync/v_03/mg/tt_mg_SyncTbl_3.cpp
)

set(CODE_FILES_TST_SV_STATE_V_01
    ${APPS_XXX_SRC_DIR_SV}/svState/v_01/ap/tt_ap_svState.cpp
    ${APPS_XXX_SRC_DIR_SV}/svState/v_01/mn/tt_mn_svStateMain.cpp
    ${APPS_XXX_SRC_DIR_SV}/svState/v_01/mg/tt_mg_StateManager.cpp
    ${APPS_XXX_SRC_DIR_SV}/svState/v_01/mg/tt_mg_StateTbl.cpp
)

set(CODE_FILES_TST_SV_STATE_MACHINE_V_01
    ${APPS_XXX_SRC_DIR_SV}/svStateMachine/v_01/ap/tt_ap_svStateMachine.cpp
    ${APPS_XXX_SRC_DIR_SV}/svStateMachine/v_01/mn/tt_mn_svStateMachineMain.cpp
)

set(CODE_FILES_TST_TB
    ${APPS_XXX_SRC_DIR_TB}/kr/krThread/v_${TB_KR_THREAD_VER}/krThreadTbl.cpp
    ${APPS_XXX_SRC_DIR_TB}/kr/krInit/v_${TB_KR_INIT_VER}/krInitStaticTbl.cpp
    ${APPS_XXX_SRC_DIR_TB}/kr/krTimer/v_${TB_KR_TIMER_VER}/krTimerTbl.cpp
    ${APPS_XXX_SRC_DIR_TB}/sv/svStateMachine/v_${TB_SV_STATE_MACHINE_VER}/svStateMachineTbl.cpp
    ${APPS_XXX_SRC_DIR_TB}/mn/tt_MainTbl.cpp
)

set(CODE_FILES_TST_MN
    ${APPS_XXX_SRC_DIR_MN}/mg/tt_MainManager.cpp
)



set(CODE_CPP_FILES_TST_LIB

    ${CODE_FILES_TST_KR_THREAD_AP}

    ${CODE_FILES_TST_KR_TIMER_AP}

    ${CODE_FILES_TST_SV_SYNC_V_01}
    ${CODE_FILES_TST_SV_SYNC_V_02}
    ${CODE_FILES_TST_SV_SYNC_V_03}
    ${CODE_FILES_TST_SV_STATE_V_01}
    ${CODE_FILES_TST_SV_STATE_MACHINE_V_01}

    ${CODE_FILES_TST_TB}

    ${CODE_FILES_TST_MN}
)




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
include(${CODE_MAIN_CMAKE_APPS_VER_DEF_DIR}/set_class_src_ver.cmake)

set(APPS_XXX_SRC_DIR         ${APPS_XXX_DIR}/src      )

set(CG_DIR                          ${APPS_XXX_SRC_DIR}/cg                                              )

# MODULE DIRECTORY Definitions
set(AP_KR_THREAD_CPP_DIR                ${APPS_XXX_SRC_DIR}/kr/krThread/v_${AP_KR_THREAD02_VER}                 )
set(AP_KR_TIMER_CPP_DIR                 ${APPS_XXX_SRC_DIR}/kr/krTimer/v_${AP_KR_TIMER01_VER}                   )
set(MN_MG_MAIN_MANAGER_CPP_DIR          ${APPS_XXX_SRC_DIR}/mn/mg                                               )
set(AP_SV_STATE_CPP_DIR                 ${APPS_XXX_SRC_DIR}/sv/svState/v_${AP_SV_STATE_VER}                     )
set(AP_SV_STATE_MACHINE_CPP_DIR         ${APPS_XXX_SRC_DIR}/sv/svStateMachine/v_${AP_SV_STATE_MACHINE_VER}      )
set(AP_SV_SYNC_CPP_DIR                  ${APPS_XXX_SRC_DIR}/sv/svSync/v_${AP_SV_SYNC_VER}                       )


# TABLE MODULE DIRECTORY Definitions
set(TB_KR_THREAD_CPP_DIR                ${APPS_XXX_SRC_DIR}/tb/kr/krThread/v_${TB_KR_THREAD_VER}                )
set(TB_KR_INIT_CPP_DIR                  ${APPS_XXX_SRC_DIR}/tb/kr/krInit/v_${TB_KR_INIT_VER}                    )
set(TB_KR_TIMER_CPP_DIR                 ${APPS_XXX_SRC_DIR}/tb/kr/krTimer/v_${TB_KR_TIMER_VER}                  )
set(TB_SV_STATE_MACHINE_CPP_DIR         ${APPS_XXX_SRC_DIR}/tb/sv/svStateMachine/v_${TB_SV_STATE_MACHINE_VER}   )
set(TB_MN_MAIN_CPP_DIR                  ${APPS_XXX_SRC_DIR}/tb/mn                                               )


set(CODE_DIR_LIB_APP_INCLUDE

    ${CG_DIR}
    
    ${AP_KR_THREAD_CPP_DIR}       
    ${AP_KR_TIMER_CPP_DIR}        
    ${MN_MG_MAIN_MANAGER_CPP_DIR} 
    ${AP_SV_STATE_CPP_DIR}        
    ${AP_SV_STATE_MACHINE_CPP_DIR}
    ${AP_SV_SYNC_CPP_DIR}        

    ${TB_KR_THREAD_CPP_DIR}  
    ${TB_KR_INIT_CPP_DIR}    
    ${TB_KR_TIMER_CPP_DIR}        
    ${TB_SV_STATE_MACHINE_CPP_DIR}
    ${TB_MN_MAIN_CPP_DIR}
    
)

cmake_minimum_required(VERSION 3.8)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

project(dungeonrush)

set(VITA_APP_NAME "DungeonRush")
set(VITA_TITLEID  "DUNGEON00")
set(VITA_VERSION  "01.00")

IF (CMAKE_BUILD_TYPE STREQUAL Debug)
  ADD_DEFINITIONS(-DDBG)
ENDIF()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -w -fpermissive")

file(GLOB_RECURSE CFILES "${CMAKE_SOURCE_DIR}/*.c")
SET_SOURCE_FILES_PROPERTIES(${CFILES} PROPERTIES LANGUAGE CXX )

include_directories(
  src/
)

aux_source_directory(./src dir_src)

add_executable(${PROJECT_NAME} ${dir_src})

target_link_libraries(${PROJECT_NAME}
  SDL2_mixer
  mikmod
  mpg123
  FLAC
  vorbisfile
  vorbis
  ogg
  SDL2
  SDL2_image
  jpeg
  webp
  SDL2_ttf
  freetype
  png
  z
  vita2d
  SceDisplay_stub
  SceCtrl_stub
  SceAudio_stub
  SceAudioIn_stub
  SceSysmodule_stub
  SceGxm_stub
  SceCommonDialog_stub
  SceAppMgr_stub
  SceTouch_stub
  SceMotion_stub
  SceHid_stub
  m
  stdc++
  pthread
)



include("${VITASDK}/share/vita.cmake" REQUIRED)
vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})
vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
  FILE res/text.txt text.txt
  FILE res/font/m5x7.ttf font/m5x7.ttf

  FILE res/audio/main_title.ogg audio/main_title.ogg
  FILE res/audio/bg1.ogg audio/bg1.ogg
  FILE res/audio/bg2.ogg audio/bg2.ogg
  FILE res/audio/bg3.ogg audio/bg3.ogg
  FILE res/audio/arrow_hit.wav audio/arrow_hit.wav
  FILE res/audio/button1.wav audio/button1.wav
  FILE res/audio/claw_hit.wav audio/claw_hit.wav
  FILE res/audio/claw_hit_heavy.wav audio/claw_hit_heavy.wav
  FILE res/audio/coin.wav audio/coin.wav
  FILE res/audio/fireball_explosion.wav audio/fireball_explosion.wav
  FILE res/audio/hit_0.5v.wav audio/hit_0.5v.wav
  FILE res/audio/human_death.wav audio/human_death.wav
  FILE res/audio/ice_shoot.wav audio/ice_shoot.wav
  FILE res/audio/ice_shoot_0.5v.wav audio/ice_shoot_0.5v.wav
  FILE res/audio/interaction1_0.75v.wav audio/interaction1_0.75v.wav
  FILE res/audio/light_shoot.wav audio/light_shoot.wav
  FILE res/audio/lose_2v.wav audio/lose_2v.wav
  FILE res/audio/med.wav audio/med.wav
  FILE res/audio/powerloss.wav audio/powerloss.wav
  FILE res/audio/shoot.wav audio/shoot.wav
  FILE res/audio/sounds audio/sounds
  FILE res/audio/sword_hit.wav audio/sword_hit.wav
  FILE res/audio/thunder_2v.wav audio/thunder_2v.wav
  FILE res/audio/win.wav audio/win.wav

  FILE res/drawable/0x72_DungeonTilesetII_v1_3 drawable/0x72_DungeonTilesetII_v1_3
  FILE res/drawable/0x72_DungeonTilesetII_v1_3.png drawable/0x72_DungeonTilesetII_v1_3.png
  FILE res/drawable/Axe drawable/Axe
  FILE res/drawable/Axe.png drawable/Axe.png
  FILE res/drawable/BloodBound drawable/BloodBound
  FILE res/drawable/BloodBound.png drawable/BloodBound.png
  FILE res/drawable/ClawFx drawable/ClawFx
  FILE res/drawable/ClawFx.png drawable/ClawFx.png
  FILE res/drawable/ClawFx2 drawable/ClawFx2
  FILE res/drawable/ClawFx2.png drawable/ClawFx2.png
  FILE res/drawable/HolyShield drawable/HolyShield
  FILE res/drawable/HolyShield.png drawable/HolyShield.png
  FILE res/drawable/HpMed drawable/HpMed
  FILE res/drawable/HpMed.png drawable/HpMed.png
  FILE res/drawable/Ice drawable/Ice
  FILE res/drawable/Ice.png drawable/Ice.png
  FILE res/drawable/IcePick drawable/IcePick
  FILE res/drawable/IcePick.png drawable/IcePick.png
  FILE res/drawable/IceShatter drawable/IceShatter
  FILE res/drawable/IceShatter.png drawable/IceShatter.png
  FILE res/drawable/Shine drawable/Shine
  FILE res/drawable/Shine.png drawable/Shine.png
  FILE res/drawable/SolidFx drawable/SolidFx
  FILE res/drawable/SolidFx.png drawable/SolidFx.png
  FILE res/drawable/SolidFx.png.bk drawable/SolidFx.png.bk
  FILE res/drawable/SwordFx drawable/SwordFx
  FILE res/drawable/SwordFx.bk drawable/SwordFx.bk
  FILE res/drawable/SwordFx.png drawable/SwordFx.png
  FILE res/drawable/SwordFx.png.bk drawable/SwordFx.png.bk
  FILE res/drawable/SwordPack drawable/SwordPack
  FILE res/drawable/SwordPack.png drawable/SwordPack.png
  FILE res/drawable/Thunder drawable/Thunder
  FILE res/drawable/Thunder.png drawable/Thunder.png
  FILE res/drawable/Thunder_Yellow drawable/Thunder_Yellow
  FILE res/drawable/Thunder_Yellow.png drawable/Thunder_Yellow.png
  FILE res/drawable/arrow drawable/arrow
  FILE res/drawable/arrow.png drawable/arrow.png
  FILE res/drawable/attack_up drawable/attack_up
  FILE res/drawable/attack_up.png drawable/attack_up.png
  FILE res/drawable/blood drawable/blood
  FILE res/drawable/blood.png drawable/blood.png
  FILE res/drawable/cross_hit drawable/cross_hit
  FILE res/drawable/cross_hit.png drawable/cross_hit.png
  FILE res/drawable/explosion-2 drawable/explosion-2
  FILE res/drawable/explosion-2.png drawable/explosion-2.png
  FILE res/drawable/fireball drawable/fireball
  FILE res/drawable/fireball.png drawable/fireball.png
  FILE res/drawable/fireball_explosion1 drawable/fireball_explosion1
  FILE res/drawable/fireball_explosion1.png drawable/fireball_explosion1.png
  FILE res/drawable/floor_exit drawable/floor_exit
  FILE res/drawable/floor_exit.png drawable/floor_exit.png
  FILE res/drawable/floor_spike drawable/floor_spike
  FILE res/drawable/floor_spike.png drawable/floor_spike.png
  FILE res/drawable/golden_cross_hit drawable/golden_cross_hit
  FILE res/drawable/golden_cross_hit.png drawable/golden_cross_hit.png
  FILE res/drawable/halo_explosion1 drawable/halo_explosion1
  FILE res/drawable/halo_explosion1.png drawable/halo_explosion1.png
  FILE res/drawable/halo_explosion2 drawable/halo_explosion2
  FILE res/drawable/halo_explosion2.png drawable/halo_explosion2.png
  FILE res/drawable/powerful_bow drawable/powerful_bow
  FILE res/drawable/powerful_bow.png drawable/powerful_bow.png
  FILE res/drawable/purple_ball drawable/purple_ball
  FILE res/drawable/purple_ball.png drawable/purple_ball.png
  FILE res/drawable/purple_exp drawable/purple_exp
  FILE res/drawable/purple_exp.png drawable/purple_exp.png
  FILE res/drawable/staff drawable/staff
  FILE res/drawable/staff.png drawable/staff.png
  FILE res/drawable/title drawable/title
  FILE res/drawable/title.png drawable/title.png
  FILE res/drawable/ui drawable/ui
  FILE res/drawable/ui.png drawable/ui.png

  FILE psv/icon0_dark_128.png sce_sys/icon0.png
  FILE psv/pic0.png sce_sys/pic0.png
  FILE psv/livearea/contents/bg_with_logo.png sce_sys/livearea/contents/bg.png
  FILE psv/livearea/contents/logo_8bit.png sce_sys/livearea/contents/logo.png 
  FILE psv/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
  FILE psv/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
)

# running below in shell to create audio and drawable filelist.
# d={audio,drawable}
# for dir in  $(ls res/$d); do echo FILE res/$d/$dir $d/$dir;  done
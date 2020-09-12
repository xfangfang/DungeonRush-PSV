#include "res.h"
#include "audio.h"
#include "helper.h"

extern const int bgmNums;
#ifdef __vita__
  #include <soloud.h>
  #include <soloud_wav.h>

  extern SoLoud::Soloud gSoloud;
  extern SoLoud::Wav  *bgms[AUDIO_BGM_SIZE];
  extern SoLoud::Wav  *sounds[AUDIO_SOUND_SIZE];
#else
  extern Mix_Music *bgms[AUDIO_BGM_SIZE];
  extern Mix_Chunk *sounds[AUDIO_SOUND_SIZE];
#endif


int nowBgmId = -1;
void playBgm(int id) {
  printf("bgm: %d %d\n",nowBgmId,id);
  if (nowBgmId == id) return;
  #ifdef __vita__
    if (nowBgmId != -1){
      gSoloud.stopAll();
    }
    gSoloud.playBackground(*bgms[id]);
  #else
    if (nowBgmId == -1) Mix_PlayMusic(bgms[id], -1);
    else Mix_FadeInMusic(bgms[id], -1, BGM_FADE_DURATION);
  #endif
  nowBgmId = id;
}
void stopBgm() {
  printf("stop bgm\n");
  #ifdef __vita__
    gSoloud.stopAll();
  #else
    Mix_FadeOutMusic(BGM_FADE_DURATION);
  #endif
  nowBgmId = -1;
}
void randomBgm() {
  printf("random bgm\n");
  playBgm(randInt(0, bgmNums-1));
}
void playAudio(int id) {
  #ifdef __vita__
    gSoloud.play(*sounds[id]);
  #else
      Mix_PlayChannel(-1, sounds[id], 0 );
  #endif
}
void pauseSound() {
  #ifdef __vita__
    gSoloud.setPauseAll(true);
  #else
    Mix_Pause(-1);
    Mix_PauseMusic();
  #endif

}
void resumeSound() {
  #ifdef __vita__
    gSoloud.setPauseAll(false);
  #else
    Mix_Resume(-1);
    Mix_ResumeMusic();
  #endif
}
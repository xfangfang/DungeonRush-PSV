#include "res.h"
#include "audio.h"
#include "helper.h"

extern const int bgmNums;
extern Mix_Music *bgms[AUDIO_BGM_SIZE];
extern Mix_Chunk *sounds[AUDIO_SOUND_SIZE];


int nowBgmId = -1;
void playBgm(int id) {
  printf("bgm: %d %d\n",nowBgmId,id);
  if (nowBgmId == id) return;
  if (nowBgmId == -1) Mix_PlayMusic(bgms[id], -1);
  else Mix_FadeInMusic(bgms[id], -1, BGM_FADE_DURATION);
  nowBgmId = id;
}
void stopBgm() {
  printf("stop bgm\n");
  Mix_FadeOutMusic(BGM_FADE_DURATION);
  nowBgmId = -1;
}
void randomBgm() {
  printf("random bgm\n");
  playBgm(randInt(1, bgmNums-1));
}
void playAudio(int id) {
  Mix_PlayChannel(-1, sounds[id], 0 );
}
void pauseSound() {
  Mix_Pause(-1);
  Mix_PauseMusic();
}
void resumeSound() {
  Mix_Resume(-1);
  Mix_ResumeMusic();
}
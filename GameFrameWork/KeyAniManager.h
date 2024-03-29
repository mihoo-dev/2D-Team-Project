#pragma once
#include "SingleTonBase.h"
#include <map>

class animation;
class image;

class KeyAniManager:public SingleTonBase<KeyAniManager>
{
private:
	typedef map<string, animation*>				animMap;
	typedef map<string, animation*>::iterator	animMapIter;
private:
	animMap	totalAnim;
public:
	KeyAniManager();
	~KeyAniManager();

	HRESULT init();
	void release();
	void update();
	void render();

	//디폴트 애니메이션
	void addDefaultFrameAnimation(string animationKeyName, char*imageKeyName, int fps, bool reverse, bool loop);
	void addDefaultFrameAnimation(string animationKeyName, char*imageKeyName, int fps, bool reverse, bool loop, void*cbFunction);
	void addDefaultFrameAnimation(string animationKeyName, char*imageKeyName, int fps, bool reverse, bool loop, void*cbFunction, void*obj);

	//배열 애니메이션
	void addArrayFrameAnimation(string animationKeyName, char*imageKeyName, int*arr, int arrLen, int fps, bool loop);
	void addArrayFrameAnimation(string animationKeyName, char*imageKeyName, int*arr, int arrLen, int fps, bool loop, void*cbFunction);
	void addArrayFrameAnimation(string animationKeyName, char*imageKeyName, int*arr, int arrLen, int fps, bool loop, void*cbFunction, void*obj);

	//구간 애니메이션
	void addCoordinateFrameAnimation(string animationKeyName, char*imageKeyName, int start, int end, int fps, bool reverse, bool loop);
	void addCoordinateFrameAnimation(string animationKeyName, char*imageKeyName, int start, int end, int fps, bool reverse, bool loop, void*cbFunction);
	void addCoordinateFrameAnimation(string animationKeyName, char*imageKeyName, int start, int end, int fps, bool reverse, bool loop, void*cbFunction, void*obj);

	void start(string animationKeyName);
	void stop(string animationKeyName);
	void pause(string animationKeyName);
	void resume(string animationKeyName);

	animation*findAnimation(string animationKeyName);
	void deleteAll();
};


#ifndef GL_UTIL_H
#define GL_UTIL_H
#include<fstream>
#include <time.h>

typedef unsigned char       BYTE;

//声明单例宏
#define GL_DECLARE_SINGLETON(CLASS_NAME)  \
	private:\
	CLASS_NAME(); \
	CLASS_NAME(const CLASS_NAME&); \
	CLASS_NAME& operator= (const CLASS_NAME&);    \
	public:\
	static CLASS_NAME &Instance()
//定义单例宏
#define GL_DEFINE_SINGLETON(CLASS_NAME)   \
	CLASS_NAME::CLASS_NAME() {};  \
	CLASS_NAME & CLASS_NAME::Instance(){\
	static CLASS_NAME s_instance; \
	return s_instance;\
	}

#define INITEERROROUT(P) InitOutOf(P)
#define ERROROUT(P)  ErrorOut(__FILE__,__LINE__,P)
#define ENDERROROUT() EndErrorOut()
#define ZERO_MEM(a) memset(a, 0, sizeof(a))


class ErrorLog{
	GL_DECLARE_SINGLETON(ErrorLog);
private:
	std::ofstream of;
public:
	void Init(const char*fileName);
	std::ofstream& getOf(){ return of; };
	void End(){ of.close(); }

};


void InitOutOf( const char*);
void ErrorOut( const char*file, int line, const char *neirong);
void GetTime(std::ofstream &);
void EndErrorOut();
void GlfwErrorCallBack(int n, const char* descrption);
bool ReadFile(const char* pFileName, std::string& outFile);


#define GL_INVALID_MATERIAL 0xFFFFFFFF
#define INVALID_OGL_VALUE   0xFFFFFFFF

#define SAFERELEASE(p) if (p) { delete p; p = NULL; }

enum RenderType{
	TEXTURE_TYPE,   //渲染纹理
	MODEL_NORMAL_TYPE,    //渲染模型法线
	WORLD_NORMAL_TYPE,    //渲染世界法线
	MODEL_POSITION_TYPE,  //渲染模型坐标
	WORLD_POSITION_TYPE,  //渲染世界坐标

};
enum MaterialType{
	DIFF,
	SPEC,
	EMIT,
	MIX,
};

template<typename T>
void PHO_Camp(T Tmin, T Tmax, T& var){
	if (var < Tmin)
		var = Tmin;
	else if (var > Tmin)
		var = Tmax;
}



#endif
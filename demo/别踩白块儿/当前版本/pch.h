// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
#ifndef _UNISTD_H

#define _UNISTD_H
#include <io.h>
#include <process.h>
#endif /* _UNISTD_H */
#ifndef PCH_H
#define PCH_H

// TODO: 添加要在此处预编译的标头


#endif //PCH_H

#if _MSC_VER>=1900 
#include "stdio.h" _ACRTIMP_ALT FILE* __cdecl __acrt_iob_func(unsigned); 
#ifdef __cplusplus extern "C" 
#endif FILE* __cdecl __iob_func(unsigned i) { return __acrt_iob_func(i); }
#endif


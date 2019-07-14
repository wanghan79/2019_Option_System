//#include "stdafx.h"
#include <locale.h> //setlocale
#include <stdio.h>  //wprintf, printf
#include <windows.h>//GetModuleFileName, GetCurrentDirectory, GetWindowsDirectory, GetSystemDirectory
#include <ShlObj.h> //SHGetSpecialFolderPath

int main()
{
    //用来配置地域的信息，设置当前程序使用的本地化信息。
    setlocale(LC_ALL, "chs");
    TCHAR szPath[MAX_PATH]; 
    DWORD ret;

    /*
    获取当前进程已加载模块的文件的完整路径，该模块必须由当前进程加载。
    DWORD GetModuleFileName (
    HMODULE hModule,    //handle to module
    LPTSTR lpFilename,  //file name of module
    DWORD nSize         //size of buffer
    )
    return Long，如执行成功，返回复制到lpFileName的实际字符数量；零表示失败。使用GetLastError可以打印错误信息。
    */
    ret = GetModuleFileName(NULL, szPath, MAX_PATH);
    if (!ret) {
        printf("GetModuleFileName fail (%d)\n", GetLastError());
        return FALSE;
    }
    //打印程序路径信息
    printf("GetModuleFileName -> %s\n", szPath);

    /*
    在一个缓冲区中装载当前目录
    DWORD GetCurrentDirectory (
    DWORD nBufferLength,    //sizeof directory buffer
    LPTSTR lpBuffer         //directory buffer
    );
    return Long，装载到lpBuffer的字节数。如nBufferLength的长度不够，不足以容纳目录，则返回值是必要的缓冲区长度（要求至少这个长度），其中包括空中止字符。零表示失败。会设置GetLastError
    */
    ret = GetCurrentDirectory(MAX_PATH, szPath);
    if (!ret) {
        printf("GetCurrentDirectory fail (%ld)\n", GetLastError());
        return FALSE;
    }
    //打印程序所在目录信息
    printf("GetCurrentDirectory -> %s\n", szPath); 
    
    /*
    获取Windows目录的完整路径名
    UINT WINAPI GetSystemDirectory (
    __out LPTSTR lpBuffer,  //buffer for windows directory
    __in UINT uSize         //size of directory buffer
    );
    return Long类型，复制到lpBuffer的一个字串的长度。如lpBuffer不够大，不能容下整个字串，就会返回lpBuffer要求的长度，零表示失败。并且将出错的信息存储在GetLastError函数中，用户可以通过调用GetLastError来得到错误信息。
    */
    ret = GetWindowsDirectory(szPath, MAX_PATH);
    if (!ret) {
        printf("GetWindowsDirectory fail (%ld)\n", GetLastError());
        return FALSE;
    }
    printf("GetWindowsDirectory -> %s\n", szPath);
    //GetWindowsDirectory -> C:\Windows

    /*
    获取Windows目录名
    UINT WINAPI GetSystemDirectory (
    __out LPTSTR lpBuffer,  //buffer for system directory
    __in UINT uSize         //size of directory buffer
    );
    return Long类型，复制到lpBuffer的一个字串的长度。如lpBuffer不够大，不能容下整个字串，就会返回lpBuffer要求的长度，零表示失败。并且将出错的信息存储在GetLastError函数中，用户可以通过调用GetLastError来得到错误信息。
    */
    ret = GetSystemDirectory(szPath, MAX_PATH);
    if (!ret) {
        printf("GetSystemDirectory fail (%ld)\n", GetLastError());
        return FALSE;
    }
    printf("GetSystemDirectory -> %s\n", szPath);
    //GetSystemDirectory -> C:\Windows\system32

    /*
    获取指定的系统路径
    BOOL SHGetSpecialFolderPath (
    HWND hwndOwner, //A handle to the owner window that the client should specify if it displays
    LPTSTR lpszPath,
    int nFolder,    //A CSIDL that identifies the folder of interest.
    BOOL fCreate    //Indicates whether the folder should be created if it does not already exist.
    );
    #define CSIDL_DESKTOP                   0x0000        // <desktop>
    #define CSIDL_INTERNET                  0x0001        // Internet Explorer (icon on desktop)
    #define CSIDL_PROGRAMS                  0x0002        // Start Menu\Programs
    #define CSIDL_CONTROLS                  0x0003        // My Computer\Control Panel
    #define CSIDL_PRINTERS                  0x0004        // My Computer\Printers
    #define CSIDL_PERSONAL                  0x0005        // My Documents
    #define CSIDL_FAVORITES                 0x0006        // <user name>\Favorites
    #define CSIDL_STARTUP                   0x0007        // Start Menu\Programs\Startup
    #define CSIDL_RECENT                    0x0008        // <user name>\Recent
    #define CSIDL_SENDTO                    0x0009        // <user name>\SendTo
    #define CSIDL_BITBUCKET                 0x000a        // <desktop>\Recycle Bin
    #define CSIDL_STARTMENU                 0x000b        // <user name>\Start Menu
    #define CSIDL_MYDOCUMENTS               CSIDL_PERSONAL //  Personal was just a silly name for My Documents
    #define CSIDL_MYMUSIC                   0x000d        // "My Music" folder
    #define CSIDL_MYVIDEO                   0x000e        // "My Videos" folder
    #define CSIDL_DESKTOPDIRECTORY          0x0010        // <user name>\Desktop
    #define CSIDL_DRIVES                    0x0011        // My Computer
    #define CSIDL_NETWORK                   0x0012        // Network Neighborhood (My Network Places)
    #define CSIDL_NETHOOD                   0x0013        // <user name>\nethood
    #define CSIDL_FONTS                     0x0014        // windows\fonts
    #define CSIDL_TEMPLATES                 0x0015
    #define CSIDL_COMMON_STARTMENU          0x0016        // All Users\Start Menu
    #define CSIDL_COMMON_PROGRAMS           0X0017        // All Users\Start Menu\Programs
    #define CSIDL_COMMON_STARTUP            0x0018        // All Users\Startup
    #define CSIDL_COMMON_DESKTOPDIRECTORY   0x0019        // All Users\Desktop
    #define CSIDL_APPDATA                   0x001a        // <user name>\Application Data
    #define CSIDL_PRINTHOOD                 0x001b        // <user name>\PrintHood

    #ifndef CSIDL_LOCAL_APPDATA
    #define CSIDL_LOCAL_APPDATA             0x001c        // <user name>\Local Settings\Applicaiton Data (non roaming)
    #endif // CSIDL_LOCAL_APPDATA

    #define CSIDL_ALTSTARTUP                0x001d        // non localized startup
    #define CSIDL_COMMON_ALTSTARTUP         0x001e        // non localized common startup
    #define CSIDL_COMMON_FAVORITES          0x001f

    #ifndef _SHFOLDER_H_
    #define CSIDL_INTERNET_CACHE            0x0020
    #define CSIDL_COOKIES                   0x0021
    #define CSIDL_HISTORY                   0x0022
    #define CSIDL_COMMON_APPDATA            0x0023        // All Users\Application Data
    #define CSIDL_WINDOWS                   0x0024        // GetWindowsDirectory()
    #define CSIDL_SYSTEM                    0x0025        // GetSystemDirectory()
    #define CSIDL_PROGRAM_FILES             0x0026        // C:\Program Files
    #define CSIDL_MYPICTURES                0x0027        // C:\Program Files\My Pictures
    #endif // _SHFOLDER_H_

    #define CSIDL_PROFILE                   0x0028        // USERPROFILE
    #define CSIDL_SYSTEMX86                 0x0029        // x86 system directory on RISC
    #define CSIDL_PROGRAM_FILESX86          0x002a        // x86 C:\Program Files on RISC

    #ifndef _SHFOLDER_H_
    #define CSIDL_PROGRAM_FILES_COMMON      0x002b        // C:\Program Files\Common
    #endif // _SHFOLDER_H_

    #define CSIDL_PROGRAM_FILES_COMMONX86   0x002c        // x86 Program Files\Common on RISC
    #define CSIDL_COMMON_TEMPLATES          0x002d        // All Users\Templates

    #ifndef _SHFOLDER_H_
    #define CSIDL_COMMON_DOCUMENTS          0x002e        // All Users\Documents
    #define CSIDL_COMMON_ADMINTOOLS         0x002f        // All Users\Start Menu\Programs\Administrative Tools
    #define CSIDL_ADMINTOOLS                0x0030        // <user name>\Start Menu\Programs\Administrative Tools
    #endif // _SHFOLDER_H_

    #define CSIDL_CONNECTIONS               0x0031        // Network and Dial-up Connections
    #define CSIDL_COMMON_MUSIC              0x0035        // All Users\My Music
    #define CSIDL_COMMON_PICTURES           0x0036        // All Users\My Pictures
    #define CSIDL_COMMON_VIDEO              0x0037        // All Users\My Video
    #define CSIDL_RESOURCES                 0x0038        // Resource Direcotry

    #ifndef _SHFOLDER_H_
    #define CSIDL_RESOURCES_LOCALIZED       0x0039        // Localized Resource Direcotry
    #endif // _SHFOLDER_H_

    #define CSIDL_COMMON_OEM_LINKS          0x003a        // Links to All Users OEM specific apps
    #define CSIDL_CDBURN_AREA               0x003b        // USERPROFILE\Local Settings\Application Data\Microsoft\CD Burning
    // unused                               0x003c
    #define CSIDL_COMPUTERSNEARME           0x003d        // Computers Near Me (computered from Workgroup membership)
    */

    int CSIDLs[] = {
        CSIDL_DESKTOP,
        CSIDL_INTERNET,
        CSIDL_PROGRAMS,
        CSIDL_CONTROLS,
        CSIDL_PRINTERS,
        CSIDL_PERSONAL,
        CSIDL_FAVORITES,
        CSIDL_STARTUP,
        CSIDL_RECENT,
        CSIDL_SENDTO,
        CSIDL_BITBUCKET,
        CSIDL_STARTMENU,
        CSIDL_MYDOCUMENTS,
        CSIDL_MYMUSIC,
        CSIDL_MYVIDEO,
        CSIDL_DESKTOPDIRECTORY,
        CSIDL_DRIVES,
        CSIDL_NETWORK,
        CSIDL_NETHOOD,
        CSIDL_FONTS,
        CSIDL_TEMPLATES,
        CSIDL_COMMON_STARTMENU,
        CSIDL_COMMON_PROGRAMS,
        CSIDL_COMMON_STARTUP,
        CSIDL_COMMON_DESKTOPDIRECTORY,
        CSIDL_APPDATA,
        CSIDL_PRINTHOOD,

        CSIDL_LOCAL_APPDATA,

        CSIDL_ALTSTARTUP,
        CSIDL_COMMON_ALTSTARTUP,
        CSIDL_COMMON_FAVORITES,

        CSIDL_INTERNET_CACHE,
        CSIDL_COOKIES,
        CSIDL_HISTORY,
        CSIDL_COMMON_APPDATA,
        CSIDL_WINDOWS,
        CSIDL_SYSTEM,
        CSIDL_PROGRAM_FILES,
        CSIDL_MYPICTURES,

        CSIDL_PROFILE,
        CSIDL_SYSTEMX86,
        CSIDL_PROGRAM_FILESX86,

        CSIDL_PROGRAM_FILES_COMMON,

        CSIDL_PROGRAM_FILES_COMMONX86,
        CSIDL_COMMON_TEMPLATES,

        CSIDL_COMMON_DOCUMENTS,
        CSIDL_COMMON_ADMINTOOLS,
        CSIDL_ADMINTOOLS,

        CSIDL_CONNECTIONS,
        CSIDL_COMMON_MUSIC,
        CSIDL_COMMON_PICTURES,
        CSIDL_COMMON_VIDEO,
        CSIDL_RESOURCES,

        CSIDL_RESOURCES_LOCALIZED,

        CSIDL_COMMON_OEM_LINKS,
        CSIDL_CDBURN_AREA,

        CSIDL_COMPUTERSNEARME,
    };
    const char *szCSIDLs[] = {
        "CSIDL_DESKTOP",
        "CSIDL_INTERNET",
        "CSIDL_PROGRAMS",
        "CSIDL_CONTROLS",
        "CSIDL_PRINTERS",
        "CSIDL_PERSONAL",
        "CSIDL_FAVORITES",
        "CSIDL_STARTUP",
        "CSIDL_RECENT",
        "CSIDL_SENDTO",
        "CSIDL_BITBUCKET",
        "CSIDL_STARTMENU",
        "CSIDL_MYDOCUMENTS",
        "CSIDL_MYMUSIC",
        "CSIDL_MYVIDEO",
        "CSIDL_DESKTOPDIRECTORY",
        "CSIDL_DRIVES",
        "CSIDL_NETWORK",
        "CSIDL_NETHOOD",
        "CSIDL_FONTS",
        "CSIDL_TEMPLATES",
        "CSIDL_COMMON_STARTMENU",
        "CSIDL_COMMON_PROGRAMS",
        "CSIDL_COMMON_STARTUP",
        "CSIDL_COMMON_DESKTOPDIRECTORY",
        "CSIDL_APPDATA",
        "CSIDL_PRINTHOOD",

        "CSIDL_LOCAL_APPDATA",

        "CSIDL_ALTSTARTUP",
        "CSIDL_COMMON_ALTSTARTUP",
        "CSIDL_COMMON_FAVORITES",

        "CSIDL_INTERNET_CACHE",
        "CSIDL_COOKIES",
        "CSIDL_HISTORY",
        "CSIDL_COMMON_APPDATA",
        "CSIDL_WINDOWS",
        "CSIDL_SYSTEM",
        "CSIDL_PROGRAM_FILES",
        "CSIDL_MYPICTURES",

        "CSIDL_PROFILE",
        "CSIDL_SYSTEMX86",
        "CSIDL_PROGRAM_FILESX86",

        "CSIDL_PROGRAM_FILES_COMMON",

        "CSIDL_PROGRAM_FILES_COMMONX86",
        "CSIDL_COMMON_TEMPLATES",

        "CSIDL_COMMON_DOCUMENTS",
        "CSIDL_COMMON_ADMINTOOLS",
        "CSIDL_ADMINTOOLS",

        "CSIDL_CONNECTIONS",
        "CSIDL_COMMON_MUSIC",
        "CSIDL_COMMON_PICTURES",
        "CSIDL_COMMON_VIDEO",
        "CSIDL_RESOURCES",

        "CSIDL_RESOURCES_LOCALIZED",

        "CSIDL_COMMON_OEM_LINKS",
        "CSIDL_CDBURN_AREA",

        "CSIDL_COMPUTERSNEARME",
    };
    for (int i = 0; i < sizeof(CSIDLs) / sizeof(CSIDLs[0]); i++) {
        BOOL bRet = SHGetSpecialFolderPath(NULL, szPath, CSIDLs[i], FALSE);
        if (!bRet) {
            printf("SHGetSpecialFolderPath %02d. %02d %s fail (%ld) \n", i, CSIDLs[i], szCSIDLs[i], GetLastError());
            //(1008)-试图引用不存在的令牌
        }
        else {
            printf("SHGetSpecialFolderPath %02d. %02d %s -> %s \n", i, CSIDLs[i], szCSIDLs[i], szPath);
        }
    }
    system("pause");
    return TRUE;
}


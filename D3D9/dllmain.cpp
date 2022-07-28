#include <windows.h>
#include <sstream>
//#include <d3d9.h>
//#include <d3dx9.h>
//#pragma comment(lib, "d3d9.lib")
//#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "ws2_32.lib")

using namespace std;

//#define ES  0
//LPDIRECT3DDEVICE9 npDevice;

//typedef HRESULT(WINAPI* tEndScene)(LPDIRECT3DDEVICE9);
//tEndScene oEndScene;
//BYTE g_jmp_es[5] = { 0, 0, 0, 0, 0 };
//BYTE g_codeFragment_es[5] = { 0, 0, 0, 0, 0 };
//ID3DXFont* m_font = 0;

//LRESULT CALLBACK MsgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) { return DefWindowProc(hwnd, uMsg, wParam, lParam); }
//DWORD DetourDetachFunc(LPDIRECT3DDEVICE9 pDev);
//DWORD DrawFigure(LPDIRECT3DDEVICE9 pDev, int x, int y, int h, int w, D3DCOLOR color);
//DWORD DrawBorderedFigure(LPDIRECT3DDEVICE9 pDev, int x, int y, int h, int w, D3DCOLOR color, D3DCOLOR borderColor);
//D3DCOLOR figureColor = D3DCOLOR_ARGB(255, 0, 0, 0);
//D3DCOLOR figureBorderColor = D3DCOLOR_ARGB(255, 150, 150, 150);
//D3DCOLOR activeFigureBorderColor = D3DCOLOR_ARGB(255, 255, 100, 100);
string className = "Battle Style ";
bool Active = false;
atomic<bool> ViewClass = false;

//HRESULT WINAPI hkEndScene(LPDIRECT3DDEVICE9 pDev)
//{
//    if (ViewClass) {
//        if (m_font == 0)
//            D3DXCreateFontA(pDev, 14, 0, 0, 0, 0, 1, 0, 0, 0, "Arial", &m_font);
//
//        if (Active) {
//            DrawBorderedFigure(pDev, 10, 10, 150, 40, figureColor, activeFigureBorderColor);
//        }
//        else {
//            DrawBorderedFigure(pDev, 10, 10, 150, 40, figureColor, figureBorderColor);
//        }
//
//        RECT fontRect = { 25, 18, 150, 40 };
//        (m_font)->DrawTextA(0, className.c_str(), -1, &fontRect, 0, D3DCOLOR_ARGB(255, 150, 150, 150));
//    }
//
//    DWORD res = DetourDetachFunc(pDev);
//
//    return res;
//}

//DWORD DrawBorderedFigure(LPDIRECT3DDEVICE9 pDev, int x, int y, int h, int w, D3DCOLOR color, D3DCOLOR borderColor)
//{
//    DrawFigure(pDev, x, y, h, w, borderColor);
//    DrawFigure(pDev, x + 2, y + 2, h - 2, w - 2, color);
//
//    return 0;
//}

//DWORD DrawFigure(LPDIRECT3DDEVICE9 pDev, int x, int y, int h, int w, D3DCOLOR color)
//{
//    D3DRECT rect = { x, y, h, w };
//
//    pDev->Clear(1, &rect, D3DCLEAR_TARGET, color, 0, 0);
//
//    return 0;
//}
//
//DWORD DetourDetachFunc(LPDIRECT3DDEVICE9 pDev)
//{
//    DWORD res;
//
//    BYTE* codeDest = (BYTE*)oEndScene;
//    codeDest[0] = g_codeFragment_es[0];
//    *((DWORD*)(codeDest + 1)) = *((DWORD*)(g_codeFragment_es + 1));
//
//    res = oEndScene(pDev);
//
//    codeDest[0] = g_jmp_es[0];
//    *((DWORD*)(codeDest + 1)) = *((DWORD*)(g_jmp_es + 1));
//
//    return res;
//}
//
//void DetourAttachFunc(DWORD ESAddress)
//{
//    DWORD addr, g_savedProtection_es;
//    oEndScene = (tEndScene)(ESAddress);
//    g_jmp_es[0] = 0xE9;
//    addr = (DWORD)hkEndScene - (DWORD)oEndScene - 5;
//    memcpy(g_jmp_es + 1, &addr, sizeof(DWORD));
//    memcpy(g_codeFragment_es, oEndScene, 5);
//    VirtualProtect(oEndScene, 8, PAGE_EXECUTE_READWRITE, &g_savedProtection_es);
//    memcpy(oEndScene, g_jmp_es, 5);
//}

//void DX_Init(DWORD* table)
//{
//    WNDCLASSEX wc = { sizeof(WNDCLASSEX),CS_CLASSDC,MsgProc,0L,0L,GetModuleHandle(NULL),NULL,NULL,NULL,NULL,L"DX",NULL };
//    RegisterClassEx(&wc);
//    HWND hWnd = CreateWindowA("DX", NULL, WS_OVERLAPPEDWINDOW, 100, 100, 300, 300, GetDesktopWindow(), NULL, wc.hInstance, NULL);
//    LPDIRECT3D9 pD3D = Direct3DCreate9(D3D_SDK_VERSION);
//    D3DPRESENT_PARAMETERS d3dpp;
//    ZeroMemory(&d3dpp, sizeof(d3dpp));
//    d3dpp.Windowed = TRUE;
//    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
//    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
//    LPDIRECT3DDEVICE9 pd3dDevice;
//    pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &pd3dDevice);
//    npDevice = pd3dDevice;
//    DWORD* pVTable = (DWORD*)pd3dDevice;
//    pVTable = (DWORD*)pVTable[0];
//    table[ES] = pVTable[42];
//
//    DestroyWindow(hWnd);
//}

VOID Activate(BYTE* classByte)
{
    /* std::ostringstream ss;
    ss << hex <<  offset;
    MessageBoxA(0, ss.str().c_str(), "Address", 0);*/
    BYTE dmbytes[4] = { 0x00, 0x00, 0x00, 0x00 };
    DWORD handle = (DWORD)GetModuleHandleA("cabalmain.exe");

    DWORD* BaseAddress = (DWORD*)(handle + 0xC7BF5C);
    DWORD offsetAddress = (*BaseAddress + 0x41A8);

    std::memcpy(dmbytes, classByte, 4);

    bool gender = false;

    if (dmbytes[3] == 0x04 || dmbytes[3] == 0x24 || dmbytes[3] == 0x34 || dmbytes[3] == 0x44)
    {
        gender = true;
    }

    if (Active) {
        switch (dmbytes[0])
        {
        case 0x09:
            dmbytes[3] = gender ? 0x24 : 0x20;
            break;
        case 0x0C:
            dmbytes[3] = gender ? 0x34 : 0x30;
            break;
        case 0x0B:
            dmbytes[3] = gender ? 0x44 : 0x40;
            break;
        default:
            dmbytes[3] = gender ? 0x04 : 0x00;
        }
    }
    else {
        dmbytes[3] = gender ? 0x04 : 0x00;
    }
    
    std::memcpy((PVOID)offsetAddress, dmbytes, 4);
}

DWORD WINAPI FreezeIP(char* address)
{
    DWORD ipAddrCabalMain = (DWORD)GetModuleHandleA("cabalmain.exe") + 0x76A0FC;

    while (true) {
        std::memcpy((PVOID)ipAddrCabalMain, address, 15);
    }

    return 0;
}

DWORD WINAPI ChangeIP(LPVOID lpParam)
{
    Sleep(1500);

    char encIP[15] = {};

    in_addr address;
    DWORD ipAddrProtection;

    DWORD handleIPAddr = (DWORD)GetModuleHandleA("DevPack.dll") + 0x14060;

    DWORD* handleEncIP = (DWORD*)((DWORD)GetModuleHandleA("cabalmain.exe") + 0x78D970);
    DWORD handleEncIPAddr = (*handleEncIP + 0x14);

    std::memcpy(encIP, (PVOID)handleEncIPAddr, 15);

    address.s_addr = inet_addr(encIP);

    VirtualProtect((PVOID)handleIPAddr, 15, PAGE_READWRITE, &ipAddrProtection);
    std::memcpy((PVOID)handleIPAddr, inet_ntoa(address), 15);
    VirtualProtect((PVOID)handleIPAddr, 15, ipAddrProtection, &ipAddrProtection);

    FreezeIP(inet_ntoa(address));
}

DWORD WINAPI CheckViewCharacterCreate(LPVOID lpParam)
{
    Sleep(1500);

    DWORD handle = (DWORD)GetModuleHandleA("cabalmain.exe");

    DWORD* BaseIsActiveCreateCharacterAddress = (DWORD*)(handle + 0xC7BF5C);
    DWORD isActiveCreateCharacterAddress = (*BaseIsActiveCreateCharacterAddress + 0x41D0);
    BYTE prevActiveCreateCharacterByte[1] = { 0x00 };
    BYTE activeCreateCharacterByte[1];

    while (true) {
        std::memcpy(activeCreateCharacterByte, (PVOID)isActiveCreateCharacterAddress, 1);

        if (prevActiveCreateCharacterByte[0] == activeCreateCharacterByte[0]) {
            ViewClass = false;
        }
        else {
            ViewClass = true;
        }

        std::memcpy(prevActiveCreateCharacterByte, activeCreateCharacterByte, 1);

        Sleep(1000);
    }
}

DWORD WINAPI SetHook(LPVOID lpParam)
{
    //DWORD VTable[3] = { 0 };
    //HMODULE d3d9 = NULL;

    //while (d3d9 == NULL) {
    //    d3d9 = GetModuleHandleA("d3d9.dll");
    //    Sleep(250);
    //}

    //DX_Init(VTable);
    //DetourAttachFunc(VTable[ES]);
    BOOL initValues = false;
    DWORD handle;
    DWORD handleZDisplay;
    DWORD offsetAddress;
    DWORD BSBaseAddress7;
    DWORD APBaseAddress;
    BYTE ActiveBytes[24] = { 0x24, 0x33, 0x23, 0x50, 0x72, 0x65, 0x73, 0x73, 0x20, 0x46, 0x31, 0x20, 0x74, 0x75, 0x72, 0x6E, 0x20, 0x6F, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00 };
    BYTE DisActiveBytes[24] = { 0x24, 0x30, 0x23, 0x50, 0x72, 0x65, 0x73, 0x73, 0x20, 0x46, 0x31, 0x20, 0x74, 0x75, 0x72, 0x6E, 0x20, 0x6F, 0x6E, 0x00, 0x00, 0x00, 0x00, 0x00 };

    while (initValues == false) {
        if (ViewClass == true) {
            handle = (DWORD)GetModuleHandleA("cabalmain.exe");
            handleZDisplay = (DWORD)GetModuleHandleA("zDisplay.dll");

            DWORD* BaseAddress = (DWORD*)(handle + 0xC7BF5C);
            offsetAddress = (*BaseAddress + 0x41A8);

            DWORD* BSBaseAddress = (DWORD*)(handleZDisplay + 0x100490);
            DWORD* BSBaseAddress1 = (DWORD*)(*BSBaseAddress + 0x4C);
            DWORD* BSBaseAddress2 = (DWORD*)(*BSBaseAddress1 + 0xB8);
            DWORD* BSBaseAddress3 = (DWORD*)(*BSBaseAddress2 + 0x50);
            DWORD* BSBaseAddress4 = (DWORD*)(*BSBaseAddress3 + 0x4);
            DWORD* BSBaseAddress5 = (DWORD*)(*BSBaseAddress4 + 0xDC);
            DWORD* BSBaseAddress6 = (DWORD*)(*BSBaseAddress5);

            BSBaseAddress7 = (*BSBaseAddress6 + 0xF84);
            APBaseAddress = (*BSBaseAddress6 + 0xFE4);

            std::memcpy((PVOID)APBaseAddress, DisActiveBytes, 24);

            initValues = true;
        }
    }

    while(true) {
        if (ViewClass == true) {
            if (GetAsyncKeyState(VK_F1)) {
                Active = !Active;

                if (Active) {
                    std::memcpy((PVOID)APBaseAddress, ActiveBytes, 24);
                }
                else {
                    std::memcpy((PVOID)APBaseAddress, DisActiveBytes, 24);
                }
            }

            BYTE classBytes[4] = { 0x00, 0x00, 0x00, 0x00 };
            BYTE prevClass = 0x00;

            std::memcpy(classBytes, (PVOID)offsetAddress, 4);

            if (prevClass != classBytes[0]) {
                prevClass = classBytes[0];
                Activate(classBytes);

                Sleep(100);

                string classPrefix = "Battle Style ";

                switch (classBytes[0])
                {
                case 0x09:
                    if (classBytes[3] == 0x24 || classBytes[3] == 0x20)
                    {
                        className = classPrefix + "(GL)";
                    }
                    else {
                        className = classPrefix + "(WA)";
                    }
                    break;
                case 0x0A:
                    className = classPrefix + "(BL)";
                    break;
                case 0x0B:
                    if (classBytes[3] == 0x44 || classBytes[3] == 0x40)
                    {
                        className = classPrefix + "(DM)";
                    }
                    else {
                        className = classPrefix + "(WZ)";
                    }
                    break;
                case 0x0C:
                    if (classBytes[3] == 0x34 || classBytes[3] == 0x30)
                    {
                        className = classPrefix + "(FG)";
                    }
                    else {
                        className = classPrefix + "(FA)";
                    }
                    break;
                case 0x0D:
                    className = classPrefix + "(FS)";
                    break;
                case 0x0E:
                    className = classPrefix + "(FB)";
                    break;
                default:
                    className = classPrefix + "(FB)";
                }

                BYTE classNameByte[17];
                std::memcpy(classNameByte, className.data(), className.length());
                std::memcpy((PVOID)BSBaseAddress7, classNameByte, 17);
            }

            Sleep(50);
        }
    }

    return 0;
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpvReserved)
{
    if (dwReason == DLL_PROCESS_ATTACH) {
        CreateThread(0, 0, ChangeIP, 0, 0, 0);
        CreateThread(0, 0, SetHook, 0, 0, 0);
        CreateThread(0, 0, CheckViewCharacterCreate, 0, 0, 0);
    }

    return TRUE;
}
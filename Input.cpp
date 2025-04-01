#include "Input.h"

BYTE Input::keys[256] = {};
bool Input::mouseButton[3] = { false, false, false };
LONG Input::currentMouseX = 0;
LONG Input::currentMouseY = 0;
XMFLOAT3 Input::mousePos = { 0.0f, 0.0f, 0.0f };

void Input::initialize(HWND hwnd)
{
    RAWINPUTDEVICE rid[2];

    // Register keyboard
    rid[0].usUsagePage = 0x01;
    rid[0].usUsage = 0x06;
    rid[0].dwFlags = 0;
    rid[0].hwndTarget = hwnd;

    // Register mouse
    rid[1].usUsagePage = 0x01;
    rid[1].usUsage = 0x02;
    rid[1].dwFlags = 0;
    rid[1].hwndTarget = hwnd;

    RegisterRawInputDevices(rid, 2, sizeof(RAWINPUTDEVICE));
}

void Input::processInput(LPARAM lparam)
{
    UINT dwSize;
    GetRawInputData((HRAWINPUT)lparam, RID_INPUT, NULL, &dwSize, sizeof(RAWINPUTHEADER));

    BYTE* lpb = new BYTE[dwSize];
    if (GetRawInputData((HRAWINPUT)lparam, RID_INPUT, lpb, &dwSize, sizeof(RAWINPUTHEADER)) == dwSize)
    {
        RAWINPUT* raw = (RAWINPUT*)lpb;

        if (raw->header.dwType == RIM_TYPEKEYBOARD)
        {
            keys[raw->data.keyboard.VKey] = (raw->data.keyboard.Flags & RI_KEY_BREAK) ? 0 : 1;
        }
        else if (raw->header.dwType == RIM_TYPEMOUSE)
        {
            mouseButton[0] = raw->data.mouse.usButtonFlags & RI_MOUSE_BUTTON_1_DOWN;
            mouseButton[1] = raw->data.mouse.usButtonFlags & RI_MOUSE_BUTTON_2_DOWN;
            mouseButton[2] = raw->data.mouse.usButtonFlags & RI_MOUSE_BUTTON_3_DOWN;

            currentMouseX += raw->data.mouse.lLastX;
            currentMouseY += raw->data.mouse.lLastY;
            mousePos = XMFLOAT3((float)currentMouseX, (float)currentMouseY, 0);
        }
    }
    delete[] lpb;
}

bool Input::isKeyPressed(UINT key)
{
    return keys[key] != 0;
}

XMFLOAT3 Input::getMousePos()
{
    return mousePos;
}

void Input::setMousePos(LONG x, LONG y)
{
    currentMouseX = x;
    currentMouseY = y;
    mousePos = XMFLOAT3((float)x, (float)y, 0);
}

bool Input::isMouseButtonPressed(int button)
{
    if (button >= 0 && button < 3)
        return mouseButton[button];
    return false;
}

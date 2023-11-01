#include <windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  MSG msg          = {0};
  WNDCLASS wc      = {0};
  wc.lpfnWndProc   = WndProc;
  wc.hInstance     = hInstance;
  wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND);
  wc.lpszClassName = L"SayHelloInWin32World";
  if(!RegisterClass(&wc))
  {
    MessageBox( NULL, L"Cannot register windows class", L"Error", MB_OK | MB_ICONEXCLAMATION);
    return 1;
  }
  if(!CreateWindow(wc.lpszClassName,
                   L"Minimal w32 hello-world application",
                   WS_OVERLAPPEDWINDOW|WS_VISIBLE,
                   CW_USEDEFAULT,
                   CW_USEDEFAULT,
                   CW_USEDEFAULT,
                   CW_USEDEFAULT,
                   0,
                   0,
                   hInstance,
                   NULL))
  {
    MessageBox( NULL, L"Cannot create window!", L"Error", MB_OK | MB_ICONEXCLAMATION);
    return 1;
  }
  while (GetMessage(&msg, NULL, 0, 0) > 0)
  {
    DispatchMessage(&msg);
  }
  return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  RECT rect;
  HDC wdc = GetDC(hWnd);
  PAINTSTRUCT ps;
  switch(message)
  {
    case WM_PAINT:
      BeginPaint(hWnd, &ps);
      GetClientRect (hWnd, &rect);
      SetTextColor(wdc, 0x00000000);
      SetBkMode(wdc,TRANSPARENT);
      DrawText(wdc, L"Say \"hello\" in win32 world!", -1, &rect, DT_CENTER | DT_VCENTER| DT_SINGLELINE | DT_NOCLIP);
      EndPaint(hWnd, &ps);
      break;
    case WM_CLOSE:
      DeleteDC(wdc);
      PostQuitMessage(0);
      break;
    default:
      return DefWindowProc(hWnd, message, wParam, lParam);
  }
  return 0;
}
